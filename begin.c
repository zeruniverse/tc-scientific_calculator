/*--------------------------------------------------------------------------*/
/*This part of program uses VGA mode to display picture.                    */
/*It's the beginning part of our program.                                   */
/*The bmp file loading code is partly quoted from the Internet,             */
/*and the other parts are originally written by myself.                     */
/*NO BUSSINESS USE ALLOWED.    All rights reserved.                         */
/*BY ZHAO ZEYU,college of computer science and technology, ZJU.             */
/*contact me by E-mail:zzy8200@gmail.com                                    */
/*--------------------------------------------------------------------------*/
/*change the main function to other name while finally compiling and linking*/
/*--------------------------------------------------------------------------*/
#include "calc.h"

/*install time interrupt*/
unsigned int time=0;
void interrupt(*oldtimer)(void);
void interrupt newtimer(void)
{
(*oldtimer)();
time++;
}
void begintimer(void interrupt (*inp)(void))
{
 oldtimer=getvect(0x1c);
 disable();
 setvect(0x1c,inp);
 enable();
 }
void killtimer(void)
{
 disable();
 setvect(0x1c,oldtimer);
 enable();
}
/*load bmp files*/
typedef struct tagBITMAPFILEHEADER
{
    unsigned int bfType;
    unsigned long bfSize;
    unsigned int bfReserved1;
    unsigned int bfReserved2;
    unsigned long bfOffBits;
}BITMAPFILEHEADER;

typedef struct tagBITMAPINFOHEADER
{
    unsigned long biSize;
    long biWidth;
    long biHeight;
    unsigned int biPanes;
    unsigned int biBitCount;
    unsigned long biCompression;
    unsigned long biSizeImage;
    long biXPelsPerMeter;
    long biYPelsPerMeter;
    unsigned long biClrUsed;
    unsigned long biClrImportant;
}BITMAPINFOHEADER;

typedef struct tagRGBQUAD
{
    unsigned char rgbBlue;
    unsigned char rgbGreen;
    unsigned char rgbRed;
    unsigned char rgbReserved;
}RGBQUAD;

typedef struct tagBITMAPINFO
{
    BITMAPINFOHEADER bmiHeader;
    RGBQUAD bmiColors[];
}BITMAPINFO;

int xmax;
int ymax;

void InitGraph()    /*change to VGA mode*/
{
int mod=VGA;
int dr=VGAHI;
initgraph(&mod,&dr,"");
xmax=getmaxx();
ymax=getmaxy();
}



void Exit(char *ErrorCode)
{
printf("%s\n",ErrorCode);
printf("Press any key to skip this part and continue");
getch();

}

long WidthBytes(long Width,int BitCount)
{
long WBytes;
WBytes=(Width*BitCount+31)/8;
WBytes=WBytes/4*4;
return WBytes;
}

unsigned char SetPalette(unsigned char data)
{
  switch(data)
  {
  case 1:
    return 4;
  case 4:
    return 1;
  case 3:
    return 6;
  case 6:
    return 3;
  case 9:
    return 12;
  case 12:
    return 9;
  case 11:
    return 14;
  case 14:
    return 11;
  default:
    return data;
  }
}

void begin() /*display the BMP file and draw circles to exit*/
{
long i,j;
int x,y,z;
long WBytes;
long Height,Width;
FILE *fp;
void *Temp=NULL;
BITMAPFILEHEADER bfh;
BITMAPINFOHEADER bih;
unsigned char SrcData,data;
InitGraph();
    if((fp=fopen("LOGO.bmp","rb"))==NULL)
{
Exit("Can Not Load Our Logo.\n");return;
}
fread(&bfh,sizeof(BITMAPFILEHEADER),1,fp);
fread(&bih,sizeof(BITMAPINFOHEADER),1,fp);
Height=bih.biHeight;
Width=bih.biWidth;
WBytes=WidthBytes(Width,bih.biBitCount);
fread(Temp,sizeof(RGBQUAD),16,fp);
printf("%d %d",'\f','\t');
for(i=Height-1;i>=0;i--)
{
  fseek(fp,54+16*sizeof(RGBQUAD)+i*WBytes,SEEK_SET);
  for(j=0;j<Width;j++)
  {
      if(j%2==0)
      {
    fread(&SrcData,1,1,fp);
    data=SetPalette(SrcData/16);
    putpixel(j,Height-1-i,data);
      }
      else
      {
    data=SetPalette(SrcData%16);
    putpixel(j,Height-1-i,data);
      }
      }
}
bioskey(0);
x=xmax/2;
y=ymax/2;
j=x>y?x:y;
begintimer(newtimer);
i=0;
while(1)
{
   if(time) { time=0;circle(x,y,i);i=i+50;}
   if(i>j) break;
}
killtimer();

}
