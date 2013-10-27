int even =0;
const int Blue1 = 22 ; // Blue LED Array Pin numbers
const int Blue2 = 24;
const int Blue3 = 26;

#define DisplaySerial Serial;
#include <SoftwareSerial.h>;
SoftwareSerial DisplaySerial(2,3);
 
#include "Picaso_Serial_4DLib.h"
#include "bigdemo.h" 
#include "Picaso_const4D.h"
Picaso_Serial_4DLib Display(&DisplaySerial);

void setup()
{
 
  
  pinMode(Blue1,OUTPUT);  // Initialize Blue pins as outputs
  pinMode(Blue2,OUTPUT);
  pinMode(Blue3,OUTPUT);
  
}

void flash()
{
 for (int i=0; i<5;i++)
  { 
    digitalWrite(Blue1,LOW);
    digitalWrite(Blue2,LOW);
    digitalWrite(Blue3,LOW);
  
    delay(1000);
  
    digitalWrite(Blue1,HIGH);
    digitalWrite(Blue2,HIGH);
    digitalWrite(Blue3,HIGH);
  
    delay(1000);
  }
  
}

void sequence()
{
   for (int i=1; i<4;i++)
   {
     even = 20+(i*2);
     digitalWrite(even,HIGH);
     delay(1000);
     digitalWrite(even,LOW);
   }
  
  Display.gfx_Cls();
  Display.txt_BGcolour(BLACK);
  Display.txt_FGcolour(YELLOW);
  Display.putstr("The LED's flashed %d times", i);
  delay(3000);

}

void loop ()
{
  DisplaySerial.begin(9600) ;
  Display.TimeLimit4D   = 5000 ; // 5 second timeout on all commands
  Display.gfx_Cls() ;
  Display.txt_BGcolour(BLACK);
  Display.txt_FGcolour(YELLOW);
  Display.txt_MoveCursor(6, 2) ;
  Display.txt_Height(2) ;
  Display.txt_Width(2) ;
  Display.putstr("Main Menu");
  
  Display.gfx_BevelShadow(1) ;                // make it really dark
  Display.gfx_BevelWidth(6) ;
  Display.gfx_Button(flash, 120,50, YELLOW, PURPLE, FONT3, 1, 1, "LED Flash") ;
  delay(100) ;
  Display.gfx_Button(sequence, 120,50, YELLOW, PURPLE, FONT3, 1, 1, "LED Sequence") ;
  delay(100) ;
   
}
