# 🏠 ESP32 Smart Room Environment Monitor

A Wi-Fi-enabled IoT monitoring system built using the **ESP32** and **DHT11** sensor to monitor indoor environmental conditions in real time. The system hosts an embedded web server that displays live room temperature, humidity, and room health through a responsive dashboard accessible from any device connected to the same network.

---

## 📌 Project Overview

This project demonstrates how an ESP32 can be used as a standalone IoT web server for real-time environmental monitoring. The ESP32 reads temperature and humidity data from a DHT11 sensor and serves a live dashboard over Wi-Fi without requiring any external cloud platform.

The dashboard automatically refreshes every 5 seconds and evaluates the room's environmental condition based on the measured temperature.

---

## ✨ Features

- 🌡️ Real-time Room Temperature Monitoring
- 💧 Real-time Room Humidity Monitoring
- 🟢 Automatic Room Health Evaluation
- 💬 Intelligent Environmental Recommendations
- 🌐 Built-in ESP32 Web Server
- 📶 Wi-Fi Connectivity
- 🔄 Auto-refreshing Dashboard (every 5 seconds)
- 📱 Accessible from any device on the same Wi-Fi network
- 🎨 Responsive HTML & CSS based dashboard

---

## 🛠 Hardware Used

| Component | Quantity |
|-----------|---------:|
| ESP32 Dev Module | 1 |
| DHT11 Temperature & Humidity Sensor | 1 |
| Breadboard | 1 |
| Jumper Wires | As Required |
| USB Cable | 1 |

---

## 🔌 Circuit Connections

| DHT11 Pin | ESP32 Pin |
|-----------|-----------|
| VCC | 3.3V |
| GND | GND |
| DATA | GPIO 4 |

---

## 💻 Software & Libraries

- Arduino IDE
- ESP32 Board Package
- WiFi.h
- WebServer.h
- DHT.h

---

## ⚙️ How It Works

1. ESP32 connects to the local Wi-Fi network.
2. The DHT11 sensor measures room temperature and humidity.
3. The ESP32 hosts a web server on Port 80.
4. When a client opens the ESP32 IP address in a browser, a dynamic HTML dashboard is generated.
5. The webpage refreshes automatically every 5 seconds to display the latest sensor values.
6. Based on the temperature, the ESP32 classifies the room as:
   - 🟢 Healthy
   - 🟠 Warm
   - 🔴 Attention Required

---

## 🏗 System Architecture

```
           DHT11 Sensor
                │
                ▼
             ESP32
                │
          Wi-Fi Network
                │
        Embedded Web Server
                │
                ▼
      Laptop / Mobile Browser
```

---

## 📸 Project Images

### Dashboard

<img width="1535" height="697" alt="image" src="https://github.com/user-attachments/assets/3f4e9756-5cd2-400f-87db-3cb960987a49" />


```
images/dashboard.png
```

### Hardware Setup
<img width="427" height="512" alt="image" src="https://github.com/user-attachments/assets/201d3cc6-83a0-4114-a232-eb9683d8c369" />


```
images/hardware.jpg
```

### Project Setup

<img width="435" height="517" alt="image" src="https://github.com/user-attachments/assets/88d7ea05-e3b8-4de6-ba98-20ced32a7f98" />



```
images/cover.jpg
```

---

## 📂 Repository Structure

```
ESP32-Smart-Room-Environment-Monitor
│
├── SmartRoomEnvironmentMonitor.ino
├── README.md
├── LICENSE
│
└── images
    ├── dashboard.png
    ├── hardware.jpg
    └── cover.jpg
```

---

## 🚀 Future Improvements

- ☁️ ThingSpeak Cloud Integration
- 📊 Historical Data Logging
- 📱 Mobile Friendly Dashboard
- 📡 MQTT Communication
- 📈 Live Charts
- 🔔 Email/SMS Alerts
- 🤖 TinyML-based Environmental Anomaly Detection

---

## 🎯 Learning Outcomes

Through this project, I learned:

- ESP32 GPIO Programming
- Sensor Interfacing (DHT11)
- Wi-Fi Communication
- Embedded HTTP Server
- HTML & CSS Generation from ESP32
- Dynamic Web Pages
- IoT System Design
- Client-Server Communication
- Embedded C++ Programming

---

## 👩‍💻 Author

**Niharika Saini**

B.Tech Electronics & Computer Engineering (ECM)

Jaypee Institute of Information Technology

---

⭐ If you found this project interesting, consider giving it a star!
