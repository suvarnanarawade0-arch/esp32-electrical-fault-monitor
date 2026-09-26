# ESP32-Based Electrical Fault Detection and IoT Monitoring System

## Abstract

Electrical systems require continuous monitoring to identify abnormal operating conditions and support timely maintenance.

This project presents an ESP32-based electrical fault detection and IoT monitoring system that measures voltage, current, and temperature using suitable sensors.

The measured parameters are processed by the ESP32 and compared against predefined thresholds to identify selected abnormal conditions. The system displays measurements locally and transmits available data to an IoT dashboard for remote monitoring.

A low-voltage DC prototype is developed to demonstrate the working principle of the proposed system.

The project focuses on embedded monitoring, threshold-based fault identification, and IoT-enabled observation of electrical parameters.

## 1. Introduction

Electrical systems are essential to residential, commercial, and industrial infrastructure. Abnormal operating conditions can affect equipment performance, reliability, and safety.

Conventional electrical protection systems are designed to respond to specified fault conditions. However, additional monitoring can provide useful information about operating parameters and the nature of detected abnormalities.

Embedded systems and IoT technologies enable electrical parameters to be measured, processed, and communicated using compact and relatively low-cost hardware.

This project explores the use of an ESP32 microcontroller to monitor selected electrical parameters and identify abnormal conditions using sensor measurements.

## 2. Problem Statement

Electrical systems may experience abnormal voltage, current, or temperature conditions.

Although conventional protection devices provide protection against specified electrical faults, users may not always have access to continuous remote measurements or detailed information about the observed abnormal condition.

The project investigates an embedded monitoring system that can measure selected electrical parameters, identify configured abnormal conditions, and communicate the corresponding status.

## 3. Objectives

1. Develop an ESP32-based electrical monitoring system.
2. Measure voltage, current, and temperature.
3. Identify selected abnormal conditions using threshold-based logic.
4. Display sensor readings and fault status.
5. Enable remote monitoring through an IoT dashboard.
6. Evaluate the system through low-voltage DC experiments.

## 4. Existing System and Proposed Approach

### 4.1 Existing Systems

Electrical installations commonly use protective devices such as fuses, circuit breakers, and protective relays.

These devices operate according to their design specifications and provide protection against particular fault conditions.

Monitoring and communication capabilities vary depending on the equipment and installation.

### 4.2 Proposed Approach

The proposed system adds sensor-based monitoring and IoT communication to a low-voltage experimental setup.

The ESP32 processes the sensor measurements and identifies abnormal conditions according to configured thresholds.

The system provides local and remote visibility of the measured parameters and detected status.

The proposed prototype is intended to demonstrate monitoring and fault identification rather than replace conventional protection equipment.

## 5. System Architecture

The system consists of the following functional blocks:

1. Electrical supply and load.
2. Voltage, current, and temperature sensors.
3. ESP32 microcontroller.
4. Threshold-based fault detection logic.
5. OLED display.
6. IoT communication and dashboard.

### System Flow

Electrical Supply and Load → Sensors → ESP32 → Threshold Analysis → Fault Status → OLED Display and IoT Dashboard

## 6. Hardware Design

### 6.1 ESP32 Microcontroller

The ESP32 acts as the central processing unit.

It reads sensor measurements, performs the programmed analysis, updates the display, and communicates with the IoT platform.

### 6.2 Voltage Sensor

The voltage sensor provides a signal corresponding to the electrical voltage being monitored.

The sensor output must be compatible with the ESP32 input specifications.

### 6.3 Current Sensor

The current sensor measures the current flowing through the monitored circuit.

Its output is processed by the ESP32 to determine the measured current and identify configured abnormal conditions.

### 6.4 Temperature Sensor

The temperature sensor monitors the temperature of the selected measurement point.

The measured temperature is compared against the configured temperature threshold.

### 6.5 OLED Display

The OLED display provides local information about the sensor readings and system status.

### 6.6 Power Supply

The prototype uses a low-voltage DC supply for experimental testing.

## 7. Software Design

The embedded software is developed using the Arduino IDE.

The program performs the following operations:

1. Initializes the sensors and display.
2. Establishes the required IoT connection.
3. Reads the sensor measurements.
4. Processes the measured values.
5. Compares measurements against configured thresholds.
6. Identifies selected abnormal conditions.
7. Updates the local display.
8. Transmits available measurements and status information.

## 8. Fault Detection Methodology

The system uses threshold-based analysis.

For each monitored parameter, the measured value is compared with a predefined operating range.

If the measurement exceeds the configured limits, the system identifies the corresponding abnormal condition.

The detection method depends on the accuracy of the sensor measurements and the correct selection of thresholds.

The system identifies only the abnormal conditions explicitly implemented in the software.

## 9. IoT Implementation

The ESP32 uses wireless communication to transmit available measurements and system status to the IoT dashboard.

The dashboard can display the configured voltage, current, temperature, and fault indicators.

Remote monitoring depends on the availability of the network and IoT service.

## 10. Experimental Setup

The prototype is assembled using the ESP32, selected sensors, OLED display, DC power supply, and electrical load.

The circuit is operated under controlled low-voltage conditions.

The sensor readings and system response are observed during normal and selected abnormal operating conditions.

## 11. Results and Discussion

The results are documented using measured sensor values, test observations, and dashboard screenshots.

The discussion evaluates:

* Sensor measurement behaviour.
* Detection of configured abnormal conditions.
* Display functionality.
* IoT communication.
* System limitations.

Only experimentally verified results are included in the final report.

## 12. Limitations

The prototype has the following limitations:

1. It is demonstrated using low-voltage DC.
2. Measurement accuracy depends on sensor calibration.
3. Threshold-based detection is limited to implemented conditions.
4. Remote monitoring depends on network availability.
5. The system has not been validated as a high-voltage protection device.
6. The prototype does not replace certified electrical protection equipment.

## 13. Future Scope

Future development may include:

* AC electrical parameter monitoring using suitable isolated sensors.
* Improved fault classification.
* Fault localization.
* Historical data logging.
* Additional communication methods.
* Integration with validated protection systems.
* Expanded experimental testing.

## 14. Conclusion

The project demonstrates the application of embedded systems and IoT communication to electrical parameter monitoring.

The ESP32 processes sensor measurements, identifies selected abnormal conditions using threshold-based logic, and communicates the available system status.

The low-voltage DC prototype provides an experimental platform for studying sensor integration, embedded programming, and remote monitoring.

Further calibration, testing, and validation would be required before considering deployment in practical electrical installations.

## 15. References

Add the datasheets and technical documentation for the actual components used.

Include relevant research papers, official ESP32 documentation, Arduino documentation, and IoT platform documentation.

All references should be cited consistently in the report.
