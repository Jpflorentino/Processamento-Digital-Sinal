%%Variaveis
%Amplitude
A = 63;
%Frequencia
f0 = 100;
%Periodo
t0 = 1/f0;
%Amostras
N = 64;

t = 0:(t0/(N-1)):t0;

figure
%%Sinusoidal
x1 = round( A * Sinusoidal(2*pi*f0*t) + A);
subplot(4,1,1);
plot (t,x1)

%%Rampa 
x2 = round(A * Rampa(2*pi*f0*t) + A);
subplot(4,1,2);
plot (t,x2)

%%Triangular
x3 = round(A * Triangular(2*pi*f0*t, 1/2) + A);
subplot(4,1,3);
plot (t,x3)

%%Quadrada
x4 = (A * Square(2*pi*f0*t) + A);
subplot(4,1,4);
plot (t,x4)
