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

## Challenges Faced & Solutions

1. **Soil Moisture Sensor Wiring Issues**  
   The sensor’s pins were difficult to position properly on the breadboard. I used jumper wires to create secure, flexible connections, ensuring stable readings.

2. **Pump Power Limitation**  
   The water pump required more current than the Arduino could supply. I solved this by using an external 5V USB power source dedicated to the pump.

3. **Wire Identification for Pump and USB Cable**  
   Since the wires weren’t labeled, I had to cut open the cable and test each conductor to find the correct GND and VCC lines.

4. **Thin Copper Strips Breaking**  
   The internal copper strands were fragile and snapped easily. I reinforced connections by trimming, twisting, and re-stripping wires until they were stable.

5. **Relay Module Connection Problems**  
   The initial wires kept slipping or breaking inside the relay terminals. I replaced the wires with sturdier ones and tightened all connections.

6. **Pump Replacement**  
   After multiple wiring failures, I bought a new pump and matching cable, which ensured a reliable, consistent connection.

7. **ESP8266 Jumper Wire Limitations**  
   The ESP8266 was extremely sensitive to loose wiring. I replaced it with a D1 Mini (USB-C), which offered more stable power and easier Wi-Fi integration.

8. **Pump Running Continuously**  
   The pump wouldn’t stop after turning on. I fixed this by adding hysteresis thresholds in the Arduino code to create a buffer between “wet” and “dry” readings.

9. **Water Flow Too Fast**  
   I adjusted the pump delay and run-time values in the code to control watering speed more precisely.

10. **Blynk App Not Updating**  
    The Arduino needed to send Serial data, and the ESP had to read it and update Blynk accordingly. Implementing this communication fixed the issue.

11. **Voltage Level Differences**  
    The Arduino TX pin outputs 5V while the ESP RX pin expects 3.3V. A voltage divider was used to safely match the levels.

12. **Wi-Fi Causing Code Overload**  
    The Arduino couldn’t manage both Wi-Fi and hardware control reliably. I split the system so:  
    - Arduino controls the pump, buzzer, LED, and relay  
    - ESP/D1 Mini handles Wi-Fi and Blynk  
    Communication between them happens through Serial.

13. **Serial Communication Problems**  
    Sync issues between the Arduino and ESP caused delays and missed data. After troubleshooting baud rates and wiring, the communication became reliable.

14. **Needed a New Arduino with Built-In Wi-Fi**  
    Switching to hardware with integrated Wi-Fi simplified everything, reducing wiring complexity and connection problems.

15. **Final Result**  
    After solving all hardware, software, and communication challenges, the smart watering system works successfully.

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
