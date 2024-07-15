#include <stdio.h>
#include <math.h>

int main (){

printf("digite o número que tu queres: ");

int k; 

scanf("%d", &k);

int medidor = 1;
int acúmulo = 1;

if (k==0){printf("1");}
  else {
    while (k>=medidor){
      acúmulo = acúmulo*medidor;
      medidor = medidor + 1;
  }
       }
printf("%d! = %d", k, acúmulo);


return 0;  
}