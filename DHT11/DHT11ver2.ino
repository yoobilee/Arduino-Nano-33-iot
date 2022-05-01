#include <DHT.h>

DHT mydht(A1, DHT11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  mydht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  int temp = mydht.readTemperature();
  int humi = mydht.readHumidity();

  Serial.print("Temp : ");
  Serial.println(temp);
  Serial.print("Humidity : ");
  Serial.println(humi);
  delay(1000);
}
