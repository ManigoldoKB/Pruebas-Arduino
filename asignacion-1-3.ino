#include<Adafruit_GFX.h>

#include <Adafruit_PCD8544.h>

#include <SPI.h>

#include<math.h>


const int potenciometro1 = A0;
const int potenciometro2 = A1;

float y;
float a;
float z;
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
      int valor1, valor2;
      float voltaje1, voltaje2;

      valor1 = analogRead(potenciometro1);
      valor2 = analogRead(potenciometro2);

      voltaje1 = valor1/1023.0;
      voltaje2 = valor2/1023.0;
 
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

//Voltaje Potenciometro 1
display.setCursor(36,39);
display.setTextSize(1);
String auxstring1=(String)"V= "+5*voltaje1;
display.print(auxstring1);
display.display();  

//Voltaje Potenciometro 2
display.setCursor(36,2);
display.setTextSize(1);
String auxstring2=(String)"V= "+5*voltaje2;
display.print(auxstring2);
display.display();

float voltaje=0.5*(voltaje1+voltaje2);
 //Se genera la funcion seno se tiene que ajustar a los desplazamientos de los ejes
 for (int i=5; i<68; i++)
      
       {   
          y=i*0.1;
          z = 15*voltaje*sin(y-0.5*voltaje-M_PI)+24;
          display.drawPixel(i, z, BLACK);
          display.display();

          


       }      
       //delay(1000);
       display.clearDisplay();
}
