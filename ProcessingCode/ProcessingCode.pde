/* ====================================================
 *     Project : HPI 
 *      Author : Marco A. Ortiz Torres
 *        Date : November 17, 2016
 * Description : The purpose of this program is take the data from 9600
 *               and read the sesor data. The sensor data will then write
 *               a specific gcode to a .txt file.
 *   Reference : https://www.arduino.cc/en/Reference/FileWrite
 *               http://electronics.stackexchange.com/questions/54/saving-arduino-sensor-data-to-a-text-file
 *               https://learn.sparkfun.com/tutorials/connecting-arduino-to-processing
 ==================================================== */
import processing.serial.*;
Serial mySerial;
PrintWriter output;

int circleRad = 0;

void setup() {

	size(640, 360); //prepare screen
   mySerial = new Serial( this, Serial.list()[0], 9600 );
   output = createWriter( "test.gcode" );
   startCode();
}

void draw() {
  background(51);
  if (mySerial.available() > 0 ) {
    int value = mySerial.read();
    if ( value >= 0) {
      xAxis(value);
      circleRad = value; //Integer.parseInt(value)/3; //update data input and calibrate
      // noStrock();
      fill(0);
      ellipse(320, 180, circleRad*2, circleRad*2); //draw circle based on data value
      }
      else if (value == 21212){
      endCode();
      keyPressed();
      }
   }
}

void keyPressed() {
  output.flush();  // Writes the remaining data to the file
  output.close();  // Finishes the file
  exit();  // Stops the program
}

void startCode(){
  output.print ("G21;");
  output.print ("G90;");
  output.print ("M82;");
  output.print ("M107;");
  output.print ("G28 X0 Y0;"); 
  output.print ("G28 Z0;");
  output.print ("G1 Z15.0 1200;"); 
  output.print ("G92 E0; ");
  output.print ("G1 F200 E0;"); 
  output.print ("G92 E0;"); 
  output.print ("G1 F{travel_speed};");
  output.print ("M203 X192 Y208 Z3;");
  output.print ("M117 Printing...;");
}
void endCode(){
  output.print("M400;");
  output.print ("M104 S0;");
  output.print ("M140 S0;");
  output.print ("M107;");
  output.print ("G91;");
  output.print ("G1 E-1 F300;");
  output.print ("G1 Z+0.5 E-5 X-20 Y-20 F3000;");
  output.print ("G90;");
  output.print ("G1 X0 Y250;");
  output.print ("M84;");
  output.print ("G90;");
  output.print ("M117 TAZ Ready.;");
}
/* Structure for X Y Z motion */
void xAxis(int val){
  output.print ("G1 X");
  output.print (val);
  output.print (";");
}
void yAxis(int val){
  output.print ("G1 Y");
  output.print (val);
  output.print (";");
}
void zAxis(int val){
  output.print ("G1 Z");
  output.print (val);
  output.print (";");
}