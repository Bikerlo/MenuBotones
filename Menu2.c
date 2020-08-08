#include "lcd.h"
#define ACEPTAR PORTB.RB0
#define ARRIBA PORTB.RB1
#define ABAJO PORTB.RB2


char txt[20]=" ";
int opcion=1;
void menu(){
     LCD_CMD(1);
     LCD_OUT(1,1,"1.gaseosas ");
     LCD_OUT(2,1,"2.ensaladas");
     LCD_OUT(3,1,"3.jugos");
     LCD_OUT(4,1,"opcion: ");
     sprintf(txt,"%i",opcion);
     LCD_OUT(4,8,txt);
     
     do{
        if (ARRIBA==1){
           opcion++;
           if (opcion>3){
              opcion=1;
           }
           while(ARRIBA==1);
        }
        if (ABAJO==1){
           opcion--;
           if (opcion<1){
              opcion=3;
           }
           while(ABAJO==1);
        }
        sprintf(txt,"%i",opcion);
        LCD_OUT(4,8,txt);
     }while(ACEPTAR==0);
      while(ACEPTAR);
     switch (opcion){
            case 1:
                 LCD_CMD(1);
                 LCD_OUT(1,1,"1.COCA 2.PEPSI");
                 LCD_OUT(2,1,"3.COLOMBIANA");
                 LCD_OUT(3,1,"4.VOLVER MENU Ppal");
                 LCD_OUT(4,1,"opcion: ");
                 sprintf(txt,"%i",opcion);
                 LCD_OUT(4,8,txt);
                 do{
                    if (ARRIBA==1){
                       opcion++;
                       if (opcion>4){
                          opcion=1;
                       }
                       while(ARRIBA==1);
                    }
                    if (ABAJO==1){
                       opcion--;
                       if (opcion<1){
                          opcion=4;
                       }
                       while(ABAJO==1);
                    }
                    sprintf(txt,"%i",opcion);
                    LCD_OUT(4,8,txt);
                 }while(ACEPTAR==0);
                 while(ACEPTAR);
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
