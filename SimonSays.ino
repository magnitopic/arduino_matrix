#include "LedControl.h" // incluye libreria LedControl

LedControl lc0 = LedControl(11, 13, 10, 1); // crea objeto
LedControl lc1 = LedControl(11, 13, 10, 2); // crea objeto
LedControl lc2 = LedControl(11, 13, 10, 3); // crea objeto
LedControl lc3 = LedControl(11, 13, 10, 4); // crea objeto

//Variables que usaremos más adelante
bool anotherGame = false;
int num = 0;

byte x[8] = {  // array que contiene todos los elementos de las
    B10000001, // filas necesarias por mostrar el digito cero
    B01000010,
    B00100100,
    B00011000,
    B00011000,
    B00100100,
    B01000010,
    B10000001};

byte triangulo[8] = { // array que contiene todos los elementos de las
    B00010000,
    B00101000,
    B00101000,
    B01000100,
    B01000100,
    B10000010,
    B10000010,
    B11111110};

byte cuadrado[8] = { // array que contiene tocuadrado los elementos de las
    B11111111,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B10000001,
    B11111111};

byte circulo[8] = { // array que contiene tocuadrado los elementos de las
    B00011000,
    B00100100,
    B01000010,
    B10000001,
    B10000001,
    B01000010,
    B00100100,
    B00011000};

byte off[8] = { // array que contiene tocuadrado los elementos de las
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000};

void setup()
{
  lc0.shutdown(0, false); // enciende la matriz
  lc1.shutdown(1, false); // enciende la matriz
  lc2.shutdown(2, false); // enciende la matriz
  lc3.shutdown(3, false); // enciende la matriz
  lc0.setIntensity(0, 4); // establece brillo
  lc1.setIntensity(1, 4); // establece brillo
  lc2.setIntensity(2, 4); // establece brillo
  lc3.setIntensity(3, 4); // establece brillo
  lc0.clearDisplay(0);    // limpia matriz
  lc1.clearDisplay(1);    // limpia matriz
  lc2.clearDisplay(2);    // limpia matriz
  lc3.clearDisplay(3);    // limpia matriz
  //Botones
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A4, OUTPUT);
  while (Serial.available() > 0)
    Serial.read();
  Serial.begin(9600);
  // Algoritmo más aleatorio para los random
  randomSeed(analogRead(0));
}

// Prepara los botones
int fnc_dynamic_digitalRead(int _pin)
{
  pinMode(_pin, INPUT);
  return digitalRead(_pin);
}

//Patron de la matriz
int mostrar()
{
  int rnd = random(0, 4);
  if (rnd == 0)
  {
    mostrar_X();
  }
  else if (rnd == 1)
  {
    mostrar_triangulo();
  }
  else if (rnd == 2)
  {
    mostrar_cuadrado();
  }
  else
  {
    mostrar_circulo();
  }
  delay(1000);
  IsOff();
  delay(200);
  return rnd;
}

// Comprobación de los botones
bool buttonCheck(int num)
{
  bool responido = true;
  while (responido)
  {
    if ((fnc_dynamic_digitalRead(2) == false))
    {
      while (!(((fnc_dynamic_digitalRead(2) == true))))
        ; // Evita que se registre el mismo valor varias veces
      Serial.println(String("se ha pulsado el boton 0"));
      if (num == 0)
      {
        tone(6, 659.26, 250);
        return true;
      }
      else
      {
        tone(6, 523.25, 250);
        return false;
      }
      responido = false;
    }
    else if ((fnc_dynamic_digitalRead(3) == false))
    {
      while (!(((fnc_dynamic_digitalRead(3) == true))))
        ; // Evita que se registre el mismo valor varias veces
      Serial.println(String("se ha pulsado el boton 1"));
      if (num == 1)
      {
        tone(6, 698.46, 250);
        return true;
      }
      else
      {
        tone(6, 523.25, 250);
        return false;
      }
      responido = false;
    }
    else if ((fnc_dynamic_digitalRead(4) == false))
    {
      while (!(((fnc_dynamic_digitalRead(4) == true))))
        ; // Evita que se registre el mismo valor varias veces
      Serial.println(String("se ha pulsado el boton 2"));
      if (num == 2)
      {
        tone(6, 783.99, 250);
        return true;
      }
      else
      {
        tone(6, 523.25, 250);
        return false;
      }
      responido = false;
    }
    else if ((fnc_dynamic_digitalRead(5) == false))
    {
      while (!(((fnc_dynamic_digitalRead(5) == true))))
        ; // Evita que se registre el mismo valor varias veces
      Serial.println(String("se ha pulsado el boton 3"));
      if (num == 3)
      {
        tone(6, 880, 250);
        return true;
      }
      else
      {
        tone(6, 523.25, 250);
        return false;
      }
      responido = false;
    }
    else if ((fnc_dynamic_digitalRead(9) == false))
    {
      while (!(((fnc_dynamic_digitalRead(9) == true))))
        ; // Evita que se registre el mismo valor varias veces
      newGame(0);
      return true;
      responido = false;
    }
  }
}

void newGame(int number)
{
  anotherGame = true;
  num = number;
  Serial.print("New game");
}

void loop()
{
  if ((fnc_dynamic_digitalRead(9) == false))
  {
    while (!(((fnc_dynamic_digitalRead(9) == true))))
      ; // Evita que se registre el mismo valor varias veces
    newGame(1);
  }
  else if (anotherGame)
  {
    int lista[num];
    Serial.print(num);
    Serial.print("");
    for (int i = 0; i < num; i++)
    {
      lista[i] = mostrar();
    }
    for (int i = 0; i < num; i++)
    {
      anotherGame = buttonCheck(lista[i]);
      Serial.print(anotherGame);
    }
    num += 1;
    delay(1000);
  }
  else
  {
    start();
    delay(200);

    start1();
    delay(200);

    start();
    delay(200);

    start1();
    delay(200);

    start2();
    delay(200);

    start3();
    delay(200);

    start2();
    delay(200);

    start3();
    delay(200);
  }
}

void mostrar_X()
{
  for (int i = 0; i < 8; i++)
  {
    lc0.setRow(0, i, x[i]);
    lc1.setRow(1, i, off[i]);
    lc2.setRow(2, i, off[i]);
    lc3.setRow(3, i, off[i]);
  }
}

void mostrar_triangulo()
{
  for (int i = 0; i < 8; i++)
  {
    lc0.setRow(0, i, off[i]);
    lc1.setRow(1, i, triangulo[i]);
    lc2.setRow(2, i, off[i]);
    lc3.setRow(3, i, off[i]);
  }
}

void mostrar_cuadrado()
{
  for (int i = 0; i < 8; i++)
  {
    lc0.setRow(0, i, off[i]);
    lc1.setRow(1, i, off[i]);
    lc2.setRow(2, i, cuadrado[i]);
    lc3.setRow(3, i, off[i]);
  }
}

void mostrar_circulo()
{
  for (int i = 0; i < 8; i++)
  {
    lc0.setRow(0, i, off[i]);
    lc1.setRow(1, i, off[i]);
    lc2.setRow(2, i, off[i]);
    lc3.setRow(3, i, circulo[i]);
  }
}

void IsOff()
{
  for (int i = 0; i < 8; i++)
  {
    lc0.setRow(0, i, off[i]);
    lc1.setRow(1, i, off[i]);
    lc2.setRow(2, i, off[i]);
    lc3.setRow(3, i, off[i]);
  }
}

//Press Start arrays//
byte st3[8] = {
    B00000000,
    B00000000,
    B00001100,
    B00001010,
    B00001110,
    B00001000,
    B00001000,
    B00000000};
byte st2[8] = {
    B00000000,
    B00000000,
    B01100011,
    B01010010,
    B01110011,
    B01100010,
    B01010011,
    B00000000};
byte st1[8] = {
    B00000000,
    B00000000,
    B10001100,
    B00010000,
    B10011100,
    B00000100,
    B10011000,
    B00000000};
byte st0[8] = {
    B00000000,
    B00000000,
    B01100000,
    B10000000,
    B11100000,
    B00100000,
    B11000000,
    B00000000};

byte st7[8] = {
    B00000000,
    B00001100,
    B00001010,
    B00001110,
    B00001000,
    B00001000,
    B00000000,
    B00000000};

byte st6[8] = {
    B00000000,
    B01100011,
    B01010010,
    B01110011,
    B01100010,
    B01010011,
    B00000000,
    B00000000};

byte st5[8] = {
    B00000000,
    B10001100,
    B00010000,
    B10011100,
    B00000100,
    B10011000,
    B00000000,
    B00000000};

byte st4[8] = {
    B00000000,
    B01100000,
    B10000000,
    B11100000,
    B00100000,
    B11000000,
    B00000000,
    B00000000};

byte st15[8] = {
    B00000000,
    B00000011,
    B00000100,
    B00000111,
    B00000001,
    B00000110,
    B00000000,
    B00000000};
byte st14[8] = {
    B00000000,
    B00111000,
    B00010001,
    B00010001,
    B00010001,
    B00010001,
    B00000000,
    B00000000};
byte st13[8] = {
    B00000000,
    B10001100,
    B01001010,
    B11001110,
    B01001100,
    B01001010,
    B00000000,
    B00000000};
byte st12[8] = {
    B00000000,
    B01110000,
    B00100000,
    B00100000,
    B00100000,
    B00100000,
    B00000000,
    B00000000};

byte st8[8] = {
    B00000000,
    B00000000,
    B00000011,
    B00000100,
    B00000111,
    B00000001,
    B00000110,
    B00000000};
byte st9[8] = {
    B00000000,
    B00000000,
    B00111000,
    B00010001,
    B00010001,
    B00010001,
    B00010001,
    B00000000};
byte st10[8] = {
    B00000000,
    B00000000,
    B10001100,
    B01001010,
    B11001110,
    B01001100,
    B01001010,
    B00000000};
byte st11[8] = {
    B00000000,
    B00000000,
    B01110000,
    B00100000,
    B00100000,
    B00100000,
    B00100000,
    B00000000};

//esto es el menú de start//
void start()
{
  for (int i = 0; i < 8; i++)
  {
    lc0.setRow(0, i, st0[i]);
    lc1.setRow(1, i, st1[i]);
    lc2.setRow(2, i, st2[i]);
    lc3.setRow(3, i, st3[i]);
  }
}
void start1()
{
  for (int i = 0; i < 8; i++)
  {
    lc0.setRow(0, i, st4[i]);
    lc1.setRow(1, i, st5[i]);
    lc2.setRow(2, i, st6[i]);
    lc3.setRow(3, i, st7[i]);
  }
}
void start2()
{
  for (int i = 0; i < 8; i++)
  {
    lc0.setRow(0, i, st11[i]);
    lc1.setRow(1, i, st10[i]);
    lc2.setRow(2, i, st9[i]);
    lc3.setRow(3, i, st8[i]);
  }
}
void start3()
{
  for (int i = 0; i < 8; i++)
  {
    lc0.setRow(0, i, st12[i]);
    lc1.setRow(1, i, st13[i]);
    lc2.setRow(2, i, st14[i]);
    lc3.setRow(3, i, st15[i]);
  }
}