#include <16F876a.h>
#fuses XT, NOWDT
#use delay(clock=4M)

#define LCD_DB4   PIN_C4
#define LCD_DB5   PIN_C5
#define LCD_DB6   PIN_C6
#define LCD_DB7   PIN_C7
#define LCD_RS    PIN_C2
#define LCD_E     PIN_C3
#include <LCD1.c>

#use standard_io(B)
#use standard_io(C)

   int1 cont=0;
   int hr=0, min=0, seg=0, dia=1, mes=1, anio=16, a=1;/////////////////////////////////////////////////////////////////77
   int hra, mina, z=1;
   int limes[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
   char diasem[8]="Hol   ";
   
#int_TIMER1
void temp1s(void)
{
  if (cont==1)  
  {
  output_toggle(PIN_B1);
  seg++;
  }
  set_timer1 (3036);
  cont++;
  if (seg>59) 
  {
      seg=0;
      min++;
  }
}

void Confg_hr(void)
{
   delay_ms(300);
   printf(lcd_putc,"\fHora:     %02u\n", hr);
   printf(lcd_putc,"Minuto:   %02u", min);
   do{
   if (input(pin_a4)==1)
   {
      min++;
      if (min>59) min=0;
      lcd_gotoxy(1,2);
      printf(lcd_putc,"Minuto:   %02u", min);
      delay_ms(300);
   }
   if (input(pin_a3)==1)
   {
      min--;
      if (min==255) min=59;
      lcd_gotoxy(1,2);
      printf(lcd_putc,"Minuto:   %02u", min);
      delay_ms(300);
   }
   
   if (input(pin_a1)==1)
   {
      hr++;
      if (hr>23) hr=0;
      lcd_gotoxy(1,1);
      printf(lcd_putc,"Hora:     %02u", hr);
      delay_ms(300);
   }
   if (input(pin_a2)==1)
   {
      hr--;
      if (hr==255) hr=23;
      lcd_gotoxy(1,1);
      printf(lcd_putc,"Hora:     %02u", hr);
      delay_ms(300);
   }
   }while (input(pin_a5)==0);
   delay_ms(300);
   seg=0;
}

void Confg_fech(void)
{
   delay_ms(300);  
   printf(lcd_putc,"\fAnio:     %02u\n", anio);
   printf(lcd_putc,"Mes:      %02u", mes);
   
   do{
   if (input(pin_a4)==1)
   {
      mes++;
      if (mes>12) mes=1;
      lcd_gotoxy(1,2);
      printf(lcd_putc,"Mes:      %02u", mes);
      delay_ms(300);
   }
   if (input(pin_a3)==1)
   {
      mes--;
      if (mes<1) mes=12;
      lcd_gotoxy(1,2);
      printf(lcd_putc,"Mes:      %02u", mes);
      delay_ms(300);
   }
   
   if (input(pin_a1)==1)
   {
      anio++;
      if (anio>50) anio=0;
      if((anio%4)==0)   limes[2]=29;
       else limes[2]=28;
      lcd_gotoxy(1,1);
      printf(lcd_putc,"Anio:     %02u", anio);
      delay_ms(300);
   }
   if (input(pin_a2)==1)
   {
      anio--;
      if (anio==255) anio=50;
      if((anio%4)==0)   limes[2]=29;
      else limes[2]=28;
      lcd_gotoxy(1,1);
      printf(lcd_putc,"Anio:     %02u", anio);
      delay_ms(300);
   }
   }while(input(pin_a5)==0);
   delay_ms(300); 
   lcd_gotoxy(1,1);
   printf(lcd_putc,"\fDia:      %02u\n", dia);
   printf(lcd_putc,"Diasem:   %02u", z);
   do
   {
   if (input(pin_a4)==1)
   {
      dia++;
      if (dia>limes[mes]) dia=1;
      lcd_gotoxy(1,1);
      printf(lcd_putc,"Dia:      %02u", dia);
      delay_ms(300);
   }
   if (input(pin_a3)==1)
   {
      dia--;
      if (dia<1) dia=limes[mes];
      lcd_gotoxy(1,1);
      printf(lcd_putc,"Dia:      %02u", dia);
      delay_ms(300);
   }   
   if (input(pin_a1)==1)
   {
      Z++;
      if (Z>7) Z=1;
      lcd_gotoxy(1,2);
      printf(lcd_putc,"Diasem:   %02u", z);
      delay_ms(300);
   }
   if (input(pin_a2)==1)
   {
      z--;
      if (z==0) z=7;
      lcd_gotoxy(1,2);
      printf(lcd_putc,"Diasem:   %02u", z);
      delay_ms(300);
   }
   }while (input(pin_a5)==0);
   delay_ms(300);
   }

void Confg_alarm(void)
{
   delay_ms(300);
   mina=min+1;
   hra=hr;
   printf(lcd_putc,"\fLa Alarma esta:");
   do{
   if(a==1){
   lcd_gotoxy(1,2);
   printf(lcd_putc,"!!Activada......");
   }
   else
   {
   lcd_gotoxy(1,2);
   printf(lcd_putc,"...Desactivada!!");
   }
   if (input(pin_a1)==1)   a=1;
   if (input(pin_a2)==1)   a=2;
   }while(input(pin_a5)==0);
   delay_ms(300);
   
   lcd_gotoxy(1,1);
   printf(lcd_putc,"\fHora:     %02u", hra);
   lcd_gotoxy(1,2);
   printf(lcd_putc,"Minuto:   %02u", mina);
   do{
   if (input(pin_a4)==1)
   {
      mina++;
      if (mina>59) mina=0;
      lcd_gotoxy(1,2);
      printf(lcd_putc,"Minuto:   %02u", mina);
      delay_ms(300);
   }
   if (input(pin_a3)==1)
   {
      mina--;
      if (mina==255) mina=59;
      lcd_gotoxy(1,2);
      printf(lcd_putc,"Minuto:   %02u", mina);
      delay_ms(300);
   }
   
   if (input(pin_a1)==1)
   {
      hra++;
      if (hra>23) hra=0;
      lcd_gotoxy(1,1);
      printf(lcd_putc,"Hora:     %02u", hra);
      delay_ms(300);
   }
   if (input(pin_a2)==1)
   {
      hra--;
      if (hra==255) hra=23;
      lcd_gotoxy(1,1);
      printf(lcd_putc,"Hora:     %02u", hra);
      delay_ms(300);
   }
   }while (input(pin_a5)==0);
   delay_ms(300);    
}

void activa_alarm(void)
{
   printf(lcd_putc,"\f!ALARMA ACTIVADA");
   do{
      output_toggle(PIN_B2);
      delay_ms(200);
   } while (input(pin_a5)==0);
   delay_ms(300);
   output_low(PIN_B2);
   a=2;
}

void Info(void)
{
   delay_ms(300);
   printf(lcd_putc,"\f     Dario      \n");
   printf(lcd_putc,"   Diaz Baez    ");
  do{
  }while (input(pin_a5)==0);
   delay_ms(300);
}

void Ajustes(void)
{
   int op=1;
   delay_ms(300);
   do
   {
   if (op<1) op=5;
   if (op>5) op=1;
   delay_ms(300);
   switch(op)
   {
   case 1:
      printf(lcd_putc,"\fMenu de Ajustes\n");
      printf(lcd_putc,"--->Config Hora");
      do{
      if (input(pin_a5)==1)   
         {
         Confg_hr();
         printf(lcd_putc,"\fMenu de Ajustes\n");
         printf(lcd_putc,"--->Config Hora");
         }
      }while ((input(pin_a1)==0)&&(input(pin_a2)==0));
         if (input(pin_a1)==1)   op--;
         if (input(pin_a2)==1)   op++;
      break;
      
   case 2:
      printf(lcd_putc,"\fMenu de Ajustes\n");
      printf(lcd_putc,"--->Config Fecha");
      do{
      if (input(pin_a5)==1)   
         {
         Confg_fech();
         printf(lcd_putc,"\fMenu de Ajustes\n");
         printf(lcd_putc,"--->Config Fecha");
         }
      }while ((input(pin_a1)==0)&&(input(pin_a2)==0));
         if (input(pin_a1)==1)   op--;
         if (input(pin_a2)==1)   op++;
      break;
      
    case 3:
      printf(lcd_putc,"\fMenu de Ajustes\n");
      printf(lcd_putc,"--->Config Alarm");
      do{
         if (input(pin_a5)==1)   
         {
         Confg_alarm();
         printf(lcd_putc,"\fMenu de Ajustes\n");
         printf(lcd_putc,"--->Config Alarm");
         }
      }while ((input(pin_a1)==0)&&(input(pin_a2)==0));
         if (input(pin_a1)==1)   op--;
         if (input(pin_a2)==1)   op++;
      break;
      
   case 4:
      printf(lcd_putc,"\fMenu de Ajustes\n");
      printf(lcd_putc,"--->Informacion");
      do{
      if (input(pin_a5)==1)   
         {
         Info();
         lcd_gotoxy(1,1);
         printf(lcd_putc,"\fMenu de Ajustes\n");
         printf(lcd_putc,"--->Informacion");
         }
      }while ((input(pin_a1)==0)&&(input(pin_a2)==0));
         if (input(pin_a1)==1)   op--;
         if (input(pin_a2)==1)   op++;
      break;
   
   case 5:
      printf(lcd_putc,"\fMenu de Ajustes\n");
      printf(lcd_putc,"---------> Salir");
      do{
      if (input(pin_a5)==1)   break;
      }while ((input(pin_a1)==0)&&(input(pin_a2)==0));
         if (input(pin_a1)==1)   op--;
         if (input(pin_a2)==1)   op++;
      break;
   }
   }while (input(pin_a5)==0);
   delay_ms(300);
   if (z==1)   diasem="Lunes";
   if (z==2)   diasem="Martes";
   if (z==3)   diasem="Mierco";
   if (z==4)   diasem="Jueves";
   if (z==5)   diasem="Viernes";
   if (z==6)   diasem="Sabado";
   if (z==7)   diasem="Domingo";
   printf(lcd_putc,"\f    %02u:%02u:%02u\n", hr, min, seg);
   printf(lcd_putc,"\%s %02u/%02u/20%02u",diasem, dia, mes, anio);
}


void main()
{
   lcd_init();
   setup_timer_1 (T1_INTERNAL | T1_DIV_BY_8);
   set_timer1 (3036);
   enable_interrupts(INT_TIMER1);
   enable_interrupts(global);
   
   
   while(true)
   {
      if (input(pin_a5)==1)
      Ajustes();

   if (min>59)
   {
      min=0;
      hr++;
      if (hr>23) 
      {
         hr=0;
         dia++;
         z++;
         if(dia>limes[mes])
         {
            dia=1;
            mes++;
            if (mes>12)
            {
               mes=1;
               anio++;
               if (anio>50) anio=0;
               if((anio%4)==0)   limes[2]=29;
               else limes[2]=28;
            }
         if (z>7) z=1;
         }
         if (z==1)   diasem="Lunes";
         if (z==2)   diasem="Martes";
         if (z==3)   diasem="Mierco";
         if (z==4)   diasem="Jueves";
         if (z==5)   diasem="Viernes";
         if (z==6)   diasem="Sabado";
         if (z==7)   diasem="Domingo";
      }
   }
   if ((a==1)&&(hr==hra)&&(min==mina))
      activa_alarm();
   if((a==1)){
   lcd_gotoxy(10,2);
      
      printf(lcd_putc,"\f%s %02d/\%02d/\%02d\n%02d:\%02d:\%02d ",diasem,dia,mes,anio,hr,min,seg);
   
      
      printf(lcd_putc,"A:ON");}
   if((a==0)){
   lcd_gotoxy(10,2);
      
      printf(lcd_putc,"\f%s %02d/\%02d/\%02d\n%02d:\%02d:\%02d ",diasem,dia,mes,anio,hr,min,seg);
   
      
      printf(lcd_putc,"A:OFF");}
   delay_ms(200);

   //printf(lcd_putc,"\f%s %02d/\%02d/\%02d\n%02d:\%02d:\%02d ",diasem,dia,mes,anio,hr,min,seg);
      }
}
