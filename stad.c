/*work in text mode*/
#include "calc.h"
double av,max,min;
double a[500];
 int i,s;
char c;
 void stad();
int getcmd(char c);
  int cmp(double *a, double *b);
 double variance(void);
int cmp(double *a, double *b)
{
 if (*a>*b) return 1;
 if (*a==*b) return 0;
if (*a<*b) return -1;
}
double variance(void){
double x=0.0;
double p;
 for(i=0;i<s;i++){ p=a[i]-av; x+=p*p;}
return x/s;
}
int getcmd(char c)
{
  system("cls");
  printf("\n\ncommand:\na--average\nr--range\nv--variance\nd--standard deviation\ns--sort\no--input another group of statistics\nother to exit to standard mode.\n");
 switch(c)
 {  case 'a':printf("average=%lf\n",av);break;
  case 's':for(i=0;i<s;i++) printf("%lf\n",a[i]);break;
 case 'r':printf("range=%lf\n",max-min);break;
  case 'v':printf("variance=%lf\n",variance());break;
  case 'd':printf("standard deviation=%lf\n",sqrt(variance()));break;
 case 'o':mode=2;return 0;  default:mode=0; return 0;
 }
return 1;
}
void stad(){
  closegraph();
  system("cls");
 printf("This is the statistics mode");
  printf("you can calculate average number,range,variance,standard deviation,or sort them");
 printf("command:\na--average\nr--range\nv--variance\nd--standard deviation\ns--sort\n");
 printf("input the amount of numbers(up to 500)\n\n");
  rewind(stdin);
 scanf("%d",&s);
 av=0;
 printf("input real numbers divided with 'enter' key\n");
 scanf("%lf",&a[0]);av+=a[0]/s;max=a[0];min=a[0];
 for(i=1;i<s;i++) {
 scanf("%lf",&a[i]); rewind(stdin);
 av+=a[i]/s;max=a[i]>max?a[i]:max;min=a[i]<min?a[i]:min;
}
printf("\n\ncommand:\na--average\nr--range\nv--variance\nd--standard deviation\ns--sort\no--input another group of statistics\nother to exit to standard mode.\n");
 qsort(a,s,sizeof(a[0]),cmp);
 rewind(stdin);
 scanf("%c",&c); rewind(stdin);
 while(getcmd(c)) {scanf("%c",&c);rewind(stdin);}
 }
