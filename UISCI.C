#include"calc.h"
double     ans=0;                /*上一次计算的答案*/
int switchk=0;
void scigra()
{


	int i,j,k=0;
	int a=150,b=105,c=295;
	unsigned long gsize;

/*计算器按钮标签文本字符 */
	char str[][5]={"1","2","3","-","/","4","5","6","*","Sqrt","7","8","9","e","C"};
	char temp[6]="";



	cleardevice();

	setbkcolor(BLACK);
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	bar3d(130,45,500,420,10,1);        /* 计算器外框 */
	setcolor(DARKGRAY);
	line(150,60,150,90);
	line(150,90,480,90);
	setcolor(WHITE);
	line(150,60,480,60);
	line(480,60,480,90);
	setfillstyle(SOLID_FILL,YELLOW);
	bar(150,60,480,90);            /* 绘制信息显示框 */
	setfillstyle(SOLID_FILL,LIGHTGRAY);

	for(i=0;i<5;i++)                /* 绘制计算器上部按钮框 */
	     for(j=0;j<4;j++)
		  {
		      bar(a+i*70,b+j*45,a+50+i*70,b+30+j*45);
		      bottonup(a+i*70,a+i*70+50,b+j*45,b+j*45+30);
		  }



	   bar(120,430,410,470);
	   bottonup(120,410,430,470);
       settextstyle(1,0,3);
       setcolor(RED);
       outtextxy(123,438,"Switch to standard mode.");
	   bar(430,430,500,470);
	   bottonup(430,500,430,470);
	   settextstyle(1,0,3);
       setcolor(RED);
	   outtextxy(433,438,"HELP");
	   settextstyle(1,0,3);
       setcolor(YELLOW);
	   outtextxy(260,10,"scientific mode");
       settextstyle(1,0,2);
       setcolor(RED);
       for(j=0;j<3;j++)
	   for(i=0;i<5;i++)        /* 显示计算器前三排按钮标签 */
	   {
		     strcpy(temp,str[k++]);
			 if (temp[0]=='S') {outtextxy(a+6+70*i,200-j*45,temp);continue;}
			 if (temp[0]=='1') {outtextxy(a+10+70*i,200-j*45,temp);continue;}
		     outtextxy(a+17+70*i,200-j*45,temp);
	   }
       outtextxy(167,245,"0"); /* 显示计算器第四排排按钮标签 */
       outtextxy(377,245,"+");
       outtextxy(447,245,"PI");
       settextstyle(1,0,3);
       outtextxy(310,235,".");
       settextstyle(1,0,2);
       outtextxy(228,243,"+");
       outtextxy(237,246,"/");
       outtextxy(246,250,"-");
       setcolor(BLACK);

	   for(i=0;i<7;i++)                /* 绘制计算器下部按钮框 */
	     for(j=0;j<4;j++)
		  {
		      bar(a+i*50,c+j*35,a+35+i*50,c+24+j*30);
		      bottonup(a+i*50,a+i*50+35,c+j*30,c+j*30+24);
		  }

	   settextstyle(1,0,1);               /*输出下部第一行*/
	   setcolor(RED);
	   outtextxy(a+8,c,"A");
	   outtextxy(a+8+50,c,"B");
	   outtextxy(a+8+100,c,"C");
	   outtextxy(a+8+150,c,"D");
	   outtextxy(a+8+200,c,"E");
	   outtextxy(a+8+250,c,"F");
	   outtextxy(a+300,c,"Ans");

	   outtextxy(a+2,c+30,"sin");        /*下部第二行*/
	   outtextxy(a+2+50,c+30,"cos");
	   outtextxy(a+2+100,c+30,"tan");
	   outtextxy(a+8+150,c+30,"[ ]");
	   outtextxy(a+8+200,c+30,"%");
	   outtextxy(a+8+250,c+30,"<");
	   outtextxy(a+8+300,c+30,">");

	   outtextxy(a+2,c+60,"log");        /*下部第三行*/
	   outtextxy(a+5+50,c+60,"ln");
	   outtextxy(a+7+100,c+60,"n!");
	   outtextxy(a+2+150,c+60,"and");
	   outtextxy(a+8+200,c+60,"or");
	   outtextxy(a+4+250,c+60,"not");
	   outtextxy(a+3+300,c+60,"xor");
	   
	   outtextxy(a+2,c+90,"1/x");        /*下部第四行*/
	   outtextxy(a+2+50,c+90,"x^2");
	   outtextxy(a+2+100,c+90,"x^y");
	   outtextxy(a+5+150,c+90,"x^3");
	   outtextxy(a+4+200,c+90," ( ");
	   outtextxy(a+4+250,c+90," ) ");
	   outtextxy(a+3+300,c+90," = ");
	   
	   for(j=0;j<4;j++)                /* 绘制计算器右部按钮框 */
	     {
		      bar(520,b+j*45,580,b+30+j*45);
		      bottonup(520,580,b+j*45,b+j*45+30);
	     }
	   for(j=0;j<2;j++)               
	     {
		      bar(520,c+j*45,580,c+30+j*45);
		      bottonup(520,580,c+j*45,c+j*45+30);
	     }
		 
	   bar(520,60,605,90);
	   bottonup(520,605,60,90);
		 
	   settextstyle(1,0,2);               /*输出右部*/
	   setcolor(RED);
	   outtextxy(525,65,"BASE-N");
	   outtextxy(525,b+5,"2");
	   outtextxy(525,b+5+45,"8");
	   outtextxy(525,b+5+90,"10");
	   outtextxy(525,b+5+135,"16");
	   
	   outtextxy(525,c+5,"DEG");
	   outtextxy(525,c+5+45,"REG");
	   for(i=5;i<7;i++)                
		         {
		             bottondark(a+i*50,a+i*50+35,c+1*30,c+1*30+24);
		         } 
	   
}
void bottondark(int x1,int x2,int y1,int y2)
{
    setcolor(DARKGRAY);
	line(x1,y1,x1,y2);
	line(x1,y2,x2,y2);
	setcolor(WHITE);
	line(x1,y1,x2,y1);
	line(x2,y1,x2,y2);
	setcolor(BLACK);
	
	setfillstyle(SOLID_FILL,DARKGRAY);
	bar(x1,y1,x2,y2);
}

void sciswitch()
{
     int i,j;
	 int a=150,b=105,c=295;
	
     if(switchk>=0&&switchk<=5)
	 {
	     switch(switchk){
		     case 1:{  /*sci REG*/
                 scigra();
			     setcolor(GREEN);	
	             outtextxy(525,65,"BASE-N");
	             outtextxy(525,c+5,"DEG");
				 for(j=0;j<4;j++)                /* 计算器右部按钮框 */
	             {
		             bottondark(520,580,b+j*45,b+j*45+30);
	             }
				 for(i=0;i<6;i++)                /* 计算器下部ABCDEF */
		         {
		             bottondark(a+i*50,a+i*50+35,c,c+24);
		         }
				 for(i=3;i<7;i++)                /* 计算器下部AND等 */
		         {
		             bottondark(a+i*50,a+i*50+35,c+2*30,c+2*30+24);
		         }
				 
				 break;
				 }
			 case 0:{ /*sci DEG*/
                 scigra();
			     setcolor(GREEN);	
	             outtextxy(525,65,"BASE-N");
	             outtextxy(525,c+50,"REG");
				 for(j=0;j<4;j++)                /* 计算器右部按钮框 */
	             {
		             bottondark(520,580,b+j*45,b+j*45+30);
	             }
				 for(i=0;i<6;i++)                /* 计算器下部ABCDEF */
		         {
		             bottondark(a+i*50,a+i*50+35,c,c+24);
		         }
				 for(i=3;i<7;i++)                /* 计算器下部AND等 */
		         {
		             bottondark(a+i*50,a+i*50+35,c+2*30,c+2*30+24);
		         }
				 
				 break;
				 }
			 case 2:{/*base 10*/
                 scigra();
			     setcolor(GREEN);	
                 outtextxy(525,b+5,"2");
	             outtextxy(525,b+5+45,"8");
	             outtextxy(525,b+5+135,"16");
	             for(j=0;j<2;j++)               
	             {
		             bottondark(520,580,c+j*45,c+j*45+30);
	             }
				 for(i=3;i<5;i++)                /* 计算器上部按钮框 */
	                 for(j=0;j<4;j++)
		             {		      
		                 if(i!=4||j!=0) bottondark(a+i*70,a+i*70+50,b+j*45,b+j*45+30);
		             }
                 bottondark(a+1*70,a+1*70+50,b+3*45,b+3*45+30);
				 bottondark(a+2*70,a+2*70+50,b+3*45,b+3*45+30);
				 for(i=0;i<7;i++)                /* 计算器下部按钮框 */
	                 for(j=0;j<1;j++)
		             {		      
		                 bottondark(a+i*50,a+i*50+35,c+j*30,c+j*30+24);
		             }
				for(i=0;i<5;i++)                
	                 for(j=1;j<2;j++)
		             {		      
		                 bottondark(a+i*50,a+i*50+35,c+j*30,c+j*30+24);
		             }
				 for(i=0;i<3;i++)
				 {
				     bottondark(a+i*50,a+i*50+35,c+2*30,c+2*30+24);
			     }
				 for(i=0;i<6;i++)
				 {
				     bottondark(a+i*50,a+i*50+35,c+3*30,c+3*30+24);
			     }
				 break;
				 }
			
			 case 3:{/*base 2*/
                 scigra();
			     setcolor(GREEN);	
	             outtextxy(525,b+5+45,"8");
				 outtextxy(525,b+5+90,"10");
	             outtextxy(525,b+5+135,"16");
	             for(j=0;j<2;j++)               
	             {
		             bottondark(520,580,c+j*45,c+j*45+30);
	             }
				 for(i=0;i<5;i++)                /* 计算器上部按钮框 */
	                 for(j=0;j<2;j++)
		             {		      
		                 if(i!=4||j!=0) bottondark(a+i*70,a+i*70+50,b+j*45,b+j*45+30);
		             }
                 for(i=1;i<5;i++)                
	                 for(j=2;j<4;j++)
		             {		      
		                 bottondark(a+i*70,a+i*70+50,b+j*45,b+j*45+30);
		             }
				 for(i=0;i<7;i++)                /* 计算器下部按钮框 */
	                 for(j=0;j<1;j++)
		             {		      
		                 bottondark(a+i*50,a+i*50+35,c+j*30,c+j*30+24);
		             }
				for(i=0;i<5;i++)               
	                 for(j=1;j<2;j++)
		             {		      
		                 bottondark(a+i*50,a+i*50+35,c+j*30,c+j*30+24);
		             }
				 for(i=0;i<3;i++)
				 {
				     bottondark(a+i*50,a+i*50+35,c+2*30,c+2*30+24);
			     }
				 for(i=0;i<6;i++)
				 {
				     bottondark(a+i*50,a+i*50+35,c+3*30,c+3*30+24);
			     }
				 break;
				 }
			 case 4:{/*base 8*/
                 scigra();
			     setcolor(GREEN);	
                 outtextxy(525,b+5,"2");
	             outtextxy(525,b+5+90,"10");
	             outtextxy(525,b+5+135,"16");
	             for(j=0;j<2;j++)               
	             {
		             bottondark(520,580,c+j*45,c+j*45+30);
	             }
				 for(i=3;i<5;i++)                /* 计算器上部按钮框 */
	                 for(j=0;j<4;j++)
		             {		      
		                 if(i!=4||j!=0) bottondark(a+i*70,a+i*70+50,b+j*45,b+j*45+30);
		             }
				 bottondark(a+1*70,a+1*70+50,b+0*45,b+0*45+30);
				 bottondark(a+2*70,a+2*70+50,b+0*45,b+0*45+30);
                 bottondark(a+1*70,a+1*70+50,b+3*45,b+3*45+30);
				 bottondark(a+2*70,a+2*70+50,b+3*45,b+3*45+30);
				 for(i=0;i<7;i++)                /* 计算器下部按钮框 */
	                 for(j=0;j<1;j++)
		             {		      
		                 bottondark(a+i*50,a+i*50+35,c+j*30,c+j*30+24);
		             }
				 for(i=0;i<5;i++)               
	                 for(j=1;j<2;j++)
		             {		      
		                 bottondark(a+i*50,a+i*50+35,c+j*30,c+j*30+24);
		             }
				 for(i=0;i<3;i++)
				 {
				     bottondark(a+i*50,a+i*50+35,c+2*30,c+2*30+24);
			     }
				 for(i=0;i<6;i++)
				 {
				     bottondark(a+i*50,a+i*50+35,c+3*30,c+3*30+24);
			     }
				 break;
				 }
			 case 5:{ /*base 16*/
                 scigra();
			     setcolor(GREEN);	
                 outtextxy(525,b+5,"2");
	             outtextxy(525,b+5+45,"8");
	             outtextxy(525,b+5+90,"10");
	             for(j=0;j<2;j++)               
	             {
		             bottondark(520,580,c+j*45,c+j*45+30);
	             }
				 for(i=3;i<5;i++)                /* 计算器上部按钮框 */
	                 for(j=0;j<4;j++)
		             {		      
		               if(i!=4||j!=0)  bottondark(a+i*70,a+i*70+50,b+j*45,b+j*45+30);
		             }
                 bottondark(a+1*70,a+1*70+50,b+3*45,b+3*45+30);
				 bottondark(a+2*70,a+2*70+50,b+3*45,b+3*45+30);
				 
				 bottondark(a+6*50,a+6*50+35,c,c+24);
				 for(i=0;i<5;i++)                /* 计算器下部按钮框 */
	                 for(j=1;j<2;j++)
		             {		      
		                 bottondark(a+i*50,a+i*50+35,c+j*30,c+j*30+24);
		             }
				 for(i=0;i<3;i++)
				 {
				     bottondark(a+i*50,a+i*50+35,c+2*30,c+2*30+24);
			     }
				 for(i=0;i<6;i++)
				 {
				     bottondark(a+i*50,a+i*50+35,c+3*30,c+3*30+24);
			     }
				 break;
				 }
				 default: break;
				 }
	 }
}

void science()
{

	int i,j,k=0;
	int a=150,b=105,c=295;
	unsigned long gsize;

/*计算器按钮标签文本字符 */
	char str[][5]={"1","2","3","-","/","4","5","6","*","Sqrt","7","8","9","e","C"};
	char temp[6]="";


	cleardevice();

	setbkcolor(BLACK);
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	bar3d(130,45,500,420,10,1);        /* 计算器外框 */
	setcolor(DARKGRAY);
	line(150,60,150,90);
	line(150,90,480,90);
	setcolor(WHITE);
	line(150,60,480,60);
	line(480,60,480,90);
	setfillstyle(SOLID_FILL,YELLOW);
	bar(150,60,480,90);            /* 绘制信息显示框 */
	setfillstyle(SOLID_FILL,LIGHTGRAY);

	for(i=0;i<5;i++)                /* 绘制计算器上部按钮框 */
	     for(j=0;j<4;j++)
		  {
		      bar(a+i*70,b+j*45,a+50+i*70,b+30+j*45);
		      bottonup(a+i*70,a+i*70+50,b+j*45,b+j*45+30);
		  }



	   bar(120,430,410,470);
	   bottonup(120,410,430,470);
       settextstyle(1,0,3);
       setcolor(RED);
       outtextxy(123,438,"Switch to standard mode.");
	   bar(430,430,500,470);
	   bottonup(430,500,430,470);
	   settextstyle(1,0,3);
       setcolor(RED);
	   outtextxy(433,438,"HELP");
	   settextstyle(1,0,3);
       setcolor(YELLOW);
	   outtextxy(260,10,"scientific mode");
       settextstyle(1,0,2);
       setcolor(RED);
       for(j=0;j<3;j++)
	   for(i=0;i<5;i++)        /* 显示计算器前三排按钮标签 */
	   {
		     strcpy(temp,str[k++]);
			 if (temp[0]=='S') {outtextxy(a+6+70*i,200-j*45,temp);continue;}
			 if (temp[0]=='1') {outtextxy(a+10+70*i,200-j*45,temp);continue;}
		     outtextxy(a+17+70*i,200-j*45,temp);
	   }
       outtextxy(167,245,"0"); /* 显示计算器第四排排按钮标签 */
       outtextxy(377,245,"+");
       outtextxy(447,245,"PI");
       settextstyle(1,0,3);
       outtextxy(310,235,".");
       settextstyle(1,0,2);
       outtextxy(228,243,"+");
       outtextxy(237,246,"/");
       outtextxy(246,250,"-");
       setcolor(BLACK);

	   for(i=0;i<7;i++)                /* 绘制计算器下部按钮框 */
	     for(j=0;j<4;j++)
		  {
		      bar(a+i*50,c+j*35,a+35+i*50,c+24+j*30);
		      bottonup(a+i*50,a+i*50+35,c+j*30,c+j*30+24);
		  }

	   settextstyle(1,0,1);               /*输出下部第一行*/
	   setcolor(RED);
	   outtextxy(a+8,c,"A");
	   outtextxy(a+8+50,c,"B");
	   outtextxy(a+8+100,c,"C");
	   outtextxy(a+8+150,c,"D");
	   outtextxy(a+8+200,c,"E");
	   outtextxy(a+8+250,c,"F");
	   outtextxy(a+300,c,"Ans");

	   outtextxy(a+2,c+30,"sin");        /*下部第二行*/
	   outtextxy(a+2+50,c+30,"cos");
	   outtextxy(a+2+100,c+30,"tan");
	   outtextxy(a+8+150,c+30,"[ ]");
	   outtextxy(a+8+200,c+30,"%");
	   outtextxy(a+8+250,c+30,"<");
	   outtextxy(a+8+300,c+30,">");

	   outtextxy(a+2,c+60,"log");        /*下部第三行*/
	   outtextxy(a+5+50,c+60,"ln");
	   outtextxy(a+7+100,c+60,"n!");
	   outtextxy(a+2+150,c+60,"and");
	   outtextxy(a+8+200,c+60,"or");
	   outtextxy(a+4+250,c+60,"not");
	   outtextxy(a+3+300,c+60,"xor");
	   
	   outtextxy(a+2,c+90,"1/x");        /*下部第四行*/
	   outtextxy(a+2+50,c+90,"x^2");
	   outtextxy(a+2+100,c+90,"x^y");
	   outtextxy(a+5+150,c+90,"x^3");
	   outtextxy(a+4+200,c+90," ( ");
	   outtextxy(a+4+250,c+90," ) ");
	   outtextxy(a+3+300,c+90," = ");
	   
	   for(j=0;j<4;j++)                /* 绘制计算器右部按钮框 */
	     {
		      bar(520,b+j*45,580,b+30+j*45);
		      bottonup(520,580,b+j*45,b+j*45+30);
	     }
	   for(j=0;j<2;j++)               
	     {
		      bar(520,c+j*45,580,c+30+j*45);
		      bottonup(520,580,c+j*45,c+j*45+30);
	     }
		 
	   bar(520,60,605,90);
	   bottonup(520,605,60,90);
		 
	   settextstyle(1,0,2);               /*输出右部*/
	   setcolor(GREEN);	
	   outtextxy(525,65,"BASE-N");
	   setcolor(RED);
	   outtextxy(525,b+5,"2");
	   outtextxy(525,b+5+45,"8");
	   outtextxy(525,b+5+90,"10");
	   outtextxy(525,b+5+135,"16");
	   
	   outtextxy(525,c+5,"DEG");
	   outtextxy(525,c+5+45,"REG");
	   
	   for(i=0;i<6;i++)                /* 计算器下部ABCDEF */
          {
              bottondark(a+i*50,a+i*50+35,c,c+24);
          }
      for(i=3;i<7;i++)                /* 计算器下部AND等 */
		         {
		             bottondark(a+i*50,a+i*50+35,c+2*30,c+2*30+24);
		         }
        for(i=5;i<7;i++)                
		         {
		             bottondark(a+i*50,a+i*50+35,c+1*30,c+1*30+24);
		         } 
        for(j=0;j<4;j++)                /* 计算器右部按钮框 */
	             {
		             bottondark(520,580,b+j*45,b+j*45+30);
	             }       
	   
}
void scicalc()
{
     char    scip[100];              /* 存储输入的数字符号(含小数点) */
     int     d,dn;                /* 当前单击的按钮标签 */
     int     x,y;  /* (x,y)鼠标当前位置 (xx,yy)鼠标前一位置 */
     int     pn=0;                 /* 当前键盘输入的标签 */
	 double     u,v;                  /*存储答案*/
     int     flag43=0;
	 int     i=0,j=0,h;
  	 clearscreen();
  	 science();
	 sciswitch();
     save_as_old_mouse(0,0);
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
		     if(d==-1||d==49||d==50||d==51||d==52) continue;
             if(d==55||d==56){
                if(d==55) {mode=0; switchk=0;}           
                if(d==56) {mode=4; switchk=0;}  
			 return;}  
             
			 

             if(d==48||d==53||d==54)
             {
                if(d==48){
                   switchk=2;mode=5;
                   return;
                   
                }
                if(d==53){ 
                   switchk=0;sciswitch();continue;
                          }
			   if(d==54){ 
                   switchk=1;sciswitch();continue;
                          }
             } 
			 d=checknumsci(d,switchk);
             if(d==-1) continue; 
             show(sci[d][0],sci[d][2],sci[d][1],sci[d][3]); 
			 if(d==4)         /* 单击C*/
    	     {
    	        clearscreen();
    	        pointj=0;
    	        outtextxy(OUTX-15,OUTY,"0");
    	        outtextxy(OUTX,OUTY,".");
			 }
             if(d!=47&&d!=27&&d!=28&&d!=29&&d!=30&&d!=34&&d!=35&&d!=36&&d!=41&&d!=42&&d!=9&&d!=44&&d!=26&&d!=31&&d!=43&&d!=16)
			 {
		/*strcpy( scip,string(d));*/
		         clearscreen();
		         string(scip,d);
		         settextstyle(1,0,2);              
	             setcolor(RED);
	             if(pointj+1<=18){
                     outtextxy(OUTX-7*(18-i)-140,OUTY,scip);
                   }
                 else{
                      h=pointj+1-18;
	                  outtextxy(OUTX-7*(18-i)-140,OUTY,&scip[h]);
                   }
                   
   
                      
			 }
             if(d==47)
             {
                 if(pointj) 
                 u=calc_expr(scip);
				 if(flag43==1){flag43=0;u=pow(ans,u);}
				 ans=u;
				 outch(u);
				 pointj=0;
			 }
             if(d==16)
             {
                 if(pointj) 
                 u=calc_expr(scip);
				 if(flag43==1){flag43=0;u=pow(ans,u);}
				 ans=-u;
				 outch(-u);
				 pointj=0;
			 }
             if(d==43)
             {  
      			 u=0;
			     if(pointj) 
                 u=calc_expr(scip);
			     if(flag43==1)
				 {
				 ans=pow(ans,u);
				 outch(ans);
				 }else {ans=u;outch(u);}
				 pointj=0;
				 flag43=1;
				 
			 }
			 if(d==27)
			 {
			     if(pointj) 
                 u=calc_expr(scip);
			   if(flag43==1){flag43=0;u=pow(ans,u);}
				 u=sin(dreg(u));
				 ans=u;
				 outch(u);
				 pointj=0;
			 }
			 if(d==28)
			 {
			     if(pointj) 
                 u=calc_expr(scip);
				 if(flag43==1){flag43=0;u=pow(ans,u);}
				 u=cos(dreg(u));
				 ans=u;
				 outch(u);
				 pointj=0;
			 }
			 if(d==29)
			 {
			     if(pointj) 
                 u=calc_expr(scip);
				 if(flag43==1){flag43=0;u=pow(ans,u);}
				 u=tan(dreg(u));
				 ans=u;
				 outch(u);
				 pointj=0;
			 }
			 if(d==30)
			 {
			     if(pointj) 
                 u=calc_expr(scip);
				 if(flag43==1){flag43=0;u=pow(ans,u);}
				 u=floor(u);
				 ans=u;
				 outch(u);
				 pointj=0;
			 }
			 if(d==34)
			 {
                 if(pointj) 
			     u=calc_expr(scip);
				 if(flag43==1){flag43=0;u=pow(ans,u);}
				 if(u<=0) {clearscreen();outtextxy(OUTX-15,OUTY,"Err");continue;}
				 u=log10(u);
				 ans=u;
				 outch(u);
				 pointj=0;
			 }
			 if(d==35)
			 {
			     if(pointj) 
                 u=calc_expr(scip);
				 if(flag43==1){flag43=0;u=pow(ans,u);}
				 if(u<=0) {clearscreen();outtextxy(OUTX-15,OUTY,"Err");continue;}
				 u=log(u);
				 ans=u;
				 outch(u);
				 pointj=0;
			 }
			 if(d==36)
			 {
			     if(pointj) 
                 u=calc_expr(scip);
				 if(flag43==1){flag43=0;u=pow(ans,u);}
				 if(u==floor(u)){
				 v=1;
				 for(j=1;j<=u;j++)
				 v=v*j;
				 ans=v;
				 outch(v);
				 }
				 else{
                 clearscreen();
				 outtextxy(OUTX-15,OUTY,"Err");
				 ans=0;
                 }
                 pointj=0;
				 
			 }
			 if(d==41)
			 {
			     if(pointj) 
                 u=calc_expr(scip);
				 if(flag43==1){flag43=0;u=pow(ans,u);}
                 if(u){
				 u=1/u;
				 ans=u;
				 outch(u);
				 pointj=0;
                 }
                 else
                 outtextxy(OUTX-15,OUTY,"Err");
			 }
			 if(d==42)
			 {
			     if(pointj) 
                 u=calc_expr(scip);
				 if(flag43==1){flag43=0;u=pow(ans,u);}
				 u=pow(u,2);
				 ans=u;
				 outch(u);
				 pointj=0;
			 }
			  if(d==44)
			 {
			     if(pointj) 
                 u=calc_expr(scip);
				 if(flag43==1){flag43=0;u=pow(ans,u);}
				 u=pow(u,3);
				 ans=u;
				 outch(u);
				 pointj=0;
			 }
			 if(d==9)
			 {
			     if(pointj) 
                 u=calc_expr(scip);
				 if(flag43==1){flag43=0;u=pow(ans,u);}
				 u=sqrt(u);
				 ans=u;
				 outch(u);
				 pointj=0;
			 }
			 if(d==31)
			 {
                 if(pointj)
                 u=calc_expr(scip);
				 if(flag43==1){flag43=0;u=pow(ans,u);}
				 u=u/100;
				 ans=u;
				 outch(u);
				 pointj=0;
              }
			 if(d==26)
			 {
                 u=ans;
				 if(flag43==1){flag43=0;u=pow(ans,u);}
                 outch(u);  
                 pointj=0;
             }   
       }
}
}
