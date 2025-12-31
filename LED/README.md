# 🌈 The Rainbow LED Project!

Welcome to the Rainbow LED project! In this experiment, we are going to make a special light fade in and out with different colors.

## 🛠️ What You Need
*   1 x Arduino Mega Board
*   1 x RGB LED (It looks like a normal light bulb, but it has **4 legs**!)

## 🔌 How to Connect It (The Wiring)

This LED is special because it has 4 legs instead of 2.
*   One leg is **Longer** than the others. This is the "Power" leg.
*   The other three legs are for **Red**, **Green**, and **Blue**.

**Follow these steps carefully:**

1.  Find the **Longest Leg** on your LED.
2.  Plug that Longest Leg into **Pin 3** on your Arduino.
3.  Plug the leg to the *left* of the long one into **Pin 2**.
4.  Plug the two legs to the *right* of the long one into **Pin 4** and **Pin 5**.

It should look a little bit like this:

```text
       ( LED Bulb )
       /   |   |   \
      /    |   |    \
   Leg    Leg  Leg   Leg
    |      |    |     |
  Pin 2  Pin 3 Pin 4 Pin 5
        (Longest)
```

*(It's okay if you have to bend the legs a tiny bit to make them fit!)*

## 💻 What is the Code Doing?

The code is the set of instructions we give the computer. Here is what happens inside the Arduino:

### 1. Setup (Getting Ready)
Just like you get dressed in the morning, the Arduino needs to get ready.
*   It turns **Pin 3** ON to give the LED power.
*   It gets Pins 2, 4, and 5 ready to control the colors.

### 2. Loop (Doing the Work)
This part runs over and over again, forever!
1.  **Pick a Color:** It chooses one of the pins (2, 4, or 5).
2.  **Fade In:** It slowly turns the light ON. It starts dark and gets brighter.
3.  **Fade Out:** It slowly turns the light OFF. It starts bright and gets darker.
4.  **Next Color:** It moves to the next pin and does it all again!

### ⚠️ Important Safety Tip
We are being very careful with the brightness. Since we don't have "resistors" (tiny parts that slow down electricity), we are only turning the light on a tiny bit (Brightness 9 out of 255). This keeps the LED safe so it doesn't burn out!