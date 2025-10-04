int trig_pin = 9;
int echo_pin = 10;

int distance;
long duration;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
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
  
}
