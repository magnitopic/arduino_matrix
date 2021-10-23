/*
  Encendido secuencial de los leds de un display 8x8.
  Cuando están encendidos todos se apagan y se repite
  el loop. Esto se aplica a un display de 4 módulos.

  Autor: magnitopic.com

*/

#include "LedControl.h"     // incluye libreria LedControl

LedControl lc0=LedControl(11,13,10,1); // crea objeto
LedControl lc1=LedControl(11,13,10,2); // crea objeto
LedControl lc2=LedControl(11,13,10,3); // crea objeto
LedControl lc3=LedControl(11,13,10,4); // crea objeto

void setup() {
  lc0.shutdown(0,false);     // enciende la matriz
  lc1.shutdown(1,false);     // enciende la matriz
  lc2.shutdown(2,false);     // enciende la matriz
  lc3.shutdown(3,false);     // enciende la matriz
  lc0.setIntensity(0,4);     // establece brillo
  lc1.setIntensity(1,4);     // establece brillo
  lc2.setIntensity(2,4);     // establece brillo
  lc3.setIntensity(3,4);     // establece brillo
  lc0.clearDisplay(0);       // limpia matriz
  lc1.clearDisplay(1);       // limpia matriz
  lc2.clearDisplay(2);       // limpia matriz
  lc3.clearDisplay(3);       // limpia matriz


  
}

void loop(){
  //Bucle para enceneder los LED individualmente
  for(int fila = 0; fila < 8; fila++) {     // itera por las filas
    for(int columna = 0; columna < 8; columna++) {  // itera por las columnas
      lc0.setLed(0,fila,columna,true);     // enciende LED
      lc1.setLed(1,fila,columna,true);     // enciende LED
      lc2.setLed(2,fila,columna,true);     // enciende LED
      lc3.setLed(3,fila,columna,true);     // enciende LED
      delay(100);         // demora de 100 mseg.
    }
  }
  //Bucle para apagar los LED individualmente
  for(int fila = 0; fila < 8; fila++) {     // itera por las filas
    for(int columna = 0; columna < 8; columna++) {  // itera por las columnas
      lc0.setLed(0,fila,columna,true);     // apaga LED
      lc1.setLed(1,fila,columna,true);     // apaga LED
      lc2.setLed(2,fila,columna,true);     // apaga LED
      lc3.setLed(3,fila,columna,true);     // apaga LED
      delay(100);         // demora de 100 mseg.
    }
  }
  lc0.clearDisplay(0);       // limpia matriz
  lc1.clearDisplay(1);       // limpia matriz
  lc2.clearDisplay(2);       // limpia matriz
  lc3.clearDisplay(3);       // limpia matriz
}