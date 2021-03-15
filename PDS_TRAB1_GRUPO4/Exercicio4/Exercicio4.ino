#include <avr/io.h>

#define AIN A0

//N definido base 2 ( entre 2 e 8)
#define N 8
#define Nfloat 8.0

// definição dos arrais x[] (amostras) e h[](resposta impulsional)

float x[N] = {0};
float h[N] = {0};

// index array de amostras

int index = 0;
int auxiliar = 0;

void setup() {

 for(int i=22; i<30; i++) {

  pinMode(i,OUTPUT);

 }

 //necessário fazer um ciclo para preencher o array h[] com o valor 1/N
  for (int i=0; i<Nfloat; i++){
    h[i] = 1.0/Nfloat; 
  }
  Serial.begin(1200);
}


void loop() {
  static float sample_inf;
  static float sample_outf;
  static int sample_out;

  PORTA = sample_out;
  //Para obter nova amostra e passar a float no intervalo -0.5/0.5

  sample_inf =(float(analogRead(AIN))/1023.0)-0.5;
  
  x[index] = (sample_inf)*255;
  sample_outf = 0; //Valor de y antes do for
  
  for (int k = 0, auxiliar = index; k < N; auxiliar--,k++){ //k do array h e auxiliar do array aux
     sample_outf = sample_outf + (x[auxiliar] * h[k]);
     if(auxiliar == 0){
      auxiliar = N-1;
     }
  }
  
  index = (index++) & (N-1); //incremento do indice até 7 , quando chega a 7 volta a 0
  sample_outf = sample_outf + 127.5;
  sample_out = sample_outf;//Passar de float para int
  Serial.println(sample_out);
  delayMicroseconds(200);
  
}
