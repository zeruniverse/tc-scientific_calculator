#include <stdio.h>
#include <graphics.h>
#include <alloc.h>
#include <stdlib.h>
#include <math.h>
#include <bios.h>
#include <dos.h>
#include <conio.h>
#include <string.h>
#define OUTX   455            /* 信息显示框的右边显示起始x坐标 */
#define OUTY   68             /* 信息显示框的右边显示起始y坐标 */
extern int MouseLeftFlag;
extern int mode;
extern int sci[57][4];
extern int std[24][4];
extern int pointj;
extern int switchk;
extern double ans;
void basen();
unsigned int calcbase(unsigned int a,unsigned int b,int sign);
void string(char *str,int d);
void sciswitch();
void save_as_old_mouse(int x, int y);
void draw_mouse(int x, int y);
void move_mouse(void);
void begin();
void standard();
void science();
void initmouse();
int leftpress();
int rightpress();
void InitGraph();
void highcalc();
double calc_expr(char str[]);
void clearscreen();
void stdcalc();
unsigned int calcbase(unsigned int a,unsigned int b,int sign);
void scicalc();
double dreg(double k);
void stad();
void bottondown(int x1,int x2,int y1,int y2);
void bottonup(int x1,int x2,int y1,int y2);
void show(int x1,int x2,int y1,int y2);
void bottondark(int x1,int x2,int y1,int y2);
int checknum(int d,int k);
void outch(double sum);
void clearscreen();
void initkeyxy(void);
char itoc(int d);
void help();
double calculate(double u,double v,int sign);
