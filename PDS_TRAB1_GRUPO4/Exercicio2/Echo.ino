unsigned int amostra = 0;

void setup(){
  //Pinos das portas como output 
  for (int i = 22; i < 28 ; i++){
    pinMode(i,OUTPUT);
  }
}

void loop(){
  amostra = analogRead(A0);
  PORTA = amostra>>4;
  delayMicroseconds(100);
}
