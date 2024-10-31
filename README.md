# Advance-IoT-Based-Remote-Patient-Health-Monitoring-System


This repository contains the code and resources for **Haturi Doctor**, an IoT-based remote patient health monitoring system developed for the MTE 3104 - Microcontroller and Interfacing Sessional at the Rajshahi University of Engineering & Technology. The project provides real-time monitoring of a patient’s vital signs, including temperature, humidity, heart rate, and oxygen saturation (SpO2), and displays the data on the **Blynk** IoT platform.

## Project Overview

The **Haturi Doctor** project aims to bridge healthcare gaps by providing an easy-to-use, wireless health monitoring solution. The system collects vital health data through a combination of DHT and MAX30100 sensors and transmits the data to the **Blynk** mobile app for real-time display and remote monitoring.

Key sensors and components include:
- **DHT11** for temperature and humidity readings
- **MAX30100 Pulse Oximeter** for heart rate (BPM) and oxygen saturation (SpO2) measurements
- **ESP32 Microcontroller** for wireless communication and data processing

## Features

- **Real-Time Health Monitoring:** Records and displays temperature, humidity, heart rate, and SpO2 levels in real-time.
- **Blynk IoT Platform Integration:** Sends data to the Blynk mobile app for remote access.
- **Heartbeat Detection Callback:** Notifies the app on each detected heartbeat.
- **Future Expansion:** Allows easy integration of additional sensors (e.g., ECG, glucose) to enhance the system.

## Components

1. **ESP32** - Microcontroller for managing sensor data and connecting to Wi-Fi.
2. **DHT11** - Temperature and humidity sensor.
3. **MAX30100** - Pulse oximeter sensor for heart rate and SpO2.
4. **Blynk Platform** - Displays data on a mobile dashboard.

## Circuit Diagram

The complete circuit design can be found on [Cirkit Designer](https://app.cirkitdesigner.com/project/eac0d896-5b71-4bb7-983f-7b1f47af07a5).

## Installation and Setup

1. **Clone this repository** to your local machine:
   ```bash
   git clone https://github.com/username/Haturi-Doctor.git
   ```
2. **Install Required Libraries**:
   - [Blynk](https://github.com/blynkkk/blynk-library)
   - [DHT Sensor Library](https://github.com/adafruit/DHT-sensor-library)
   - [MAX30100_PulseOximeter](https://github.com/oxullo/Arduino-MAX30100)

3. **Configure the Code**:
   - Replace the following placeholders in `main.ino` with your Blynk and Wi-Fi credentials:
     ```cpp
     #define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
     #define BLYNK_TEMPLATE_NAME "YOUR_TEMPLATE_NAME"
     #define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"

     const char* ssid = "Your_SSID";  // Wi-Fi SSID
     const char* password = "Your_PASSWORD";  // Wi-Fi Password
     ```
4. **Upload to ESP32**:
   - Connect the ESP32 board to your computer and upload the code.

## How It Works

1. The **ESP32** connects to Wi-Fi and initializes the sensors.
2. **DHT11** measures the temperature and humidity, while **MAX30100** records heart rate and SpO2.
3. Data is sent to the Blynk platform, where it is accessible via the mobile app.
4. On each heartbeat detected by the MAX30100, a notification is printed to the serial console.

## Usage

- Open the Blynk app and navigate to your project dashboard to view real-time data.
- Temperature, humidity, heart rate, and SpO2 levels update continuously, allowing for effective remote monitoring.

## Future Scope

This project lays the foundation for enhanced healthcare accessibility in remote areas. Future enhancements include:
- **Additional Sensors** for ECG, glucose, and spirometry.
- **Telemedicine Camps** for community healthcare access.

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for more details.

---

