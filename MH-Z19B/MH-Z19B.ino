#include <SoftwareSerial.h>
#include <MHZ19.h>

SoftwareSerial ss(4,5) // 핀 연결번호에 따라 숫자 달라짐
MHZ19 mzh(&ss)


void setup() {

  Serial.begin(9600);
  Serial.println(F("Starting...")); // F 함수는 Flash에 저장하도록

  ss.begin(9600);
  
}


void loop() {

  MHZ19_RESULT response = mhz.retrieveData();
  if (response == MHZ19_RESULT_OK) {
    Serial.print(F("CO2 : "));
    Serial.print(mhz.getCO2());
    Serial.print("ppm");
  
    Serial.print(F("\tMin CO2 : "));
    Serial.print(mhz.getMinCO2()); // 최소 CO2값
    Serial.print("ppm");

    Serial.print(F("\tTemperature : "));
    Serial.print(mhz.getTemperature());
    Serial.print("℃");

    Serial.print(F("\tAccuracy : "));
    Serial.println(mhz.getAccuracy());

    if (mhz.getCO2() > 2000) { // CO2 농도가 2000 초과일 경우
        Serial.println("You need to get a fresh air!");
      }
      }
    else
    {
        Serial.print(F("Error, code : "));
        Serial.println(response);
    }

    delay (3000); // 3초 대기

}
