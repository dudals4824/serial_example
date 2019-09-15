아두이노-Bluetooth모듈 시리얼 통신
================================

## 준비물
***
1. Arduino uno
2. Bluetooth모듈 : MLT-BT05
3. 점퍼케이블
***

## 전체 소스코드

```c++
#include <SoftwareSerial.h>

const int rxPin = 2;
const int txPin = 3;
const String LED_ON_CMD = "LEDON";
const String LED_OFF_CMD = "LEDOFF";
byte byteArray[10];
String myString;
int iter = 0;
int i = 0;

SoftwareSerial mySerial(rxPin, txPin); // RX, TX

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  while (!Serial) {
    ;
  }

  Serial.println("Bluetooth Start!");
  mySerial.begin(9600);
}

void loop() {
  if (mySerial.available()) {
    byteArray[iter] = mySerial.read();
    iter++;
    myString = String((char*)byteArray);
    Serial.println(myString);
    if (myString.equalsIgnoreCase(LED_ON_CMD)){
        digitalWrite(LED_BUILTIN, HIGH);
        for(i = 0; i<10 ; i++){
            byteArray[i] = '\0';
          }
        iter = 0;
      }

    if (myString.equalsIgnoreCase(LED_OFF_CMD)){
        digitalWrite(LED_BUILTIN, LOW);
        delay(10000);
        for(i = 0; i<10 ; i++){
            byteArray[i] = '\0';
          }
        iter = 0;
    }
    //Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}

```
## 연결도
![Arduino-BLE모듈 연결](C:/Users/dut48/Documents/Arduino/arduino-ble.jpg)
