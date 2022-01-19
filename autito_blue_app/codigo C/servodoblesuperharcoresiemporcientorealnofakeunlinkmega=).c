#include <16f876a.h>
#fuses NOWDT,XT
#use delay (clock=4M)

int a=0,i=0,j=0;

void servo1();
void servo2();



void main (){
   while (true){ 
      if (input(pin_a1)==1){
         a++;}
      if (a==2){
         a=0;}

   if (a!=1){
      servo1();
      servo2();}


   }
   
void servo1(void){


   for(j=0;j<20;j++)
      {
     output_high(PIN_B0);
     delay_us(600);
     output_low(PIN_B0);
     delay_us(18000);}
     
    }

void servo2 (void){

   for(i=0;i<20;i++)
   {
     output_high(PIN_B1);
     delay_us(2400);
     output_low(PIN_B1);
     delay_us(18000);}}
     
   
