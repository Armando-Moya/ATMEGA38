#ifndef CONTROL_H_
#define CONTROL_H_
#include <estandar.h>
/*-------------|define,typedef y enum |-----------*/
class EMA
{
private:
uint8_t baZ[2];
double Alfa;
public:
EMA(double Alfap);
EMA(double Alfap, uint8_t bZp);
uint8_t fnbFilter(uint8_t bSensor);
}; 

#define ABS(x) (x)>0?(x):-(x)
#define MS(x) x/1000
#define US(x) x/1000000
#define ZERO    ((uint8_t)0x0)

#endif  /* CONTROL_*/
