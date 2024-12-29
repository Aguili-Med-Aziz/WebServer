# Embedded Web Server with Multiple Sensors and Motor Control

This project demonstrates an **embedded web server** running on an ESP32 (or similar device) using the **Mongoose** web server library. It integrates multiple sensors (Temperature, Humidity, Light, Pressure) and provides a **web interface** for real-time monitoring and motor control.

## Features
- Real-time sensor data from **DHT22**, **BH1750**, and **BMP180** sensors
- **Motor control** via PWM and basic PID control
- **Web-based dashboard** for viewing sensor data and controlling the motor
- **User authentication** for secure access

## Setup
1. Install **Arduino IDE** and **Mongoose library**.
2. Clone this repository to your Arduino project folder.
3. Edit `config.h` for pin assignments and Wi-Fi credentials.
4. Upload the code to your ESP32 (or other compatible board).
5. Connect the sensors to the specified pins.
6. Open the serial monitor to see the device's IP address.
7. Access the web server using a browser.

## License
MIT License
