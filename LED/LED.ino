// RGB LED Control (Common Anode)
// This sketch cycles through pins 2, 4, and 5, fading them in and out.
//
// Circuit:
// Pin 3: Common Anode (+) - Connected directly to Arduino Pin 3
// Pin 2, 4, 5: Cathodes (-) - Connected to the RGB LED legs
//
// WARNING: No current limiting resistors!
// We cap the brightness at 30 (out of 255) to prevent damage.

const int anodePin = 3;
// TODO: Once you figure out which pin is which color, you can rename these!
const int colorPins[] = {2, 4, 5}; 
const int maxBrightness = 9;      // Cap brightness to save the LED/Pin

void setup() {
  // Setup the Common Anode pin
  pinMode(anodePin, OUTPUT);
  // Turn the anode HIGH (5V) to provide power
  digitalWrite(anodePin, HIGH);

  // Setup the color pins
  for (int i = 0; i < 3; i++) {
    pinMode(colorPins[i], OUTPUT);
    // Initialize them to HIGH.
    // For Common Anode, HIGH means OFF (no voltage difference).
    digitalWrite(colorPins[i], HIGH);
  }
}

void loop() {
  // Cycle through each of the 3 color pins
  for (int i = 0; i < 3; i++) {
    int currentPin = colorPins[i];

    // Fade IN
    for (int brightness = 0; brightness <= maxBrightness; brightness++) {
      // Common Anode Logic:
      // 255 is OFF (5V), 0 is ON (0V).
      // To get brightness 'x', we write '255 - x'.
      analogWrite(currentPin, 255 - brightness);
      delay(80); // 80ms * 18 steps (up and down) is approx 1.5 second total
    }

    // Fade OUT
    for (int brightness = maxBrightness; brightness >= 0; brightness--) {
      analogWrite(currentPin, 255 - brightness);
      delay(80);
    }

    // Ensure the pin is fully OFF before moving to the next
    digitalWrite(currentPin, HIGH);
  }
}