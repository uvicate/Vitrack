#define DisplaySerial Serial

#include "Picaso_Serial_4DLib.h"
#include "Picaso_const4D.h"


Picaso_Serial_4DLib Display(&DisplaySerial);


void Touch_Tests(void)
{
    int punto = 0;
    int x ;
    int y ;
    int state ;
  Display.gfx_BGcolour(WHITE) ;//BACKGROUND
  Display.gfx_Cls() ;  
 
  
  //BOTONES
    Display.gfx_RectangleFilled(30, 20, 200, 70, BLUE) ; // LAS COORDENADAS O REGIONES DE CADA BOTON SON LAS QUE SERAN EVALUADAS//
    Display.gfx_RectangleFilled(30, 90, 200, 140, RED) ; // SE DEVEN DE DEJAR ESPACIOS RAZONABLES ENTRE REGIONES DE BOTONES
    Display.gfx_RectangleFilled(30, 160, 200, 210, YELLOW) ;//EL AUMENTO DE REGIONES DEVE DE SER ASCENDENTE EN Y y Y1
    Display.gfx_RectangleFilled(30, 230, 200, 280, GREEN) ;// X y X1 SON DEL MISMO TAMANO EN ESTE CASO
  
    Display.putstr("     Menu de Seleccion   \r") ;//TITULO
 /* cuando anadimos un strig como menu de seleccion la \r es para que al momento
de que se tenga que mostrar oto como los de los botones desaparesca y solo muestre
el que se esta ejecutando// si no ponemos \r los strings se mostraran al mismo tiempo
empalmandose*/
  
  Display.touch_Set(TOUCH_ENABLE) ;    // PONER DISPONIBLE TOUCH EN TODA LA LCD       
  ///////////////////////////////////////////////////////////////////////////////
  //////COMIENZA EVALUACION DE TOUCH EN BOTONES//////////OJO/////////////////////
  /*SI SE QUIERE SELECCIONAR UN SOLO BOTON A LA VEZ SE TENDRA QUE EVALUAR SOLO CON IF
  ,,,,SI QUIERES SELECCIONAR 2 O MAS BOTONES HACERLO CON ELSE IF*///////////////////
    do
      {    
        state = Display.touch_Get(TOUCH_STATUS);  //SI ESTADO DE TOUCH ES 
                                              
                                              
          if(state == TOUCH_PRESSED)            // PRESIONADO
          {
              x = Display.touch_Get(TOUCH_GETX);      //OBTENER CORDENADAS EN X 
              y = Display.touch_Get(TOUCH_GETY);      //Y CORDENADAS EN Y
            
            if((x >= 30 && x <= 200) && (y >= 20 && y <= 70)) //COMPARAMOS CON CORDENADAS DE PRIMER BOTON
              {                                               // SI ESTANDENTO DE LA REGION
                Display.putstr("     Boton Azul        \r");
                Display.gfx_ChangeColour(BLUE, BROWN);       //EJECUTAR INSTRUCCION
             
           }
           
         
         else if((x >= 30 && x <= 200) && (y >= 90 && y <= 140)) // MISMA SECUENCIA DE COMANDOS  
              {                                                  // PERO CON COORDENADAS DE 
                Display.gfx_ChangeColour(RED, BROWN);            //OTRO BOTON
                Display.putstr("     Boton Rojo         \r");
               
             }
    
       else if((x >= 30 && x <= 200) && (y >= 160 && y <= 210))  //TERCER BOTON
            {
                Display.gfx_ChangeColour(YELLOW, BROWN);
                Display.putstr("     Boton Amarillo         \r");
     
           }
           
        else  if((x >= 30 && x <= 200) && (y >= 230 && y <= 280))  // CUARTO BOTON
           {
                Display.gfx_ChangeColour(GREEN, BROWN);
                Display.putstr("     Boton Verde         \r");
           
         }
//SI EL TOUCH ESTA FUREA DE LOS BOTONES EJECUTAR           
      else{                                                      
        Display.putstr(" No Has Tocado Boton. Salir.");  
        Display.touch_Set(TOUCH_DISABLE);
        delay(5000);
        punto = 1;} 
          }
          
      } while(punto == 0);
}



void setup()
{

}

void loop()
{
  DisplaySerial.begin(9600) ;
  Display.TimeLimit4D   = 5000 ; 
  Display.gfx_Cls() ;
  Touch_Tests() ;                
}














