#include <stdio.h>
#include <math.h>

int main (){

int x, y, z;

printf("Digite o 3 dígitos do arrangement:\n");
scanf("%d %d %d", &x, &y, &z);

printf("ordem crescente:\n ");

//sejam x, y, z equivalentes a X, Y, Z
int X = x, Y = y, Z = z;

while (X>=0 || Y>=0 || Z>=0){

  if(X==0){
    printf("%d\n", x); 
    while ( Y>=0 || Z>=0){
      if(Y==0){
        printf("%d\n%d", y, z); break;
      }else {Y=Y-1;}
      if(Z==0){
        printf("%d\n%d", z, y); break;
      }else {Z=Z-1;}
    }
    break;
  }else {X=X-1;}

  if(Y==0){
    printf("%d\n", y); 
    while (X>=0 || Z>=0){
      if(X==0){
        printf("%d\n%d", x, z); break;
      }else {Y=Y-1;}
      if(Z==0){
        printf("%d\n%d", z, x); break;
      }else {Z=Z-1;}
    }
    break;
  }else {Y=Y-1;}

  if(Z==0){
    printf("%d\n", z);
    while ( Y>=0 || X>=0){
      if(Y==0){
        printf("%d\n%d", x, y); break;
      }else {Y=Y-1;}
      if(X==0){
        printf("%d\n%d", y, x); break;
      }else {Z=Z-1;}
    }
    break;
  }else {Z=Z-1;}
}


return 0;
}