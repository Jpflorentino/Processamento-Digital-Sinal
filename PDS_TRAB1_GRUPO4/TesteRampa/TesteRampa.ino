int rampa = 0;

void setup() {
  // put your setup code here, to run once:
  for (int i = 22; i<29; i++){
    pinMode(i,OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  PORTA = rampa++;
  if(rampa>=64){
    rampa = 0;
  }
  delayMicroseconds(100);
}
