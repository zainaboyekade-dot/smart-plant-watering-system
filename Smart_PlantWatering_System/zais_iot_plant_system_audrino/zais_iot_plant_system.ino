// --------------------- BLYNK & WIFI SETUP -----------------------
#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "YOUR_TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN "YOUR_BLYNK_AUTH_TOKEN"

#include <WiFiNINA.h>
#include <BlynkSimpleWiFiNINA.h>

// Your Wi-Fi credentials (removed for security)
char ssid[] = "YOUR_WIFI_NAME";
char pass[] = "YOUR_PASSWORD";

// --------------------- HARDWARE PINS -----------------------------
const int moisturePin = A0;
const int relayPin = 8;
const int led1 = 3;
const int led2 = 5;
const int led3 = 7;
const int buzzerPin = 4;

// Moisture thresholds
int thresholdOn = 600;   // soil dry → start pump
int thresholdOff = 580;  // soil wet → stop pump

bool watering = false;

// --------------------- BLYNK VIRTUAL PINS ------------------------
#define VP_MOISTURE V0   // moisture % widget
#define VP_PUMP V1       // pump status gauge
#define VP_WATER_LED V2  // LED widget for watering status
#define VP_MANUAL V3     // manual button

BlynkTimer timer;

// --------------------- MAIN UPDATE FUNCTION -----------------------
void updateSystem() {
  int moisture = analogRead(moisturePin);

  // Hysteresis Logic
  if (!watering && moisture > thresholdOn) {
    watering = true;
  } 
  else if (watering && moisture < thresholdOff) {
    watering = false;
  }

  // Control pump + LEDs + buzzer
  digitalWrite(relayPin, watering ? HIGH : LOW);
  digitalWrite(led1, watering ? HIGH : LOW);
  digitalWrite(led2, watering ? HIGH : LOW);
  digitalWrite(led3, watering ? HIGH : LOW);
  digitalWrite(buzzerPin, watering ? HIGH : LOW);

  // Send data to Blynk
  Blynk.virtualWrite(VP_MOISTURE, moisture);
  Blynk.virtualWrite(VP_PUMP, watering ? 1 : 0);
  Blynk.virtualWrite(VP_WATER_LED, watering ? 255 : 0);
}

// --------------------- MANUAL BUTTON CONTROL -----------------------
BLYNK_WRITE(VP_MANUAL) {
  int state = param.asInt();
  watering = state;

  digitalWrite(relayPin, state ? HIGH : LOW);
  digitalWrite(led1, state ? HIGH : LOW);
  digitalWrite(led2, state ? HIGH : LOW);
  digitalWrite(led3, state ? HIGH : LOW);
  digitalWrite(buzzerPin, state ? HIGH : LOW);

  // Update widgets to stay in sync
  Blynk.virtualWrite(VP_PUMP, state);
  Blynk.virtualWrite(VP_WATER_LED, state ? 255 : 0);
}

// --------------------- SETUP --------------------------------------
void setup() {
  Serial.begin(9600);

  pinMode(relayPin, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // CONNECT UNO WiFi Rev2 TO BLYNK
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Update every 1 second
  timer.setInterval(1000L, updateSystem);
}

// --------------------- LOOP ---------------------------------------
void loop() {
  Blynk.run();
  timer.run();
}
