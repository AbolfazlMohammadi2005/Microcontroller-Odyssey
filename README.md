# Microcontroller Odyssey

**From blinking an LED to talking over UART — a hands-on journey through AVR microcontroller programming in C.**

Part 3 of the **Odyssey trilogy**: [*C Odyssey*](https://github.com/AbolfazlMohammadi2005/C-Odyssey) → [*C++ Odyssey*](https://github.com/AbolfazlMohammadi2005/Cpp-Odyssey) → **Microcontroller Odyssey**
---

## What is this?

An educational, chapter-by-chapter collection of AVR (**ATmega32**) programs written in C for **CodeVisionAVR**. It starts with toggling one pin and grows, chapter by chapter, into interrupts, timers, ADC and serial communication.

Every chapter has two kinds of files:

| Prefix | Meaning |
|---|---|
| `EX` | **Examples** — the worked examples from the course textbook, kept as they are |
| `PS` | **Problem Sets** — extra exercises for the same chapter. Each file is a complete solution |

A `PS` can be a single `.c` file or a folder (e.g. `PS6/`) when the exercise is a multi-file project with its own `.h` / `.c` files.

Each problem set only uses concepts introduced up to its own chapter, so you can work through the book in order.

## Chapters

| # | Topic | Book examples | Problem sets |
|---|---|:-:|:-:|
| [1](chapters/ch1) | Digital output & bit operations | 4 | 6 |
| [2](chapters/ch2) | Shifts, arrays, 7-segment & simple state machines | 8 | 8 |
| [3](chapters/ch3) | Loops & strings | 3 | 6 |
| [4](chapters/ch4) | Functions, prototypes, multi-file projects, sprintf/puts | 10 | 8 |
| [5](chapters/ch5) | Storage classes & static | 1 | 5 |
| [6](chapters/ch6) | Pointers & the LCD library | 3 | 6 |
| [7](chapters/ch7) | enum & finite state machines | 1 | 5 |
| [8](chapters/ch8) | struct, union & bit-fields | 1 | 5 |
| [9](chapters/ch9) | Digital input, debouncing & keypad *(added)* | — | 5 |
| [10](chapters/ch10) | External interrupts *(added)* | — | 5 |
| [11](chapters/ch11) | Timers/counters, CTC & PWM *(added)* | — | 5 |
| [12](chapters/ch12) | Analog-to-digital converter (ADC) *(added)* | — | 6 |
| [13](chapters/ch13) | USART serial communication *(added)* | — | 6 |

Chapters 9–13 are not in the book; they were added to continue naturally from GPIO output into the peripherals.

## Getting started

**Tools**

- CodeVisionAVR (the code uses `<io.h>`, `<delay.h>`, `flash`, `interrupt [VECTOR]`, `#asm("sei")`)
- Proteus (or real hardware) to run it

**Assumptions used throughout**

- Chip: **ATmega32**
- Clock: **8 MHz** (the timer, ADC and baud-rate values in chapters 11–13 depend on this; if you use another clock, recompute them)
- Outputs are active-high LEDs; 7-segment displays are common-cathode
- Buttons connect to GND and use the internal pull-up (pressed = 0)

**Run an exercise**

1. In CodeVisionAVR create a project for ATmega32 and set the clock to 8 MHz.
2. Add the chosen `.c` file (for folders, add every `.c` file in it) to the project.
3. Build in CodeVisionAVR to get the `.hex` file.
4. Load the `.hex` into Proteus and run the simulation there.

## Author

**Abolfazl Mohammadi** — Physics Student and Developer.
<br>
GitHub: [@AbolfazlMohammadi2005](https://github.com/AbolfazlMohammadi2005) 
<br>
Telegram: [t.me/Physicsbymadman](https://t.me/Physicsbymadman)

## License

Released under the [MIT License](LICENSE).
