// REFLEX GAME!
// Who is the fastest? Left vs Right!

// --- PIN SETUP ---
// Buttons (Updated pins!)
int leftButton = 51;
int rightButtonInput = 23;
int rightButtonGnd = 27;

// RGB LED (Common Anode)
// Pin 3 gives power (Anode)
// Pin 2 and 4 are the colors we will use for the winners.
int ledAnode = 3;
int leftWinnerLed = 2;
int rightWinnerLed = 4;
int unusedLed = 5; // We need to make sure this stays off

void setup() {
  Serial.begin(9600);
  
  // 1. Setup On-board LED (The "GO" Signal)
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW); // Start with it OFF

  // 2. Setup Buttons
  pinMode(leftButton, INPUT_PULLUP);
  
  // Right button "Spider" setup
  pinMode(rightButtonGnd, OUTPUT);
  digitalWrite(rightButtonGnd, LOW); // Create Ground
  pinMode(rightButtonInput, INPUT_PULLUP);

  // 3. Setup RGB LED
  pinMode(ledAnode, OUTPUT);
  digitalWrite(ledAnode, HIGH); // Power ON (Common Anode)

  // Setup the color pins
  pinMode(leftWinnerLed, OUTPUT);
  pinMode(rightWinnerLed, OUTPUT);
  pinMode(unusedLed, OUTPUT);

  // Turn them all OFF initially
  // Remember: For Common Anode, HIGH means OFF.
  digitalWrite(leftWinnerLed, HIGH);
  digitalWrite(rightWinnerLed, HIGH);
  digitalWrite(unusedLed, HIGH);

  // Initialize the random number generator
  // We read a floating pin (A0) to get a random seed value.
  randomSeed(analogRead(A0));
}

void loop() {
  Serial.println("--- NEW GAME ---");
  Serial.println("Get Ready...");

  // 1. The Break (5 Seconds)
  delay(5000);

  // 2. The Random Wait (0 to 5000 ms)
  int randomWait = random(0, 5000);
  delay(randomWait);

  // 3. GO SIGNAL!
  digitalWrite(LED_BUILTIN, HIGH); // Turn on the orange light
  Serial.println("GO!");

  // 4. Wait for a winner
  // We stay in this 'while' loop forever until someone presses a button.
  while (true) {
    if (digitalRead(leftButton) == LOW) {
      // Left Pressed First!
      analogWrite(leftWinnerLed, 255 - 9); // Turn ON Pin 2 (Dimmed)
      Serial.println("LEFT WINS!");
      break; // Exit the loop
    } else if (digitalRead(rightButtonInput) == LOW) {
      // Right Pressed First!
      analogWrite(rightWinnerLed, 255 - 9); // Turn ON Pin 4 (Dimmed)
      Serial.println("RIGHT WINS!");
      break; // Exit the loop
    }
  }

  // 5. Celebrate (Keep lights on for 3 seconds)
  delay(3000);

  // 6. Reset (Turn everything off)
  digitalWrite(LED_BUILTIN, LOW);
  digitalWrite(leftWinnerLed, HIGH);  // OFF
  digitalWrite(rightWinnerLed, HIGH); // OFF
}