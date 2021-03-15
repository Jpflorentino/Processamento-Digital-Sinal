#include<math.h>

//Variavies de Input
int Freq=1000; //Freq do oscilador
float Amp=0.5; //Amplitude do Oscilador 0...4095

//Variaveis globais
int fs=10000;
float Wc=(2*PI*Freq)/fs;
float Out[3]={0,0,0};
float In[2]={Amp,0};

void setup() {
  analogWriteResolution(12);// Resolução máxima para output
  analogReadResolution(12); //Resolução máxima para input
  Serial.begin(9600);
}

void loop() {
  Out[0]= In[0] - cos(Wc)*In[1] + 2*cos(Wc)*Out[1] - Out[2]; // soma-se IN para fazer componente Dc porem nao funciona pa freq pequenas
  In[1] = In[0];
  In[0] = 0;
  Out[2] = Out[1];
  Out[1] = Out[0];
  //Serial.println(Out[0]);
  analogWrite(DAC1,(Out[0]+1.0)*2048);
  delayMicroseconds((1/fs)*10^6);
} 
