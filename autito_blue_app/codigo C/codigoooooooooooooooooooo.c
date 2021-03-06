/*
Autito por control bluetooth
*/

#include <16f876a.h>
#fuses NOWDT,HS
#use delay (clock=20M)
#use RS232(BAUD=9600,BITS=8,PARITY=N,XMIT=PIN_C6,RCV=PIN_C7)
void luz_adelante();
void adelante();
void atras();
void izquierda();
void derecha();
void servoabrir();
void servocerrar();
void freno();
int i;

/*circuito
SERVOS RC0,RC1
luz1 rbo luz2 rb1
driver l293 rb3 rb4 rb5 rb6 rb7
hc-06 rx rc7 tx rc6
*/

char blue;

void main (){
   while (true){
   blue=getc();//recibe el dato de la aplicacion y la guarda en blue
   //bluetooth//
   switch (blue)
      {
   case 'A':
   output_high(PIN_b0);
   break;
   case 'B':
   output_low(PIN_b0);
   break;
   case 'C':
   adelante();//el motor gira y el auto avanza
   break;
   case 'D':
   atras();//el motor gira y el auto retrosede enciende led pin 22
   break;
   case 'E':
   izquierda();//gira a la izquieda
   break;
   case 'F':
   derecha();//estos comentarios son estupidos
   break;
   case 'G':
   freno();//enciende led pin 22
   break;
   case 'H':
   servoabrir();
   break;
   case 'I':
   servocerrar();
   break;
   
      }}}

/*in1=rb7 in2=rb6 in3=rb5 in4=rb4 EN1,2,3,4=b3

logica de l293 driver de motor

         adelante atras derecha izquierda  

b7 in1   0        1     1       0
b6 in2   1        0     0       1
b5 in3   0        1     0       1
b4 in4   1        0     1       0

*/

void adelante(void){
   
   output_low(PIN_b1);
   output_high(PIN_b3);
   output_low(PIN_b7);
   output_high(PIN_b6);
   output_low(PIN_b5);
   output_high(PIN_b4);
}

void atras(void){

   output_high(PIN_b1);
   output_high(PIN_b3);
   output_high(PIN_b7);
   output_low(PIN_b6);
   output_high(PIN_b5);
   output_low(PIN_b4);
}

void derecha(void){

   output_low(PIN_b1);
   output_high(PIN_b3);
   output_high(PIN_b7);
   output_low(PIN_b6);
   output_low(PIN_b5);
   output_high(PIN_b4);
}

void izquierda(void){

   output_low(PIN_b1);
   output_high(PIN_b3);
   output_low(PIN_b7);
   output_high(PIN_b6);
   output_high(PIN_b5);
   output_low(PIN_b4);
}

void servoabrir(void){

   for(i=0;i<20;i++)
    {
     output_high(PIN_C0);
     delay_us(600);
     output_low(PIN_C0);
     delay_us(18000);}
}

void servocerrar (void){

   for(i=0;i<20;i++)
    {
     output_high(PIN_C0);
     delay_us(2400);
     output_low(PIN_C0);
     delay_us(18000);;}
}

void freno(void){
   output_low(PIN_b3);
   output_high(PIN_b1);
}
