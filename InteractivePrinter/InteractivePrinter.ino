/* ====================================================
 *     Project : HPI 
 *      Author : Marco A. Ortiz Torres
 *        Date : November 9, 2016
 * Description : The purpose of this program is to use sensor data
 *               that (specifically a button) to create or alter the
 *               gcode for a printer to print out.
 *   Reference : https://www.arduino.cc/en/Reference/FileWrite
 ==================================================== */
#include <SD.h>

// Pin numbers that will stay constant
const int button1 = 2;    // X
const int button2 = 3;    // Y
const int button3 = 4;    // Z
const int button4 = 5;    // 
const int button5 = 6;    // 
const int button6 = 7;    // Export .gcode
const int ledPin =  13;   // Test LED Pin

String fileName = "text.txt";   // NAME OF FILE TO WRITE TO

// variables will change
int buttonState = 0;      // variable for reading the pushbutton status

void setup() 
{
  Serial.begin(9600);
  Serial.println("Initializing memory");
  SD.open(fileName);
  pinMode(ledPin, OUTPUT);    // initialize the LED pin as an output:
  pinMode(button1, INPUT);    // initialize the pushbutton pin as an input
  
  
}

void loop() 
{ 
  buttonState = digitalRead(button1);  // checking the state of the button
  buttonState = digitalRead(button2);
  buttonState = digitalRead(button3);
  buttonState = digitalRead(button4);
  buttonState = digitalRead(button5);
  buttonState = digitalRead(button6);

  if (button1 == HIGH)                      // If button 1 is pressed
  {
    digitalWrite(ledPin, HIGH);             // Turn the LED on
  }
  else if (button2 == HIGH) 
  {
    // X
  }
  else if (button3 == HIGH) 
  {
    // Y
  }
  else if (button4 == HIGH) 
  {
    // Z
  }
  else if (button5 == HIGH) 
  {
    
  }
  else if (button6 == HIGH) 
  {
    SD.close();
  }
  else 
  {
    digitalWrite(ledPin, LOW);              // turn LED off:
  }
}

