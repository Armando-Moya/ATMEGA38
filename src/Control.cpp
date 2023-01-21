#include <Control.h>

/*---------------------------|filtro EMA|--------------------*/
 EMA::EMA(double Alfap)/*|initialize the values of baz and Alfa|*/
 {
  this->baZ[ZERO]=ZERO;/*|initialize the valua as zero|*/
  this->Alfa=Alfap;/*|Alfa is same to Alfap|*/
 } 

 EMA::EMA(double Alfap,uint8_t bZp)/*|initialize the values of baz and Alfa|*/
 {
  this->baZ[ZERO]=bZp;/*|initialize baz as bzp |*/
  this->Alfa=Alfap;/*|initialize Alfa as Alfap|*/
 }


 uint8_t EMA::fnbFilter(uint8_t bSensor)/*|this function is used to aplicated the difference equations|*/
 {
   this->baZ[1]=(bSensor*this->Alfa)+(1-this->Alfa)*(this->baZ[0]);
   this->baZ[ZERO]=this->baZ[1];
   return this->baZ[1];
 }