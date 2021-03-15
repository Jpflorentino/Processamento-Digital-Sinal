#define nfiltro 4
#define N 4
#define Rz 0.9
#define Rp 0.99


float freqFiltro = 0.0;
int index_filtro = 0;

float freq[nfiltro] = {1000,2000,3000,5000};
float Out[N];
float Out2[N];

float volatile In_filtro[N] = {0.0,0.0,0.0} , In2_filtro[N-1] = {0.0,0.0};
float volatile out_filtro = 0.0;

void setup_filtro(){
  freqFiltro = (freq[index_filtro]/20000.0)*2.0*PI;
  Out[0] = 1.0;
  Out[1] = -2.0*Rz*cos(freqFiltro);
  Out[2] = Rz*Rz;
  Out2[0] = 1.0;
  Out2[1] = -2.0*Rp*cos(freqFiltro);
  Out2[2] = Rp*Rp;
}

float filter(float am){
  In_filtro[0] = am;
  out_filtro = In_filtro[0] + (Out[1] * In_filtro[1]) + (Out[2] * In_filtro[2]);
  out_filtro -= (Out2[1] *In2_filtro[0])+(Out2[2] * In2_filtro[1]);

  In_filtro[2] = In_filtro[1];
  In_filtro[1] = In_filtro[0];

  In2_filtro[1] = In2_filtro[0];
  In2_filtro[0] = out_filtro;
  //1.0091
  //9.956
  return (out_filtro/9.956);
}

void filter_Interruption(){
  noInterrupts();
  index_filtro = ++index_filtro % nfiltro;
  freqFiltro = (freq[index_filtro]/20000.0)*2.0*PI;
  interrupts();
}
