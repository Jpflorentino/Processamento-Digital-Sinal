// Exemplo utilizacao Arduino timer CTC interrupt
// Versao INEFICIENTE
// Paulo Marques - ISEL - Out 2014
// Bibliotecas avr: (constantes atmel )
#include <avr/io.h>
#include <avr/interrupt.h>
#define AIN A0
#define WATCHDOG_PIN 13 //Para debug
volatile int watchdog_val =LOW;
volatile boolean time_to_sample = false;


//Interrupt Service Routine
ISR(TIMER1_COMPA_vect)
{
time_to_sample = true;
}

void setup(){
// Colocar pinos PORTA como output
for(int i=22; i<30; i++){
pinMode(i,OUTPUT);
}
//pinMode(WATCHDOG_PIN, OUTPUT); //p/debug

// Iniciar timer
cli(); // desativar interrupções globais
// TCCR = Timer/Counter control register
TCCR1A = 0; // registo TCCR1A = 0
TCCR1B = 0; // registo TCCR1B = 0
// preparar comparador para interrupção
// OCR - Output Compare Register
//OCR1A = 1600; // Fs = 16MHz / OCR1A = 10kHz
OCR1A = 3200; // Fs=5kHz
// ativar modo Clear Timer on Compare (CTC)
match
TCCR1B |= (1 << WGM12);
// bit prescaler CS10 = 1
TCCR1B |= (1 << CS10);
// ativar interrupção pelo comparador do timer:
TIMSK1 |= (1 << OCIE1A);
// ativar interrupções globais:
sei();
}

void loop(){
static float sample_inf, sample_outf;
static int sample_in;
static int sample_out;
static int i;
// esperar tempo para nova amostra
while(!time_to_sample){};
time_to_sample = false;
PORTA = sample_out
//Obter nova amostra e escalar para float
//no intervalo -0.5 ... +0.5
sample_inf = float(analogRead(AIN))/1024.0-0.5;
// processamento...
// ...
// ...
sample_outf=sample_inf;
// preparar próxima amostra de saida
sample_out=int((sample_outf+0.5)*128);
// para debug...
// digitalWrite(WATCHDOG_PIN, watchdog_val);
// watchdog_val=!watchdog_val;
}
