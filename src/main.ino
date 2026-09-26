#define BLYNK_TEMPLATE_ID "TMPL31aW9lxQ4"
#define BLYNK_TEMPLATE_NAME "Electrical Fault Monitoring"
#define BLYNK_AUTH_TOKEN "your_auth_code"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

char ssid[] = "YOUR_WIFI_SSID_HERE";
char pass[] = "YOUR_WIFI_PASSWORD_HERE";

#define PIN_ACS712_A 34
#define PIN_VSENS_A 33
#define PIN_DS18B20_A 4

#define PIN_ACS712_B 35
#define PIN_VSENS_B 32
#define PIN_DS18B20_B 27

#define PIN_DS18B20_C 18

#define PIN_OLED_SDA 21
#define PIN_OLED_SCL 22
#define PIN_FAULT_LED 23

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define OLED_ADDR 0x3C

Adafruit_SSD1306 display(
  SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET
);

const float ADC_VREF = 3.3;
const float ADC_MAX = 4095.0;

const float VOLTAGE_RATIO_A = 5.0;
const float VOLTAGE_RATIO_B = 5.0;

const float ACS712_SENSITIVITY_A = 0.100;
const float ACS712_SENSITIVITY_B = 0.100;

const float ACS712_ZERO_OFFSET_A = 1.65;
const float ACS712_ZERO_OFFSET_B = 1.65;

bool CALIBRATION_DONE = false;

const float FAULT_CURRENT_THRESHOLD_A = 0.05;
const float FAULT_CURRENT_THRESHOLD_B = 0.05;

OneWire oneWireA(PIN_DS18B20_A);
OneWire oneWireB(PIN_DS18B20_B);
OneWire oneWireC(PIN_DS18B20_C);

DallasTemperature sensorA(&oneWireA);
DallasTemperature sensorB(&oneWireB);
DallasTemperature sensorC(&oneWireC);

BlynkTimer timer;

float zoneA_voltage = 0, zoneA_current = 0, zoneA_temp = 0;
float zoneB_voltage = 0, zoneB_current = 0, zoneB_temp = 0;
float zoneC_voltage_avg = 0, zoneC_current_avg = 0, zoneC_temp = 0;

int faultStatus = -1;
int faultZone = 0;

int readAveragedADC(int pin, int samples = 10) {
  long sum = 0;

  for (int i = 0; i < samples; i++) {
    sum += analogRead(pin);
    delay(2);
  }

  return sum / samples;
}

void readZoneA() {
  int rawV = readAveragedADC(PIN_VSENS_A);
  float pinVoltageV = (rawV / ADC_MAX) * ADC_VREF;
  zoneA_voltage = pinVoltageV * VOLTAGE_RATIO_A;

  int rawI = readAveragedADC(PIN_ACS712_A);
  float pinVoltageI = (rawI / ADC_MAX) * ADC_VREF;

  zoneA_current =
    (pinVoltageI - ACS712_ZERO_OFFSET_A) /
    ACS712_SENSITIVITY_A;
}

void readZoneB() {
  int rawV = readAveragedADC(PIN_VSENS_B);
  float pinVoltageV = (rawV / ADC_MAX) * ADC_VREF;
  zoneB_voltage = pinVoltageV * VOLTAGE_RATIO_B;

  int rawI = readAveragedADC(PIN_ACS712_B);
  float pinVoltageI = (rawI / ADC_MAX) * ADC_VREF;

  zoneB_current =
    (pinVoltageI - ACS712_ZERO_OFFSET_B) /
    ACS712_SENSITIVITY_B;
}

void readTemperatures() {
  sensorA.requestTemperatures();
  sensorB.requestTemperatures();
  sensorC.requestTemperatures();

  float tA = sensorA.getTempCByIndex(0);
  float tB = sensorB.getTempCByIndex(0);
  float tC = sensorC.getTempCByIndex(0);

  zoneA_temp = (tA == DEVICE_DISCONNECTED_C) ? NAN : tA;
  zoneB_temp = (tB == DEVICE_DISCONNECTED_C) ? NAN : tB;
  zoneC_temp = (tC == DEVICE_DISCONNECTED_C) ? NAN : tC;
}

void computeZoneC() {
  zoneC_voltage_avg = (zoneA_voltage + zoneB_voltage) / 2.0;
  zoneC_current_avg = (zoneA_current + zoneB_current) / 2.0;
}
void evaluateFault() {
  if (!CALIBRATION_DONE) {
    faultStatus = -1;
    faultZone = 0;
    return;
  }

  bool faultA =
    (zoneA_current < FAULT_CURRENT_THRESHOLD_A);

  bool faultB =
    (zoneB_current < FAULT_CURRENT_THRESHOLD_B);

  if (faultA) {
    faultStatus = 1;
    faultZone = 1;
  } else if (faultB) {
    faultStatus = 1;
    faultZone = 2;
  } else {
    faultStatus = 0;
    faultZone = 0;
  }
}

void updateFaultLED() {
  digitalWrite(
    PIN_FAULT_LED,
    (faultStatus == 1) ? HIGH : LOW
  );
}

void sendToBlynk() {
  Blynk.virtualWrite(V0, zoneA_voltage);
  Blynk.virtualWrite(V1, zoneA_current);
  Blynk.virtualWrite(V2, zoneA_temp);

  Blynk.virtualWrite(V3, zoneB_voltage);
  Blynk.virtualWrite(V4, zoneB_current);
  Blynk.virtualWrite(V5, zoneB_temp);

  Blynk.virtualWrite(V6, zoneC_voltage_avg);
  Blynk.virtualWrite(V7, zoneC_current_avg);
  Blynk.virtualWrite(V8, zoneC_temp);

  Blynk.virtualWrite(V9, faultStatus);
  Blynk.virtualWrite(V10, faultZone);
}

void updateOLED() {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0, 0);
  display.print("A: ");
  display.print(zoneA_voltage, 1);
  display.print("V ");
  display.print(zoneA_current, 2);
  display.print("A");

  display.setCursor(0, 12);
  display.print("B: ");
  display.print(zoneB_voltage, 1);
  display.print("V ");
  display.print(zoneB_current, 2);
  display.print("A");

  display.setCursor(0, 24);
  display.print("C(avg): ");
  display.print(zoneC_voltage_avg, 1);
  display.print("V ");
  display.print(zoneC_current_avg, 2);
  display.print("A");

  display.setCursor(0, 40);
  display.setTextSize(2);

  if (faultStatus == -1) {
    display.print("NOT CAL");
  } else if (faultStatus == 0) {
    display.print("SAFE");
  } else {
    display.print("UNSAFE");
  }

  display.display();
}

void printDiagnostics() {
  Serial.println(F("---- Sensor Snapshot ----"));

  Serial.print(F("Zone A V="));
  Serial.print(zoneA_voltage, 2);
  Serial.print(F(" V I="));
  Serial.print(zoneA_current, 3);
  Serial.print(F(" A T="));
  Serial.print(zoneA_temp, 1);
  Serial.println(F(" C"));

  Serial.print(F("Zone B V="));
  Serial.print(zoneB_voltage, 2);
  Serial.print(F(" V I="));
  Serial.print(zoneB_current, 3);
  Serial.print(F(" A T="));
  Serial.print(zoneB_temp, 1);
  Serial.println(F(" C"));

  Serial.print(F("Zone C V(avg)="));
  Serial.print(zoneC_voltage_avg, 2);
  Serial.print(F(" V I(avg)="));
  Serial.print(zoneC_current_avg, 3);
  Serial.print(F(" A T="));
  Serial.print(zoneC_temp, 1);
  Serial.println(F(" C"));

  Serial.print(F("Fault status: "));

  if (faultStatus == -1) {
    Serial.println(F("NOT CALIBRATED"));
  } else if (faultStatus == 0) {
    Serial.println(F("SAFE"));
  } else {
    Serial.println(F("UNSAFE"));
  }

  Serial.print(F("Fault zone: "));
  Serial.println(faultZone);
  Serial.println();
}
void updateCycle() {
  readZoneA();
  readZoneB();
  readTemperatures();
  computeZoneC();
  evaluateFault();
  updateFaultLED();
  sendToBlynk();
  updateOLED();
  printDiagnostics();
}

void setup() {
  Serial.begin(115200);
  delay(500);

  Serial.println(F("Starting Electrical Fault Monitor..."));

  analogReadResolution(12);

  pinMode(PIN_FAULT_LED, OUTPUT);
  digitalWrite(PIN_FAULT_LED, LOW);

  sensorA.begin();
  sensorB.begin();
  sensorC.begin();

  Wire.begin(PIN_OLED_SDA, PIN_OLED_SCL);

  if (!display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR)) {
    Serial.println(F("OLED init failed."));
  } else {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(0, 0);
    display.println("Starting...");
    display.display();
  }

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  timer.setInterval(2000L, updateCycle);
}

void loop() {
  Blynk.run();
  timer.run();
}
