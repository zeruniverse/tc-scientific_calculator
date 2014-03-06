#include "calc.h"
int checkbase(int p)
{
   switch(p)
   {
     case 2:return 10;
	 case 3:return 2;
	 case 4:return 8;
	 case 5:return 16;
	}
}
char switchtoch(int a)
{
  switch(a)
  {
    case 0:return '0';
    case 1:return '1';
	case 2:return '2';
	case 3:return '3';
	case 4:return '4';
	case 5:return '5';
	case 6:return '6';
	case 7:return '7';
	case 8:return '8';
	case 9:return '9';
	case 10:return 'A';
	case 11:return 'B';
	case 12:return 'C';
	case 13:return 'D';
	case 14:return 'E';
	case 15:return 'F';
   }
}	
 int divided(char *a,int k,unsigned int p)
{
  int u;
  if (p==0) return 0;
  u=divided(a,k,p/k);
  a[u]=switchtoch(p%k);
  return u+1;
 }
char *changetobase_n(unsigned int p,int k)/*10进制p转化为k进制数*/
{   
 char a[50];unsigned int t;
 t=divided(a,k,p);
 a[t]='\0';
 return a;
 }
int switchtoint(char a)
{
  switch(a)
  {
    case '0':return 0;
    case '1':return 1;
	case '2':return 2;
	case '3':return 3;
	case '4':return 4;
	case '5':return 5;
	case '6':return 6;
	case '7':return 7;
	case '8':return 8;
	case '9':return 9;
	case 'A':return 10;
	case 'B':return 11;
	case 'C':return 12;
	case 'D':return 13;
	case 'E':return 14;
	case 'F':return 15;
   }
}

	
	
unsigned int changetoten(char *a,int k) 
{
  unsigned int l,u=0;
  int i;
  if (pointj==0) return 0;
  l=pointj;
  for(i=l-1;i>=0;i--)
  {
    u+=(pow(k,l-1-i)*switchtoint(a[i]));
   }
  return u;
}
void basen()
{
     int     d,dn;                /* 当前单击的按钮标签 */
     int     x,y;  /* (x,y)鼠标当前位置 (xx,yy)鼠标前一位置 */
     int     pn=0;                 /* 当前键盘输入的标签 */
     char    strbase[50];
	unsigned int     h,h1;
	 int     flag=47,i=0;
  	 clearscreen();
     pointj=0;
  	 sciswitch();
	 outtextxy(OUTX-15,OUTY,"0");
     while(1)    /* 单击右键则退出简单计算器 */
     {    
         if (bioskey(1)!=0)
            pn=bioskey(0);
         if(rightpress()==1||pn==0x011b)
	     {mode=-1;return;}


    	 if(leftpress()!=1 && pn==0)    /* 鼠标左键未单击的处理 */
    	 {
           move_mouse();
    	 }
    	 else if(MouseLeftFlag==1||pn!=0)  /* 鼠标左键单击的处理 */
    	 {
    	     if(MouseLeftFlag==1){
			 MouseLeftFlag=0;   /* 置标志为0，防止单击1次左键而多次进入 */ 
             get_mouse_position(&x,&y);
             d=returnscikey(x,y); /* 得到单击按钮的标签 */
			 }
			 else {
			 d=scigetKey(pn);
			 pn=0;
			 }
			  if(d==55||d==56){
                if(d==55) {mode=0; switchk=0;}           
                if(d==56) {mode=4; switchk=0;}   
			 return;} 
			 d=checknumsci(d,switchk);
		     if(d==-1) continue;
 
             show(sci[d][0],sci[d][2],sci[d][1],sci[d][3]);
			 if(d==4)         /* 单击C */
    	     {
    	        clearscreen();
    	        pointj=0;
				flag=47;
    	        outtextxy(OUTX-15,OUTY,"0");
				continue;
			 } 
			 
			 if(d==48){
                   switchk=0;mode=1;
                   return;
                      }    
			if(d==49){ 
						  clearscreen();
			        if(pointj==0) {outtextxy(OUTX-15,OUTY,"0");switchk=3;sciswitch();clearscreen(); continue;}
			        h=changetoten(strbase,checkbase(switchk));
			        switchk=3;sciswitch();clearscreen(); 	 					
         			strcpy(strbase,changetobase_n(h,checkbase(switchk)));
					pointj=strlen(strbase);
					if(pointj+1<=18){
                     outtextxy(OUTX-7*(18-i)-140,OUTY,strbase);
                   } else outtextxy(OUTX-7*(18-i)-140,OUTY,"Not enough space");
				   continue; }
		    if(d==50){ 
						        clearscreen();
			        if(pointj==0) {outtextxy(OUTX-15,OUTY,"0");switchk=4;sciswitch();clearscreen(); continue;}
			        h=changetoten(strbase,checkbase(switchk));
			        switchk=4;sciswitch();clearscreen(); 	 					
         			strcpy(strbase,changetobase_n(h,checkbase(switchk)));
					pointj=strlen(strbase);
					if(pointj+1<=18){
                     outtextxy(OUTX-7*(18-i)-140,OUTY,strbase);
                   } else outtextxy(OUTX-7*(18-i)-140,OUTY,"Not enough space");
				   continue;}
		    if(d==51){ 
				    clearscreen();
			        if(pointj==0) {outtextxy(OUTX-15,OUTY,"0");switchk=2;sciswitch();clearscreen(); continue;}
			        h=changetoten(strbase,checkbase(switchk));
			        switchk=2;sciswitch();clearscreen(); 	 					
         			strcpy(strbase,changetobase_n(h,checkbase(switchk)));
					pointj=strlen(strbase);
					if(pointj+1<=18){
                     outtextxy(OUTX-7*(18-i)-140,OUTY,strbase);
                   } else outtextxy(OUTX-7*(18-i)-140,OUTY,"Not enough space");
				   continue;}
		    if(d==52){ 
			        clearscreen();
			        if(pointj==0) {outtextxy(OUTX-15,OUTY,"0");switchk=5;sciswitch();clearscreen();continue;}
			        h=changetoten(strbase,checkbase(switchk));
			        switchk=5;sciswitch();clearscreen(); 	 					
         			strcpy(strbase,changetobase_n(h,checkbase(switchk)));
					pointj=strlen(strbase);
					if(pointj+1<=18){
                     outtextxy(OUTX-7*(18-i)-140,OUTY,strbase);
                   } else outtextxy(OUTX-7*(18-i)-140,OUTY,"Not enough space");
				   continue;}				   
		     if(d!=32&&d!=33&&d!=37&&d!=38&&d!=39&&d!=40&&d!=47) {
			 string(strbase,d);
			 clearscreen();
			 if(pointj+1<=18){
                     outtextxy(OUTX-7*(18-i)-140,OUTY,strbase);
                   } else outtextxy(OUTX-7*(18-i)-140,OUTY,"Not enough space");
				   continue;
			}
			 if(d==39) {
			 h=changetoten(strbase,checkbase(switchk));clearscreen();h=calcbase(h,0,39);
			 strcpy(strbase,changetobase_n(h,checkbase(switchk)));
			 pointj=strlen(strbase);
			 if(pointj+1<=18){
                     outtextxy(OUTX-7*(18-i)-140,OUTY,strbase);
                   } else outtextxy(OUTX-7*(18-i)-140,OUTY,"Not enough space");
			pointj=0;strbase[0]='\0';	 	   continue;
			}
			 if(flag==47) {
			 if(d==47) continue;
			 flag=d;h=changetoten(strbase,checkbase(switchk));clearscreen();
			 if(pointj+1<=18){
                     outtextxy(OUTX-7*(18-i)-140,OUTY,strbase);
                   } else outtextxy(OUTX-7*(18-i)-140,OUTY,"Not enough space");
			pointj=0;strbase[0]='\0';	 			 
			 continue;}
			 h1=changetoten(strbase,checkbase(switchk));clearscreen();h=calcbase(h,h1,flag);strcpy(strbase,changetobase_n(h,checkbase(switchk)));
			 pointj=strlen(strbase);
			 if(pointj+1<=18){
                     outtextxy(OUTX-7*(18-i)-140,OUTY,strbase);
                   } else outtextxy(OUTX-7*(18-i)-140,OUTY,"Not enough space");
			 pointj=0;strbase[0]='\0';	   flag=d;
	   }
	   }
	 
 }