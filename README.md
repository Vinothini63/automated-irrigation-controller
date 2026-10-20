# Automated Irrigation Controller Using ESP32

## Project Overview
This project simulates an automated irrigation controller using an ESP32 microcontroller in Wokwi. A potentiometer simulates soil moisture readings, and the system controls a relay and LEDs based on the moisture level.

## Components Used
- ESP32 DevKit V1
- Potentiometer
- 16×2 I2C LCD
- Relay Module
- Red LED
- Green LED
- 220Ω Resistors

## Working Principle
- The potentiometer simulates soil moisture levels.
- The LCD displays the moisture percentage and pump status.
- When the moisture level is below 35%, the relay and red LED turn ON.
- When the moisture level reaches 35% or above, the relay turns OFF and the green LED turns ON.

## Technologies Used
- Arduino C++
- ESP32
- Wokwi Simulation
- I2C LCD

## Simulation
Add your Wokwi project link here.

## Note
This is a simulation project. The potentiometer represents the soil moisture input; it does not measure actual soil moisture.

## Author
Vinothini
