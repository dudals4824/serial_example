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
  // Open serial communications and wait for port to open:
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("Bluetooth Start!");
  mySerial.begin(9600);
}

void loop() { // run over and over
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
