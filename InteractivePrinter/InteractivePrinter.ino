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

int ButtonPin1 = A2;
int ButtonPin2 = A4;
int ButtonPin3 = A5;
int LightPin = A3;

int buttonValue1;
int buttonValue2;
int buttonValue3;
int lightValue;

void setup() 
{
  pinMode(ButtonPin1, INPUT);
  pinMode(ButtonPin2, INPUT);
  pinMode(ButtonPin3, INPUT);
  pinMode(LightPin, INPUT);
  
  Serial.begin(9600);
}

void loop() 
{ 
  buttonValue1 = digitalRead(ButtonPin1);
  buttonValue2 = digitalRead(ButtonPin2);
  buttonValue3 = digitalRead(ButtonPin3);
  lightValue = analogRead(LightPin);
  int lightConversion = lightValue/3;

  
  if (lightValue > 250){
    if(buttonValue1 == HIGH){
      Serial.println(lightConversion);
    }
    else if(buttonValue2 == HIGH){
      Serial.println(lightConversion);
    }
  }
  else if(buttonValue3 == HIGH){
    Serial.println(21212);
  }

  delay(100);
}
