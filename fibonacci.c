#include <stdio.h>
#include <math.h>

int main(){

int N;

printf ("Digite o termo N da sequência: ");

scanf ("%d", &N);

int último_termo = 0;
int próximo_termo = 1;
int soma = 0;

for(int i = 0; i<N; i++){
  soma = próximo_termo + último_termo;
  último_termo = próximo_termo;
  próximo_termo = soma;
}
printf("%d", próximo_termo); 
}