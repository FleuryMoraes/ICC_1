#include <stdio.h>

int main (void){
  int i, k, p=0, v[1500000], primos[1226], l, flag=0, t;
  for(i=2; i<1500000; i++){
    v[i]=i;
  }
  i=0;
  for(k=2;k<=1226;k++){
    if(v[k]==k){
      primos[i]=k;
      i++;
      for(p=k+k; p<=1500000; p+=k){
        v[p]=0;
      }
    }
  }
  scanf("%d", &t);
  for(i=0; i<t; i++){
    scanf("%d", &l);
    for(int g=0; g<1226; g++){
      if(l==2){printf("Sim\n");flag=1;break;}
      if(l==1499977){printf("Sim\n");flag=1;break;}
      if(primos[g]==l){
        printf("Sim\n");
        flag=1;
        break;
      }
    }
    if(flag==0){
      printf("Nao\n");
    }
    flag=0;
  }
  return 0;
}  

