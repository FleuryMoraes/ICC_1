#include<stdio.h>
#include<math.h>

int main (void){
unsigned short int A, B, C;
scanf("%hu %hu %hu", &A, &B, &C); 
long long int cripto; 
cripto = C;
cripto = cripto << 16;
cripto = cripto + B;
cripto = cripto << 16;
cripto = cripto + A;
printf("%lld", cripto);  

return 0; 
}  