// BUTTONS!
// This program checks if you are pressing buttons and tells the computer.

// We give names to the pins so we know which button is which.
int leftButtonPin = 51;

// The right button is special! It connects two number pins together.
// We will use one pin as the "Input" (to listen) and one as "Ground" (power drain).
int rightButtonInput = 23;
int rightButtonGround = 27;

void setup() {
  // Start the Serial Monitor.
  // This opens a phone line so the Arduino can talk to the computer.
  // 9600 is the speed they talk at.
  Serial.begin(9600);

  // --- LEFT BUTTON SETUP ---
  // INPUT_PULLUP is a cool trick!
  // Normally, a pin floats like a feather in the wind.
  // PULLUP turns on a tiny internal magnet (resistor) that holds the pin HIGH (5V).
  // When you press the button, it connects to Ground and gets pulled LOW.
  pinMode(leftButtonPin, INPUT_PULLUP);

  // --- RIGHT BUTTON SETUP ---
  // We need to make Pin 29 act like a Ground pin (0 Volts).
  pinMode(rightButtonGround, OUTPUT);
  digitalWrite(rightButtonGround, LOW); // LOW means 0V (Ground)

  // Now we set up the input pin just like the left button.
  pinMode(rightButtonInput, INPUT_PULLUP);
}

void loop() {
  // Check the Left Button
  // Remember: Because we use INPUT_PULLUP, LOW means the button is PRESSED!
  // (Think of it like pulling a balloon down to the ground).
  if (digitalRead(leftButtonPin) == LOW) {
    Serial.println("Left button is pressed!");
  }

  // Check the Right Button
  // This works the same way. If Pin 23 touches Pin 29 (which is LOW),
  // then Pin 23 becomes LOW.
  if (digitalRead(rightButtonInput) == LOW) {
    Serial.println("Right button is pressed!");
  }

  // For debugging: print the button states
  Serial.print(digitalRead(rightButtonInput));Serial.println(digitalRead(leftButtonPin));
  // Wait for 100 milliseconds (1/10th of a second).
  // This stops the Arduino from screaming "PRESSED!" too fast for us to read.
  delay(100);
}
