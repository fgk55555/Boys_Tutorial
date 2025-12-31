// This is the "Blink" program!
// It makes the little light on the Arduino board flash on and off.

// VARIABLES: These are like boxes where we store numbers.
// You can change these numbers to make the light blink faster or slower!
int onTime = 1000;  // How long the light stays ON (in milliseconds)
int offTime = 1000; // How long the light stays OFF (in milliseconds)

// The setup function is like getting ready for the day.
// You only do it once when you wake up (or when the Arduino turns on).
void setup() {
  // We are telling the Arduino that the pin connected to the light (LED_BUILTIN)
  // will be used to send electricity OUT to turn on the light.
  // On your Arduino Mega, this is Pin 13.
  pinMode(LED_BUILTIN, OUTPUT);
}

// The loop function is the main action!
// It runs over and over again, forever and ever.
// Like a song on repeat!
void loop() {
  // Turn the light ON!
  // HIGH means "Give it power!"
  digitalWrite(LED_BUILTIN, HIGH);

  // A FOR LOOP is like counting.
  // We count from 0 up to 'onTime'.
  // Every time we count 1, we wait for 1 millisecond.
  for (int i = 0; i < onTime; i++) {
    delay(1);
  }

  // Turn the light OFF.
  // LOW means "Stop the power."
  digitalWrite(LED_BUILTIN, LOW);

  // Another FOR LOOP to wait while the light is off.
  for (int i = 0; i < offTime; i++) {
    delay(1);
  }
}