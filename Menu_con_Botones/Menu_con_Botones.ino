#include <Picaso_Const4D.h>
#include <Picaso_Serial_4DLib.h>

#include <Picaso_Serial_4DLib.h>                
#include <Picaso_Const4D.h>

#define DisplaySerial Serial                    // define display serial port

Picaso_Serial_4DLib Display(&DisplaySerial);    // declare this serial port
char* pagina1[] = {"miau","Miau2","Miau3","Miau4"};
char* pagina2[] = {"miau5","Miau6","Miau7","Miau8"};

void Touch_Tests(void)
{
    int punto = 0;
    int x ;
    int y ;
    int state ;
  Display.gfx_BGcolour(WHITE) ;//BACKGROUND
  Display.gfx_Cls() ;  
 
  Display.gfx_BevelShadow(2) ;                // make it really dark
  Display.gfx_BevelWidth(5) ;        

  //BOTONES
   
        Display.gfx_Button(ON , 30,20, YELLOW, RED, FONT3, 3.5, 4, pagina1[0]) ;
     //   Display.gfx_ClipWindow(30,20, 180, 75);
 
        Display.gfx_Button(ON, 30,90, YELLOW, RED, FONT3, 3.5, 4, pagina1[1]) ;
       // Display.gfx_ClipWindow(30,90, 180, 145) ;
     
        Display.gfx_Button(ON, 30,160, YELLOW, RED, FONT3, 3.5, 4, pagina1[2]) ;
    //    Display.gfx_ClipWindow(30,160, 180, 215) ;
 
        Display.gfx_Button(ON, 30,230, YELLOW, RED, FONT3, 3.5, 4, pagina1[3]) ;
      //  Display.gfx_ClipWindow(30,230, 180, 285) ;

 
    Display.putstr("     Selecciona producto   \r") ;//TITULO
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
            
            if((x >= 30 && x <= 180) && (y >= 20 && y <= 75)) //COMPARAMOS CON CORDENADAS DE PRIMER BOTON
              {                                               // SI ESTANDENTO DE LA REGION
                Display.putstr("     Boton 1        \r");
                //Display.gfx_ChangeColour(BLUE, BROWN);       //EJECUTAR INSTRUCCION
        Display.gfx_Button(OFF , 30,20, YELLOW, RED, FONT3, 3.5, 4, pagina1[0]) ;

         }
           
         
         else if((x >= 30 && x <= 180) && (y >= 90 && y <= 145)) // MISMA SECUENCIA DE COMANDOS  
              {                                                  // PERO CON COORDENADAS DE 
                //Display.gfx_ChangeColour(RED, BROWN);            //OTRO BOTON
                Display.putstr("     Boton 2         \r");
        Display.gfx_Button(OFF, 30,90, YELLOW, RED, FONT3, 3.5, 4, pagina1[1]) ;

           }
    
       else if((x >= 30 && x <= 180) && (y >= 160 && y <= 215))  //TERCER BOTON
            {
                //Display.gfx_ChangeColour(YELLOW, BROWN);
                Display.putstr("     Boton 3         \r");
             Display.gfx_Button(OFF, 30,160, YELLOW, RED, FONT3, 3.5, 4, pagina1[2]) ;

           }
           
        else  if((x >= 30 && x <= 180) && (y >= 230 && y <= 285))  // CUARTO BOTON
           {
                //Display.gfx_ChangeColour(GREEN, BROWN);
                Display.putstr("     Boton 4         \r");
                Display.gfx_Button(OFF, 30,230, YELLOW, RED, FONT3, 3.5, 4, pagina1[3]) ;
                // make it really dark  
       }
//SI EL TOUCH ESTA FUREA DE LOS BOTONES EJECUTAR           
      else{                                                      
        Display.putstr(" Siguente  /r");  
        Display.touch_Set(TOUCH_DISABLE);
        delay(1000);
        punto = 1;} 
          }
          
      } while(punto == 0);
} 
void Touch_Tests1(void)
{
    int punto = 1;
    int x ;
    int y ;
    int state ;
  Display.gfx_BGcolour(WHITE) ;//BACKGROUND
  Display.gfx_Cls() ;  
 
  Display.gfx_BevelShadow(2) ;                // make it really dark
  Display.gfx_BevelWidth(5) ;        

  //BOTONES
   
        Display.gfx_Button(ON , 30,20, YELLOW, RED, FONT3, 3.5, 4, pagina2[0]) ;
     //   Display.gfx_ClipWindow(30,20, 180, 75);
 
        Display.gfx_Button(ON, 30,90, YELLOW, RED, FONT3, 3.5, 4, pagina2[1]) ;
       // Display.gfx_ClipWindow(30,90, 180, 145) ;
     
        Display.gfx_Button(ON, 30,160, YELLOW, RED, FONT3, 3.5, 4, pagina2[2]) ;
    //    Display.gfx_ClipWindow(30,160, 180, 215) ;
 
        Display.gfx_Button(ON, 30,230, YELLOW, RED, FONT3, 3.5, 4, pagina2[3]) ;
      //  Display.gfx_ClipWindow(30,230, 180, 285) ;

 
    Display.putstr("     Selecciona producto   \r") ;//TITULO
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
            
            if((x >= 30 && x <= 180) && (y >= 20 && y <= 75)) //COMPARAMOS CON CORDENADAS DE PRIMER BOTON
              {                                               // SI ESTANDENTO DE LA REGION
                Display.putstr("     Boton 1        \r");
                //Display.gfx_ChangeColour(BLUE, BROWN);       //EJECUTAR INSTRUCCION
        Display.gfx_Button(OFF , 30,20, YELLOW, RED, FONT3, 3.5, 4, pagina2[0]) ;

         }
           
         
         else if((x >= 30 && x <= 180) && (y >= 90 && y <= 145)) // MISMA SECUENCIA DE COMANDOS  
              {                                                  // PERO CON COORDENADAS DE 
                //Display.gfx_ChangeColour(RED, BROWN);            //OTRO BOTON
                Display.putstr("     Boton 2         \r");
        Display.gfx_Button(OFF, 30,90, YELLOW, RED, FONT3, 3.5, 4, pagina2[1]) ;

           }
    
       else if((x >= 30 && x <= 180) && (y >= 160 && y <= 215))  //TERCER BOTON
            {
                //Display.gfx_ChangeColour(YELLOW, BROWN);
                Display.putstr("     Boton 3         \r");
             Display.gfx_Button(OFF, 30,160, YELLOW, RED, FONT3, 3.5, 4, pagina2[2]) ;

           }
           
        else  if((x >= 30 && x <= 180) && (y >= 230 && y <= 285))  // CUARTO BOTON
           {
                //Display.gfx_ChangeColour(GREEN, BROWN);
                Display.putstr("     Boton 4         \r");
                Display.gfx_Button(OFF, 30,230, YELLOW, RED, FONT3, 3.5, 4, pagina2[3]) ;
                // make it really dark  
       }
//SI EL TOUCH ESTA FUREA DE LOS BOTONES EJECUTAR           
      else{                                                      
        Display.putstr(" Anterior  /r");  
        Display.touch_Set(TOUCH_DISABLE);
        delay(1000);
        punto = 0;} 
          }
          
      } while(punto == 1);
} 



void setup()
{ 
  
  
}  
     
void loop()
{
   DisplaySerial.begin(9600) ;
  Display.TimeLimit4D   = 1000 ; 
  Display.gfx_Cls() ;
  Touch_Tests() ;                    
  Touch_Tests1();
    
      
}
