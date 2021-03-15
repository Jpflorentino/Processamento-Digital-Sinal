#define nPontos 512
#define tamanho_loop 3

int tempo_micro = ((20/nPontos)*10^3);
volatile int index_dis = 0;
volatile int inc_dis = 0;
volatile int loop_dis = 2;
volatile float x_dis[nPontos], ult_dis = 0.0;
float incTamanho_dis[tamanho_loop] = {0.7,1.0,1.3};

float distortion (float amostra){

  x_dis[index_dis] = amostra;
  index_dis = (++index_dis % nPontos);
  ult_dis += incTamanho_dis[loop_dis];
  inc_dis = ult_dis;

  if (inc_dis >= nPontos){
    ult_dis = 0;
    inc_dis = 0;
  }

  return x_dis[inc_dis];
}

//Interruption

void distortion_Interruption(){
  noInterrupts();
  loop_dis = (++loop_dis % tamanho_loop);
  interrupts();
}
