#include <stdio.h>

int main (){

int troco, resto;

scanf("%d", &troco);

printf("%d nota(s) de R$ 200\n", resto = troco/200);
troco = troco -resto*200;
printf("%d nota(s) de R$ 100\n", resto = troco/100);
troco = troco -resto*100;
printf("%d nota(s) de R$ 50\n", resto = troco/50);
  troco = troco -resto*50;
  printf("%d nota(s) de R$ 20\n", resto = troco/20);
  troco = troco -resto*20;
  printf("%d nota(s) de R$ 10\n", resto = troco/10);
  troco = troco -resto*10;
  printf("%d nota(s) de R$ 5\n", resto =troco/5);
  troco = troco -resto*5;
  printf("%d nota(s) de R$ 2\n", resto = troco/2);
  troco = troco -resto*2;
  printf("%d moeda(s) de R$ 1\n", troco);

  return 0;
}