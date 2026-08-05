# 💊 Smart Medicine Reminder System using ESP32

An IoT-based Smart Medicine Reminder System built with **ESP32**, designed to help patients take medicines on time. The system provides visual and audio reminders, sends Telegram notifications, records medicine adherence, generates weekly reports, and includes an emergency SOS alert feature.

---

## 📌 Project Overview

The Smart Medicine Reminder System assists elderly people and patients by reminding them to take medicines at scheduled times. It uses the Internet to synchronize time, stores reminder schedules permanently, and communicates with caregivers through Telegram.

---

## ✨ Features

- ⏰ Three Daily Medicine Reminders
- 📅 Automatic Time Synchronization using NTP
- 📟 LCD Display for Date, Time, and Reminder Status
- 🔔 Buzzer Alert for Medicine Reminder
- 🔴 Red LED Reminder Indicator
- 🟢 Green LED Confirmation Indicator
- 📲 Telegram Notification for Every Reminder
- ✅ Medicine Taken Confirmation
- ❌ Missed Dose Detection
- 📊 Weekly Medicine Adherence Report
- 🆘 Emergency SOS Button
- 💾 EEPROM (Preferences) Storage for Reminder Times
- 🌐 Wi-Fi Connectivity

---

# 🛠 Hardware Components

| Component | Quantity |
|-----------|----------|
| ESP32 Dev Board | 1 |
| 16x2 LCD with I2C | 1 |
| Push Button (Medicine Taken) | 1 |
| Push Button (SOS) | 1 |
| Active Buzzer | 1 |
| Red LED | 1 |
| Green LED | 1 |
| Breadboard | 1 |
| Jumper Wires | Several |
| USB Cable | 1 |

---

# 📚 Software Requirements

- Arduino IDE
- ESP32 Board Package
- UniversalTelegramBot Library
- WiFi Library
- Preferences Library
- LiquidCrystal_I2C Library

---

# 📂 Project Structure

```
Smart-Medicine-Reminder/
│
├── SmartMedicineReminder.ino
├── README.md
├── circuit_diagram.png
├── images/
│   ├── hardware.jpg
│   ├── lcd_display.jpg
│   └── telegram_notification.jpg
└── documentation/
    └── Project_Report.pdf
```

---

# ⚙ Working Principle

1. ESP32 connects to Wi-Fi.
2. Current time is synchronized using NTP Server.
3. Reminder times are loaded from Preferences memory.
4. The LCD continuously displays the current date and time.
5. When the reminder time matches:
   - LCD displays medicine reminder.
   - Buzzer starts beeping.
   - Red LED turns ON.
   - Telegram notification is sent.
6. Patient presses the Medicine Button after taking medicine.
7. System:
   - Stops buzzer.
   - Turns Green LED ON.
   - Saves medicine statistics.
   - Sends confirmation through Telegram.
8. If medicine is not taken within 2 minutes:
   - Dose is marked as missed.
   - Telegram alert is sent.
9. Every Sunday:
   - Weekly report is generated automatically.
10. SOS Button immediately sends an emergency alert to the caregiver.

---

# 📱 Telegram Notifications

The system automatically sends:

- 💊 Medicine Reminder
- ✅ Medicine Taken
- ❌ Dose Missed
- 🆘 Emergency SOS Alert
- 📊 Weekly Medicine Report

---

# 📊 Weekly Report Example

```
📊 WEEKLY MEDICINE REPORT

✅ Taken : 18
❌ Missed : 3
📅 Total : 21
📈 Success : 85.7%
```

---

# 🔌 Pin Configuration

| ESP32 Pin | Component |
|-----------|-----------|
| GPIO26 | Buzzer |
| GPIO25 | Red LED |
| GPIO33 | Green LED |
| GPIO27 | Medicine Button |
| GPIO32 | SOS Button |
| SDA | LCD SDA |
| SCL | LCD SCL |

---

# 🚀 Future Improvements

- Mobile Application
- Voice Reminder
- RFID Patient Identification
- Cloud Database
- Firebase Integration
- SMS Notification
- Caregiver Dashboard
- Medicine Box with Automatic Lock
- AI-based Medicine Prediction
- Google Calendar Synchronization

---

# 🎯 Applications

- Elderly Care
- Hospitals
- Home Healthcare
- Chronic Disease Management
- Assisted Living Centers
- Patient Monitoring

---

# 📖 Technologies Used

- ESP32
- Arduino IDE
- Embedded C++
- IoT
- NTP Protocol
- Telegram Bot API
- Wi-Fi Communication
- EEPROM Preferences
- I2C Communication

---

# 👨‍💻 Author

**Sangili Murugan M**

B.E. Electronics and Communication Engineering

Arjun College of Technology

Anna University

---

# 📜 License

This project is open-source and available under the MIT License.

---

## ⭐ If you like this project, don't forget to Star ⭐ the repository!final-project
