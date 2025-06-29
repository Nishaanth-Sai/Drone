# Drone

This project is a simple quadcopter control system built with an **Arduino UNO**, controlled via the **HC-05 Bluetooth module** using the **Arduino Car mobile app**. The drone receives directional and throttle commands wirelessly and adjusts the speed of four brushless motors via ESCs.

---

## 🧠 Project Overview

This program reads input commands from a Bluetooth-connected mobile app and adjusts the throttle and direction of the drone accordingly. Each command corresponds to a directional movement (forward, backward, left, right) or throttle adjustment (increase/decrease speed). The ESCs are armed on startup, and the system supports real-time command handling.

---

## 🔧 Features

- 📡 **Bluetooth Control** via HC-05 module
- 🎮 **Mobile App Integration** with Arduino Car app
- 🚀 **Throttle and Direction Control** through ESC and brushless motors
- 🧠 **ESC Arming and Safety Checks** before flight
- 🧩 **Modular Commands** to move in all basic directions or hover
- 🖨️ **Serial Debugging Output** to monitor status and received commands

---

## 🛠️ Hardware Components

| Component           | Description                          |
|---------------------|--------------------------------------|
| Arduino UNO         | Microcontroller for controlling logic |
| HC-05 Bluetooth     | Wireless module to receive commands   |
| 4x ESC (Electronic Speed Controller) | Controls each brushless motor's speed |
| 4x Brushless Motor  | Provides thrust to lift the drone     |
| LiPo Battery        | Powers motors and controller          |
| 3D-Printed Chassis  | Lightweight custom frame for the drone |
| Arduino Car App     | Android app to send commands over Bluetooth |

---

## 🔋 Command Mapping

| Command Sent | Action           |
|--------------|------------------|
| `X` / `x`    | Increase throttle (ascend) |
| `Y` / `y`    | Decrease throttle (descend) |
| `F` / `f`    | Move forward      |
| `B` / `b`    | Move backward     |
| `L` / `l`    | Move left         |
| `R` / `r`    | Move right        |

When no command is received, the drone maintains current throttle (hover).

---

## 📂 Code Highlights

- Uses `SoftwareSerial` to communicate with HC-05 on pins 2 and 3.
- ESCs connected to pins 5, 6, 7, and 8.
- Throttle value (`x`) is bounded between `MIN_THROTTLE` and `MAX_THROTTLE`.
- Arming sequence sets ESCs to full throttle, then to minimum to prepare for operation.

---

## 🛠️ Setup Instructions

1. **Wiring:**
   - Connect HC-05:  
     - TX → Pin 2 (Arduino RX)  
     - RX → Pin 3 (Arduino TX) via voltage divider  
   - ESC signal wires → Pins 5, 6, 7, 8  
   - Power the motors and ESCs with a **LiPo battery**.
   - Connect ESC ground to Arduino ground.

2. **Upload the Code:**
   - Use the Arduino IDE to upload the sketch to your Arduino UNO.

3. **Pair with Bluetooth:**
   - Pair your phone with the HC-05 (default password is usually `1234` or `0000`).

4. **Use the Arduino Car App:**
   - Send directional commands via buttons mapped to the control scheme above.

---

## 🧠 Safety Notes

- Always test with **props removed** until you're confident in control.
- Arm ESCs only in a safe, clear environment.
- Do not exceed recommended LiPo voltage limits.

---

## 🤝 Acknowledgements

- Arduino Community  
- Developers of the Arduino Car mobile app  
- Makers & DIY Drone Enthusiasts

