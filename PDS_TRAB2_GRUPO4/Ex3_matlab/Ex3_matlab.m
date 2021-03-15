clear
clc

%Variaveis

A = 0.999;
B= 0.99;
Fs = 10000;
fc = 500;

wo = (fc*2*pi)/Fs;

%Expressões para a transformada onde A = amplitude dos zeros, B dos polos

Y = [1 -2*A*cos(wo) A^2];
X = [1 -2*B*cos(wo) B^2];

%Calcular a resposta

[H,W] = freqz(Y,X,Fs);

%resposta normalizada

resp = max(abs(H));
respn = abs(H)/resp;

%Graficos

subplot(2,1,1);
plot(W./pi,respn);
title('Amplitude normalizada');

subplot(2,1,2);
plot(W./pi, abs(H));
title('Amplitude regular');



%
