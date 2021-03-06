/* ====================================================
 *     Project : HPI 
 *      Author : Marco A. Ortiz Torres
 *        Date : DEcember 9, 2016
 * Description : 
 *   Reference : https://learn.adafruit.com/photocells/using-a-photocell
 *               https://learn.sparkfun.com/tutorials/flex-sensor-hookup-guide
 *               https://learn.adafruit.com/tmp36-temperature-sensor/using-a-temp-sensor
 *               https://www.arduino.cc/en/tutorial/potentiometer
==================================================== */
 
int lightPin = A0;  // Light Sensor
int flexPin = A1;   // Flex Sensor
int tempPin = A2;   // Tempeture Sensor
int potPin = A3;    // Potentiometer

int lightValue;
int flexValue;
int tempValue;
int potValue;
bool flag = false;

void setup() {
  Serial.begin(9600);
  pinMode (lightPin, INPUT);
  pinMode (flexPin, INPUT);
  pinMode (tempPin, INPUT);
  pinMode (potPin, INPUT);
}

void loop() {
  lightValue = analogRead(lightPin);
  flexValue = analogRead(flexPin);
  tempValue = analogRead(tempPin);
  potValue = analogRead(potPin);
  
  if (lightValue < 700){
    Serial.print("Light Value = ");
    Serial.println(2400);
    flag = false;
  }
  else if (lightValue == constrain(lightValue,800,900)){
    Serial.print("Light Value = ");
    Serial.println(1200);
    flag = false;
  }
  else if (lightValue > 900 and flag != true){
    Serial.print("Light Value = ");
    Serial.println(800);
    flag = true;
  }
  if (flexValue != constrain(flexValue, 570, 600)){
    Serial.print("Flex Value = ");
    flexValue = (flexValue-260)/3.15;
    Serial.println(flexValue);
  }
  if (tempValue > 68){
    Serial.print("Tempature = ");
    Serial.println(tempValue);
  }
  if (potValue != constrain(potValue, 149, 250)){
    Serial.print("Potentiometer = ");
    potValue = potValue/7;
    Serial.println(potValue);
  }
  
  delay(500);
}
