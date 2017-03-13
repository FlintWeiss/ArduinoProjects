#ifdef __AVR__
  #include <avr/power.h>
#endif

#include "TrailingAverage.h"

/*======================================================================
 * Variable resistors are read over an analog input. They are wired
 * either one side to voltage and one side to the pin OR one side to
 * ground and the other side to the pin. This code expects that we
 * are using ground to measure resistance which makes the values low.
 * 
 * Because anlaog is inherently noisy, we need to average the values
 * read from the pin to stabilize the values.
 *======================================================================
 */

#define sensorPin  A0

TrailingAverage fingerTA(20);
TrailingAverage thumbTA(10);

// NOTE: this is a magic number and will have be tuned for the wearer.
//   40 was pretty realible for an adult with large hands but needed
//   to be turned down to 30 a student with smaller hands.
#define CLOSED 30

/*
#define WINDOW 10
int trailingValues[WINDOW];
int tvIndex = 0;
int tvTotal = 0;
*/

void setup() {
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}// end setup

void loop() {

   int sensorValue = 0; 
   int avgValue = 0;
   
   // increase the number of bit returned to make the values a little bigger
   analogReadResolution(12);
   
   sensorValue = analogRead(sensorPin);
   //Serial.print("sensor value: "); Serial.println(sensorValue);
   
   avgValue = fingerTA.averageInput(sensorValue);
   //Serial.print("averaged value: "); Serial.println(avgValue);

   if(avgValue > CLOSED) 
   { 
      // equivalent to a button press. take action.
      Serial.println("closed"); 
   } else {
      Serial.print("open: "); Serial.println(avgValue);
   }
      
   delay(25);
   
} // end loop

/*=========================================================================
 * averageAnalogInput - computes the average of trailing X input values to
 *    hide the noise inherent in Analog.
 * Algortihm:
 *    To avoid having to iterate through the array and recomputing the total
 *    every time, we keep the total from call to call and then subtract the 
 *    value being replaced and add the replacement value being added.
 * Setup: 
 *    WINDOW: the number of trailing window inputs to track
 *    trailingValues: an array[TRAILING_WINDOW] that holds the values
 *    tvTotal: the current total value
 *    tvIndex: the current location of the item to replace
 * Parameters:
 *    input: the new input to add to the average
 * Returns:
 *    the computed average value
 */
/*
int averageAnalogInput(int input) {
  int newAvg = 0;

  //Serial.print("- input: "); Serial.println(input);
  //Serial.print("- tvTotal 3: "); Serial.println(tvTotal);
  //Serial.print("- tvTotal 1: "); Serial.println(tvTotal);
  tvTotal = tvTotal - trailingValues[tvIndex];
  if(tvTotal < 0) { tvTotal = 0; }
  //Serial.print("- tvTotal 2: "); Serial.println(tvTotal);

  trailingValues[tvIndex] = input;
  tvTotal += input;
  //Serial.print("- tvTotal 3: "); Serial.println(tvTotal);
  
  newAvg = tvTotal/WINDOW;
  //Serial.print("- newAvg: "); Serial.println(newAvg); 
  
  tvIndex++;
  if(tvIndex > WINDOW-1) { tvIndex = 0; }
  //Serial.print("- tvIndex: "); Serial.println(tvIndex); 
  
  return(newAvg);
} // end averageAnalogInput
*/


