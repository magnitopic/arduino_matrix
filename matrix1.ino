/*
  Utilizando un display de leds en forma de matriz de 8x8
  el procedimiento muestra un recorrido de encendido-apagado
  por todos los leds de la matriz.
  Es un bucle sin fin donde cada led se enciende y se apaga
  secuencialmente, y recorre toda la matriz de 8x8 total 64 leds.
  Como estamos en una display de 4 unidades, se crean 4 objetos
  lc0,lc1,lc2,lc3 para manejarlos de forma independiente.

  Autor: magnitopic.com
  
  nota: si estamos en un Linux es posible que se necesite dar
  permisos al puerto USB:
  sudo chmod 666 /dev/ttyUSB0
*/

#include "LedControl.h"     // incluye libreria LedControl

LedControl lc0=LedControl(11,13,10,1); // crea objeto 1
LedControl lc1=LedControl(11,13,10,2); // crea objeto 2
LedControl lc2=LedControl(11,13,10,3); // crea objeto 3
LedControl lc3=LedControl(11,13,10,4); // crea objeto 4

// los pines utilizados 11, 13, 10 son para un Arduino UNO

void setup() {
  lc0.shutdown(0,false);     // enciende la matriz del display 1º
  lc1.shutdown(1,false);     // enciende la matriz del display 2º
  lc2.shutdown(2,false);     // enciende la matriz del display 3º
  lc3.shutdown(3,false);     // enciende la matriz del display 4º
  lc0.setIntensity(0,4);     // establece brillo del display 1º
  lc1.setIntensity(1,4);     // establece brillo del display 2º
  lc2.setIntensity(2,4);     // establece brillo del display 3º
  lc3.setIntensity(3,4);     // establece brillo del display 4º
  lc0.clearDisplay(0);     // limpia matriz del display 1º
  lc1.clearDisplay(1);     // limpia matriz del display 2º
  lc2.clearDisplay(2);     // limpia matriz del display 3º
  lc3.clearDisplay(3);     // limpia matriz del display 4º
  
}

void loop(){
  for(int fila = 0; fila < 8; fila++) {     // itera por las filas
    for(int columna = 0; columna < 8; columna++) {  // itera por las columnas
      lc0.setLed(0,fila,columna,true);     // enciende LED
      lc1.setLed(1,fila,columna,true);     // enciende LED
      lc2.setLed(2,fila,columna,true);     // enciende LED
      lc3.setLed(3,fila,columna,true);     // enciende LED
      delay(100);         // demora de 100 mseg.
      lc0.setLed(0,fila,columna,false);      // apaga LED
      lc1.setLed(1,fila,columna,false);      // apaga LED
      lc2.setLed(2,fila,columna,false);      // apaga LED
      lc3.setLed(3,fila,columna,false);      // apaga LED
      delay(100);         // demora de 100 mseg.
    }
  }
}