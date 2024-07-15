#include<stdio.h>

void marcar_os_cosplayers(char matriz[20][20], int linhas, int colunas, int linha[100], int coluna[100]){
  int h=0;
  for (int i=0; i<linhas; i++){
    for (int u=0; u<colunas; u++){
      if (matriz[i][u]=='c'){
        linha[h]=i;
        coluna[h]=u;
        h++;
      }
    }
  }
}

void demarcar_lugares(char matriz[20][20], int linhas, int colunas, int linha[100], int coluna[100], int *p){
  int h=0, g=0;
  for (int i=0; i<linhas; i++){
    for (int u=0; u<colunas; u++){
      while(g<100){
        if(i==linha[h]||u==coluna[h]){
          matriz[i][u]='x';
          break;
        }
        h++;
        g++;
      }
      h=0;
      g=0;
      if(matriz[i][u]=='x'||matriz[i][u]=='f'){
        matriz[i][u]='x';
      }else{
        matriz[i][u]='o';
        *p+=1;
      } 
    }
  }
}

int main(void){
  int N, M, cont=0, *p, g=0;
  p=&cont;
  int linhas_lixo[100];
  int colunas_lixo[100];
  while(g<100){
    linhas_lixo[g]=1000;
    colunas_lixo[g]=1000;
    g++;
  }
  char matriz[20][20];
  scanf("%d", &N);
  scanf("%d", &M);
  for(int i=0; i<N; i++){
    for(int u=0; u<M; u++){
      scanf(" %c", &matriz[i][u]);
    }
  }
  marcar_os_cosplayers(matriz, N, M, linhas_lixo, colunas_lixo);
  demarcar_lugares(matriz, N, M, linhas_lixo, colunas_lixo, p);
  if(cont>0){
    for(int i=0; i<N; i++){
      for(int u=0; u<M; u++){
        printf("%c ", matriz[i][u]);
        if(u==M-1){printf("\n");}
      }
    }
  }else{printf("Eh um dia triste para os mono Yasuo\n");}
  return 0;
}