#include<stdio.h>
#include<stdlib.h>
//ta pagando mt 

void ler_tabuleiro(int linhas, int colunas, char ***matriz){
  (*matriz) = (char **)malloc(sizeof(char *)*linhas);
  for (int i=0; i<linhas; i++){
    (*matriz)[i] = (char *)malloc(sizeof(char)*colunas);
    for (int j=0; j<colunas; j++){
      scanf(" %c", &(*matriz)[i][j]);
    }
  }
}

void marcar_posicoes(int linhas, int colunas, char ***matriz){
  int paridade=0;
  for (int i=0; i<linhas; i++){
    for (int j=0; j<colunas; j++){
      paridade=0;
      //nn esta lendo o ultimo elemento??;
      if((*matriz)[i][j]=='.'){
        //faz diferença a ordem que eu coloco o baguio??;
        if(i+1<linhas && (*matriz)[i+1][j]=='X'){
          paridade++;
        }
        if(i>=1 && (*matriz)[i-1][j]=='X'){
          paridade++;
        }
        if(j+1<colunas && (*matriz)[i][j+1]=='X'){
          paridade++;
        }
        if(j>=1 && (*matriz)[i][j-1]=='X'){
          paridade++;
        }
        if(paridade%2==0){
          (*matriz)[i][j]='*';
        }
      }  
    }
  }  
}

void printar_tabuleiro(int linhas, int colunas, char ***matriz){
  for (int i=0; i<linhas; i++){
    for (int j=0; j<colunas; j++){
      printf("%c", (*matriz)[i][j]);
      if(j==colunas-1){printf("\n");}
    }
  }
}

int main(void){
  int N, M;
  char **tabuleiro;
  scanf ("%d %d", &N, &M);
  ler_tabuleiro(N, M, &tabuleiro);
  marcar_posicoes(N, M, &tabuleiro);
  printar_tabuleiro(N, M, &tabuleiro);
  for(int i=0; i<N; i++){
    free(tabuleiro[i]);
    tabuleiro[i]=NULL;
  }
  free(tabuleiro);
  tabuleiro=NULL;
  return 0;
}
