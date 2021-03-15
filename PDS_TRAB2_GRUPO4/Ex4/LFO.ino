#define numlfo 4

float Amp = 1;
volatile float ylfo[2] = {0,0};
volatile float xlfo[2] = {Amp,0};
volatile float xf = 0;
volatile float out_lfo = 0.0;
volatile float vlfo = 0.0;
volatile int index_lfo = 3;

float freq_lfo[numlfo] = {1.0, 5.0, 10.0, 40.0};

void setup_lfo(){
  vlfo = - cos((2.0*PI*freq_lfo[index_lfo])/20000.0);
  xf = 2 * vlfo;
}

float lfo_filter (float amostra) {
  noInterrupts();
  out_lfo = (xlfo[0]  + vlfo * xlfo[1]);
  out_lfo = out_lfo - (ylfo[0] * xf + ylfo[1]);

  ylfo[1] = ylfo[0];
  ylfo[0] = out_lfo;
  xlfo[1] = xlfo[0];
  xlfo[0] = 0;

  interrupts();

  return out_lfo* amostra;
}

void lfo_Interruption(){
noInterrupts();
index_lfo = ++index_lfo %numlfo;
vlfo = -cos((2.0*PI*freq_lfo[index_lfo])/20000.0);
xf = 2* vlfo;

ylfo[1] = 0;
ylfo[0] = 0;
xlfo[1] = 0;
xlfo[0] = Amp;
interrupts();
}
