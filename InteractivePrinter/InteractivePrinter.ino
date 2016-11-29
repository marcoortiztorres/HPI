/* ====================================================
 *     Project : HPI 
 *      Author : Marco A. Ortiz Torres
 *        Date : November 9, 2016
 * Description : The purpose of this program is to use sensor data
 *               that (specifically a button) to create or alter the
 *               gcode for a printer to print out. The arduino code
 *               prints the sensor data onto the terminal and the
 *               ProcessingCode reads what is being written on the
 *               terminal.
 *   Reference : https://www.arduino.cc/en/Reference/FileWrite
 *               http://electronics.stackexchange.com/questions/54/saving-arduino-sensor-data-to-a-text-file
 *               https://learn.sparkfun.com/tutorials/connecting-arduino-to-processing
 ==================================================== */
#include <SD.h>

int ButtonPin = A2;
int LightPin = A3;
int tempPin = A4;

int buttonValue;
int lightValue;

void setup() 
{
  pinMode(ButtonPin, INPUT);
  pinMode(LightPin, INPUT);
  pinMode(tempPin, INPUT);
  
  pinMode(A5, OUTPUT);
  digitalWrite(A5, HIGH);
  Serial.begin(9600);
}

void loop() 
{ 
  buttonValue = analogRead(ButtonPin)+ 1;
  //Serial.println(buttonValue);    // Sends the button value
  lightValue = analogRead(LightPin);// + 1000; // increased it by 1000 to destinguish that it is the data being read by light sensor
  tempValue = analogRead(tempPin);

   
  Serial.println(lightValue);     // Sends the sensor data of the light sensor
  delay(200);
}
