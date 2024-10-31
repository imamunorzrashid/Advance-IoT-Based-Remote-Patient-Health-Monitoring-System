#define BLYNK_TEMPLATE_ID "TMPL6U7NezFef"
#define BLYNK_TEMPLATE_NAME "haturi doctor"
#define BLYNK_AUTH_TOKEN "H_ooj204p2096ly1S7UlUelpSrWuuCWr"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <DHT.h>
#include <Wire.h>
#include "MAX30100_PulseOximeter.h"

// Replace with your Blynk Auth Token
// Replace with your WiFi credentials
const char* ssid = "GalaxyY";  // Enter SSID here
const char* password = "12345678x";  // Enter Password here

#define DHTPIN 4          // Digital pin connected to the DHT sensor
#define DHTTYPE DHT11     // DHT 11
#define REPORTING_PERIOD_MS 1000

PulseOximeter pox;
DHT dht(DHTPIN, DHTTYPE);
BlynkTimer timer;


float BPM, SpO2;
uint32_t tsLastReport = 0;

// Function to send DHT sensor data
void sendSensorData() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  
  Serial.print("Room Temperature: ");
  Serial.print(t);  // Print room temperature in Celsius
  Serial.println("°C");

      
  Serial.print("Room Humidity: ");
  Serial.print(h);
  Serial.println("%");


  Blynk.virtualWrite(V0, t);
  Blynk.virtualWrite(V1, h);

}

void onBeatDetected()
{
    Serial.println("Beat Detected!");
}

// Function to handle SpO2 sensor data
void sendSpO2Data() {
  pox.update();

  BPM = pox.getHeartRate();
  SpO2 = pox.getSpO2();

  if (millis() - tsLastReport > REPORTING_PERIOD_MS) {
    Serial.print("Heart rate: ");
    Serial.println(BPM);
    Serial.print("SpO2: ");
    Serial.print(SpO2);
    Serial.println(" %");

    Blynk.virtualWrite(V2, BPM);
    Blynk.virtualWrite(V3, SpO2);

    tsLastReport = millis();
  }
}

void setup() {
  Serial.begin(115200);
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);
  dht.begin();
  timer.setInterval(2000L, sendSensorData);

  // MAX30100 Sensor Setup
  pinMode(19, OUTPUT);
  Serial.print("Initializing Pulse Oximeter..");

  if (!pox.begin()) {
    Serial.println("FAILED");
    for (;;)
      ;
  } else {
    Serial.println("SUCCESS");
    pox.setOnBeatDetectedCallback(onBeatDetected);
  }

  // The default current for the IR LED is 50mA and it could be changed by uncommenting the following line.
  pox.setIRLedCurrent(MAX30100_LED_CURR_7_6MA);
}

void loop() {
  Blynk.run();
  sendSpO2Data();
  timer.run();
   // Call the function to send SpO2 data
}
