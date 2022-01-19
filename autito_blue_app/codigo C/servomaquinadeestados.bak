#include <16f877A.h>
#FUSES NOWDT,HS,NOPUT,NOPROTECT,NODEBUG,NOBROWNOUT,NOLVP,NOCPD,NOWRT
#use delay(crystal=20MHz)
#use RS232(BAUD=9600,BITS=8,PARITY=N,XMIT=PIN_C6,RCV=PIN_C7)
#include "DHT11.c"
//#FUSES HSPLL, PLL5, CPUDIV1 NOWDT,NOPROTECT,NOBROWNOUT,NOPUT
//#FUSES NOWDT,NOPUT,NOPROTECT,NODEBUG,NOBROWNOUT,NOLVP,NOCPD,NOWRT
//#use delay(clock=48M)
//#use RS232(baud=9600,xmit=PIN_C6,rcv=PIN_C7)

int estado_del_motor;
int estado_del_servo;
int estado_de_la_luz;
int i;
void maquina_de_estado_motor();
void maquina_de_estado_servo();
void maquina_de_estado_luz();
void DHT11();
char dato;
unsigned char temp,humedad;

void main () {
while(true)
{
/*if (input (PIN_B4)==1){
     output_high (PIN_B1);}
   else 
   {
   output_low (PIN_B1);
 //  delay_ms (1000);
    }*/
    
if (kbhit () )
dato=getc();
if (dato!= estado_del_motor)
   maquina_de_estado_motor ();
if (dato!= estado_del_servo)
   maquina_de_estado_servo ();
if (dato!= estado_de_la_luz)
   maquina_de_estado_luz ();
DHT11();
   printf("%3u", temp);
   printf("|");
   printf("%3u", humedad);
   printf("|");
   delay_ms(950);
   output_high(PIN_D1);
   delay_ms(1000);
   output_low(PIN_D1);
}
}


void maquina_de_estado_luz ()
{
estado_de_la_luz=dato;
switch (dato)
{ 
case 'A':output_high(PIN_B3);
break;
case 'B':output_low(PIN_B3);
break;
case 'E':output_high(PIN_A1);
break;
case 'F':output_low(PIN_A1);
break;
}
}


void maquina_de_estado_motor (){
estado_del_motor=dato;
switch (dato)
{
case 'C': //FLECHA HACIA ARRIBA CON SWITCH ALTO- MOTOR
do{
   output_low  (PIN_D0);
   output_high (PIN_D3);
   output_high (PIN_D2);}
   while (input(PIN_B4)==1);
   if (input(PIN_B4)==0)
   {
   dato=0;
   output_low (PIN_D0);
   output_low (PIN_D3);
   output_low (PIN_D2);   
   }
   break;

   case 'D': //FLECHA HACIA ABAJO CON SWITCH BAJO- MOTOR
   do{
   output_high (PIN_D0);
   output_low  (PIN_D3);
   output_high (PIN_D2);}
   while (input(PIN_B5)==1);
   if (input(PIN_B5)==0)
   {
   dato=0;
   output_low (PIN_D0);
   output_low (PIN_D3);
   output_low (PIN_D2);   
   }
   break;
}
}
 
void maquina_de_estado_servo () //DEFINIR PIN PARA SERVO!
{ 
estado_del_servo=dato;
switch (dato)
{
   case 'R':
   for(i=0;i<20;i++)
    {
     output_high(PIN_B1);
     delay_us(600);
     output_low(PIN_B1);
     delay_us(18000);
    }
    break;
    case 'T':
   for(i=0;i<20;i++)
    {
     output_high(PIN_B1);
     delay_us(2400);
     output_low(PIN_B1);
     delay_us(18000);
    }
    break;
}
}

void DHT11()
{        
   unsigned char state = 0;   //Lectura DHT11
   DHT11_init();
   state = get_data();
      
      switch(state) 
      { 
            case 1: 
            { 
            } 
            case 2: 
            { 
               printf("no hay sensor"); 
               printf("|");
               printf("Sensor no conectado"); 
               break; 
            } 
            case 3: 
            { 
               printf("Faltan datos en la informacion");
               break; 
            } 
            
            default: 
            { 
               temp     = values[2];   //printf("Tmp/ C: %3u.%03u \r\n", values[2], values[3]);
               humedad  = values[0];   //printf("R.H/ R: %3u.%03u \r\n", values[0], values[1]);
               break;
            }
           // delay_ms(1000);
      }
   
}

/*if (input (PIN_B0)==1){
     output_low (PIN_B1);}
   else 
   {
   output_high (PIN_B1);
   delay_ms (1000);
    }
    */
    
  /*
  for(i=0;i<20;i++)
    {
     output_high(PIN_A5);
     delay_us(2400);
     output_low(PIN_A5);
     delay_us(18000);
    }
    delay_ms (300);
    
    for(i=0;i<20;i++)
    {
     output_high(PIN_A5);
     delay_us(600);
     output_low(PIN_A5);
     delay_us(18000);
*/

