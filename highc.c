/**************************************
*using array to record and calculate  *
big numbers. addition, subtraction and *
multiplication are implemented by 3 algrithm*
**************************************/
#include"calc.h"
int na,nb,flaga=1,flagb=1;            /*na,nb is the length of two integers;flag is their sign(negative or positive)*/  
char oper;
int a1[250],a2[250];               /*a[i] means the i-th bit counting from the lowest bit*/
void subtraction(int a[],int b[]);
void addition(int a[],int b[]);
int input() ;
void multiplication( int a[], int b[]) ;
int input()                       /*get input to a1 and a2*/
{
    int i,ai=1,bi=1;
	char c1[251], c2[251]; 
    scanf ( "%s ", c1);    	
	scanf("%c ",&oper);
	scanf ( "%s", c2); 
    na = strlen( c1 );                        
    nb = strlen( c2 );                       
    if(c1[0]=='-') { na--; flaga=-1;ai=0;}           
    if(c2[0]=='-') { nb--; flagb=-1;bi=0;}
    for (i=0; i<na; i++,ai++) {a1[i]=c1[na-ai]-'0'; if(a1[i]<0||a1[i]>9) return 0;}    
    for (i=0; i<nb; i++,bi++) {a2[i]=c2[nb-bi]-'0'; if(a2[i]<0||a2[i]>9) return 0;}
    return 1;
}
void addition(int a[],int b[])          
{
    int i,c[252]={0},k;
    if(flaga*flagb>0)
    {
        if(na>nb) k=na;
        else k=nb;                                       
        for(i=0;i<k;i++)
        {
            c[i]=a[i]+b[i]+c[i];
            c[i+1]=(int)c[i]/10;
            c[i]=(int)c[i]%10;
         }                                              
        if(c[k]) k++;                                     
        if(flaga<0) printf("-");
        for(i=k-1;i>=0;i--)  printf("%d",c[i]);  
        printf("\n");		
        return;
    }
    else                                         /* if(flaga*flagb<0) it's a subtraction in fact*/
	{
	   if (flaga==-1) {flaga=1;i=na;na=nb;nb=i;subtraction(b,a);}
       else {flagb=1;subtraction(a,b);}
    } 	   
    return;
}
void subtraction(int a[],int b[])                      
{
    int i,f=0,c[251]={0},k;
    if(flaga*flagb>0)
    {
	    if(flaga==-1) {flaga=1;flagb=1;i=na;na=nb;nb=i;subtraction(b,a);return;}      
        if(na>nb) k=na;
        else                                
         { k=nb;
            for(i=k;a[i]<=b[i]&&i>=0;i--)
            if(a[i]<b[i]) {f=1;break;}              
           }

        if(!f)                        
         for(i=0;i<k;i++)
         {
             if(a[i]<b[i])
             {     a[i+1]--;
                   a[i]+=10;
            }
            c[i]=a[i]-b[i];
          }
        else                                       
          for(i=0;i<k;i++)
            {
               if(b[i]<a[i])
               {   b[i+1]--;
                  b[i]+=10;
               }
               c[i]=b[i]-a[i];
             }
        while(!c[k-1]&&k>1) k--;             
        if(f) printf("-");                   
        for(i=k-1;i>=0;i--) printf("%d",c[i]);
		printf("\n");
        return;
    }
    else 
	{  
	   if(flaga==1) {flagb=1;addition(a,b);}
	   else {flagb=-1;addition(a,b);}
	 }
}
void multiplication( int a[], int b[])               
{
    int i, j, c[501] = {0},k;
	if((na==1&&a[0]==0)||(nb==1&&b[0]==0)){printf("0\n");return;}
    k = na + nb - 1;                  
    for(i = 0; i < na; i++)         
     for(j = 0;j < nb; j++)
      {
        c[i+j] = a[i] * b[j] + c[i+j];
        c[i+j+1] = c[i+j] / 10 + c[i+j+1];
        c[i+j] = c[i+j] % 10;
      }
    while(!c[k]) k--;                         
    if(flaga*flagb<0) printf("-");
    for(i = k; i >= 0; i--)  printf("%d",c[i]);     
	printf("\n");
}
void highcalc()
{
  int i;
  closegraph();
  system("cls");
  printf("It's high-precision calculation mode.\n");
  printf("you can calculate addition, subtraction and multiplication.\n");
  printf("The limitation of the two numbers is 50-bit integers.\n");
  printf("your input should be like this.\n");
  printf("\n*************\n");
  printf("3\n+\n5\n******\n-3\n*\n-5\n******\n5\n*\n3\n*************\n");
  printf("Pressing enter key after a number or operator.\n");    
  printf("\n\ninput illegal statistics like 'b' for three times to go back to standard mode.\n\n");
  while(input())
  { if (oper=='+') addition(a1,a2);
    else if (oper=='-') subtraction(a1,a2); 
	else if (oper=='*') multiplication(a1,a2); 
	else break;
	for(i=0;i<=249;i++){a1[i]=0;a2[i]=0;}
   }
mode=0;
 }
