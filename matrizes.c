#include<stdio.h>
#include<stdlib.h>

void imprimir_matriz(int N, int M, int ***matriz_1, int ***matriz_2);
void multiplicacao(int N, int M, int ***matriz_1, int ***matriz_2);

int main(void){
  int N, M;
  scanf("%d", &N);
  scanf("%d", &M);
  int **matriz_1, **matriz_2;

  matriz_1 = (int **)malloc(sizeof(int*) * N);
  for (int i=0; i<N; i++){
    matriz_1[i] = (int*)malloc(sizeof(int) * N);
    for (int u=0; u<N; u++){
      scanf("%d", &matriz_1[i][u]);
    }
  }

  matriz_2 = (int **)malloc(sizeof(int*) * M);
  for (int i=0; i<M; i++){
    matriz_2[i] = (int*)malloc(sizeof(int) * M);
    for (int u=0; u<M; u++){
      scanf("%d", &matriz_2[i][u]);
    }
  }
  imprimir_matriz(N,M,&matriz_1,&matriz_2);
  multiplicacao(N,M,&matriz_1,&matriz_2);
  return 0;
}

void imprimir_matriz(int N, int M, int ***matriz_1, int ***matriz_2){
  printf("Matrizes:\n");
  int i, u, diagonal1=0, diagonal2=0;
  for (i=0; i<N; i++){
    for (u=0; u<N; u++){
      if(i!=u){
        if((*matriz_1)[i][u]==0){
          diagonal1++;
        }
      }  
      printf("%d ", (*matriz_1)[i][u]);
      if(u==N-1){printf("\n");}
    }
  }  
  for (i=0; i<M; i++){
    for (u=0; u<M; u++){
      if(i!=u){
        if((*matriz_2)[i][u]==0){
          diagonal2++;
        }
      }  
      printf("%d ", (*matriz_2)[i][u]);
      if(u==M-1){printf("\n");}
    }
  }//tambem checa se eh ou nao diagonal;
  if(diagonal1==N*(N-1)){
    printf("A matriz 1 eh diagonal\n");
  }else{
    printf("A matriz 1 nao eh diagonal\n");
  }
  if(diagonal2==M*(M-1)){
    printf("A matriz 2 eh diagonal\n");
  }else{
    printf("A matriz 2 nao eh diagonal\n");
  }
}

void multiplicacao(int N, int M, int ***matriz_1, int ***matriz_2){
  if(N==M){
    printf("Matriz multiplicada:\n");
    int i,u,produto,flag;
    for (i=0; i<N; i++){
      for (u=0; u<N; u++){
        flag=0;
        produto=0;
        while(flag<N){
          produto += (*matriz_1)[i][flag]*(*matriz_2)[flag][u];
          flag++;
        }
        printf("%d ", produto);
        if(u==N-1){printf("\n");}
      }
    }
  }else{
    printf("Matrizes de tamanho incompativel\n");
  }
}