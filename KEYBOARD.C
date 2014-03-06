#define ESC 0x011b
#define F1 0x3b00
#define ENTER 0x1c0d

#define ONE 0x0231   /*主键盘数字*/
#define TWO 0x0332
#define THREE 0x0433
#define FOUR 0x0534
#define FIVE 0x0635
#define SIX 0x0736
#define SEVEN 0x0837
#define EIGHT 0x0938
#define NINE 0x0a39
#define ZERO 0x0b30

#define ONES 0x4f31  /*小键盘数字*/
#define TWOS 0x5032
#define THREES 0x5133
#define FOURS 0x4b34
#define FIVES 0x4c35
#define SIXS 0x4d36
#define SEVENS 0x4737
#define EIGHTS 0x4838
#define NINES 0x4939
#define ZEROS 0x5230

#define PLUS 0x0d2b   /*主键盘运算符号*/
#define MINUS 0x0c2d
#define MULT 0x0c2a
#define DIVI 0x352f
#define POWER 0x075e  /*次方*/
#define DOT 0x342e    /*小数点*/
#define EQUAL 0x0d3d
#define LBRACKEY 0x0a28    /*左右括号*/
#define RBRACKEY 0x0b29

#define PLUSS 0x4e2b  /*小键盘运算符号*/
#define MINUSS 0x4a2d
#define MULTS 0x372a
#define DIVIS 0x352f

#define UPA 0x1e41  /*ABCDEF键*/
#define UPB 0x3042
#define UPC 0x2e43
#define UPD 0x2044
#define UPE 0x1245
#define UPF 0x2247

#include"calc.h"

int pointj=0;
int stdgetKey(int key){

int d=-1;


switch(key){

case (0x0231):d=10;break;
case TWO:d=11;break;
case THREE:d=12;break;
case FOUR:d=5;break;
case FIVE:d=6;break;
case SIX:d=7;break;
case SEVEN:d=0;break;
case EIGHT:d=1;break;
case NINE:d=2;break;
case ZERO:d=15;break;

case ONES:d=10;break;
case TWOS:d=11;break;
case THREES:d=12;break;
case FOURS:d=5;break;
case FIVES:d=6;break;
case SIXS:d=7;break;
case SEVENS:d=0;break;
case EIGHTS:d=1;break;
case NINES:d=2;break;
case ZEROS:d=15;break;

case PLUS: d=18;break;
case MINUS: d=13;break;
case MULT: d=8;break;
case DIVI:d=14;break;
case DOT:d=17;break;


case PLUSS: d=18;break;
case MINUSS:d=13;break;
case MULTS:d=8;break;


case ENTER: d=19;break;
case EQUAL: d=19;break;
}
return d;
} 

int scigetKey(int key){

int d=-1;


switch(key){

case ONE:d=10;break;
case TWO:d=11;break;
case THREE:d=12;break;
case FOUR:d=5;break;
case FIVE:d=6;break;
case SIX:d=7;break;
case SEVEN:d=0;break;
case EIGHT:d=1;break;
case NINE:d=2;break;
case ZERO:d=15;break;

case ONES:d=10;break;
case TWOS:d=11;break;
case THREES:d=12;break;
case FOURS:d=5;break;
case FIVES:d=6;break;
case SIXS:d=7;break;
case SEVENS:d=0;break;
case EIGHTS:d=1;break;
case NINES:d=2;break;
case ZEROS:d=15;break;

case PLUS: d=18;break;
case MINUS: d=13;break;
case MULT: d=8;break;
case DIVI:d=14;break;
case DOT:d=17;break;

case POWER:d=43;break;
case LBRACKEY:d=45;break;
case RBRACKEY:d=46;break;

case PLUSS: d=18;break;
case MINUSS:d=13;break;
case MULTS:d=8;break;


case UPA:d=20;break;
case UPB:d=21;break;
case UPC:d=22;break;
case UPD:d=23;break;
case UPE:d=24;break;
case UPF:d=25;break;

case ENTER: d=47;break;
case EQUAL: d=47;break;
}
return d;
} 


