# 💡 The Blinking Light Project

This is the "Hello World" of electronics! We are going to make the built-in light on the Arduino board flash on and off.

## 🛠️ What You Need
*   1 x Arduino Mega Board
*   That's it! (The light is already built into the board).

## 💻 What is the Code Doing?

### 1. Variables (The Control Panel)
At the very top of the file, we have **Variables**. Think of a variable like a box with a name on it. Inside the box, we put a number.

*   `onTime`: How long the light stays ON.
*   `offTime`: How long the light stays OFF.

You can change the numbers in these boxes to change how the program works!

### 2. The "For Loop" (The Counter)
Computers are really good at counting. A `for` loop is just a way to tell the computer to count.

Instead of sleeping for a long time, we tell the Arduino:
> "Count to 1000. Every time you say a number, wait for 1 millisecond."

It looks like this:
```cpp
for (int i = 0; i < onTime; i++) {
  delay(1);
}
```
*   `int i = 0`: Start counting at 0.
*   `i < onTime`: Keep going as long as the number is smaller than our `onTime` variable.
*   `i++`: Add 1 to the count every time.

## 🚀 Your Mission

1.  **Upload the code** to the Arduino and watch the orange light blink.
2.  **Change the Speed:**
    *   Go to the top of the code.
    *   Change `onTime` to `100`.
    *   Change `offTime` to `100`.
    *   Upload it again. What happens?
3.  **Make a Heartbeat:**
    *   Try setting `onTime` to `100` and `offTime` to `1000`.
    *   Does it look like a heartbeat?