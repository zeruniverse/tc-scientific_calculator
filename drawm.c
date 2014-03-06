#include"calc.h"
unsigned short screen_mask[] =
{
   /* 16 words of screen mask */
   0x3FFF, /*0011111111111111*/
   0x1FFF, /*0001111111111111*/
   0x0FFF, /*0000111111111111*/
   0x07FF, /*0000011111111111*/
   0x03FF, /*0000001111111111*/
   0x01FF, /*0000000111111111*/
   0x00FF, /*0000000011111111*/
   0x007F, /*0000000001111111*/
   0x01FF, /*0000000111111111*/
   0x10FF, /*0001000011111111*/
   0xB0FF, /*1011000011111111*/
   0xF87F, /*1111100001111111*/
   0xF87F, /*1111100001111111*/
   0xFC3F, /*1111110000111111*/
   0xFC3F, /*1111110000111111*/
   0xFE1F, /*1111111000011111*/
};
unsigned short cursor_mask[] =
{
   /* 16 words of cursor mask */
   0x0000, /*0000000000000000*/
   0x4000, /*0100000000000000*/
   0x6000, /*0110000000000000*/
   0x7000, /*0111000000000000*/
   0x7800, /*0111100000000000*/
   0x7C00, /*0111110000000000*/
   0x7E00, /*0111111000000000*/
   0x7F00, /*0111111100000000*/
   0x7C00, /*0111110000000000*/
   0x4600, /*0100011000000000*/
   0x0600, /*0000011000000000*/
   0x0300, /*0000001100000000*/
   0x0300, /*0000001100000000*/
   0x0180, /*0000000110000000*/
   0x0180, /*0000000110000000*/
   0x00C0, /*0000000011000000*/
};

struct 
{
   int x, y;
   unsigned char shape[16][16];
} old_mouse;


void clear_old_mouse(void);
void save_as_old_mouse(int x, int y);
void draw_mouse(int x, int y);
void move_mouse(void);

void clear_old_mouse(void)
{
  
   int i, j;
   for(i=0; i<16; i++)
   {
      for(j=0; j<16; j++)
      {
         putpixel(old_mouse.x+i,old_mouse.y+j,old_mouse.shape[i][j]);
      }      
      
   }
}

void save_as_old_mouse(int x, int y)
{
 
   int i, j;
   old_mouse.x = x;
   old_mouse.y = y;
   for(i=0; i<16; i++)
   {
      for(j=0; j<16; j++)
      {
         old_mouse.shape[i][j] = getpixel(x+i,y+j);
      }      
      
   }
}

void draw_mouse(int x, int y)
{
 
   int i, j;
   for(i=0; i<16; i++)
   {
      for(j=0; j<16; j++)
      {
         if(cursor_mask[i]>>(15-j) & 1)
            putpixel(x+i,y+j,RED); 
      }
    
   }
}

void move_mouse(void)
{
   int x, y;
   union REGS r;
   r.x.ax = 0x0003;
   int86(0x33, &r, &r);
   x = r.x.cx;
   y = r.x.dx;
   if(x == old_mouse.x && y == old_mouse.y)
      return;
   clear_old_mouse();
   save_as_old_mouse(x, y);
   draw_mouse(x, y);
}