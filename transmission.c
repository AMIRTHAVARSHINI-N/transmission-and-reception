#include <main.h>
#define LCD_ENABLE_PIN PIN_B0
#define LCD_RS_PIN PIN_B1
#define LCD_RW_PIN PIN_B2
#define LCD_DATA4 PIN_B4
#define LCD_DATA5 PIN_B5
#define LCD_DATA6 PIN_B6
#define LCD_DATA7 PIN_B7
#use rs232(baud=9600,xmit=PIN_C6,bits=8,stream=PORT1)

#include <lcd.c>

void main()
{
   setup_adc_ports(ALL_ANALOG);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1|RTCC_8_bit);      //256 us overflow
   lcd_init();
   int16 a1;
   char b1,c1;
   setup_adc(ADC_CLOCK_INTERNAL);
   set_adc_channel(0);
   
   while(TRUE)
   {
   read_adc(ADC_START_ONLY);
   while(adc_done()==0);
   a1 = read_adc(ADC_READ_ONLY);
      b1=a1&0x00ff;
      c1=(a1&0xff00)>>8;
      putc(0x01);
      putc(b1);
      putc(c1);
      printf(LCD_PUTC,"\f%ld",a1);
      delay_ms(1000);
      a1=b1=c1=0;
   }

}
