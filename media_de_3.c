#include <stdio.h>
#include <math.h>

int main (){
  
  float x, y, z;
  
  scanf("%f %f %f", &x, &y, &z);
  
  float media;
  media = (float)(x+y+z)/3;

  printf("%.10f", media);
  
return 0;
}