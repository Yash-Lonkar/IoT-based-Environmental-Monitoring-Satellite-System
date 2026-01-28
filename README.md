🌍 IoT-Based Environmental Monitoring Satellite System

An IoT-powered environmental monitoring system that simulates satellite-based data collection using on-board sensors and transmits real-time atmospheric data to an interactive web dashboard.
The system continuously monitors temperature, humidity, pressure, and altitude using low-power sensors and publishes the data wirelessly via ESP8266 (Wi-Fi).

<br><br>IoT を活用した環境モニタリングシステムで、オンボードセンサーを用いて衛星ベースのデータ収集をシミュレーションし、リアルタイムの大気データをインタラクティブな Web ダッシュボードへ送信します。
本システムは、低消費電力センサーを使用して温度・湿度・気圧・高度を継続的に監視し、ESP8266（Wi-Fi）を介して無線でデータを送信します。<br><br>

📌 Project Overview

Environmental monitoring is critical for climate research, weather forecasting, and pollution analysis. This project demonstrates how satellite-style sensor payloads can collect environmental data and transmit it to a ground station dashboard using IoT technologies.

The system uses:

BMP280 for pressure & altitude

DHT11 for temperature & humidity

ESP8266 for wireless communication

Interactive dashboard for real-time visualization

🛰️ System Architecture
[Sensors Payload]
   │
   ├── BMP280 (Pressure, Altitude)
   ├── DHT11 (Temperature, Humidity)
   │
[ESP8266 Microcontroller]
   │
   └── Wi-Fi Communication
        │
        └── Cloud / Local Server
              │
              └── Interactive Web Dashboard

🔧 Hardware Components
Component	Description
ESP8266	Wi-Fi enabled microcontroller
BMP280	Barometric pressure & altitude sensor
DHT11	Temperature & humidity sensor
Breadboard	Circuit connections
Jumper Wires	Interconnections
Power Supply	USB / Battery
💻 Software & Technologies

Arduino IDE

ESP8266 Board Package

HTML / CSS / JavaScript

Charts.js / Plotly.js (for dashboard)

HTTP / MQTT (optional)

JSON Data Format

📊 Features

📡 Real-time environmental data transmission

🌡️ Temperature & humidity monitoring

🌬️ Atmospheric pressure measurement

🏔️ Altitude estimation

📈 Interactive dashboard with live graphs

🌐 Remote monitoring via Wi-Fi

🔋 Low power and lightweight design

📂 Project Structure
IoT-Environmental-Monitoring-Satellite-System/
│
├── firmware/
│   ├── esp8266_code.ino
│
├── dashboard/
│   ├── index.html
│   ├── style.css
│   └── script.js
│
├── circuit/
│   └── wiring_diagram.png
│
├── screenshots/
│   └── dashboard_preview.png
│
└── README.md

🔌 Circuit Connections
BMP280 → ESP8266 (I2C)
BMP280	ESP8266
VCC	3.3V
GND	GND
SCL	D1
SDA	D2
DHT11 → ESP8266
DHT11	ESP8266
VCC	3.3V
DATA	D4
GND	GND
⚙️ How It Works

Sensors collect environmental data.

ESP8266 reads sensor values periodically.

Data is formatted into JSON.

ESP8266 transmits data via Wi-Fi.

Dashboard fetches and visualizes the data in real time.

📈 Dashboard Preview

Displays live graphs for:

Temperature (°C)

Humidity (%)

Pressure (hPa)

Altitude (meters)

(Add screenshots in the /screenshots folder)

🚀 Applications

Environmental monitoring

Weather observation

Smart agriculture

Climate research

Educational satellite simulations

IoT research projects

🔮 Future Enhancements

🌐 Cloud integration (Firebase / AWS / ThingsBoard)

🛰️ GPS module for location tracking

📡 LoRa / Satellite uplink simulation

📱 Mobile app dashboard

☁️ AI-based climate analysis

🔐 Data encryption & authentication

🧪 Testing & Validation

Sensor accuracy validated using reference instruments

Wi-Fi transmission tested under varying network conditions

Dashboard tested for real-time responsiveness

👨‍💻 Author

Yash Lonkar
