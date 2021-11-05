#include "LedControl.h"     // incluye libreria LedControl

LedControl lc0=LedControl(11,13,10,1); // crea objeto
LedControl lc1=LedControl(11,13,10,2); // crea objeto
LedControl lc2=LedControl(11,13,10,3); // crea objeto
LedControl lc3=LedControl(11,13,10,4); // crea objeto

#define demora 1000     // constante demora con valor de 1000

byte x[8]= {       // array que contiene todos los elementos de las
  B10000001,          // filas necesarias por mostrar el digito cero
  B01000010,
  B00100100,
  B00011000,
  B00011000,
  B00100100,
  B01000010,
  B10000001
};

byte triangulo[8]= {        // array que contiene todos los elementos de las
  B00010000,
  B00101000,
  B00101000,
  B01000100,
  B01000100,
  B10000010,
  B10000010,
  B11111110
};

byte cuadrado[8]= {        // array que contiene tocuadrado los elementos de las
  B11111111,
  B10000001,
  B10000001,
  B10000001,
  B10000001,
  B10000001,
  B10000001,
  B11111111
};

byte circulo[8]= {       // array que contiene tocuadrado los elementos de las
  B00011000,
  B00100100,
  B01000010,
  B10000001,
  B10000001,
  B01000010,
  B00100100,
  B00011000
};

byte off[8]= {       // array que contiene tocuadrado los elementos de las
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000,
  B00000000
};

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
  Serial.begin(9600);
}




void loop(){
  int rnd=random(0,4);
  Serial.print("El numero aleatorio es = ");
  Serial.println(rnd);
  if(rnd==0){
    mostrar_X();
  }else if(rnd==1){
    mostrar_triangulo();
  }else if(rnd==2){
    mostrar_cuadrado();
  }else{
    mostrar_circulo();
  }
  delay(demora);
  IsOff();
  delay(200);
}

void mostrar_X(){
  for (int i = 0; i < 8; i++)
  {
  lc0.setRow(0,i,x[i]);
    lc1.setRow(1,i,off[i]);
    lc2.setRow(2,i,off[i]);
    lc3.setRow(3,i,off[i]);
  }
}

void mostrar_triangulo(){
  for (int i = 0; i < 8; i++)
  {
    lc0.setRow(0,i,off[i]);
    lc1.setRow(1,i,triangulo[i]);
    lc2.setRow(2,i,off[i]);
    lc3.setRow(3,i,off[i]);
  }
}

void mostrar_cuadrado(){
  for (int i = 0; i < 8; i++)
  {
    lc0.setRow(0,i,off[i]);
    lc1.setRow(1,i,off[i]);
    lc2.setRow(2,i,cuadrado[i]);
    lc3.setRow(3,i,off[i]);
  }
}

void mostrar_circulo(){
  for (int i = 0; i < 8; i++)
  {
    lc0.setRow(0,i,off[i]);
    lc1.setRow(1,i,off[i]);
    lc2.setRow(2,i,off[i]);
    lc3.setRow(3,i,circulo[i]);
  }
}

void IsOff(){
  for (int i = 0; i < 8; i++)
  {
    lc0.setRow(0,i,off[i]);
    lc1.setRow(1,i,off[i]);
    lc2.setRow(2,i,off[i]);
    lc3.setRow(3,i,off[i]);
  }
}