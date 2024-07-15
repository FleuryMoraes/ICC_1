#include<stdio.h>

int main (void){
  int n, pontuacao[100], ordem[100], i, k, *p, posicao, h=0, dado, colocacao=0;
  p=&posicao;
  scanf("%d", &n);
  for(i=0; i<n; i++){
    scanf("%d", (pontuacao+i));
    *(ordem+i)=*(pontuacao+i);
  }//bubble sort;
  for(i=1; i<n; i++){
    for(k=0; k<n-i; k++){
      if(*(ordem+k)>*(ordem+k+1)){
        *p=*(ordem+k);
        *(ordem+k)=*(ordem+k+1);
        *(ordem+k+1)=*p;
      }
    }
  }
  k=0;
  for(i=0;i<n;i++){
    colocacao=0;
    for(posicao=0;posicao<n;posicao++){
      if(*(ordem-posicao+n)!=*(ordem-posicao-1+n)){
        colocacao++;
      }
      if(*(ordem-posicao+n-1)==*(pontuacao+i)){break;}
    }
    printf("%dº Atleta, %d Pontos, %dº Colocado\n", (i+1), *(pontuacao+i), colocacao);
  } 
  return 0;
}
