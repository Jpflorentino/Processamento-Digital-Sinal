#include <math.h>

//Variaveis de Input
int Freq = 1000; //Freq do oscilador
float Amp = 0.5; //Amplitude do Oscilador
int fc = 500; //Frequencia para cortar  

//Variaveis globais
int fs=10000;
float Wc=(2*PI*Freq)/fs;
float Wc2=(2*PI*fc)/fs;
float Out[3]={0,0,0}; //Array com o sinal gerado 
float In[2]={Amp,0}; //Array a amplitude
float Out2[3]={0,0,0}; //Array para implementacao de filtro
float rz = 0.99;
float rp = 0.999;

void setup() {
  analogWriteResolution(12);// Resolução máxima para output
  analogReadResolution(12); //Resolução máxima para input
  Serial.begin(9600);
}

void loop() {
  //Criacao do gerador do sinal
  Out[0] = In[0] - cos(Wc)*In[1] + 2*cos(Wc)*Out[1] - Out[2]; // soma-se IN para fazer componente Dc porem nao funciona pa freq pequenas
  //Criacao do complexo Z
  Out2[0] = Out[0] - (2*cos(Wc2)*rz*Out[1]) + (rz*rz*Out[2]) + (2*rp*cos(Wc2)*Out2[1]) - ((rp*rp)*Out2[2]);
  //Reiniciar Arrays do Complexo
  Out2[2] = Out2[1];
  Out2[1] = Out2[0];
  //Reiniciar Arrays da geracao do sinal
  In[1] = In[0];
  In[0] = 0;
  Out[2] = Out[1];
  Out[1] = Out[0];
  //Serial.println((Out2[0]/9.9562));
  analogWrite(DAC1,(((Out2[0]/9.9562)+1.0)*2048));
  delayMicroseconds((1/fs)*10^6);
} 
