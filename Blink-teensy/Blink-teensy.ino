/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.
 
  This example code is in the public domain.
 */

void setup() {                
  // initialize the digital pin as an output.
  // Pin 13 has an LED connected on most Arduino boards:
  pinMode(13, OUTPUT);     
  Serial.begin(9600);
}

void loop() {
  static int count=1;
  Serial.print("Count = ");
  Serial.println(count++);
  digitalWrite(13, HIGH);   // set the LED on
  delay(500);              // wait for 1/2 a second
  digitalWrite(13, LOW);    // set the LED off
  delay(500);              // wait for 1/2 a second
  digitalWrite(13, HIGH);   // set the LED on
  delay(2000);              // wait for 1/2 a second
  digitalWrite(13, LOW);    // set the LED off
  delay(2000);              // wait for 1/2 a second
}



