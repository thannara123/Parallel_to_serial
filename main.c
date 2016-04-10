#include <REGX51.H>	
#include<stdio.h>
#include "lcd.h"		
sbit PL  = P1^0;   // Loading parallel data to HC165.
sbit CLK = P1^1;   // Clock pulse to HC165.
sbit Beep  = P1^2;   // 
sbit data_in  = P1^3;

  void clock(void);
  void display(unsigned char value);
				 
void main()
{  
 unsigned char position ,no_of_ip = 17;
  lcd_init();
  string("   gElectron");		   
  while(1)

   {  
      PL = 0 ;
	 delay(2);
	 PL = 1;

 	 for(position = 1; no_of_ip > position; position++ , clock())
	 {		   
		
    if(data_in == 1)
	    display(position); 	 

	 }
   }	
}  

 void clock(void)
 {
   CLK = 1;
   delay(1);
   CLK = 0;

 }

void display(unsigned int value)
  {	 
  unsigned int a[1];
    Beep = 	 1;
   	lcd_init();
	lcd_cmd(0x01);	 	
   	string("Pressed key ");
    lcd_cmd(0xc0); 
	 sprintf(a,"%d",value);  
     string(a); 
     delay(1);
     Beep = 0;
     
  }	  