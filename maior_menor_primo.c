#include <stdio.h>

int main (void){
  int A, B, i, p2, k, p1;
  scanf("%d %d", &A, &B);

  for(int b=B; b>=A; b--){  

    k = 1;
    for (i=b-1;i>1;i--){
      if ((b%i)==0)
      {
        k = 0, p2=0;
        break;
      }
    }

    if(k == 1){
      p2=b;
      break;
    }

  }
  for(int a=A; a<=B; a++){  

    k = 1;
    for (i=a-1;i>1;i--){
      if ((a%i)==0)
      {
        k = 0, p1=0;
        break;
      }
    }

    if(k == 1){
      p1=a;
      break;
    }

  }
  if(p1==1){p1++;}
  if(p1==0||p2==0){printf("nenhum primo no intervalo");}
  else{printf("menor primo: %d\nmaior primo: %d", p1 ,p2);}
  return 0;
}  

