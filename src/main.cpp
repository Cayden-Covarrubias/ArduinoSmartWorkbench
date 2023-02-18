#include <Arduino.h>


int x;

void setup() {
  Serial.begin(115200); //baudrate between python and arduino needs to be the same
  Serial.setTimeout(1);
}

void loop() {
  while (!Serial.available());
  x = Serial.readString().toInt();
  Serial.print(x + 1);
}


// // C++ code
// //

// int pushButton = 12;
// int redLight = 11;

// void setup()
// {
//   //initialize serial communication at 9600 bits per second:
//   Serial.begin(9600);
//   //make the pushbutton's pin an input:
//   pinMode(pushButton, INPUT);
//   pinMode(redLight, OUTPUT);
//   digitalWrite(redLight, LOW);
// }

// void loop()
// {
//   //read the input pin:
//   int buttonState = digitalRead(pushButton);
//   //print out the state of the button:
//   Serial.println(buttonState);
//   if(buttonState == 1){
//     digitalWrite(redLight, HIGH);
//     delay(100);
    
//   }
//   digitalWrite(redLight, LOW);
//   delay(1);
// }

// // void setup() {
// //   // put your setup code here, to run once:
// //   Serial.begin(9600);
// //   pinMode(13, OUTPUT);
// // }

// // void loop() {
// //   // put your main code here, to run repeatedly:
// //   // Serial.println("Hello World");
// //   // delay(10000);
// //   // delay(10);
// //   // //Testing

// //   digitalWrite(13,HIGH);
// //   delay(150);
// //   digitalWrite(13,LOW);
// //   delay(150);
// // }