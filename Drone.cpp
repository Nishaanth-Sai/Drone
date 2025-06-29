#include <Servo.h>
#include <SoftwareSerial.h>
#include "Wire.h"

// Define the pins for the HC05 Bluetooth module
#define RX_PIN 2
#define TX_PIN 3

// Create a SoftwareSerial object to communicate with the HC05
SoftwareSerial btSerial(RX_PIN, TX_PIN);

// Create Servo objects for the ESCs
Servo esc1;
Servo esc2;
Servo esc3;
Servo esc4;

// Define the pins for the ESCs
#define ESC_PIN1 5
#define ESC_PIN2 6
#define ESC_PIN3 7
#define ESC_PIN4 8

// Define the PWM values for arming and throttle control
const int ARM_VALUE = 1000; // Typically 1000us is used for arming
const int MIN_THROTTLE = 1000; // Minimum throttle value
const int MAX_THROTTLE = 2000; // Maximum throttle value

int x = ARM_VALUE; // Initial throttle value

void armESCs() {
  // Send the arming signal to the ESCs
  esc1.writeMicroseconds(MAX_THROTTLE);
  esc2.writeMicroseconds(MAX_THROTTLE);
  esc3.writeMicroseconds(MAX_THROTTLE);
  esc4.writeMicroseconds(MAX_THROTTLE);
  delay(2000); // Wait for 2 seconds
  esc1.writeMicroseconds(ARM_VALUE);
  esc2.writeMicroseconds(ARM_VALUE);
  esc3.writeMicroseconds(ARM_VALUE);
  esc4.writeMicroseconds(ARM_VALUE);
  Serial.println("ESCs armed");
  delay(2000); // Wait for 2 more seconds to ensure arming
}

void speed_checker() {
  // Ensure the throttle value remains within the valid range
  if (x < MIN_THROTTLE) x = MIN_THROTTLE;
  if (x > MAX_THROTTLE) x = MAX_THROTTLE;
}

void setup() {
  // Initialize the serial communication with the HC05
  btSerial.begin(9600);
  Serial.begin(9600);
  
  // Attach the ESCs to the corresponding pins
  esc1.attach(ESC_PIN1);
  esc2.attach(ESC_PIN2);
  esc3.attach(ESC_PIN3);
  esc4.attach(ESC_PIN4);
  
  // Arm the ESCs
  armESCs();
}

void loop() {
  // Check if there is any incoming data from the HC05
  if (btSerial.available() > 0) {
    // Read the incoming data
    char incomingChar = btSerial.read();
    Serial.print("Received: ");
    switch (incomingChar) {
      // Going Up
      case 'X':
      case 'x':
        x += 30;
        speed_checker();
        esc1.writeMicroseconds(x);  
        esc2.writeMicroseconds(x);  
        esc3.writeMicroseconds(x);  
        esc4.writeMicroseconds(x);
        Serial.println("X"); 
        break;
      // Going Down
      case 'Y':
      case 'y':
        x -= 30;
        speed_checker();
        esc1.writeMicroseconds(x);  
        esc2.writeMicroseconds(x);  
        esc3.writeMicroseconds(x);  
        esc4.writeMicroseconds(x);
        Serial.println("Y"); 
        break;
      // Going Forward
      case 'F':
      case 'f':
        esc1.writeMicroseconds(x - 100);  
        esc2.writeMicroseconds(x - 100);  
        esc3.writeMicroseconds(x + 50);  
        esc4.writeMicroseconds(x + 50);
        Serial.println("F");
        break;
      // Going Backward
      case 'B':
      case 'b':
        esc1.writeMicroseconds(x + 50);  
        esc2.writeMicroseconds(x + 50);  
        esc3.writeMicroseconds(x - 100);  
        esc4.writeMicroseconds(x - 100);
        Serial.println("B");
        break;
      // Going Left
      case 'L':
      case 'l':
        esc1.writeMicroseconds(x - 100);  
        esc2.writeMicroseconds(x + 50);  
        esc3.writeMicroseconds(x - 100);  
        esc4.writeMicroseconds(x + 50);
        Serial.println("L");
        break;
      // Going Right
      case 'R':
      case 'r':
        esc1.writeMicroseconds(x + 50);  
        esc2.writeMicroseconds(x - 100);  
        esc3.writeMicroseconds(x + 50);  
        esc4.writeMicroseconds(x - 100);
        Serial.println("R");
        break;
    }
  } 
  //when no input is given
  else {
    esc1.writeMicroseconds(x);  
    esc2.writeMicroseconds(x);  
    esc3.writeMicroseconds(x);  
    esc4.writeMicroseconds(x);
    Serial.println("Still");
  }
}