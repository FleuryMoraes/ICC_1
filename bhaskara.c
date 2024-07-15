#include <stdio.h>
#include <math.h>

int main (){

  float a, b, c, delta, r1, r2, r;

  printf("equação do 2°grau: 0=ax^2+bx+c;\ninsira respectivamente a, b, e c: \n");
  scanf("%f %f %f", &a, &b, &c);

  delta = b*b - 4*a*c;

  if (delta<0){
    printf("sem raízes reais");
  }else{
    if(delta==0){
      r=-b/2*a;
      printf("raíz única: %f", r);
        }else{
        r1 = (-b + sqrtf(delta))/(2*a);
        r2 = (-b - sqrtf(delta))/(2*a);
        printf("r1=%f\nr2=%f", r1, r2);

    }
  }



return 0;
}