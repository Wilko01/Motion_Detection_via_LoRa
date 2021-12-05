#include <Arduino.h>

/*********
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

//String LoRaData; // used to store the received data

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

    // Set LED and beeper to LOW
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
  pinMode(beeper, OUTPUT);
  digitalWrite(beeper, LOW);
}

void loop() {
  String LoRaData; // used to store the received data
  // try to parse packet
  int packetSize = LoRa.parsePacket();
  if (packetSize) {
    // received a packet
    Serial.print("Received packet: '");
    // read packet
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
    //Serial.println("Pauze 20 sec to not get overwelmed by the triggers");
    //delay(20000); 
}