#include <main.h>
#define LCD_ENABLE_PIN PIN_B0
#define LCD_RS_PIN PIN_B1
#define LCD_RW_PIN PIN_B2
#define LCD_DATA4 PIN_B4
#define LCD_DATA5 PIN_B5
#define LCD_DATA6 PIN_B6
#define LCD_DATA7 PIN_B7

#include <lcd.c>

void main()
{
   setup_adc_ports(ALL_ANALOG);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1|RTCC_8_bit);      //256 us overflow
   lcd_init();
   int16 a;
   char b,c;
   setup_adc(ADC_CLOCK_INTERNAL);
   set_adc_channel(0);
   
   while(TRUE)
   {
   read_adc(ADC_START_ONLY);
   while(adc_done()==0);
   a = read_adc(ADC_READ_ONLY);
      b=a&0x00ff;
      c=(a&0xff00)>>8;
      putc(0x02);
      putc(b);
      putc(c);
      printf(LCD_PUTC,"\f%ld",a);
      delay_ms(1200);
      a=b=c=0;
   }
}
