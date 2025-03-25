# stm32-indicator
stm 32 with application and base software
# Vehicle Indicator Control System (STM32)

## Overview
This project implements a vehicle indicator control system using an **STM32G070** microcontroller. The system manages **left, right, and hazard indicators** based on push button inputs.

## Features
- **Left Indicator:** Blinks every 300ms when activated.
- **Right Indicator:** Blinks every 300ms when activated.
- **Hazard Lights:** Both indicators blink together every 300ms when activated.
- **Push Button Control:**  
  - Press & hold for **1 second** to toggle indicators.
  - If both buttons are pressed for **1 second**, hazard lights activate.
- **PWM-Based LED Control:**  
  - **TIM1 CH2 → Left Indicator LED**  
  - **TIM3 CH1 → Right Indicator LED**  
- **Event Logging via UART (CP2102 TTL Adapter)**
  - Indicator state changes are logged to UART for debugging.

## Hardware Requirements
- **STM32G070 Development Board**
- **Two Push Buttons** (10kΩ pull-up resistors)
- **Two LEDs** (for indicators)
- **CP2102 TTL USB-to-Serial Adapter** (for UART logging)

## Software Requirements
- **STM32CubeIDE** (Code Development)
- **Keil / VSCode (Optional)**
- **Tera Term / PuTTY** (For UART Monitoring)

## UART Log Example
```plaintext
[INFO] Left Indicator ON
[INFO] Left Indicator OFF
[INFO] Right Indicator ON
[INFO] Hazard Lights ON
