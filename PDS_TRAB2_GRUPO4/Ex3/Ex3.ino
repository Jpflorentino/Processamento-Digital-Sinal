#include <math.h>

//Variaveis de Input
float Amp = 0.5; //Amplitude do Oscilador
int fc = 1000; //Frequencia para cortar 

//Variaveis globais
int fs=10000;
float Wc=(2*PI*fc)/fs;
float Out[3]={0,0,0};
float In[3]={0,0,0};
float rz = 0.98;
float rp = 0.999;

void setup() {
  analogWriteResolution(12);// Resolução máxima para output
  analogReadResolution(12); //Resolução máxima para input
  Serial.begin(9600);
}

void loop() {
  //Criacao do gerador do sinal
  In[0] = analogRead(A0)/2048.0;
  //Criacao do complexo Z
  Out[0] = In[0]-(2*cos(Wc)*rz*In[1])+(rz*rz*In[2])+(2*rp*cos(Wc)*Out[1])-((rp*rp)*Out[2]);
  //Reiniciar Arrays do Complexo
  Out[2] = Out[1];
  Out[1] = Out[0];
  In[2]=In[1];
  In[1]=In[0];
  Serial.println(Out[0]);
  analogWrite(DAC1,(((Out[0]/9.9562)+1.0)*2048.0));
  delayMicroseconds((1/fs)*10^6);
} 
