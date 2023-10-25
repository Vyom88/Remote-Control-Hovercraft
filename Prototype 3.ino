// C++ Code
// Name: Vyom Kapadia
// Course Code: TEJ 3M1-P
// Date: June 14, 2023


// Variables
// Bluetooth input variable
char BT_input;


// Specific pin variables
int enA = 8;
int m1 = 9;
int m2 = 10;
int m3 = 11;
int m4 = 12;
int enB = 13;


// On/Off variable
bool on = false;


// Forward/Stationary variable
int forward = 0;


void setup()  
{
  // Built-in function for the setup (setting some
  // pins to output and setting up Serial gate)


  Serial.begin(9600);


  pinMode(enA, OUTPUT);
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(m3, OUTPUT);
  pinMode(m4, OUTPUT);
  pinMode(enB, OUTPUT);
}


void loop()
{
  // Built in loop function (runs the main part of the program)


  // Checking if the HC-05 is connected
  if (Serial.available())
  {


    // Reads input from HC-05 bluetooth module (connected to a phone)
    BT_input=Serial.read();


    // Changes the on and forward variable if a button was pressed on the HC-05
    if (BT_input=='O') {
      on = !on;
    }
    else if (BT_input=='F') {
      forward = 1;
    }
    else if (BT_input=='S') {
      forward = 0;
    }


    // Writes the max power/value (255) to the enA and enB pins
    analogWrite(enA, 255);
    analogWrite(enB, 255);


    // If the hovercraft is supposed to be off, sets m1, m2, m3, and m4 to LOW
    if (!on) {
      digitalWrite(m1, LOW);
      digitalWrite(m2, LOW);
      digitalWrite(m3, LOW);
      digitalWrite(m4, LOW);
    }


    // If the hovercraft is supposed to be on and moving forward, sets m2 and m4 to HIGH
    // and m1 and m3 to LOW
    else if (forward == 1) {
      digitalWrite(m1, LOW);
      digitalWrite(m2, HIGH);
      digitalWrite(m3, LOW);
      digitalWrite(m4, HIGH);
    }


    // If the hovercraft is supposed to be on and stationary, sets m2 to HIGH
    // and m1, m3, and m4 to LOW
    else if (forward == 0) {
      digitalWrite(m1, LOW);
      digitalWrite(m2, HIGH);
      digitalWrite(m3, LOW);
      digitalWrite(m4, LOW);
    }
  }
 
}



