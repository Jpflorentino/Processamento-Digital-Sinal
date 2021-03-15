#include "includes.h"
#include <math.h>
#include <DueTimer.h>
//Definicao de variaveis constantes
#define distortionPin 50
#define lfoPin 51
#define amplitudePin 53
//Dimensao do array de amplitude

//float volatile amostra = 0.0;

void setup(){
  setup_fil();
  // put your setup code here, to run once:
  analogWriteResolution(12); // Resolução máxima para output
  analogReadResolution(12); //Resolução máxima para input
  // Inicio de chamar interrupcoes para cada pin
  attachInterrupt(digitalPinToInterrupt(distortionPin), distortion_Interruption,RISING);
  attachInterrupt(digitalPinToInterrupt(filterPin), filter_Interruption,RISING);
  attachInterrupt(digitalPinToInterrupt(lfoPin), lfo_Interruption,RISING);
  attachInterrupt(digitalPinToInterrupt(amplitudePin), amplitude_Interruption, RISING);
  Timer3.attachInterrupt(mainHandler).setFrequency(20000).start(); 
}

void mainHandler(){
  // put your main code here, to run repeatedly:
  float amostra = ((analogRead(A0)/2047.0)-1);
  // Funcao do filtro
   amostra = filter(amostra); 
  // Funcao de distorção   
  amostra = distortion(amostra); //done
  // Funcao amplitude LFO
  amostra = lfo_filter(amostra); //done
  //Amplitude sinal
  amostra = amplitude(amostra);
  // Output 
  analogWrite(DAC1, amostra);
}

void loop(){
  
}
