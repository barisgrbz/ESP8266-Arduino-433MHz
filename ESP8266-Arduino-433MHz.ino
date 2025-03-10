#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();
bool receiverMode = true; 
bool sendRequested = false; 

// Kart modeline göre pin atamaları
#ifdef ESP8266
  #define RF_RECEIVER_PIN 5  // ESP8266 için uygun pin (D1 - GPIO5)
  #define RF_TRANSMITTER_PIN 4  // ESP8266 için uygun pin (D2 - GPIO4)
#else
  #define RF_RECEIVER_PIN 2  // Arduino için 2. pin (Interrupt 0)
  #define RF_TRANSMITTER_PIN 10  // Arduino için 10. pin
#endif

void setup() {
  Serial.begin(9600);
  
  mySwitch.enableReceive(RF_RECEIVER_PIN);
  mySwitch.enableTransmit(RF_TRANSMITTER_PIN);

  Serial.println("Sistem Başlatıldı...");
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == 'r') {
      receiverMode = true;
      Serial.println("Alıcı mod aktif");
    } else if (command == 't') {
      receiverMode = false;
      sendRequested = true;
      Serial.println("Verici mod aktif");
    }
  }

  if (receiverMode) {
    receiveModeFunction();
  } else {
    if (sendRequested) {
      transmitModeFunction();
      sendRequested = false;
    }
  }
}

void receiveModeFunction() {
  if (mySwitch.available()) {
    Serial.print("Gelen RF Kodu: ");
    Serial.println(mySwitch.getReceivedValue());
    mySwitch.resetAvailable();
  }
}

void transmitModeFunction() {
  /* RC Switch Kütüphanesinin Örnek Gönderimleri */
   /* See Example: TypeA_WithDIPSwitches */
  mySwitch.switchOn("11111", "00010");
  delay(1000);
  mySwitch.switchOff("11111", "00010");
  delay(1000);

  /* Same switch as above, but using decimal code */
  mySwitch.send(5393, 24);
  delay(1000);  
  mySwitch.send(5396, 24);
  delay(1000);  

  /* Same switch as above, but using binary code */
  mySwitch.send("000000000001010100010001");
  delay(1000);  
  mySwitch.send("000000000001010100010100");
  delay(1000);

  /* Same switch as above, but tri-state code */ 
  mySwitch.sendTriState("00000FFF0F0F");
  delay(1000);  
  mySwitch.sendTriState("00000FFF0FF0");
  delay(1000);

  delay(20000);
  Serial.println("RF Kodu Gönderildi");
}
