#include "U8glib.h"
#include <stdio.h>
#include <stdlib.h>

U8GLIB_SSD1306_128X32 u8g(U8G_I2C_OPT_NONE);  // I2C / TWI 

#define ctr1 14 // A0
#define ctr2 15 // A1
#define ctr3 16 // A3
#define ctr4 17 // A4


void Display( int spleen1, int spleen2, int spleen3, int spleen4, int spleen5, int spleen6 ) 
{
  char buf[50]; // buffer
  int line1 = 12;
  int line2 = 32;
  int col1 = 0;
  int col2 = 45;
  int col3 = 90;
  
  u8g.setFont(u8g_font_helvB08); // font size 

  // SPLEEN 1
  char s1[50];
  char* spleen_1 = itoa(spleen1, buf, 10);
  strcpy(s1, "1: ");
  strcat(s1, spleen_1);
  u8g.drawStr( col1, line1, s1 ); // spleen 1: (x,y, text)

  //SPLEEN 2
  char s2[50];
  char* spleen_2 = itoa(spleen2, buf, 10);
  strcpy(s2, "2: ");
  strcat(s2, spleen_2);
  u8g.drawStr( col2, line1, s2); // spleen 2: (x,y, text)


  //SPLEEN 3
  char s3[50];
  char* spleen_3 = itoa(spleen3, buf, 10);
  strcpy(s3, "3: ");
  strcat(s3, spleen_3);
  u8g.drawStr( col3, line1, s3); // spleen 2: (x,y, text)
  

  //SPLEEN 4
  char s4[50];
  char* spleen_4 = itoa(spleen4, buf, 10);
  strcpy(s4, "4: ");
  strcat(s4, spleen_4);
  u8g.drawStr( col1, line2, s4); // spleen 2: (x,y, text)

  //SPLEEN 5
  char s5[50];
  char* spleen_5 = itoa(spleen5, buf, 10);
  strcpy(s5, "5: ");
  strcat(s5, spleen_5);
  u8g.drawStr( col2, line2, s5); // spleen 2: (x,y, text)

  //SPLEEN 6
  char s6[50];
  char* spleen_6 = itoa(spleen6, buf, 10);
  strcpy(s6, "6: ");
  strcat(s6, spleen_6);
  u8g.drawStr( col3, line2, s6); // spleen 2: (x,y, text)
  
}

char* ctr1Char ( int* number ) 
{
   char r[16];
   char* re = itoa(number, r, 10);
   return re;
}

char* ctr2Char ( int* number ) 
{
  char buf [12]; // "-2147483648 \ 0"
  return (itoa (number - 512, buf, 10));
}

void setup(void) 
{
  Serial.begin(9600);
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) {
    u8g.setColorIndex(255);     // white
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) {
    u8g.setColorIndex(3);         // max intensity
  }
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1);         // pixel on
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) {
    u8g.setHiColorByRGB(255,255,255);
  }

  pinMode (ctr1, INPUT);
  pinMode (ctr2, INPUT);
}
 
void loop(void) 
{
  u8g.firstPage();  
  do
  {        
    Display( analogRead (ctr1), analogRead (ctr2), analogRead (ctr3), analogRead (ctr4), 0, 0 );
    
  } while( u8g.nextPage() );
   
  delay(100);
}
 
