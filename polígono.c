#include <stdio.h> 
#include <math.h>

int main (){
  int N;
  double k;
  double π = 3.14159265358979323846;
  scanf("%d %lf", &N, &k); 
  double resultado = (N*pow(k,2))/(4*tan(π/N));
  printf("%lf\n", resultado);
  return 0;  
}