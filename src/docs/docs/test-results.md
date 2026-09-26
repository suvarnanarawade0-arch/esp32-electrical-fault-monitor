# Testing and Experimental Results

## 1. Objective

The objective of testing is to verify whether the ESP32-based electrical fault detection system can measure electrical parameters, identify configured abnormal conditions, and communicate the corresponding status.

Testing is conducted using a low-voltage DC prototype.

## 2. Testing Methodology

The prototype is tested under normal operating conditions and selected abnormal conditions.

The measured values are compared with the configured threshold limits. The resulting system status is observed through the Serial Monitor, OLED display, and IoT dashboard.

## 3. Test Cases

| Test ID | Test Condition                       | Expected Response                          | Actual Result  |
| ------- | ------------------------------------ | ------------------------------------------ | -------------- |
| T01     | Normal operating condition           | Normal status displayed                    | [Enter result] |
| T02     | Current exceeds configured limit     | Overcurrent alert                          | [Enter result] |
| T03     | Current falls below configured limit | Undercurrent alert                         | [Enter result] |
| T04     | Voltage exceeds configured limit     | Overvoltage alert                          | [Enter result] |
| T05     | Voltage falls below configured limit | Undervoltage alert                         | [Enter result] |
| T06     | Temperature exceeds configured limit | Overtemperature alert                      | [Enter result] |
| T07     | IoT connectivity available           | Dashboard receives data                    | [Enter result] |
| T08     | IoT connectivity unavailable         | Local monitoring continues, if implemented | [Enter result] |

Only mark a test as successful if the expected response was actually observed.

## 4. Sensor Measurements

| Parameter   | Measured Value | Reference Value | Error   |
| ----------- | -------------- | --------------- | ------- |
| Voltage     | [Value]        | [Value]         | [Value] |
| Current     | [Value]        | [Value]         | [Value] |
| Temperature | [Value]        | [Value]         | [Value] |

The measurement error can be calculated using:

Percentage Error = |Measured Value - Reference Value| / Reference Value × 100

The reference values should be obtained using an appropriate calibrated measuring instrument.

## 5. Threshold Configuration

The system uses predefined threshold values to identify abnormal electrical conditions.

| Parameter   | Lower Threshold | Upper Threshold |
| ----------- | --------------- | --------------- |
| Voltage     | [Value]         | [Value]         |
| Current     | [Value]         | [Value]         |
| Temperature | Not applicable  | [Value]         |

The thresholds are selected according to the prototype's operating conditions, component ratings, and intended demonstration scenarios.

These values are experimental settings for the prototype and are not universal electrical protection limits.

## 6. Observations

The following observations are recorded during testing:

* Accuracy and stability of sensor readings.
* Response of the system to abnormal conditions.
* Correctness of the fault classification.
* OLED display updates.
* IoT dashboard updates.
* Communication delays or failures.
* Any false alerts or missed detections.

## 7. Limitations

The performance of the system depends on sensor accuracy, calibration, threshold selection, and the implemented detection logic.

The prototype demonstrates selected abnormal conditions using low-voltage DC. Its results cannot automatically be generalized to AC transmission or distribution systems.

The system is not a replacement for certified electrical protection equipment.

## 8. Conclusion

The experimental results are used to evaluate the functionality of the proposed monitoring system.

The final conclusion should be based on the actual measurements and test results obtained during prototype testing.
