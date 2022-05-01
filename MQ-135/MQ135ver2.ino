int smokeA0 = A5;

void setup() {
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0);

  Serial.print("GAS Pin A5: ");
  Serial.println(analogSensor);
  delay(1000);
}   
