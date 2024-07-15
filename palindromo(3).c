#include<stdio.h>

int main(void){
  int N, cont, decision=1, repeticoes=0, letras_impares=0, flag;
  char v[100000];
  scanf("%d\n %s", &N, v);
  if(N%2==0){
    cont=1;
  }else cont=0;
  for(int y=0; y<N; y++){
    for(int k=y+1; k<N; k++){
      if(*(v+y)=='+'){
        flag=1;
      }else{ 
        if(*(v+y)==*(v+k)){
        repeticoes++;
        *(v+k)='+';
      }}
    }
    if(repeticoes%2==0 && flag!=1){
      letras_impares++;
    }
    repeticoes=0;
    flag=0;
  }
  if(*(v+N-1)=='+'){
    letras_impares--;
  }
  if(letras_impares>1 && cont==0){
    decision=0;
  }
  if(letras_impares>0 && cont==1){
    decision=0;
  }
  //o codigo ta que nem eu:horroroso, mas funcional :p
  if(decision==1){
    printf("Sim\n");
  }else printf("Nao\n");
  return 0;
}