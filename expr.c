/*This part calculate an expression with addition, *
subtraction multiplication division and parentheses */

#include"calc.h"

void Split(char *str);
void SplitPrem(char *str);
void Combine(double f1,char Operate,double f2);
void Bracket(char *str);

char str1[100],str2[100],str3[100],sub_str1[100],sub_str2[100],sub_str3[20];
char sub_str31[20],sub_str32[20],str_4[100],operate;
int  pause=0,left=0,k1,k2,k3;
double f1=0.0,f2=0.0, f=0.0;

double calc_expr(char str[])
{
   double temp;
      
    strcpy(str1,str);

   Split(str1);

   temp=atof(str1);
   return temp;

}

void Split(char *str)
{
  int  i,j,k,l,jk;

  left=0;
  while(*str) {
    if(*str == '(') left++;
    str++;
  }
    str2[0]='\0';
    str3[0]='\0';
    if(left>0)
    {
    Bracket(str1);
    j=strlen(str1);
    for( i=0; i<j; i++)
     {
     if(str1[i]== '(')
     {
      jk=0;
      for( k=i; k<j; k++)
      {
       if(str1[k]== ')')   break;
       for( l=i+1; l<k-1; l++)
       {
	if(str1[l]== '('){jk++;	break;}
       }
      }
      if(jk==0)
      {
		 for(l=0; l<i; l++)	 str2[l]=str1[l];
			 str2[i]='\0';
		 for(l=k+1; l<j; l++)	 str3[l-k-1]=str1[l];
			 str3[j-k-1]='\0';
		 for(l=i+1; l<=k-1; l++) str1[l-i-1]=str1[l];
			 str1[k-i-1]='\0';
		 break;
	}
     }
     }
    }
    SplitPrem(str1);
}

void SplitPrem(char *str)
{
  int i,j,k,l;

  f1=0.0;
  f2=0.0;
  pause=0;
  strcpy(str1,str);
  Bracket(str1);
  j=strlen(str1);

  for( i=1; i<j-1; i++)
  {
   if((str1[i]=='*'||str1[i]=='/'))
     {
       strcpy(sub_str1," ");
       strcpy(sub_str2," ");
       strcpy(sub_str3," ");
       strcpy(sub_str31," ");
       strcpy(sub_str32," ");
       operate=str1[i];
       for( k1=i-2; k1>=0; k1--)
       {
	 if((str1[k1]=='*'||str1[k1]=='/'||str1[k1]=='+'||str1[k1]=='-'))
		 {
			 for( l=0; l<=k1; l++)	 sub_str1[l]=str1[l];
				 sub_str1[k1+1]='\0';
			 break;
		 }
	   }
       for( k2=i+2; k2<j; k2++)
	   {
	 if((str1[k2]=='*'||str1[k2]=='/'||str1[k2]=='+'||str1[k2]=='-'))
		 {
			 for(l=k2; l<j; l++) sub_str2[l-k2]=str1[l];
				 sub_str2[j-k2]='\0';
			 break;
		 }
	   }
      if(k1<0) k1=-1;
	  for(l=k1+1; l<i; l++)  sub_str31[l-k1-1]=str1[l];
		  sub_str31[i-k1-1]='\0';
      if(k2>j) k2=j;
	  for(l=i+1; l<k2; l++)	  sub_str32[l-i-1]=str1[l];
	     sub_str32[k2-i-1]='\0';
	  f1=atof(sub_str31);
	  f2=atof(sub_str32);
	  Combine(f1,operate,f2);
	}
   if(pause==1) break;
  }

  j=strlen(str1);
  for( i=1; i<j-1; i++)
  {
  if((str1[i]=='+'||str1[i]=='-'))
	{
       strcpy(sub_str1,"  ");
       strcpy(sub_str2,"  ");
       strcpy(sub_str3,"  ");
       strcpy(sub_str31,"  ");
       strcpy(sub_str32,"  ");
       operate=str1[i];
		 sub_str1[0]='\0';
		 k3=0;
       for( k2=i+2; k2<j-1; k2++)
	   {
	 if((str1[k2]=='+'||str1[k2]=='-'))
		 {
			 k3=1;
			 for(l=k2; l<j; l++)	 sub_str2[l-k2]=str1[l];
			      sub_str2[j-k2]='\0';
			 break;
		 }
	   }
	  for(l=0; l<i; l++)  sub_str31[l]=str1[l];
	       sub_str31[i]='\0';
      if(k2>j) k2=j;
	  if( k3==0) k2=j;
	  for(l=i+1; l<k2; l++)	  sub_str32[l-i-1]=str1[l];
		sub_str32[k2-i-1]='\0';
	  f1=atof(sub_str31);
	  f2=atof(sub_str32);
	  Combine(f1,operate,f2);
	}
   if(pause==1) break;
  }
  strcpy(str_4,str2);
  strcat(str_4,str1);
  strcat(str_4,str3);
  strcpy(str1,str_4);
  Bracket(str1);
  j=strlen(str1);
  str2[0]='\0';
  str3[0]='\0';
  for( i=0; i<j; i++)
  {
      if((str1[i]=='('))
      {
		  Split(str1);
		  break;
      }
  }

  for( i=0; i<j-1; i++)
  {
      if((str1[i]=='*'||str1[i]=='/'||str1[i]=='+'||str1[i]=='-'))
      {
		  k=1;
		  if(str1[0]=='-')
		  {
		     k=0;
		     for( l=1; l<j-1; l++)
		     {
		     if((str1[l]=='*'||str1[l]=='/'||str1[l]=='+'||str1[l]=='-'))
		     {
		      k=1;
		      break;
		     }
		     }
		  }
		  if(k==0) break;
		  if(k==1)
		  {
		   SplitPrem(str1);
		   break;
		  }
	  }
  }
}

void Combine(double f1,char Operate,double f2)
{
  int i,j,k,l;

  f=0.0;
  switch (Operate) {
	 case '+':
		f=f1+f2;
		break;
	 case '-':
		f=f1-f2;
		break;
	 case '*':
		f=f1*f2;
		break;
	 case '/':
	   if(f2!=0)
	     f=f1/f2;
	   break;
  }
  sprintf(sub_str3,"%5.3f",f);
  strcpy(str1,sub_str1);
  strcat(str1,sub_str3);
  strcat(str1,sub_str2);
  Bracket(str1);
  j=strlen(str1);
  for( i=0; i<j-1; i++)
  {
      if((str1[i]=='*'||str1[i]=='/'||str1[i]=='+'||str1[i]=='-'))
      {
		   k=1;
		  if(str1[0]=='-')
		  {
		     k=0;
		     for( l=1; l<j-1; l++)
		     {
		     if((str1[l]=='*'||str1[l]=='/'||str1[l]=='+'||str1[l]=='-'))
		     {
		      k=1;
		      break;
		     }
		     }
		  }
		  if(k==0) break;
		  if(k==1)
		  {
		   SplitPrem(str1);
		   break;
		  }
      }
  }
  pause=1;
  strcpy(str_4,str2);
  strcat(str_4,str1);
  strcat(str_4,str3);
  strcpy(str1,str_4);
  str2[0]='\0';
  str3[0]='\0';
  Bracket(str1);
  j=strlen(str1);
  for( i=0; i<j; i++)
  {
      if((str1[i]=='('))
      {
		  Split(str1);
		  break;
	  }
  }
}

void Bracket(char *str)
{
  int i,j,len;

  len=strlen(str);
  j=0;
  for(i=0; i<len; i++)
  {
   if(str[i]!=' ')
   {
    str[j]=str[i];
    j=j+1;
   }
  }
  str[j]='\0';

  if(j>0 && str[j-1]=='.')
  {
   str[j-1]='\0';
   j=j-1;
  }
}
