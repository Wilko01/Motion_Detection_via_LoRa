#include <Arduino.h>

/*********
   Info: 
  - https://github.com/sandeepmistry/arduino-LoRa
  - https://github.com/sandeepmistry/arduino-LoRa/blob/master/API.md

  Modified from the examples of the Arduino LoRa library
  More resources: https://randomnerdtutorials.com
  Transmitter
*********/

#include <SPI.h>
#include <LoRa.h>

//define the pins used by the transceiver module
#define ss 5
#define rst 14
#define dio0 25

// Set GPIOs for LED and PIR Motion Sensor
const int beeperPin = 12;
const int ledPin = 26;
const int motionSensorPin = 27;

// variable for storing the motion sensor status 
int motionSensorState = 0;

void setup() {
  //initialize Serial Monitor
  Serial.begin(115200);
  while (!Serial);
  Serial.println("LoRa Sender");
  Serial.println("Project: Motion_Detection_via_Lora Transmitter code");

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

// Set beeper to LOW
  pinMode(beeperPin, OUTPUT);
  digitalWrite(beeperPin, LOW);
  
  // Set LED to LOW
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);

  // Set motionSensorPin as input
  pinMode(motionSensorPin, INPUT);
}

void loop() {
  //read the motion state
  motionSensorState = digitalRead(motionSensorPin);
 // Serial.print("motionSensorState = ");
 // Serial.println(motionSensorState);
  // check if motion is detected
  // if it is, the motionSensorState is HIGH
  if (motionSensorState == HIGH) {
     // detectsMovement(); //send Lora message, set LED and beeper high
     Serial.println("MOTION DETECTED send!");
    //Send LoRa packet to receiver
    LoRa.beginPacket();
    LoRa.print("motion"); //send the word motion via LoRa
    LoRa.endPacket();
    digitalWrite(ledPin, HIGH); //turn the led high for visual debugging
    digitalWrite(beeperPin, HIGH); //turn the led high
    delay(2000);
    digitalWrite(ledPin, LOW);
    digitalWrite(beeperPin, LOW);
      delay(5000);
    } else { //No motion so set low
      digitalWrite(ledPin, LOW);
    }
//      delay(1000);
     }
    
 