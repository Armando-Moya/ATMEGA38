 #ifndef ESTANDAR_H_
 #define ESTANDAR_H_
/*-------------|define,typedef y enum |-----------*/
 #include<Arduino.h>
 typedef unsigned char uint8_t;
 typedef unsigned int uint16_t;
 typedef struct port
 {
  uint8_t PIN;
  uint8_t DDR;
  uint8_t PORT; 
 }port;



 typedef struct timer
 {
  uint8_t TCCRA;
  uint8_t TCCRB;
  uint8_t TCNT;
  uint8_t OCRA;
  uint8_t OCRB;

 }timer_8b;

 typedef struct timer2
 {
  uint8_t TCCRA;
  uint8_t TCCRB;
  uint8_t TCCRC;
  uint8_t const RESERVE;
  uint16_t TCNT;
  uint16_t ICR;
  uint16_t OCRA;
  uint16_t OCRB;

 }timer_16b;

 typedef struct adc
 {
   uint16_t ADCt;
   uint8_t  ADCSRa;
   uint8_t  ADCSRb;
   uint8_t  ADMUx;
    
 }adc;
 
 

//acelrerometer 2G 
//gyroscope 250dps 

 #define D ((volatile port*)0x29)
 #define B ((volatile port*)0x23)
 #define C ((volatile port*)0x26)
 
 #define Adc ((volatile adc*)0x78) 

 #define TIMER_0 ((volatile timer_8b*)0x44) //0x44
 #define TIMER_2 ((volatile timer_8b*)0xB0)
 #define TIMER_1 ((volatile timer_16b*)0x80)
 #define FREQ    ((uint16_t)16000000)

 #define TIMSK_0 (*(volatile uint8_t*)(0x6E))
 #define TIMSK_1 (*(volatile uint8_t*)(0x6F))
 #define TIMSK_2 (*(volatile uint8_t*)(0x70))
 #define ACSr    (*(volatile uint8_t*)(0x30)) 

/*---------------------------|prototipos de funcion|--------------------*/


/*---------------------------|variables|-------------------------------*/
#endif

