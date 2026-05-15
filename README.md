# 🌾 FarmPulse - Smart IoT Agriculture System

## 🚀 Overview
FarmPulse is an ESP32-based smart agriculture automation system that enables remote monitoring and control of farming operations using IoT (ThingESP + WhatsApp/cloud integration).

It integrates sensors, actuators, and cloud communication to automate irrigation, seed dispensing, weed control, and environmental monitoring.

---

## ⚙️ Features
- 🌱 Soil moisture monitoring system
- 💧 Smart irrigation control (automatic/manual)
- 🌾 Seed dispensing mechanism using servo motor
- 🌿 Weed cutting motor control
- 🌡 Temperature & humidity monitoring (DHT11)
- 📡 Remote control via WhatsApp / ThingESP

---

## 🧠 System Architecture

User Command (WhatsApp / ThingESP)
        ↓
Cloud Server (IoT Platform)
        ↓
ESP32 Microcontroller
        ↓
Sensors + Actuators
        ↓
Farm Operations (Irrigation / Seed / Weed Control)

---

## 🔌 Hardware Components
- ESP32 Development Board
- Soil Moisture Sensor
- DHT11 Temperature & Humidity Sensor
- Servo Motors (Soil sensor + Seed dispensing)
- Relay Module (Pump + Motor control)
- Water Pump
- Weed Cutting Motor

---

## 🎮 Supported Commands

### 🌱 Irrigation Control
- Start Irrigation → Turns pump ON
- Stop Irrigation → Turns pump OFF

### 🌿 Weed Control
- Start Weed Cutting → Motor ON
- Stop Weed Cutting → Motor OFF

### 🌾 Seed System
- Dispense Seed → Activates seed mechanism

### 🌍 Monitoring
- Check Soil → Returns moisture + temperature + humidity
- temperature → Shows temperature
- humidity → Shows humidity

---

## ⚙️ Working Principle
1. User sends command via WhatsApp (ThingESP)
2. ESP32 receives command via WiFi
3. Based on command, sensors or actuators are activated
4. Real-time feedback is sent back to user

---

## 🔥 Key Highlights
- Real-time IoT-based farming automation
- Cloud-connected agriculture system
- Sensor-driven smart irrigation
- Low-cost smart farming solution

---

## 🚀 Future Improvements
- AI-based crop health prediction
- Mobile app dashboard
- Solar-powered system
- Fully autonomous irrigation scheduling
- Camera-based crop monitoring

---

## 👨‍💻 Author
Kiran  
GitHub: https://github.com/kiranshankar08

---

## 📌 Project Status
✔ Hardware integration complete  
✔ IoT cloud communication working  
✔ Ready for real-world testing
