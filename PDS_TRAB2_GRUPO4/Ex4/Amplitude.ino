//Inicio Funcao amplitude
#define maxAmp 3.3
#define nAmp 5

volatile int index_amp = 4;
float amp_array[nAmp] = {787,  1000,    1269,    1612,    2047};

float amplitude (float amostra){
  return amostra * amp_array[index_amp];
}

void amplitude_Interruption(){
  noInterrupts();
  index_amp = ++index_amp % nAmp;
  interrupts();
}
//Fim da funcao
