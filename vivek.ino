 /*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/
// defines pins numbers
const int trigPin = 13;
const int echoPin = 12;
// defines variables
long duration;
int distance;
#include <LiquidCrystal.h> //Load Liquid Crystal Library

LiquidCrystal LCD(11,10,9,2,3,4,5); //Create Liquid Crystal Object called LCD

#define trigPin 13 //Sensor Echo pin connected to Arduino pin 13

#define echoPin 12 //Sensor Trip pin connected to Arduino pin 12

//Simple program just for testing the HC-SR04 Ultrasonic Sensor with LCD dispaly

//URL:

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
Serial.begin(9600); // Starts the serial communication
pinMode(trigPin, OUTPUT);

pinMode(echoPin, INPUT);

LCD.begin(16,2); //Tell Arduino to start your 16 column 2 row LCD

LCD.setCursor(0,0); //Set LCD cursor to upper left corner, column 0, row 0

LCD.print("Target Distance:"); //Print Message on First Row

}
void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance: ");
Serial.println(distance);
long duration, distance;

digitalWrite(trigPin, LOW);

delayMicroseconds(2);

digitalWrite(trigPin, HIGH);

delayMicroseconds(10);

digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance = (duration/2) / 29.1;

LCD.setCursor(0,1); //Set cursor to first column of second row

LCD.print(" "); //Print blanks to clear the row

LCD.setCursor(0,1); //Set Cursor again to first column of second row

LCD.print(distance); //Print measured distance

LCD.print(" cm"); //Print your units.

delay(250); //pause to let things settle
}
