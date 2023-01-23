#include <main.h>
#define LCD_ENABLE_PIN PIN_B0
#define LCD_RS_PIN PIN_B1
#define LCD_RW_PIN PIN_B2
#define LCD_DATA4 PIN_B3
#define LCD_DATA5 PIN_B4
#define LCD_DATA6 PIN_B5
#define LCD_DATA7 PIN_B6


#include <lcd.c>

void main()
{
   lcd_init();
   char b,c,b1;
   int16 ans=0;
   b=c=0;
   while(TRUE)
   {
      b1 = getc();
      if(b1 == 0x02)
      {
      ans=0;
      b=getc();
      c=getc();
      ans = ans + c;
      ans=ans<<8;
      ans=ans |b;
      printf(lcd_putc "\fTemp1 sensor \n Data = %ld",ans);
      delay_ms(1000);
      }
      else if (b1 == 0x01)
      {
      ans=0;
      b=getc();
      c=getc();
      ans= ans + c;
      ans=ans<<8;
      ans=ans |b;
      printf(lcd_putc "\fTemp2 Sensor\n Data = %ld",ans);
      delay_ms(1000);
      }
   }
}
