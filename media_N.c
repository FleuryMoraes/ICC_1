#include <stdio.h>
#include <math.h>

int main (){

  int N;

  printf("escreva N (n° de números que digitará): ");

  scanf("%d", &N);

  float k;
  float soma = 0;

  for(int i=0; i<N;i++){
    scanf("%f", &k);
    soma = soma + k;
  }
  float media = (float)soma/(float)N;

  printf("A média é: %.4f", media);

return 0;  
}