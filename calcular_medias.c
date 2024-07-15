#include <stdio.h>

void ler_matriz(int linhas, int colunas, float matriz[100][25]){
  for (int i=0; i<linhas; i++){
    for (int j=0; j<colunas; j++){
      scanf("%f", &matriz[i][j]);
    }
  }
}

void calcular_medias(int linhas, int colunas, float matriz[100][25]){
  float soma_notas, nota, dp=1;
  for (int i=0; i<linhas; i++){
    nota=0;
    soma_notas=0;
    for (int j=0; j<colunas; j++){
      soma_notas += matriz[i][j];
    }
    nota = soma_notas/colunas;
    printf("Media do aluno %d = %.2f : ", (i+1), nota);
    if(nota>=5){
      dp=0;
      printf("Aprovado\n");
    }else{
      printf("Reprovado\n");
    }
  }
}

void medias_provas(int linhas, int colunas, float matriz[100][25]){
  int cont=0;
  float medias, somas, swap;
  float vetor_medias[25];
  for (int j=0; j<colunas; j++){
    medias=0;
    somas=0;
    for (int i=0; i<linhas; i++){
      somas += matriz[i][j];
    }
    medias = somas/linhas;
    vetor_medias[j]=medias;
    cont++;
  }
  for(int j=0; j<cont-1; j++){
    for (int k=0; k<cont-1; k++){
      if(vetor_medias[k]>vetor_medias[k+1]){
        swap=vetor_medias[k];
        vetor_medias[k]=vetor_medias[k+1];
        vetor_medias[k+1]=swap;
      }
    }
  }
  for(int i=0; i<cont; i++){
    printf("%.2f ", vetor_medias[cont-1-i]);
  }
}

int main (void){
  int N, M;
  float matriz[100][25];
  scanf("%d %d", &N, &M);
  ler_matriz(N, M, matriz);//funcao pra ler a matrizinha
  calcular_medias(N, M, matriz);//funcao
  printf("\n");
  medias_provas(N, M, matriz);//funcao
  return 0;
}