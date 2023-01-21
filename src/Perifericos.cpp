#include <Perifericos.h>
/*---------------------------|NOKIA5110/3310|----------------------------*/








/*---------------------------|COMPARADOR|----------------------------*/

COMPARATOR::COMPARATOR(uint8_t bNegativeInputp, uint8_t bModep)
{
  ACSR &= B11011111;      // Set ACBG, to be equal to "0"
  ADCSRA = (0 && ADEN);   // Disable the ADC module because
  ADCSRB = (1 && ACME);   // Enable the MUX selector for negative input of comparator
  ADMUX = 0;              // Select A0 as comparator negative input  
  ACSR |= B00000011;  
  /*ACSr|=(AC1|TOGGLE|this->bMode)&~(ACB6);
  Adc->ADCSRa=(0x0<<ADEn);
  Adc->ADCSRb=(0x1<<ACmE);
  Adc->ADMUx=(this->bNegative_Input-14u);*/
}

/*
ISR (ANALOG_COMP_vect) 
{      
  if(ACSr & B00100010)             //If we are into falling edge
  {
    if(!(ACSr & B00100000)) {      //If ACO is 0 (we have that ! for inverse)
      //A change from HIGH to LOW was detected
      DIGITAL_WRITE(5,B,LOW);
      ACSr |= B00000011;      // Remember top set back the interrupt on rising edge for next ISR
    }
  }
  else                              //else, if we are into rising edge
  {
    if((ACSr & B00100000)){         //If ACO is 1 
      //A change from LOW to HIGH was detected
        DIGITAL_WRITE(5,B,HIGH);
      ACSr |= B00000010;      // Remember top set back the interrupt on falling edge for next ISR
    }    
  }  
}
*/

/*---------------------------|pwm|----------------------------*/
 void fnvInit_Pwm2(void)
 {
  cli();/*|stoped all interrupts|*/ 
  TIMER_2->TCCRA=(uint8_t)ZERO;/*|Reset entire TCCR1A to 0|*/ 
  TIMER_2->TCCRB=(uint8_t)ZERO;/*|Reset entire TCCR1B to 0|*/ 
  TIMER_2->TCCRB|=(uint8_t)DIV_64;/*|Set CS12 to 1 so we get prescalar 256|*/  
  TIMSK_2|=(OVERFLOW|OCIEA|OCIEB); //Set OCIE1A to 1 so we enable compare match A and B and Overflow   
  PINMODE(5,D,OUTPUT);
  PINMODE(6,D,OUTPUT);
  sei();/*|running all interrupts|*/
  
 }
 

 ISR(TIMER2_COMPA_vect)
 { 
  DIGITALWRITE(5,D,HIGH);/*|set the pin 5 port B a HIGH|*/ 
 }

 ISR(TIMER2_COMPB_vect)
 {
  DIGITALWRITE(6,D,HIGH);/*|set the pin 6 port B a HIGH|*/ 
 }
 
 ISR(TIMER2_OVF_vect)
 {
  TIMER_2->TCNT=(uint8_t)ZERO;/*|Reset the timer count|*/
  DIGITALWRITE(5,D,LOW);/*|set the pin 5 port B a low|*/ 
  DIGITALWRITE(6,D,LOW);/*|set the pin 6 port B a low|*/ 
 }


void fnvInit_Pwm0(void)
 {
  cli();/*|stoped all interrupts|*/ 
  TIMER_0->TCCRA=(uint8_t)ZERO;/*|Reset entire TCCR1A to 0|*/ 
  TIMER_0->TCCRB=(uint8_t)ZERO;/*|Reset entire TCCR1B to 0|*/ 
  TIMER_0->TCCRB|=(uint8_t)DIV_256;/*|Set CS12 to 1 so we get prescalar 256|*/  
  TIMSK_0|=(OVERFLOW|OCIEA|OCIEB); //Set OCIE1A to 1 so we enable compare match A and B and Overflow   
  PINMODE(3,B,OUTPUT);
  TIMER_0->OCRB=(uint8_t)129;
  sei();/*|running all interrupts|*/
  
 }


 ISR(TIMER0_COMPA_vect)
 { 
  DIGITALWRITE(3,B,HIGH); /*|set the pin 5 port B a HIGH|*/ 
 }
 
 
 ISR(TIMER0_COMPB_vect)
 {
  DIGITALWRITE(3,B,LOW);/*|set the pin 5 port B a low|*/ 
  TIMER_0->TCNT=(uint8_t)ZERO;/*|Reset the timer count|*/
 }



/*---------------------------|Servo Motor|--------------------*/
 void fnvServo_Init(void)
 {
  cli();/*|stoped all interrupts|*/ 
  TCCR1A=0;/*|set TCCRA to ZERO|*/  
  TCCR1B=0;/*|set TCCRB to ZERO|*/
  TCCR1B|=(uint8_t)DIV_8;/*|define the prescale as 8 to divide the clock frecuency|*/ 
  OCR1B|=(uint16_t)40000;/*|define the pwm period as 20ms   period_of_signal/(clock_period*prescaler_div_factor)|*/
  TIMSK1|=(uint8_t)OCIEA|(uint8_t)OCIEB;/*|set the OCIEA=1 and OCIEB=1 to habilite the vect interrupt|*/
  sei();/*|running all interrupts|*/
  pinMode(6,OUTPUT);/*|define pin 5 port B as OUTPUT|*/
  //DIGITALWRITE(0,B,LOW);/*|set pin 5 to LOW |*/
 }

/*
 void fnvServo_Write(long Angulo)
 { 
  uint16_t b=-22.2*Angulo+38300;|funcion to convert angle to count value to register OCRA o OCRB|
  TIMER_1->OCRA=(uint16_t)b;|set the value b to OCRA|
 }*/
 
 ISR(TIMER1_COMPA_vect)/*|this isr is used to set to low pin 5 B|*/
 { 
  digitalWrite(6,LOW);/*|set the pin 5 port B a low|*/ 
  TCNT1=(uint16_t)ZERO;/*|Reset the timer count|*/
 }

 
 ISR(TIMER1_COMPB_vect)/*|this isr is used to set to low pin 5 B|*/
 {
  digitalWrite(6,HIGH);/*|set the pin 5 port B a HIGH|*/ 
 }

