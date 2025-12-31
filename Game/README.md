# 🏎️ The Reflex Game

It's time to test your speed! This game combines everything we've learned: LEDs, Buttons, and Random Numbers.

## 🎮 How to Play

1.  **Wait:** The game starts with a 5-second break.
2.  **Watch:** The computer picks a random time to wait (between 0 and 5 seconds). It's a surprise!
3.  **GO!:** When the **Orange Light** on the board turns ON, press your button as fast as you can!
4.  **Win:**
    *   If **Left** is fastest, the **Pin 2 Color** lights up.
    *   If **Right** is fastest, the **Pin 4 Color** lights up.

## 🛠️ The Setup (Combine Everything!)

We are using all the parts from the previous lessons.

### 1. The Buttons
*   **Left Button:** Pin 51 & GND.
*   **Right Button:** Pin 23 & Pin 27.

### 2. The RGB LED
*   **Long Leg (Anode):** Pin 3.
*   **Other Legs:** Pins 2, 4, and 5.

## 💻 Code Secrets

### `random(0, 5000)`
This function asks the Arduino to pick a number out of a hat. We use this to make the wait time unpredictable so you can't cheat by counting!

### `while (true)`
This is an infinite loop *inside* our main loop. It says:
> "Keep checking the buttons forever. Do not stop until I say `break`."

When a button is pressed, we run the `break;` command, which smashes out of the `while` loop so the game can finish.

### `digitalWrite(pin, LOW)` to turn ON?
Remember, our RGB LED is **Common Anode**.
*   The main power comes from Pin 3 (HIGH).
*   To turn a color ON, we connect its pin to Ground (LOW) so electricity can flow.

## 🚀 Challenge

1.  Open the **Serial Monitor** to see who wins.
2.  Can you trick your opponent by pretending to press the button early?
3.  **Coding Challenge:** Can you add a sound (using a buzzer) when someone wins?