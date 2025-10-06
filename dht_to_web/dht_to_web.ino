#define BLYNK_TEMPLATE_NAME "ESP32 DHT"
#define BLYNK_TEMPLATE_ID "TMPL38-ugkxSq"
#define BLYNK_AUTH_TOKEN "3ZDTAYBVfrnF0uLhSERIub7K8-LRcmuW"

#include <WiFi.h>           // Use <ESP8266WiFi.h> if using ESP8266
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>   // Change to <BlynkSimpleEsp8266.h> for ESP8266
#include "DHT.h"

// ----- WiFi Credentials -----
char ssid[] = "Airtel_aash_2175";
char pass[] = "air75716";

// ----- DHT Sensor -----
#define DHTPIN 27        // GPIO pin (D2 on NodeMCU = GPIO4)
#define DHTTYPE DHT11    // or DHT22

DHT dht(DHTPIN, DHTTYPE);

BlynkTimer timer;

// Function to read DHT and send to Blynk
void sendSensor()
{
  float h = dht.readHumidity();
  float t = dht.readTemperature(); // Celsius

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Push to Blynk virtual pins (adjust Vx to match your app setup)
  Blynk.virtualWrite(V0, t);   // Temperature
  Blynk.virtualWrite(V1, h);   // Humidity

  Serial.print("Temp: ");
  Serial.print(t);
  Serial.print(" °C, Hum: ");
  Serial.print(h);
  Serial.println(" %");
}

void setup()
{
  Serial.begin(115200);

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  dht.begin();

  // Run every 2 seconds
  timer.setInterval(2000L, sendSensor);
}

void loop()
{
  Blynk.run();
  timer.run();
}
