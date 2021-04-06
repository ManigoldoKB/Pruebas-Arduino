#include<Adafruit_GFX.h>

#include <Adafruit_PCD8544.h>

#include <SPI.h>

#include<math.h>


static const unsigned char PROGMEM enemy[] =
{
B00000000,B00000000,
B00000001,B00000000,
B00000011,B10000000,
B00000010,B10000000,
B00000010,B11000000,
B00000111,B11000000,
B00001101,B11100000,
B00011111,B11110000,
B00111111,B11111000,
B01111111,B11111100,
B01111111,B11111100,
B01111111,B11111100,
B00011111,B11110000,
B00000111,B11100000,
B00000000,B00000000,
};


float numero[] = {1,2,23,45,5,56,4,65};
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
          
 //Se genera la funcion seno se tiene que ajustar a los desplazamientos de los ejes
 for (int i=5; i<68; i++)
      
       {   
          y=i*0.1;
          z = 15*sin(y-0.5-M_PI)+24;
          display.drawPixel(i, z, BLACK);
          display.display();

          //El codigo para borrar el numero
          display.fillRect(31,9,43,7,WHITE);
          display.display();

          
          
          //El codigo para mostrar el numero

          //Imprimir la (
          display.setCursor(31,9);
          display.print("(");
          display.display();
          int aux= i;
          //Imprimir numero eje x
          display.setCursor(37,9);
          display.println(aux);

          //Imprimir la ,
          display.setCursor(49,9);
          display.print(",");
          display.display();


          //Imprimir el mostrar numero eje vertical
          
          int ejey = round( (z-24)*0.66666667)*-1;
          
          display.setCursor(55,9);
          display.println(ejey);
          display.display();

          //Imprimir ) 
          display.setCursor(73,9);
          display.print(")");
          display.display();



/*
          if(i%2==0 || i==0){
            
            if(z<24){
              for(int j=24; j>z; j-=2){
              display.drawPixel(i-2,j-2, WHITE);
              display.display();
              }
             }
          
            else{
              for(int j=24; j<z; j+=2){
              display.drawPixel(i-2,j-2, WHITE);
              display.display();
          
              }
            }
          
          
            //codigo para la linea guia horizontal
          
            for(int j=5; j<=i; j+=2){
              display.drawPixel(j-2,z-2, WHITE);
              display.display();
            }
          
          delay(1500);
          
             

            // Codigo para las lineas guia
            
            //Verificacion para ver de que lado esta para la linea horizontal
            if(z<24){
              for(int j=24; j>z; j-=2){
              display.drawPixel(i,j, BLACK);
              display.display();
              }
            }
          
            else{
              for(int j=24; j<z; j+=2){
              display.drawPixel(i,j, BLACK);
              display.display();
          
              }
            }
          
          
        
          }

            else{
            //codigo para la linea guia horizontal
          
            for(int j=5; j<=i; j+=2){
              display.drawPixel(j,z, BLACK);
              display.display();
            }
          }
          delay(1500);
*/          
          delay(500);}
          




         
 }

void loop()
 {
      
   
}
