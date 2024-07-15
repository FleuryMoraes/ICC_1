#include<stdio.h>

int main(void){
  int A, B, a[10], b[10], y, m, flag=0;
  scanf("%d\n", &A);
  for(y=0; y<A; y++){
    scanf("%d", (a+y));
  }
  scanf("%d\n", &B);
  for(y=0; y<B; y++){
    scanf("%d", (b+y));
  }
  printf("intersecao:");
  for(y=0; y<A; y++){
    for(m=0; m<B; m++){
      if(a[y]==b[m]){
        printf(" %d", a[y]);
        flag++;
      }
    }
  }
  if(flag==0)printf(" vazio");
  flag=0;
  printf("\na - b:");
  for(y=0; y<A; y++){
    for(m=0; m<B; m++){
      if(a[y]==b[m]){
        a[y]='%';
      }
    }
  }
  for(y=0; y<A; y++){
    if(a[y]!='%'){
      printf(" %d", a[y]);
      flag++;
    }
  }
  if(flag==0)printf(" vazio");
  return 0;
}