#include"calc.h"
int std[24][4];/*x1,y1,x2,y2*/
int sci[57][4];
int mode=0;
void clearscreen()
{
	setfillstyle(SOLID_FILL,YELLOW);
	bar(150,60,480,90);
}
void initkeyxy(void)
{
 int i,j,k;
 	 int a=150, b=105, c=295;
 	 for(i=0;i<5;i++) {                            /*std 按键第一行*/
		 std[i][0]=a+i*70;
		 std[i][2]=a+i*70+50;
		 std[i][1]=b;
		 std[i][3]=b+30;}

     for(i=5;i<10;i++){                           /*std 按键第二行*/
		 std[i][0]=a+(i-5)*70;
		 std[i][2]=a+(i-5)*70+50;
		 std[i][1]=b+45;
		 std[i][3]=b+45+30;}

	 for(i=10;i<15;i++){                            /*std 按键第三行*/
		 std[i][0]=a+(i-10)*70;
		 std[i][2]=a+(i-10)*70+50;
		 std[i][1]=b+90;
		 std[i][3]=b+90+30;}

	 for(i=15;i<20;i++){                            /*std 按键第四行*/
		 std[i][0]=a+(i-15)*70;
		 std[i][2]=a+(i-15)*70+50;
		 std[i][1]=b+135;
		 std[i][3]=b+135+30;}

	 std[20][0]=120;std[20][2]=550;std[20][1]=315;std[20][3]=345;	/*sci*/
	 std[21][0]=120;std[21][2]=550;std[21][1]=350;std[21][3]=380;	/*数据统计*/
	 std[22][0]=120;std[22][2]=550;std[22][1]=385;std[22][3]=415;	/*高精度*/
	 std[23][0]=120;std[23][2]=550;std[23][1]=420;std[23][3]=470;	/*help*/

	 for(i=0;i<5;i++){                             /*sci 按键第一行*/
		 sci[i][0]=a+i*70;
		 sci[i][2]=a+i*70+50;
		 sci[i][1]=b;
		 sci[i][3]=b+30;}

     for(i=5;i<10;i++){                           /*sci 按键第二行*/
		 sci[i][0]=a+(i-5)*70;
		 sci[i][2]=a+(i-5)*70+50;
		 sci[i][1]=b+45;
		 sci[i][3]=b+45+30;}

	 for(i=10;i<15;i++){                            /*sci 按键第三行*/
		 sci[i][0]=a+(i-10)*70;
		 sci[i][2]=a+(i-10)*70+50;
		 sci[i][1]=b+90;
		 sci[i][3]=b+90+30;}

	 for(i=15;i<20;i++){                            /*sci 按键第四行*/
		 sci[i][0]=a+(i-15)*70;
		 sci[i][2]=a+(i-15)*70+50;
		 sci[i][1]=b+135;
		 sci[i][3]=b+135+30;}

	 for(i=20;i<27;i++){                           /*sci 按键第五行*/
         sci[i][0]=a+(i-20)*50;
         sci[i][2]=a+(i-20)*50+35;
         sci[i][1]=c;
         sci[i][3]=c+24;}

     for(i=27;i<34;i++){                            /*sci 按键第六行*/
         sci[i][0]=a+(i-27)*50;
         sci[i][2]=a+(i-27)*50+35;
         sci[i][1]=c+30;
         sci[i][3]=c+24+30;}

     for(i=34;i<41;i++){                            /*sci 按键第七行*/
         sci[i][0]=a+(i-34)*50;
         sci[i][2]=a+(i-34)*50+35;
         sci[i][1]=c+60;
         sci[i][3]=c+24+60;}

     for(i=41;i<48;i++){                             /*sci 按键第八行*/
         sci[i][0]=a+(i-41)*50;
         sci[i][2]=a+(i-41)*50+35;
         sci[i][1]=c+90;
         sci[i][3]=c+24+90;}

	     sci[48][0]=520;                          /*sci 右部按键*/
         sci[48][2]=605;
         sci[48][1]=60;
         sci[48][3]=90;

	 for(i=49;i<53;i++){
	     sci[i][0]=520;
         sci[i][2]=580;
         sci[i][1]=b+(i-49)*45;
         sci[i][3]=b+(i-49)*45+30;}

	 for(i=53;i<55;i++){
	     sci[i][0]=520;
         sci[i][2]=580;
         sci[i][1]=c+(i-53)*45;
         sci[i][3]=c+(i-53)*45+30;}

	sci[55][0]=120;sci[55][2]=410;sci[55][1]=430;sci[55][3]=470;
    sci[56][0]=430;sci[56][2]=500;sci[56][1]=430;sci[56][3]=470;
}
int returnstdkey(int xx, int yy)                    /*形参为鼠标位置*/
{

	 int i,j,k;
	 int index=-1;



	 for(i=0;i<24;i++)                              /*确定鼠标位置对应的按键*/
	     if(xx>std[i][0]&&xx<std[i][2]&&yy>std[i][1]&&yy<std[i][3])
		     {index=i;
			  break;
              }

	 return index;
}

int returnscikey(int xx, int yy)
{
	 int i,j,k;
	 int index=-1;



	 for(i=0;i<57;i++)                              /*确定鼠标位置对应的按键*/
	     if(xx>sci[i][0]&&xx<sci[i][2]&&yy>sci[i][1]&&yy<sci[i][3])
		     {index=i;
			  break;
			  }
	 return index;
}

void bottondown(int x1,int x2,int y1,int y2)
{
	setcolor(DARKGRAY);
	line(x1,y1,x2,y1);
	line(x2,y1,x2,y2);
	setcolor(WHITE);
	line(x1,y1,x1,y2);
	line(x1,y2,x2,y2);
}
void bottonup(int x1,int x2,int y1,int y2)
{
	setcolor(DARKGRAY);
	line(x1,y1,x1,y2);
	line(x1,y2,x2,y2);
	setcolor(WHITE);
	line(x1,y1,x2,y1);
	line(x2,y1,x2,y2);
	setcolor(BLACK);
}
void show(int x1,int x2,int y1,int y2)
{
	bottondown(x1,x2,y1,y2);    /* 显示按钮的按下状态 */
	delay(500000);         /* 延时 */
	bottonup(x1,x2,y1,y2);       /* 显示按钮的弹起状态 */
}
int checknum(int d,int k)/*k=0,std;k=1,sci*/
{
	 switch(d)
	 {
	   case 0:return 7;
	   case 1:return 8;
	   case 2:return 9;
	   case 5:return 4;
	   case 6:return 5;
	   case 7:return 6;
	   case 10:return 1;
	   case 11:return 2;
	   case 12:return 3;
	   case 15:return 0;
	  }
	 if(k) {if(d==3) return 10; if (d==19) return 11;}
	 return -1;
}
void outch(double sum)
{
	int i=0,m=0,j=0,fig;
	char FIG[8];
	char temp[2]="";
	long int xu;

	if(sum>1e20||sum<-1e20)      /* sum绝对值大于1e20,输出E */
		{clearscreen();outtextxy(OUTX-10,OUTY,"Err");}
	else if(sum>=1e8)            /* sum小于等于1e20且大于等于1e8的处理 */
	{
		clearscreen();
		while(sum>100&&j<20)
		{
				sum/=10;
				j++;
		}
		j++;
		FIG[0]=((int)sum)%10+'0';
		FIG[1]=floor(sum/10)+'0';
		if(j<=9) {
			FIG[2]=j+'0';
			temp[0] = FIG[2];
			outtextxy(OUTX,OUTY,temp);
			outtextxy(OUTX-10,OUTY,"E");
			temp[0] = FIG[0];
			outtextxy(OUTX-30,OUTY,temp);
			outtextxy(OUTX-45,OUTY,".");
			temp[0]=FIG[1];
			outtextxy(OUTX-60,OUTY,temp);
		}
		else {
			FIG[2]=j%10+'0';
			FIG[3]=floor(j/10)+'0';
			temp[0]=FIG[2];
			outtextxy(OUTX,OUTY,temp);
			temp[0]=FIG[3];
			outtextxy(OUTX-15,OUTY,temp);
			outtextxy(OUTX-30,OUTY,"E");
			temp[0]=FIG[0];
			outtextxy(OUTX-45,OUTY,temp);
			outtextxy(OUTX-60,OUTY,".");
			temp[0]=FIG[1];
			outtextxy(360,OUTY,temp);
		}
	}
	else if(sum<=-1e8)      /* sum大于等于-1e20且小于等于-1e8的处理 */
	{
		outch(-sum);
		outtextxy(OUTX-90,OUTY,"-");
	}
	else                          /* 此时sum的值在-1e8和1e8之间 */
	{
		if(-1e-6<sum&&sum<1e-6)     /* sum值是0的处理 */
		{
			clearscreen();
			outtextxy(OUTX-15,OUTY,"0");
			outtextxy(OUTX,OUTY,".");
		}
		if(sum>1e-6)               /* sum值大于0的处理(小于1e8) */
		{
			while(floor(sum)!=sum && sum<1e7 && m<8)
			{
				sum*=10;
				m++;
			}
			xu=floor(sum);
			while(xu!=0)
			{
				FIG[i++]=xu%10+'0';
				xu=floor(xu/10);
			}
			clearscreen();
			if(m==0)
			{
				for(fig=0;fig<i;fig++)
				{
					temp[0]=FIG[fig];
					outtextxy(OUTX-15*(fig+1),OUTY,temp);
				}
				outtextxy(OUTX,OUTY,".");
			}
			if(m<i)
			{
				for(fig=0;fig<m;fig++)
				{
					temp[0]=FIG[fig];
					outtextxy(OUTX-15*fig,OUTY,temp);
				}
				outtextxy(OUTX-15*m,OUTY,".");
				for(fig=m;fig<i;fig++)
				{
					temp[0]=FIG[fig];
					outtextxy(OUTX-15*(fig+1),OUTY,temp);
				}
			}
			if(m>=i)
			{
				for(fig=0;fig<i;fig++)
				{
					temp[0]=FIG[fig];
					outtextxy(OUTX-15*fig,OUTY,temp);
				}
				outtextxy(OUTX-15*m,OUTY,".");
				outtextxy(OUTX-15*(m+1),OUTY,"0");
				for(fig=i;fig<m;fig++)
					outtextxy(OUTX-15*fig,OUTY,"0");
			}
		}
		if(sum<-1e-6)       /* sum值小于0的处理(大于-1e8) */
		{
			sum=-sum;
			while(floor(sum)!=sum && m<8 && sum<1e7)
			{
				sum*=10;
				m++;
			}
			xu=(long int)sum;
			while(xu!=0)
			{
				FIG[i++]=xu%10+'0';
				xu=floor(xu/10);
			}
			clearscreen();
			if(m==0)
			{
				for(fig=0;fig<i;fig++)
				{
					temp[0]=FIG[fig];
					outtextxy(OUTX-15*(fig+1),OUTY,temp);
				}
				outtextxy(OUTX,OUTY,".");
				outtextxy(OUTX-15*(i+1),OUTY,"-");
			}
			if(m<i)
			{
				for(fig=0;fig<m;fig++)
				{
					temp[0]=FIG[fig];
					outtextxy(OUTX-15*fig,OUTY,temp);
				}
				outtextxy(OUTX-15*m,OUTY,".");
				for(fig=m;fig<i;fig++)
				{
					temp[0]=FIG[fig];
					outtextxy(OUTX-15*(fig+1),OUTY,temp);
				}
				outtextxy(OUTX-15*(fig+1),OUTY,"-");
			}
			if(m>=i)
			{
				for(fig=0;fig<i;fig++)
				{
					temp[0]=FIG[fig];
					outtextxy(OUTX-15*fig,OUTY,temp);
				}
				outtextxy(OUTX-15*m,OUTY,".");
				outtextxy(OUTX-15*(m+1),OUTY,"0");
				for(fig=i;fig<m;fig++)
					outtextxy(OUTX-15*fig,OUTY,"0");
				outtextxy(OUTX-15*(m+2),OUTY,"-");
			}
		}
	}
}
char itoc(int d)
{
  switch(d)
  {
  case 0: return '0';
  case 1: return '1';
  case 2: return '2';
  case 3: return '3';
  case 4: return '4';
  case 5: return '5';
  case 6: return '6';
  case 7: return '7';
  case 8: return '8';
  case 9: return '9';
  }
 }
int checknumsci(int index, int k)
{

     if(k>=-1&&k<=5)
	 {
	     switch(k){
		     case 1:{
			 if(index>=0&&index<=19||index>=26&&index<=31||index>=34&&index<=36||index>=41&&index<=48||index>=53&&index<=54)
			     return index;
			 else return -1;
			 }
			 case 0:{
			 if(index>=0&&index<=19||index>=26&&index<=31||index>=34&&index<=36||index>=41&&index<=48||index>=53&&index<=54)
			     return index;
		     
			 else return -1;
			 }
			 case 2:{
			 if(index==4||index>=0&&index<=2||index>=5&&index<=7||index>=10&&index<=12||index==15||index==32||index==33||index>=37&&index<=40||index>=47&&index<=52)
			     return index;
			 else return -1;
			 }

			 case 3:{
			 if(index==4||index==10||index==15||index>=37&&index<=40||index==32||index==33||index>=47&&index<=52)
			     return index;
			 else return -1;
			 }
			 case 4:{
			 if(index==4||index==0||index>=5&&index<=7||index>=10&&index<=12||index==32||index==33||index==15||index>=37&&index<=40||index>=47&&index<=52)
			     return index;
			 else return -1;
			 }
			 case 5:{
			 if(index==4||index>=0&&index<=2||index>=5&&index<=7||index>=10&&index<=12||index==15||index==32||index==33||index>=20&&index<=25||index>=37&&index<=40||index>=47&&index<=52)
			     return index;
			 else return -1;
			 default: break;
			 
			 }
		     }
	 }
}
void string(char *str,int d)
{


    switch(d){
	    case 10:str[pointj++]='1';break;
        case 11:str[pointj++]='2';break;
        case 12:str[pointj++]='3';break;
        case 5:str[pointj++]='4';break;
        case 6:str[pointj++]='5';break;
        case 7:str[pointj++]='6';break;
        case 0:str[pointj++]='7';break;
        case 1:str[pointj++]='8';break;
        case 2:str[pointj++]='9';break;
        case 15:str[pointj++]='0';break;
		case 3:{str[pointj++]='2';str[pointj++]='.';str[pointj++]='7';str[pointj++]='1';str[pointj++]='8';str[pointj++]='2';str[pointj++]='8';str[pointj++]='1';str[pointj++]='8';str[pointj++]='2';str[pointj++]='8';str[pointj++]='4';str[pointj++]='5';str[pointj++]='9';break;}
		
		case 18:if(pointj==0) {sprintf(str,"%lf",ans); pointj=strlen(str);} str[pointj++]='+';break;
        case 13:if(pointj==0) {sprintf(str,"%lf",ans); pointj=strlen(str);} str[pointj++]='-';break;
        case 8:if(pointj==0) {sprintf(str,"%lf",ans); pointj=strlen(str);} str[pointj++]='*';break;
        case 14:if(pointj==0) {sprintf(str,"%lf",ans); pointj=strlen(str);} str[pointj++]='/';break;
        case 17:str[pointj++]='.';break;
		case 19:{str[pointj++]='3';str[pointj++]='.';str[pointj++]='1';str[pointj++]='4';str[pointj++]='1';str[pointj++]='5';str[pointj++]='9';str[pointj++]='2';str[pointj++]='6';str[pointj++]='5';break;}
		case 20:str[pointj++]='A';break;
		case 21:str[pointj++]='B';break;
		case 22:str[pointj++]='C';break;
		case 23:str[pointj++]='D';break;
		case 24:str[pointj++]='E';break;
		case 25:str[pointj++]='F';break;
		case 31:str[pointj++]='%';break;
		
		case 43:str[pointj++]='^';break;
        case 45:str[pointj++]='(';break;
        case 46:str[pointj++]=')';break;
		default:break;
    }

     str[pointj]='\0';


return ;
}
