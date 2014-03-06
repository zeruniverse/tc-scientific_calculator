#include"calc.h"
double dreg(double k)
{
  double p;
  p=k;
  if (switchk==0)  p=k/180.0000000*3.14159265359;
  return p;
 }
double calculate(double u,double v,int sign)
{
  switch(sign)
  {
    case 8:return u*v;
    case 13:return u-v;
    case 14:return u/v;
    case 18:return u+v;
  }
}
unsigned int calcbase(unsigned int a,unsigned int b,int sign)
{
   switch(sign)
   {
     case 37:return a&b;
	 case 38:return a|b;
	 case 40:return a^b;
	 case 32:return a<<b;
	 case 33:return a>>b;
	 case 39:return ~a;
	}
}
