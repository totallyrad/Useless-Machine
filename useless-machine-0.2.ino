/*
State change detection (edge detection)
Based on example code by Tom Igoe on State Edge detection
This example code is in the public domain.
http://arduino.cc/en/Tutorial/ButtonStateChange


Version 0.2 adds in servo detatch in an attempt to manage servo buzzing.

I removed attaching the servos to pin 9 and 10 from the setup, and moved it into the loop
so it can be detatched when switch is LOW
*/

#include <Servo.h> 
 
Servo myservo1;  // create servo object to control a servo 
Servo myservo2;  // a maximum of eight servo objects can be created 
                
int pos = 0;    // variable to store the servo position

// these constants do not change
const int  buttonPin = 2;    // the pin that the pushbutton/switch is attached to
const int ledPin = 13;       // the pin that the LED is attached to

// Variables will change:
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  // initialize the LED as an output:
  pinMode(ledPin, OUTPUT);
  // I moved the servo attach to the void loop to try implementing servro detatch to eliminate hum
  // initialize serial communication:
  Serial.begin(9600);
}


void loop() {
  // read the switch input pin:
  buttonState = digitalRead(buttonPin);
  


  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
  
    if (buttonState == HIGH) {    // if the current state is HIGH then run next section of code
    
      
    digitalWrite(ledPin, HIGH);  
   
  myservo1.attach(9);   // attaches the servos on pin 9 to myservo1
  myservo2.attach(10);  // attaches the servos on pin 10 to myservo2

  {         
    myservo2.write(160);
    delay(1000);
    myservo1.write(90);               // tell servo to go to position  
    delay(500);                       // waits 15ms for the servo to reach the position 
    myservo1.write(100);              // tell servo to go to position  
    delay(500);                       // waits 15ms for the servo to reach the position 
    myservo1.write(110);              // tell servo to go to position  
    delay(500);                       // waits 15ms for the servo to reach the position 
     myservo1.write(160);             // tell servo to go to position  
    delay(1000);                      // waits 15ms for the servo to reach the position 
    myservo1.write(180);              // tell servo to go to position  
    delay(500);                       // waits 15ms for the servo to reach the position 
    myservo1.write(10);               // tell servo to go to position  
    delay(500);  
    myservo2.write(10);
    

  } 
    } 
    else {
      // if the current state is LOW then the button
      // went from on to off:
         digitalWrite(ledPin, LOW); 
         myservo1.attach(9);   // attaches the servos on pin 9 to myservo1
         myservo2.attach(10);  // attaches the servos on pin 10 to myservo2
         myservo1.write(10);  // Moves myservo1 to rest position
         myservo2.write(10);  // Moves myservo2 to rest position
         myservo1.detach(9);  // Turns off servo on myservo1
         myservo2.detach(10); // Turns off servo on myservo2
    }
  }
  // save the current state as the last state, 
  //for next time through the loop
  lastButtonState = buttonState;


  
}








