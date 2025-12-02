# Smart Plant Watering System 🌱💧
**Created by:** Zainab Oyekade
**GitHub:** [@zainaboyekade-dot](https://github.com/zainaboyekade-dot)

This project automatically waters a plant based on soil moisture using an Arduino, a water pump, and the Blynk IoT app.

## 📌 Features
- Automatically waters when the soil is dry
- Stops watering when the soil is wet
- LED + buzzer local alerts
- Manual pump control via Blynk
- Real-time moisture, pump, and LED monitoring
- Sends notifications when watering

## 🛠 Components Used
- Arduino Uno Rev 2
- Capacitive Soil Moisture Sensor
- 5V Water Pump (externally powered)
- 5V Relay Module
- LED + Resistor
- Buzzer
- Breadboard + Jumper Wires
- 5v USB Power Bank

## 🔌 How It Works
1. The soil moisture sensor reads the moisture level
2. Arduino checks if the soil is dry or wet
3. If dry → relay turns pump on
4. If wet → relay turns pump off
5. LEDs + buzzer show status
6. Blynk app updates readings + notifications

## 📸 Demo
Images are inside the **iot_plant_images/** folder
Videos are inside the **iot_plant_videos/** folder

## 📂 Project Structure
- iot_plant_images/
- iot_plant_videos/
- zais_iot_plant_system_arduino/
- README.md

## 🧠 Lessons Learned
- Arduino programming and debugging
- Sensor integration and calibration
- Relay control + powering external devices safely
- Building IoT features with Blynk
- Hardware troubleshooting and testing

## 🚀 Future Improvements
- Add a second sensor for multiple plants
- Add a predictive watering schedule with ML
- Add a web dashboard to monitor plant data
- Add battery power monitoring
