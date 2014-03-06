#include"calc.h"
void standard()
{
	int i,j,k=0;
	int a=150,b=105;
	unsigned long gsize;
    
/*计算器按钮标签文本字符 */
	char str[][5]={"1","2","3","-","/","4","5","6","*","Sqrt","7","8","9","1/x","C"};
	char temp[6]="";
	InitGraph();
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(SOLID_FILL,LIGHTGRAY);
	bar3d(130,45,500,280,10,1);        /* 计算器外框 */
	setcolor(DARKGRAY);
	line(150,60,150,90);
	line(150,90,480,90);
	setcolor(WHITE);
	line(150,60,480,60);
	line(480,60,480,90);
	setfillstyle(SOLID_FILL,YELLOW);
	bar(150,60,480,90);            /* 绘制信息显示框 */
	setfillstyle(SOLID_FILL,LIGHTGRAY);

	for(i=0;i<5;i++)                /* 绘制计算器按钮框 */
	     for(j=0;j<4;j++)
		  {
		      bar(a+i*70,b+j*45,a+50+i*70,b+30+j*45);
		      bottonup(a+i*70,a+i*70+50,b+j*45,b+j*45+30);
		  }

       setcolor(YELLOW);
       settextstyle(1,0,1);

       bar(120,315,550,345);
	   bottonup(120,550,315,345);
	   bar(120,350,550,380);
	   bottonup(120,550,350,380);
	   bar(120,385,550,415);
	   bottonup(120,550,385,415);
	   bar(120,420,550,470);
	   bottonup(120,550,420,470);
	   setcolor(YELLOW);
       settextstyle(1,0,1);
       outtextxy(30,290,"control with left-click or keyboard,right-click or Esc to exit.");
       outtextxy(130,321,"Switch to scientific mode.");
       outtextxy(130,356,"Switch to statistics mode.");
       outtextxy(130,391,"switch to high-precision calculation mode.");

       settextstyle(1,0,3);
       setcolor(RED);
       outtextxy(283,433,"HELP");
	   settextstyle(1,0,3);
       setcolor(YELLOW);
	   outtextxy(260,10,"standard mode");
       settextstyle(1,0,2);
       setcolor(GREEN);
       for(j=0;j<3;j++)
	   for(i=0;i<5;i++)        /* 显示计算器前三排按钮标签 */
	   {
		     strcpy(temp,str[k++]);
			 if (temp[0]=='S') {outtextxy(a+6+70*i,200-j*45,temp);continue;}
			 if (temp[0]=='1') {outtextxy(a+10+70*i,200-j*45,temp);continue;}
		     outtextxy(a+17+70*i,200-j*45,temp);
	   }
       outtextxy(167,245,"0"); /* 显示计算器最后一排按钮标签 */
       outtextxy(377,245,"+");
       outtextxy(447,245,"=");
       settextstyle(1,0,3);
       outtextxy(310,235,".");
       settextstyle(1,0,2);
       outtextxy(228,243,"+");
       outtextxy(237,246,"/");
       outtextxy(246,250,"-");
       setcolor(BLACK);
}
void stdcalc()
{
    double  u=0,v=0;          /* u:输入的第1个数, v:输入的第2个数  */
    int     flag=0;        /* 输入数据是否有小数点标志：0-无 1-有 */
    int     sign=0;           /* 是否单击了运算符：0-无 其他-运算符字符 */
    int     x,y;  /* (x,y)鼠标当前位置 (xx,yy)鼠标前一位置 */
    char   s[9];              /* 存储输入的数字符号(含小数点) */
    int     fget=4;          /* 前一次单击的按钮标签 */
    int     d,dn;                /* 当前单击的按钮标签 */
	int     pn=0;                 /* 当前键盘输入的标签 */
    int     i=0,j; 
    standard();
     save_as_old_mouse(0,0);
         	        outtextxy(OUTX-15,OUTY,"0");
    	        outtextxy(OUTX,OUTY,".");
    while(1)    /* 单击右键则退出简单计算器 */
    {     
          if (kbhit()!=0)
            pn=bioskey(0);
			
		  if (rightpress()==1||pn==0x11b)
		    {mode=-1;break;}
		 
    	if(leftpress()!=1 && pn==0)    /* 鼠标左键未单击的处理 */
    	{
           move_mouse();
    	}
    	else if(MouseLeftFlag==1||pn!=0)  /* 鼠标左键单击的处理 */
    	{
    	    if(MouseLeftFlag==1){
			 MouseLeftFlag=0;   /* 置标志为0，防止单击1次左键而多次进入 */ 
             get_mouse_position(&x,&y);
             d=returnstdkey(x,y); /* 得到单击按钮的标签 */
			}
			else {
			 d=stdgetKey(pn);
			 pn=0;
			 }
			
			if(d==-1) continue;
			if(d==20||d==21||d==22||d==23) 
			{if(d==20) mode=1;if(d==21) mode=2;if(d==22) mode=3;if(d==23) mode=4;
			break;}
    	    show(std[d][0],std[d][2],std[d][1],std[d][3]);

    	    if(d==4)         /* 单击C开始使用 */
    	    {
    	        clearscreen();
    	        outtextxy(OUTX-15,OUTY,"0");
    	        outtextxy(OUTX,OUTY,".");
    	        v=u=0;
    	        sign=0;
    	        flag=0;
    	        i=0;
    	    }
    	    else if((dn=checknum(d,0))!=-1)  /* 单击'0'-'9'数字键的处理 */
    	    {
      	      if(dn==0&&u==0&&flag==0) /* 开始时始终单击'0'，就显示0 */
    	      {
    	          i=0;
    	          s[i++]=itoc(dn);
    	          s[i++]='.';
    	          s[i]='\0';
    	          u=atof(s);
    	    	    outch(u);
    	      }
    	      else
    	      { 
    	       if(fget==4||fget==19||fget==3||fget==9)
    	    	  {
    	    		   clearscreen();
    	    		   i=0;
    	    		   s[i++]=itoc(dn);
    	    		   s[i++]='.';
    	    		   s[i]='\0';
    	    		   u=atof(s);
    	    		   outch(u);
    	    	  }
    	    	  if(checknum(fget,0)!=-1)
    	    	  {
    	    	     if(sign==0) /* 未单击运算符，处理第1个数u */
    	    	     {
    	    		     if(flag==0) /* 输入数据无小数点 */
    	    		     {
    	    		        clearscreen();
    	    		        u=u*10+d-'0';
    	    		        if((u>0&&u<1e8)||(u<0&&u>-1e8))
    	    		        {
    	    		           s[--i]=itoc(dn);
    	    		           s[++i]='.';
    	    		           s[++i]='\0';
    	    		           u=atof(s);
    	    		           outch(u);
    	    		        }
    	    		        else
    	    		           outch(u);
    	    		     }
    	    		     if(flag==1) /* 输入数据有小数点 */
    	    		     {
    	    		        if(i<=8)
    	    		        {
    	    		           clearscreen();
    	    		           s[i]=itoc(dn);
    	    		           s[++i]='\0';
    	    		           u=atof(s);
			                   outch(u);
    	    		        }
    	    		     }
    	    	     }
    	    	     if(sign!=0) /* 单击了运算符，处理第2个数v */
    	    	     {
    	    		    if(flag==0)
    	    		    {
    	    		       clearscreen();
    	    		       v=v*10+d-'0';
    	    		       if((v>0&&v<1e8)||(v<0&&v>-1e8))
    	    		       {
    	    		          s[--i]=itoc(dn);
    	    		          s[++i]='.';
    	    		          s[++i]='\0';
    	    		          v=atof(s);
    	    		          outch(v);
    	    		       }
    	    		       else
    	    		          outch(v);
    	    		    }
    	    		    if(flag==1)
    	    		    {
    	    		       if(i<=8)
    	    		       {
    	    		          clearscreen();
    	    		          s[i++]=itoc(dn);
    	    		          s[i]='\0';
    	    		          v=atof(s);
			                  outch(v);
    	    		       }
    	    		    }
    	    	     }
    	    	   }
    	    	   if(fget==8||fget==13||fget==14||fget==18)
    	    	   {
    	    		    clearscreen();
    	    		    i=0;
    	    		    s[i++]=itoc(dn);
    	    		    s[i++]='.';
    	    		    s[i]='\0';
    	    		    v=atof(s);
    	    		    outch(v);
    	    	   }
    	    	   if(fget==17) /* 前一次单击的是小数点按钮 */
    	    	   {
    	    		   clearscreen();
    	    		   s[i]=itoc(dn);
    	    		   s[++i]='\0';
    	    		   if(sign==0)
    	    		   {
			             u=atof(s);
			             outch(u);
    	    		   }
    	    		   if(sign!=0)
    	    		   {
			             v=atof(s);
			             outch(v);
    	    		   }
    	    	   }
    	       }
    	     
    	   }
    	   else if(d==8||d==13||d==14||d==18)  
{  /* 单击加,减,乘,除按钮的处理 */
    	      if(sign!=0)
    	      {
    	      	if(fget==8||fget==13||fget==14||fget==18);
    	      	else
    	      	{
    	      	   if(sign==14&&v==0)
    	      	   {
    	      	   	clearscreen();
    	      	   	outtextxy(OUTX-15,OUTY,"Err");
    	      	   }
    	      	   else{
    	      	   	u=calculate(u,v,sign);
    	      	   	outch(u);
    	      	   }
    	      	}
    	      }
    	      sign=d;
    	      flag=0;
    	      i=0;
    	   }
    	   else if(d==19)   /* 单击等号按钮的处理 */ 
    	   {
    	      if(sign!=0)
    	      {
    	      	if(sign=='/'&&fabs(v)<1e-6)
    	      	{
    	      	   clearscreen();
    	      	   outtextxy(OUTX-15,OUTY,"Err");
    	      	}
    	      	else
    	      	{
    	      	   u=calculate(u,v,sign);
    	      	   outch(u);
    	      	}
    	      }
    	      flag=0;
    	      sign=0;
    	      i=0;
    	   }
    	   else if(d==17)   /* 单击小数点按钮的处理 */ 
    	   {
    	     if(flag==0)
    	     	 flag=1;
    	   }
    	   else if(d==3)  /* 单击1/x按钮的处理 */ 
    	   {
    	      if(sign==0)   /* 如果是第1个数，输出u的百分数 */
    	      	{if(fabs(u)>1e-6) {u=1/u; outch(u);} else  {clearscreen();  outtextxy(OUTX-15,OUTY,"Err");}}
    	      if(sign!=0)   /* 是第2个数（单击过运算符），输出v的百分数 */
    	      	{if(fabs(v)>1e-6) {v=1/v; outch(v);} else  {clearscreen();  outtextxy(OUTX-15,OUTY,"Err");}}

    	      i=0;
    	   }
    	   else if(d==9)  /* 单击求平方根按钮的处理 */
         {
    	     if(sign==0)    /*对输入的第1个数求平方根 */
    	     {
    	     	  if(u<0)
    	     	  {
    	     	     clearscreen();
    	     	     outtextxy(OUTX-15,OUTY,"Err");
    	     	  }
    	     	  else{
    	     	     u=sqrt(u);
    	     	     outch(u);
    	     	  }
    	     }
    	     if(sign!=0) /*对输入的第2个数求平方根 */
    	     {
    	     	  if(v<0)
    	     	  {
    	     	     clearscreen();
    	     	     outtextxy(OUTX-15,OUTY,"Er");
    	     	  }
    	     	  else{
    	     	     v=sqrt(v);
    	     	     outch(v);
    	     	  }
    	     }
    	     i=0;
    	   }
    	   else if(d==16)   /* 单击+/-按钮的处理 */
    	   {
    	         if(sign==0)
    	         {
    	         	u=-u;
    	         	outch(u);
    	         }
    	         else
    	         {
    	         	v=-v;
    	         	outch(v);
    	         }
    	   }
    	   else
    	      continue;

	       fget=d;   /* 保存上次单击按钮的标签 */
       } /* End of else if(MouseLeftFlag==1) */
     }   /* End of while(rightpress()!=2) */

}
