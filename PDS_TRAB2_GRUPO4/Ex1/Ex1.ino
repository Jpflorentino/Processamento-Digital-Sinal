#include <avr/io.h>

#define AIN A0
#define n 8
#define sizeBuff 100

float x[sizeBuff]={0};
int index = 0; //indice de escrita 
float aux = 0; //indice de leitura

void setup(){
  analogWriteResolution(12);// Resolução máxima para output
  analogReadResolution(12); //Resolução máxima para input
  Serial.begin(9600);
}


void loop(){
  static float sample_inf;
  static float sample_outf;
  static int sample_out;

  PORTA = sample_out;
  sample_inf = (float(analogRead(AIN))/1024.0)-0.5;
  x[index] = sample_inf*255; //escreve as amostras em x[]
  sample_outf = x[int(aux)]; //novo array com o n alterado
  sample_outf = sample_outf + 127.5; 
  sample_out = sample_outf;
  index++; //aumenta o indice para receber amostras novas
  aux+= n; //aumenta o auxiliar transformado pelo n
  if(index>sizeBuff){
    index=0;
  } //chegou ao fim e volta a 0 
  if(aux>sizeBuff){
    aux=0;
  } //chegou ao fim e volta a 0
  
  Serial.println(sample_out);
  analogWrite(DAC1,((sample_outf+1.0)*2048));
  delayMicroseconds((20/sizeBuff)*10^6);
}
