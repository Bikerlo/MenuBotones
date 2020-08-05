#include "lcd.h"
#define ACEPTAR PORTB.RB0
#define SUBIR PORTB.RB1
#define BAJAR PORTB.RB2

int valor=34;
int opcion=1;
int acep=0;
char txt[20]="  ";

void menu2(){
     if (SUBIR==1){
        valor++;
        if (valor>100){
           valor=0;
        }
        delay_ms(200);
     }
     if (BAJAR==1){
        valor--;
        if (valor<0){
           valor=100;
        }
        delay_ms(200);
     }
     if (ACEPTAR==1){
         acep=1;
         while(ACEPTAR);
     }
     lcd_out(1,1,"Valor: ");
     sprintf(txt,"%-3d",valor);
     lcd_out(1,8,txt);
}
void menu1(){
     LCD_cmd(1);
     lcd_out(1,1,"Valor: ");
     sprintf(txt,"%d",valor);
     lcd_out(1,8,txt);
}

void menu(){
     lcd_cmd(1);
     acep=0;
     while (acep==0){
           if (SUBIR==1){
              opcion++;
              if (opcion>2){
                 opcion=1;
              }
              while(SUBIR);
           }
           if (BAJAR==1){
              opcion--;
              if (opcion<1){
                 opcion=2;
              }
              while(BAJAR){}
           }
           if (ACEPTAR==1){
              acep=1;
              while(ACEPTAR);
           }
           switch (opcion){
                  case 1:
                  lcd_out(1,1,"1.Ver Valor <-");
                  lcd_out(2,1,"2.Mod Valor   ");
                  break;
                  case 2:
                  lcd_out(1,1,"1.Ver Valor   ");
                  lcd_out(2,1,"2.Mod Valor <-");
                  break;
           }
     }
     switch (opcion){
            case 1:
                 menu1();
                 acep=0;
                 do{
                    if(ACEPTAR==1){
                       acep=1;
                       while(ACEPTAR);
                    }
                 }while(acep==0);
            break;
            case 2:
                 acep=0;
                 lcd_cmd(1);
                 do{
                    menu2();
                 }while(acep==0);
            break;
            
     }
}


void main() {
     ADCON1=0x0F;
     LCD_init();
     LCD_CMD(12);

     while (1){
           menu();
     }
}