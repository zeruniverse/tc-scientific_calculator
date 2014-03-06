#include"calc.h"
int  MouseLeftFlag=0; /*flag of pressing the left key of the mouse*/


void initmouse() /*install mouse*/
{
	union REGS ireg,oreg;
	int ret;
	ireg.x.ax=0;               
	int86(0x33,&ireg,&oreg);  
	ret=oreg.x.ax;
	if(ret!=-1)                 /*mouse error*/
	{
		printf("Mouse error.");
		exit(1);
	}
}

void get_mouse_position(int *x,int *y)/*get mouse position*/
{
	union REGS ireg,oreg;
	ireg.x.ax=3;                   
	int86(0x33,&ireg,&oreg); 
	*x=oreg.x.cx;                 
	*y=oreg.x.dx;                
}

int leftpress() /*check the left press*/
{
	union REGS ireg,oreg;
	ireg.x.ax=3;                 
	int86(0x33,&ireg,&oreg);
	delay(30000);               
	if(oreg.x.bx&1)             
	    MouseLeftFlag=1;
	return oreg.x.bx&1; 
}

int rightpress() /*check for the right press*/
{
	union REGS ireg,oreg;
	ireg.x.ax=3;                
	int86(0x33,&ireg,&oreg);
	return oreg.x.bx&2?1:0;
}

