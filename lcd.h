 #include"delay.h"
 #define LCDPORT P2		// named the Port2 as LCDPORT
 sbit RS=LCDPORT^2;		// P2.2 named RS
 sbit E=LCDPORT^3;		// P2.3 named as E
 #define LINE2 lcd_cmd(0xc0);   // used to display the second line oxc0 is 
 
 
 void latch(void)	 // used to a high to low pulse the pin E 
{
    E = 1;
    delay(1);
    E = 0;
}

void lcd_cmd(unsigned char c)		 // used to send the command / Instruction to the lcd port 
{									 
RS = 0;    // send a '0' value to select to send command
delay(1);					
LCDPORT = c & 0xf0;	 //	 send  the command c only 4 bit by masking the lower bit 
latch();
delay(1); 
LCDPORT =  (c << 4);	// giving the lowerbit  by shifting the 4 bit to left 
latch(); 
}

 void lcd_data(unsigned char c)
 {
 RS =1;	   // send 1 to send data 
 delay(1);
LCDPORT = c & 0xf0 | 0x4;	//send  the data  only  4 bit by masking the lower bit and also making the RS pin high by giving 0x04 .
delay(1);
latch();

LCDPORT = (c << 4)| 0x4; ;	//	giving the lower bit  by shifting the 4 bit to left 
latch(); 
}
 
void lcd_init()
{
  delay(20);
    lcd_cmd(0x30);		//as per data sheet
  delay(20);
    lcd_cmd(0x30);	   //as per data sheet
  delay(4);
    lcd_cmd(0x32);	   //as per data sheet
	delay(4);

	 
    lcd_cmd(0x28);            // Function set (4-bit interface, 2 lines, 5*7Pixels)
    lcd_cmd(0x28);            // Function set (4-bit interface, 2 lines, 5*7Pixels)
    lcd_cmd(0x0c);            // Make cursorinvisible
    lcd_cmd(0x6);            // Set entry Mode(auto increment of cursor)
}

 void string(const char *q)			 // used to send single charcter to display the lcd 
{
    while (*q) {
        lcd_data(*q++);
    }
}
