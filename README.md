# esp32-electrical-fault-monitor
ESP32-based electrical fault detection and IoT monitoring system using voltage, current, and temperature sensors.
# ESP32-Based Electrical Fault Detection and IoT Monitoring System

**An embedded system for monitoring electrical parameters and identifying abnormal operating conditions.**

## 1. Project Overview

This project presents an ESP32-based electrical fault detection and monitoring system designed to identify abnormal electrical behaviour using sensor measurements.

The system monitors voltage, current, and temperature, compares the measured values against configured thresholds, and generates alerts when abnormal conditions are detected.

IoT connectivity enables remote monitoring of the system's operating parameters and fault status.

The prototype demonstrates the concept using a low-voltage DC supply. It is not a certified protection device for electrical transmission or distribution lines.

## 2. Problem Statement

Electrical systems can experience abnormal operating conditions such as overcurrent, undervoltage, overvoltage, and excessive temperature.

Although conventional protection devices are designed to disconnect electrical systems during specified fault conditions, they do not necessarily provide continuous remote monitoring, detailed sensor data, or immediate information about the location and nature of an abnormal condition.

This project explores an embedded monitoring system that can identify selected abnormal conditions and communicate the detected status to the user.

## 3. Objectives

* Monitor voltage, current, and temperature.
* Identify selected abnormal electrical conditions.
* Generate fault alerts based on configured thresholds.
* Display measurements and system status.
* Enable remote monitoring through an IoT dashboard.
* Demonstrate the system using a low-voltage DC prototype.

## 4. Proposed Solution

The proposed system uses an ESP32 microcontroller to acquire sensor measurements and process them using predefined threshold conditions.

When a measured parameter exceeds its configured limit, the system identifies the corresponding abnormal condition and generates an alert.

The measured values and system status can be transmitted to an IoT dashboard for remote observation.

## 5. Hardware Components

| Component               | Purpose                               |
| ----------------------- | ------------------------------------- |
| ESP32 development board | Processing and wireless communication |
| Voltage sensor          | Voltage measurement                   |
| Current sensor          | Current measurement                   |
| Temperature sensor      | Temperature monitoring                |
| OLED display            | Local display of measurements         |
| DC power supply         | Low-voltage prototype supply          |
| Load resistor           | Demonstration load                    |
| Connecting wires        | Circuit connections                   |

Replace this list with the exact components and models used in the final prototype.

## 6. Software and Technologies

* Arduino IDE
* Embedded C/C++
* ESP32
* Blynk IoT
* Sensor libraries used in the project

## 7. System Architecture

Sensor measurements → ESP32 → Threshold analysis → Fault classification → Display and IoT dashboard

Insert the final system architecture diagram here.

## 8. Working Principle

1. The sensors measure the selected electrical parameters.
2. The ESP32 reads and processes the sensor data.
3. The measured values are compared with configured thresholds.
4. The system identifies abnormal conditions according to the implemented logic.
5. The OLED displays the measurements and system status.
6. The IoT dashboard receives the available measurements and alerts.

## 9. Fault Conditions

Document only the fault conditions implemented and tested in the prototype.

| Condition       | Detection method                     | Output                 |
| --------------- | ------------------------------------ | ---------------------- |
| Overcurrent     | Current exceeds configured limit     | Fault alert            |
| Undercurrent    | Current falls below configured limit | Abnormal current alert |
| Overvoltage     | Voltage exceeds configured limit     | Fault alert            |
| Undervoltage    | Voltage falls below configured limit | Fault alert            |
| Overtemperature | Temperature exceeds configured limit | Temperature alert      |

The thresholds and detection logic must be calibrated and validated for the actual hardware.

## 10. Circuit Diagram

Insert the final circuit diagram and explain the sensor connections, ESP32 pins, power supply, and common ground.

## 11. Prototype Implementation

Add photographs of the assembled circuit, ESP32 board, sensors, display, and load.

Explain how the components are connected and how the prototype is powered.

## 12. IoT Dashboard

Insert screenshots of the dashboard showing the available voltage, current, temperature, and fault-status indicators.

Explain how the ESP32 communicates with the dashboard.

## 13. Testing and Results

Describe the tests performed on the prototype.

For each test, include:

* Test condition
* Expected response
* Actual measured values
* Observed system response
* Pass/fail status

Include actual experimental data and photographs where available.

## 14. Limitations

* The prototype is demonstrated using low-voltage DC.
* Sensor accuracy depends on calibration and hardware specifications.
* Threshold-based detection is limited to the conditions implemented.
* IoT alerts depend on connectivity and service availability.
* The prototype is not validated for direct connection to high-voltage AC transmission lines.
* The system does not replace certified electrical protection equipment.

## 15. Future Scope

* AC voltage and current monitoring using suitable isolated sensing circuits.
* Improved fault classification and localization.
* Data logging and historical analysis.
* Backup communication during network failure.
* Integration with validated protection and emergency alert systems.

## 16. Team Members

Add the names, roles, and contributions of the project team.

## 17. References

Add the datasheets, technical documentation, research papers, and other sources used in the project.

## 18. License

Specify the license applicable to the project.

## Documentation

* [Hardware Connections](hardware/pin-connections.md)
* [Project Setup Guide](docs/setup.md)
* [Testing and Experimental Results](docs/test-results.md)
* [Detailed Technical Report](docs/technical-report.md)

## Project Repository

This repository contains the source code, hardware documentation, experimental results, and technical report for the ESP32-based Electrical Fault Detection and IoT Monitoring System.

