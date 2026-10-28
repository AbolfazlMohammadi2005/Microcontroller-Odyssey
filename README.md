# Microcontroller Odyssey

**From blinking an LED to talking over UART — a hands-on journey through AVR microcontroller programming in C.**

Part 3 of the **Odyssey trilogy**: [*C Odyssey*](https://github.com/AbolfazlMohammadi2005/C-Odyssey) → [*C++ Odyssey*](https://github.com/AbolfazlMohammadi2005/Cpp-Odyssey) → **Microcontroller Odyssey**
---

## What is this?

An educational collection of AVR (**ATmega32**) programs written in C for **CodeVisionAVR**. It starts with toggling one pin and grows, step by step, into interrupts, timers, ADC and serial communication.

Every folder is named `NN-Name` and contains two sub-folders:

| Folder | Meaning |
|---|---|
| `CodeVisionAVR` | The programs. Every exercise is called `Pset01`, `Pset02`, ... and is a complete solution |
| `Proteus` | The simulation projects (`.pdsprj`) for the exercises of that folder |

A `Pset` can be a single `.c` file or a folder (e.g. `Pset03/`) when the exercise is a multi-file project with its own `.h` / `.c` files.

Each exercise only uses concepts introduced up to its own folder, so you can work through them in order.

## Contents

| Folder | Topic | Psets |
|---|---|:-:|
| [01-Digital Output](01-Digital%20Output) | Digital output & bit operations | 11 |
| [02-Shift and Array](02-Shift%20and%20Array) | Shifts, arrays, 7-segment & simple state machines | 16 |
| [03-Loop and String](03-Loop%20and%20String) | Loops & strings | 14 |
| [04-Function](04-Function) | Functions, prototypes, multi-file projects, sprintf/puts | 18 |
| [05-Storage Class](05-Storage%20Class) | Storage classes & static | 6 |
| [06-Pointer and LCD](06-Pointer%20and%20LCD) | Pointers & the LCD library | 14 |
| [07-Enum and State Machine](07-Enum%20and%20State%20Machine) | enum & finite state machines | 6 |
| [08-Struct and Union](08-Struct%20and%20Union) | struct, union & bit-fields | 6 |
| [09-Digital Input](09-Digital%20Input) | Digital input, debouncing & keypad | 6 |
| [10-External Interrupt](10-External%20Interrupt) | External interrupts | 5 |
| [11-Timer](11-Timer) | Timers/counters, CTC & PWM | 5 |
| [12-ADC](12-ADC) | Analog-to-digital converter (ADC) | 6 |
| [13-USART](13-USART) | USART serial communication | 6 |

## Getting started

**Tools**

- CodeVisionAVR (the code uses `<io.h>`, `<delay.h>`, `flash`, `interrupt [VECTOR]`, `#asm("sei")`)
- Proteus (or real hardware) to run it

**Assumptions used throughout**

- Chip: **ATmega32**
- Clock: **8 MHz** (the timer, ADC and baud-rate values in `11-Timer`, `12-ADC` and `13-USART` depend on this; if you use another clock, recompute them)
- Outputs are active-high LEDs; 7-segment displays are common-cathode
- Buttons connect to GND and use the internal pull-up (pressed = 0)

**Run an exercise**

1. In CodeVisionAVR create a project for ATmega32 and set the clock to 8 MHz.
2. Add the chosen `.c` file from the `CodeVisionAVR` folder (for folders, add every `.c` file in it) to the project.
3. Build in CodeVisionAVR to get the `.hex` file.
4. Load the `.hex` into Proteus and run the simulation there. Keep the Proteus project in the `Proteus` folder.

## References

- Muhammad Ali Mazidi, Sarmad Naimi, Sepehr Naimi — *The AVR Microcontroller and Embedded Systems: Using Assembly and C*
- Richard Barnett, Larry O'Cull, Sarah Cox — *Embedded C Programming and the Atmel AVR*
- Elliot Williams — *Make: AVR Programming*
- Brian W. Kernighan, Dennis M. Ritchie — *The C Programming Language*
- Microchip (Atmel) — *ATmega32 datasheet*
- HP InfoTech — *CodeVisionAVR user manual*

## Author

**Abolfazl Mohammadi** — Physics Student and Developer.
<br>
GitHub: [@AbolfazlMohammadi2005](https://github.com/AbolfazlMohammadi2005) 
<br>
Telegram: [t.me/Physicsbymadman](https://t.me/Physicsbymadman)

## License

Released under the [MIT License](LICENSE).
