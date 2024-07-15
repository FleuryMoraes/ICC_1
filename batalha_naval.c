#include <stdio.h>
#include <stdlib.h>

void leitura(int B, char matriz[27][27]){
  for(int i=0;i<B;i++){
    for(int u=0;u<B;u++){
      scanf(" %c", &matriz[i][u]);
    }
  }
}

void tabela(int B, char matriz[27][27], int N, char linhas[26], int colunas[26]){
  for(int i=0;i<N;i++){
    int linha = linhas[i] - 'A';
    int coluna = colunas[i] - 1;
    if(matriz[linha][coluna]=='N'){
      matriz[linha][coluna]='X';
      printf("acerto!\n");
    }else{
      printf("erro!\n");
    }
  }

  for(int i=0;i<B;i++){

    for(int u=0;u<B;u++){
      printf("%c ", matriz[i][u]);
    }
    printf("\n");
  }
}

int main(void){
  int B, N, coluna[26];

  char matriz[27][27], linhas[26];
  scanf("%d", &B);
  leitura(B, matriz);
  scanf("%d", &N);
  for(int g=0;g<N;g++){
    scanf(" %c %d", &linhas[g], &coluna[g]);
  }
  tabela(B,matriz,N,linhas,coluna);
  return 0;
}