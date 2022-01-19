# INCLUDE <12F675.h>
# DEVICE ADC=10
# FUSES NOMCLR
# USE delay (internaL=4M)
void main (){
setup_adc_ports(sAN0);
setup_adc(ADC_CLOCK_INTERNAL);
while (true){
int16 analogico;
set_adc_channel(0);
delay_us(10);
analogico = read_adc();
  if (input(pin_a3)==0){


  if (analogico>100){
  output_high(pin_a1);
  }
else{
 output_low(pin_a1);
}
  }
if (analogico>300){
  output_high(pin_a2);
  }
  else{
 output_low(pin_a2);
  }
  
  
   if (analogico>700){
  output_high(pin_a4);
  }
   else{
 output_low(pin_a4);
  }
  
 
  if (analogico>900){
  output_high(pin_a5);
  }
   else{
 output_low(pin_a5);
  }
   }
}


