//IoT based Accident Detection System
//Group 04// Project Guide: Prof. Panil Jain
//Parth Chande//Rahul Panda//Aryan Patil//Samuel Selvakumar
//B.E. Electronics and Telecommunication Engineering
//Xavier Institute of Engineering, Mumbai.

#include <SoftwareSerial.h>
#include <TinyGPS++.h>

// The serial connection to the GSM device
static const int RXPin = 11, TXPin = 10;
static const uint32_t GPSBaud = 9600;

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);
SoftwareSerial mySerial(13, 12);
char msg;

//defining impact sensors
#define IMP1 2
#define IMP2 3
#define IMP3 4
#define IMP4 5

#define tiltSensor A4          //defining tilt sensor
int val = 0;                   //variable for reading the tilt switch status

//defining flame sensor
int flame_sensor_pin = A5 ;    // initializing pin A5 as the sensor output pin
int flame_pin = LOW ;          // state of sensor
#define campin 9               //defining arduino pin 9 for triggering the cameras

void setup()
{
mySerial.begin(9600);         // Setting the baud rate of GSM Module
ss.begin(GPSBaud);            // Setting the baud rate of GPS Module
Serial.begin(9600);           // Setting the baud rate of Arduino
pinMode(IMP1, INPUT);         // declaring IMP1 pin as input pin for Arduino

pinMode(IMP2, INPUT);         // declaring IMP2 pin as input pin for Arduino
pinMode(IMP3, INPUT);         // declaring IMP3 pin as input pin for Arduino
pinMode(IMP4, INPUT);         // declaring IMP4 pin as input pin for Arduino
pinMode(tiltSensor, INPUT);   // declaring tilt sensor pin as input pin for Arduino
pinMode(flame_sensor_pin, INPUT); // declaring sensor pin as input pin for Arduino
pinMode(campin, OUTPUT);      // declaring cam pin as output pin for Arduino
digitalWrite(campin, HIGH);   // state of cam pin
delay(100);                   // Delay of 100 milli seconds or 0.1 second
}

void loop() {
while (ss.available() > 0) {
gps.encode(ss.read());                 // Fetchig the GPS coordinates
if (gps.location.isUpdated()) {        // When GPS signal is available
Serial.println(gps.location.lat(), 6); // Fetching latitude
Serial.println(gps.location.lng(), 6); // Fetching longitude
}
}
int state1 = digitalRead(IMP1);        // Reading Impact sensor 1 value
if (state1 == LOW) {                   // When Impact sensor 1 is triggered
digitalWrite(campin, LOW);             // Set campin to low or triggering the ESP32-CAM
delay(2000);                           // Delay of 2000 milli seconds or 2 second
digitalWrite(campin, HIGH);            // Set campin to high for ending the trigger
SendMessage();                         //calling the SendMessage function
delay(5000);                           // Delay of 5000 milli seconds or 5 second
ownerinfo();                           //calling the ownerinfo function
delay(5000);                           // Delay of 5000 milli seconds or 5 second
carinfo();                             //calling the carinfo function
delay(5000);                           // Delay of 5000 milli seconds or 5 second
SendMessageS();                        //calling the SendMessageS function
delay(5000);                           // Delay of 5000 milli seconds or 5 second
ownerinfoS();                          //calling the ownerinfoS function
delay(5000);                           // Delay of 5000 milli seconds or 5 second
carinfoS();;                           //calling the carinfoS function
}

////////////

int state2 = digitalRead(IMP2);   // Reading Impact sensor 2 value
if (state2 == LOW) {              // When Impact sensor 2 is triggered
digitalWrite(campin, LOW);        // Set campin to low or triggering the ESP32-CAM
delay(2000);                      // Delay of 2000 milli seconds or 2 second
digitalWrite(campin, HIGH);       // Set campin to high for ending the trigger
SendMessage();                    //calling the SendMessage function
delay(5000);                      // Delay of 5000 milli seconds or 5 second
ownerinfo();                      //calling the ownerinfo function
delay(5000);                      // Delay of 5000 milli seconds or 5 second

carinfo();          //calling the carinfo function
delay(5000);        // Delay of 5000 milli seconds or 5 second
SendMessageS();     //calling the SendMessageS function
delay(5000);        // Delay of 5000 milli seconds or 5 second
ownerinfoS();       //calling the ownerinfoS function
delay(5000);        // Delay of 5000 milli seconds or 5 second
carinfoS();;        //calling the carinfoS function
}

///////////

int state3 = digitalRead(IMP3);   // Reading Impact sensor 3 value
if (state3 == LOW) {              // When Impact sensor 3 is triggered
digitalWrite(campin, LOW);        // Set campin to low or triggering the ESP32-CAM
delay(2000);                      // Delay of 2000 milli seconds or 2 second
digitalWrite(campin, HIGH);       // Set campin to high for ending the trigger
SendMessage();                    //calling the SendMessage function
delay(5000);                      // Delay of 5000 milli seconds or 5 second
ownerinfo();                      //calling the ownerinfo function
delay(5000);                      // Delay of 5000 milli seconds or 5 second
carinfo();                        //calling the carinfo function
delay(5000);                      // Delay of 5000 milli seconds or 5 second
SendMessageS();                   //calling the SendMessageS function
delay(5000);                      // Delay of 5000 milli seconds or 5 second
ownerinfoS();                     //calling the ownerinfoS function
delay(5000);                      // Delay of 5000 milli seconds or 5 second
carinfoS();;                      //calling the carinfoS function
}

////////////

int state4 = digitalRead(IMP4);     // Reading Impact sensor 4 value
if (state4 == LOW) {                // When Impact sensor 4 is triggered
digitalWrite(campin, LOW);          // Set campin to low or triggering the ESP32-CAM
delay(2000);                        // Delay of 2000 milli seconds or 2 second
digitalWrite(campin, HIGH);         // Set campin to high for ending the trigger
SendMessage();                      //calling the SendMessage function
delay(5000);                        // Delay of 5000 milli seconds or 5 second
ownerinfo();                        //calling the ownerinfo function
delay(5000);                        // Delay of 5000 milli seconds or 5 second
carinfo();                          //calling the carinfo function
delay(5000);                        // Delay of 5000 milli seconds or 5 second
SendMessageS();                     //calling the SendMessageS function
delay(5000);                        // Delay of 5000 milli seconds or 5 second
ownerinfoS();                       //calling the ownerinfoS function
delay(5000);                        // Delay of 5000 milli seconds or 5 second
carinfoS();;                        //calling the carinfoS function
}

///////////////////////////////////////////////////////////////////////////////////////////

val = digitalRead(tiltSensor);      // read state of tilt sensor
if (val == HIGH) {                  // When Tilt is detected
digitalWrite(campin, LOW);          // Set campin to low or triggering the ESP32-CAM
delay(2000);                        // Delay of 2000 milli seconds or 2 second
digitalWrite(campin, HIGH);         // Set campin to high for ending the trigger
TiltMessage();                      //calling the TiltMessage function
delay(5000);                        // Delay of 5000 milli seconds or 5 second
ownerinfo();                        //calling the ownerinfo function
delay(5000);                        // Delay of 5000 milli seconds or 5 second
carinfo();                          //calling the carinfo function
delay(5000);                        // Delay of 5000 milli seconds or 5 second
TiltMessageS();                     //calling the TiltMessageS function
delay(5000);                        // Delay of 5000 milli seconds or 5 second
ownerinfoS();                       //calling the ownerinfoS function
delay(5000);                        // Delay of 5000 milli seconds or 5 second
carinfoS();;                        //calling the carinfoS function
}

///////////////////////////////////////////////////////////////////////////////////////////

flame_pin = digitalRead(flame_sensor_pin);    // reading the sensor
if (flame_pin == HIGH) {                      // when fire is detected
onlyfire();                                   //calling the onlyfire function
delay(5000);                                  // Delay of 5000 milli seconds or 5 second
ownerinfo();                                  //calling the ownerinfo function
delay(5000);                                  // Delay of 5000 milli seconds or 5 second
carinfo();                                    //calling the carinfo function
delay(5000);                                  // Delay of 5000 milli seconds or 5 second
onlyfireS();                                  //calling the onlyfireS function
delay(5000);                                  // Delay of 5000 milli seconds or 5 second
ownerinfoS();                                 //calling the ownerinfoS function
delay(5000);                                  // Delay of 5000 milli seconds or 5 second
carinfoS();;                                  //calling the carinfoS function
}
}

//////////////////////////////////////////////////////////////////////////////////////////
/// SENDING ALERT TEXT MESSAGE TO A MOBILE NUMBER (Emergency Services)
//////////////////////////////////////////////////////////////////////////////////////////

void SendMessage() {                           // Text message when impact is detected
mySerial.println("AT+CMGF=1");                 //Sets the GSM Module in Text Mode
delay(1000);                                   // Delay of 1000 milli seconds or 1 second
mySerial.println("AT+CMGS=\"9082xxxxxx\"\r");  // enter mobile number
delay(1000);                                   // Delay of 1000 milli seconds or 1 second
mySerial.println("---ACCIDENT ALERT---");      // The SMS text you want to send
delay(1000);                                   // Delay of 1000 milli seconds or 1 second
mySerial.println("<Impact detected>");         // The SMS text you want to send
delay(1000);                                   // Delay of 1000 milli seconds or 1 second
fire();                                        // Calls the 'fire' function
mySerial.println("https://www.google.com/maps?q=" + String(gps.location.lat(), 6) + "," + String(gps.location.lng(), 6));                //Creating a Google maps link using the GPS coordinates
mySerial.write(26);                            // ASCII code of CTRL+Z
delay(1000);                                   // Delay of 1000 milli seconds or 1
second
}

////////////////////////////////////////////////////

void TiltMessage() {                          // Text message when tilt is detected
mySerial.println("AT+CMGF=1");                //Sets the GSM Module in Text Mode
delay(1000);                                  // Delay of 1000 milli seconds or 1 second
mySerial.println("AT+CMGS=\"9082xxxxxx\"\r"); // Enter mobile number
delay(1000);                                  // Delay of 1000 milli seconds or 1 second
mySerial.println("!!! Accident Alert !!!");   // The SMS text you want to send
delay(1000);                                  // Delay of 1000 milli seconds or 1 second
mySerial.println("Car Tilted or Flipped");    // The SMS text you want to send
delay(1000);                                  // Delay of 1000 milli seconds or 1 second
fire();                                       // Calls the 'fire' function
mySerial.println("https://www.google.com/maps?q=" + String(gps.location.lat(), 6) + "," + String(gps.location.lng(), 6));               //Creating a Google maps link using the GPS coordinates
mySerial.write(26);                           // ASCII code of CTRL+Z
delay(1000);                                  // Delay of 1000 milli seconds or 1
second
}

////////////////////////////////////////////////////

void fire() {                                   // Text message when fire is detected
flame_pin = digitalRead(flame_sensor_pin);      // reading from the sensor
if (flame_pin == HIGH)                          // applying condition
{
Serial.println ( " FLAME , FLAME , FLAME " ) ;  // The SMS text you want to send
mySerial.println("Fire Detected");              // The SMS text you want to send
delay(1000);                                    // Delay of 1000 milli seconds or 1 second
}

else
{
Serial.println ( " no flame " ) ;
mySerial.println("No Fire");                    // The SMS text you want to send
mySerial.println((char)26);                     // ASCII code of CTRL+Z
delay(1000);                                    // Delay of 1000 milli seconds or 1 second
}
}

////////////////////////////////////////////////////

void ownerinfo () {                                               // Text message icluding information of car owner
mySerial.println("AT+CMGF=1");                                    //Sets the GSM Module in Text Mode
delay(1000);                                                      // Delay of 1000 milli seconds or 1 second
mySerial.println("AT+CMGS=\"9082xxxxxx\"\r");                     // Enter mobile number
delay(1000);                                                      // Delay of 1000 milli seconds or 1 second
mySerial.println("__Details of the CAR owner__");                 // The SMS text you want to send
mySerial.println("Name: Parth Chande");                           // The SMS text you want to send
mySerial.println("Blood Group: ");                                // The SMS text you want to send
mySerial.println("Address: Plot No: 00, Sector: 00, New Panvel"); // The SMS text you want to send
mySerial.println((char)26); // ASCII code of CTRL+Z
delay(1000);
}

////////////////////////////////////////////////////

void carinfo () {                                  // Text message icluding information of car
mySerial.println("AT+CMGF=1");                     //Sets the GSM Module in Text Mode
delay(1000);                                       // Delay of 1000 milli seconds or 1 second
mySerial.println("AT+CMGS=\"9082xxxxxx\"\r");      // Enter mobile number
delay(1000);                                       // Delay of 1000 milli seconds or 1 second
mySerial.println("__Details of the CAR__");        // The SMS text you want to send
mySerial.println("License Plate No: XIE GR 04 ");  // The SMS text you want to send
mySerial.println("Car Color: Blue");               // The SMS text you want to send
mySerial.println((char)26);                        // ASCII code of CTRL+Z
delay(1000);                                       // Delay of 1000 milli seconds or 1 second
}

////////////////////////////////////////////////////

void onlyfire() {                                // Text message when only fire is deteted without any impact or tilt
mySerial.println("AT+CMGF=1");                   //Sets the GSM Module in Text Mode
delay(1000);                                     // Delay of 1000 milli seconds or 1 second
mySerial.println("AT+CMGS=\"9082xxxxxx\"\r");    // Enter mobile number
delay(1000);                                     // Delay of 1000 milli seconds or 1 second
mySerial.println("Fire Detected");               // The SMS text you want to send
mySerial.println("No Impact or Tilt of vehicle");// The SMS text you want to send
mySerial.write(26);                              // ASCII code of CTRL+Z
delay(1000);                                     // Delay of 1000 milli seconds or 1 second
}

//////////////////////////////////////////////////////////////////////////////////////////
/// SENDING ALERT TEXT MESSAGE TO ANOTHER NUMBER (Family)
//////////////////////////////////////////////////////////////////////////////////////////

void SendMessageS() {
mySerial.println("AT+CMGF=1");                   //Sets the GSM Module in Text Mode
delay(1000);                                     // Delay of 1000 milli seconds or 1 second
mySerial.println("AT+CMGS=\"8268xxxxxx\"\r");    // Enter mobile number
delay(1000);                                     // Delay of 1000 milli seconds or 1 second
mySerial.println("---ACCIDENT ALERT---");        // The SMS text you want to send
delay(1000);                                     // Delay of 1000 milli seconds or 1 second
mySerial.println("<Impact detected>");           // The SMS text you want to send
delay(1000);                                     // Delay of 1000 milli seconds or 1 second
fire();                                          // Calls the 'fire' function
mySerial.println("https://www.google.com/maps?q=" + String(gps.location.lat(), 6) + "," + String(gps.location.lng(), 6));                  //Creating a Google maps link using the GPS coordinates
mySerial.write(26);                              // ASCII code of CTRL+Z
delay(1000);                                     // Delay of 1000 milli seconds or 1 second
}

////////////////////////////////////////////////////

void TiltMessageS() {
mySerial.println("AT+CMGF=1");                    //Sets the GSM Module in Text Mode
delay(1000);                                      // Delay of 1000 milli seconds or 1 second
mySerial.println("AT+CMGS=\"8268xxxxxx\"\r");     // Enter mobile number
delay(1000);                                      // Delay of 1000 milli seconds or 1 second
mySerial.println("!!! Accident Alert !!!");       // The SMS text you want to send
delay(1000);                                      // Delay of 1000 milli seconds or 1 second
mySerial.println("Car Tilted or Flipped");        // The SMS text you want to send
delay(1000);                                      // Delay of 1000 milli seconds or 1 second
fire();                                           // Calls the 'fire' function
mySerial.println("https://www.google.com/maps?q=" + String(gps.location.lat(), 6) + "," + String(gps.location.lng(), 6)); //Creating a Google maps link using the GPS coordinates
mySerial.write(26);                               // ASCII code of CTRL+Z
delay(1000);                                      // Delay of 1000 milli seconds or 1 second
}

////////////////////////////////////////////////////

void ownerinfoS ()
{
mySerial.println("AT+CMGF=1");                                    //Sets the GSM Module in Text Mode
delay(1000);                                                      // Delay of 1000 milli seconds or 1 second
mySerial.println("AT+CMGS=\"8268xxxxxx\"\r");                     // Enter mobile number
delay(1000);                                                      // Delay of 1000 milli seconds or 1 second
mySerial.println("__Details of the CAR owner__");                 // The SMS text you want to send
mySerial.println("Name: Parth Chande");                           // The SMS text you want to send
mySerial.println("Blood Group: ");                                // The SMS text you want to send
mySerial.println("Address: Plot No: 00, Sector: 00, New Panvel"); // The SMS text you want to send
mySerial.println((char)26);                                       // ASCII code of CTRL+Z
delay(1000);                                                      // Delay of 1000 milli seconds or 1 second
}

////////////////////////////////////////////////////

void carinfoS ()
{
mySerial.println("AT+CMGF=1");                     //Sets the GSM Module in Text Mode
delay(1000);                                       // Delay of 1000 milli seconds or 1 second
mySerial.println("AT+CMGS=\"8268xxxxxx\"\r");      // Enter mobile number
delay(1000);                                       // Delay of 1000 milli seconds or 1 second
mySerial.println("__Details of the CAR__");        // The SMS text you want to send
mySerial.println("License Plate No: XIE GR 04 ");  // The SMS text you want to send
mySerial.println("Car Color: Blue");               // The SMS text you want to send
mySerial.println((char)26);                        // ASCII code of CTRL+Z
delay(1000);                                       // Delay of 1000 milli seconds or 1 second
}

/////////////////////////////////////////////////////

void onlyfireS() {
mySerial.println("AT+CMGF=1");                    //Sets the GSM Module in Text Mode
delay(1000);                                      // Delay of 1000 milli seconds or 1 second
mySerial.println("AT+CMGS=\"8268xxxxxx\"\r");     // Enter mobile number
delay(1000);                                      // Delay of 1000 milli seconds or 1 second
mySerial.println("Fire Detected");                // The SMS text you want to send
mySerial.println("No Impact or Tilt of vehicle"); // The SMS text you want to send
mySerial.println((char)26);                       // ASCII code of CTRL+Z
delay(1000);                                      // Delay of 1000 milli seconds or 1 second
}