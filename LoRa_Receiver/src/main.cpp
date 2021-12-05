#include <Arduino.h>

/*********
  Info: 
  - https://github.com/sandeepmistry/arduino-LoRa
  - https://github.com/sandeepmistry/arduino-LoRa/blob/master/API.md

  Modified from the examples of the Arduino LoRa library
  More resources: https://randomnerdtutorials.com
  Receiver
*********/

#include <SPI.h>
#include <LoRa.h>

//define the pins used by the transceiver module
#define ss 5
#define rst 14
#define dio0 25

// Set GPIOs for LED and beeper
const int led = 26;
const int beeper = 12;

String LoRaData; // used to store the received data

void setup() {
  //initialize Serial Monitor
  Serial.begin(115200);
  while (!Serial);
  Serial.println("LoRa Receiver");
  Serial.println("Project: Motion_Detection_via_Lora Receiver code");

  //setup LoRa transceiver module
  LoRa.setPins(ss, rst, dio0);
  
  //replace the LoRa.begin(---E-) argument with your location's frequency 
  //866E6 for Europe
  while (!LoRa.begin(866E6)) {
    Serial.println(".");
    delay(500);
  }
   // Change sync word (0xF3) to match the receiver
  // The sync word assures you don't get LoRa messages from other LoRa transceivers
  // ranges from 0-0xFF
  LoRa.setSyncWord(0x99); //customized to 99
  Serial.println("LoRa Initializing OK!");
  
  // register the receive callback
  LoRa.onReceive(onReceive);

  // put the radio into receive mode
  LoRa.receive();

    // Set LED and beeper to LOW
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  pinMode(beeper, OUTPUT);
  digitalWrite(beeper, LOW);
}

void loop() {
}

void onReceive(int packetSize) {
  // received a packet
  Serial.print("Received packet '");

  // read packet
 // for (int i = 0; i < packetSize; i++) {
 //   Serial.print((char)LoRa.read());
 // }

  // print RSSI of packet
 // Serial.print("' with RSSI ");
 // Serial.println(LoRa.packetRssi());
 
    while (LoRa.available()) {
      LoRaData = LoRa.readString();
    }
      if (LoRaData == "motion"){
        digitalWrite(led, HIGH);
        digitalWrite(beeper, HIGH);
        delay(2000);
        digitalWrite(led, LOW);
        digitalWrite(beeper, LOW);
      } 
      Serial.print(LoRaData);
      Serial.print("'");
      // print RSSI of packet
      Serial.print(" with RSSI ");
      Serial.println(LoRa.packetRssi());
    }




