int time = 5;
int latch = 4;
int data = 3;

int time2 = 12;
int latch2 = 11;
int data2 = 10;

int patron;

const byte numeros[8] = 
{
  0b00000001,
  0b00000010,
  0b00000100,
  0b00001000,
  0b00010000,
  0b00100000,
  0b01000000,
  0b10000000,
};

const byte numeros_2[8] = 
{
  0b11111110,
  0b11111101,
  0b11111011,
  0b11110111,
  0b11101111,
  0b11011111,
  0b10111111,
  0b01111111
};

void setup() {
  pinMode(latch, OUTPUT);
  pinMode(time, OUTPUT);
  pinMode(data, OUTPUT);

  pinMode(latch2, OUTPUT);
  pinMode(time2, OUTPUT);
  pinMode(data2, OUTPUT);
  
}

void verificacion(){
  for (int i = 0; i < 8; i++)
  {
     digitalWrite(latch2, LOW);
     shiftOut(data2, time2, LSBFIRST, numeros_2[i]);
     digitalWrite(latch2, HIGH);
   
    for (int j = 0; j < 8; j++)
    {
      
      digitalWrite(latch, LOW);
      shiftOut(data, time, LSBFIRST, numeros[j]);
      digitalWrite(latch, HIGH);
      delay(100);
    }
  }
}

void Imagen() {
  
}

void loop() {
  verificacion();
  

}

