#include <Arduino.h>
#include <Perifericos.h>
//enum pins{
    //LCD_PIN_RES=6,/*RESET INPUT*/
    //LCD_PIN_SCE=7,/*CHIP ENABLE PIN */
    //LCD_PIN_DC=5,/*DATA OR COMMAND PIN*/
    //LCD_PIN_SDIN=4,/*SERIAL DATA INPUT*/
    //LCD_PIN_SCLK=8 /*SERIAL CLOCK INPUT*/
//};*/

//double bAlfa=0.25;
//COMPARATOR test(A0,R1S1NG);
void setup() 
{
 //pinMode(LCD_PIN_RES,OUTPUT);
 //pinMode(LCD_PIN_SCE,OUTPUT);
 //pinMode(LCD_PIN_DC,OUTPUT);
 //pinMode(LCD_PIN_SDIN,OUTPUT);
 //pinMode(LCD_PIN_SCLK,OUTPUT);
 //digitalWrite(LCD_PIN_RES,HIGH);
 //digitalWrite(LCD_PIN_SCE,HIGH);
 fnvInit_Pwm2();
 //fnvServo_Init();
 /* initialize the lcd */
 /*RES pulse for reset function */
 //digitalWrite(LCD_PIN_RES,LOW);
 //delayMicroseconds(1);// time original ist the value 0.1 microseconds//
 //digitalWrite(LCD_PIN_RES,HIGH);

}

void loop() 
{
  //OCR1A=36300;
  ANALOGWRITEA2(178);
  ANALOGWRITEA2(25);
  delay(500);
  
}