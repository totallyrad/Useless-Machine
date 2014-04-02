/*
State change detection (edge detection)
Based on example code by Tom Igoe on State Edge detection
This example code is in the public domain.
http://arduino.cc/en/Tutorial/ButtonStateChange
*/

#include <Servo.h> 
 
Servo myservo1;  // create servo object to control a servo 
Servo myservo2;                // a maximum of eight servo objects can be created 
                
int pos = 0;    // variable to store the servo position

// these constants do not change
const int  buttonPin = 2;    // the pin that the pushbutton is attached to
const int ledPin = 13;       // the pin that the LED is attached to

// Variables will change:
int buttonState = 0;         // current state of the button
int lastButtonState = 0;     // previous state of the button

void setup() {
  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT);
  // initialize the LED as an output:
  pinMode(ledPin, OUTPUT);
  // attaches the servos on pin 9 and 10 to the servo objects 
  myservo1.attach(9);
  myservo2.attach(10);  
  // initialize serial communication:
  Serial.begin(9600);
}


void loop() {
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH then the button
      // wend from off to on:
    digitalWrite(ledPin, HIGH);  

  {         
    myservo2.write(160);
    delay(1000);    
    myservo1.write(90);              // tell servo to go to position  
    delay(500);                       // waits 15ms for the servo to reach the position 
    myservo1.write(100);              // tell servo to go to position  
    delay(500);                       // waits 15ms for the servo to reach the position 
    myservo1.write(110);              // tell servo to go to position  
    delay(500);                       // waits 15ms for the servo to reach the position 
     myservo1.write(160);              // tell servo to go to position  
    delay(1000);                       // waits 15ms for the servo to reach the position 
    myservo1.write(180);              // tell servo to go to position  
    delay(500);                       // waits 15ms for the servo to reach the position 
    myservo1.write(10);         // tell servo to go to position  
        myservo2.write(10);
    delay(500);  
    myservo2.write(10);
  } 
    } 
    else {
      // if the current state is LOW then the button
      // wend from on to off:
         digitalWrite(ledPin, LOW); 
         myservo1.write(10);
         myservo2.write(10);
    }
  }
  // save the current state as the last state, 
  //for next time through the loop
  lastButtonState = buttonState;


  
}








