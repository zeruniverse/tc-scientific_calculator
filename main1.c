#include"calc.h"
void main(void)
{
  initkeyxy();   
  begin();  
  initmouse();
  while (mode>=0)
  {
  if(mode==0) stdcalc();
  if(mode==1) scicalc();
  if(mode==2) stad();
  if(mode==3) highcalc();
  if(mode==4) help();
  if(mode==5) basen();
  }
  
 closegraph();
 }
