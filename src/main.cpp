#include <Arduino.h>

int deathlight = 13; //output light for death
int killlight = 12; //output light for killing an enemy
//int highscore = 11; //output light for new high score
int currentscore = 0; //stores the current score
int prevscore = 0; //stores the previous score, indicates when you kill an enemy

void setup() {
  Serial.begin(9600); //baudrate between python and arduino needs to be the same
  pinMode(deathlight, OUTPUT);
  pinMode(killlight, OUTPUT);
  //pinMode(highscore, OUTPUT);
  digitalWrite(deathlight, LOW);
  digitalWrite(killlight, LOW);
  //digitalWrite(highscore, LOW);

  Serial.setTimeout(1);
}

void loop() {
  while (!Serial.available());
  currentscore = Serial.readString().toInt();
  Serial.print("Current score: " + String(currentscore));
  if (currentscore > prevscore) {
    digitalWrite(killlight, HIGH);
    delay(1000);
    digitalWrite(killlight, LOW);
    prevscore=currentscore;
  }
  if (prevscore > currentscore) {
    digitalWrite(deathlight, HIGH);
    delay(1000);
    digitalWrite(deathlight, LOW);
    prevscore = 0;
  }
  // if (isHighscore) {
  //   digitalWrite(highscore, HIGH);
  //   delay(100);
  //   digitalWrite(highscore, LOW);
  // }
  // isHighscore = false;

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