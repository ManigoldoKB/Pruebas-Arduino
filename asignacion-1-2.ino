#include<Adafruit_GFX.h>

#include <Adafruit_PCD8544.h>

#include <SPI.h>

#include<math.h>


const int potenciometro1 = A0;
const int potenciometro2 = A1;
float numero[] = {1,2,23,45,5,56,4,65};
float y;
float a;
float z;
int multi=1;
// pin 7 - Serial clock out (SCLK)
// pin 6 - Serial data out (DIN)
// pin 5 - Data/Command select (D/C)
// pin 4 - LCD chip select (CS)
// pin 3 - LCD reset (RST)
Adafruit_PCD8544 display = Adafruit_PCD8544(13, 12, 11, 10, 9); // LCD Declaration

 /*void drawDottedLine(){
        
          }
        }
*/


void setup()
 {
  Serial.begin(9600);
   display.begin();
   display.clearDisplay();
   display.display();
   display.setContrast(50);
    

         
 }

void loop()
 {
      int valor;
      float voltaje;

      valor = analogRead(potenciometro1);

      voltaje = valor/1023.0;
 
  //Dibuja la linea horizontal
  display.drawLine(0, 24, 84, 24, BLACK);
  display.display();
  //Dibuja la linea Vertical
  display.drawLine(5, 5, 5, 48, BLACK);
  display.display();
  //Dibuja la flecha al final
 display.fillTriangle(2,3,5,0,8,3,BLACK);
 display.display();
 //Se genera la linea punteada superior
     y = 9;

          for(int i=0; i<84; i+=3){
            display.drawPixel(i,y, BLACK);
            display.display();
          }
          
//Se genera la linea punteada inferior
     y = 39;

          for(int i=0; i<84; i+=3){
            display.drawPixel(i,y, BLACK);
            display.display();
          }

       //10V
display.setCursor(9,2);
display.setTextSize(1);
display.print("10V");
display.display();
//-10V
display.setCursor(9,39);
display.setTextSize(1);
display.print("-10V");
display.display();   
//Voltaje actual
display.setCursor(36,2);
display.setTextSize(1);
String auxstring=(String)"V= "+10*voltaje;
display.print(auxstring);
display.display();  


if(voltaje>0.25 && voltaje<0.5)
  multi=2;
else if(voltaje>0.5 && voltaje<0.75)
  multi=3;
else if(voltaje>0.75 && voltaje<1)
  multi=4;


 //Se genera la funcion seno se tiene que ajustar a los desplazamientos de los ejes
 for (int i=0; i<68; i++)
      
       {   
          y=i*0.1;
          z = 15*voltaje*sin(multi*y-0.5-M_PI)+24;
          display.drawPixel(i, z, BLACK);
          display.display();

          //El codigo para borrar el numero
          display.fillRect(31,39,43,7,WHITE);
          display.display();

          
          
          //El codigo para mostrar el numero

          //Imprimir la (
          display.setCursor(31,39);
          display.print("(");
          display.display();
          int aux= i;
          //Imprimir numero eje x
          display.setCursor(37,39);
          display.println(aux);

          //Imprimir la ,
          display.setCursor(49,39);
          display.print(",");
          display.display();


          //Imprimir el mostrar numero eje vertical
          
          int ejey = round( (z-24)*0.66666667)*-voltaje;
          
          display.setCursor(55,39);
          display.println(ejey);
          display.display();

          //Imprimir ) 
          display.setCursor(73,39);
          display.print(")");
          display.display();


       }      
       delay(250);
       display.clearDisplay();
}
