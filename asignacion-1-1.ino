#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

float y;
float z;

Adafruit_PCD8544 display = Adafruit_PCD8544(13, 12, 11, 10, 9); // LCD Declaration

  

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
   display.begin();
   display.setContrast(30);
  display.clearDisplay();
    display.begin();
  // init done
  display.clearDisplay();
  display.display();
  display.setContrast(50);
  display.setCursor(0,0);
  // Mostrar corazón en pantalla
  display.write(3);
  display.display();
}


void loop() {
  

}
