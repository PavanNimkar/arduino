#include <WiFi.h>

int trig_pin = 2;
int echo_pin = 4;
int distance;
long duration;

const char* ssid     = "Airtel_aash_2175";
const char* password = "air75716";

void setup() {
  Serial.begin(115200);
  Serial.begin(9600);
  delay(1000);
  Serial.println();
  Serial.printf("Connecting to %s\n", ssid);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  // wait for connection
  int tries = 0;
  while (WiFi.status() != WL_CONNECTED && tries < 30) {
    delay(500);
    Serial.print(".");
    tries++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println();
    Serial.println("WiFi connected!");
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
  } else {
    Serial.println();
    Serial.println("Failed to connect.");
  }
}

void loop() {
  // nothing here
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin, LOW);

  duration = pulseIn(echo_pin, HIGH);
  distance = (duration/2) * 0.0343;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print("CM\n");
  delay(1000);
}
