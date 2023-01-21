#ifndef PERIFERICOS_H_
#define PERIFERICOS_H_
#include<estandar.h>
/*-------------|define,typedef y enum |-----------*/
 class SERVO
 {
 private:
 uint8_t pin;
 port  *puerto;

 public:

 };

 class COMPARATOR
 {
 private:
   uint8_t bNegative_Input;
   uint8_t bMode;
 public:
   COMPARATOR(uint8_t bNegativeInputp, uint8_t bModep);   
 };

 #define ZERO    ((uint8_t)0x0)
 #define DIGITALWRITE(Pin,Puerto,Valor) (Valor)?Puerto->PORT|=(uint8_t)(0x1<<Pin):Puerto->PORT&=~((uint8_t)(0x1<<Pin))
 #define PINMODE(Pin,Puerto,Modo)     (Modo)?Puerto->DDR|=(uint8_t)(0x1<<Pin):Puerto->DDR&=~((uint8_t)(0x1<<Pin))
 #define TRUE                          ((bool)1)
 #define FALSE                         ((bool)0)
 #define ANALOGWRITEA2(value)          TIMER_2->OCRA|=(uint8_t)map(value,0,254,254,1)
 #define ANALOGWRITEB2(value)          TIMER_2->OCRB|=(uint8_t)map(value,0,254,254,1)
 #define ANALOGWRITEA0(value)          TIMER_0->OCRA|=(uint8_t)map(value,0,254,128,1)
 #define Servo_Write(Angulo)           OCR1A=(uint16_t)((long)-22.2*(long)Angulo+38300L)
 enum PRESCALAR{DIV_1=(uint8_t)0x1,DIV_8,DIV_64,DIV_256,DIV_1024};
 enum MODE{OVERFLOW=0x1<<0,OCIEA=0x1<<1,OCIEB=0x1<<2};
 enum ACsR{AC1C=0x4,AC1E,AC1,AC0,ACB6,ACd};
 enum INTERRUPt_MODE{TOGGLE,RESERVE,FALL1NG,R1S1NG};
 enum ADCsRB{ADIs0,ADCIs1,ADTs2,ACmE=0x6};
 enum ADCsRA{ADPSO,ADPSI,ADPSS,AD1E,AD1F,ADAT3,ADSc,ADEn};

 /*---------------------------|prototipos de funcion|--------------------*/

 extern void fnvInit_Pwm0(void);
 extern void fnvInit_Pwm2(void);
 extern void fnvServo_Init(void);
 //extern void fnvServo_Write(long Angulo);
 extern void fnvComp_Init(void);
/*---------------------------|variables|---------------------------------*/


#endif /* PERIFERICOS_H_*/