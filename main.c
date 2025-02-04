#include <12F683.h>
#device adc=10
#FUSES NOWDT, INTRC_IO, NOCPD, NOPROTECT, NOMCLR, PUT, NOBROWNOUT, NOIESO, NOFCMEN
#use delay(clock=8000000)
#define ADC1   PIN_A0
//#define ADC1   PIN_A1
#define  TX   PIN_A2
#define  RX   PIN_A3
//#define ADC_TO_VOLT 0.00488758553275 // (5000.0 / 1023.0) / 1000.0
#define ADC_TO_VOLT 0.0031798631476 // (3.253.0 / 1023.0) 
#use rs232(baud=9600,parity=N,xmit=PIN_A2,rcv=PIN_A3,bits=8)


void setup()
{

   setup_adc_ports(sAN0|sAN1|VSS_VDD);
   setup_adc(ADC_CLOCK_INTERNAL);
   setup_timer_0(RTCC_INTERNAL|RTCC_DIV_1);
   setup_timer_1(T1_DISABLED);
   setup_timer_2(T2_DISABLED,0,1);
   setup_comparator(NC_NC);
   setup_vref(FALSE);
   setup_oscillator(OSC_8MHZ);
 

}

void main()
{
   int16 AdValue;
   int8 Channel;
   double Res_ADC_Val;
   int8  V;
   
   setup();
   
   Channel=0;
   while(1)
   {
         

         set_adc_channel(Channel);
         delay_us(50);
         AdValue=read_adc();
         //printf("Chan: %d=%Lu",Channel,AdValue);
         Res_ADC_Val = AdValue * ADC_TO_VOLT ;
         printf("ADC:%Lu -",AdValue);
         printf(" %.2f\r\n", Res_ADC_Val);

         
     
         //printf("V:%d ",V);


         delay_ms(250);
      
   }
   
   
}
