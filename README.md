# STM32F439ZI Bare-Metal Examples
- This repository showcases various bare-metal programming examples for the STM32F439ZI microcontroller.
- It does not use HAL or LL drivers — instead, it directly manipulates peripheral registers to demonstrate how the MCU works at a low level.
- I have created this repo to understand how STM32 peripherals function without abstraction layers.

## Project Structure
* GPIO_TOGGLE:
    - Toggles a GPIO pin using direct register configuration.
* GPIO_TOGGLE_STRUCT
    - Toggles a GPIO pin, but peripheral registers are accessed through a structured definition.
* GPIO_TOGGLE2
    - Toggles a GPIO pin using an included STM32 package (CMSIS-style register definitions).
* GPIO_TOGGLE3
    - Toggles a GPIO pin using the BSRR (Bit Set/Reset Register) for atomic operations.
* GPIO_INPUT
    - Reads the state of a GPIO input pin and reflects its value on an output pin.
* UART_Tx
    - Transmits a single character over UART using only register-level configuration.
 
## Requirements
* Hardware:
    - STM32F439ZI (tested on Nucleo-F439ZI board)
* Software:
    - ARM GCC toolchain
    - ST-LINK Utility for flashing and debugging
 
## Author
* Bare-metal STM32F439ZI examples created for learning and experimentation.
