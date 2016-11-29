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

void setup() {
   mySerial = new Serial( this, Serial.list()[0], 9600 );
   output = createWriter( "data.txt" );
   startCode();
}

void draw() {
   if (mySerial.available() > 0 ) {
       String value = mySerial.readString();
         if ( value != null ) {
           output.println( value );
       }
    }
}

void keyPressed() {
  endCode();
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
