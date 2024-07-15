#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void imputs (int N, char ***titulo, char ***autor, int **ano){
  *titulo = (char**)malloc(sizeof(char*)*N);
  *autor = (char**)malloc(sizeof(char*)*N);
  *ano = (int*)malloc(sizeof(int)*N);
  for (int i=0; i<N; i++){
    char *leitura, *token;
    leitura = (char*)malloc(sizeof(char)*175);
    (*autor)[i] = (char*)malloc(sizeof(char)*50);
    (*titulo)[i] = (char*)malloc(sizeof(char)*100);
    scanf (" %[^\n]s", leitura);
    token = strtok(leitura, ",");
    if (token != NULL){
      strcpy((*titulo)[i], token);
      token = strtok(NULL, ",");
    }
    if (token != NULL){
      strcpy((*autor)[i], token);
      token = strtok(NULL, ",");
    }
    if (token != NULL){
      sscanf(token, "%d", &(*ano)[i]);
    }
    (*titulo)[i] = (char*)realloc((*titulo)[i], strlen((*titulo)[i])+1);
    (*autor)[i] = (char*)realloc((*autor)[i], strlen((*autor)[i])+1);
    free (leitura);
  }
}

void imprimir (int N, char ***titulo, char ***autor, int **ano){
  printf ("Catalogo de Livros:\n");
  int quantidade=0, ordem=0, getulio_vargas=0;
  for (int i=0; i<N; i++){
    for (int u=0; u<N; u++){
      if(strcmp((*titulo)[u], (*titulo)[i])==0){
        if(u < i){
          quantidade = 0;
          break;
        }  
        quantidade++;
      }
    }
    if (quantidade > 0){
      if(getulio_vargas>0){
        printf("\n");
      }
      ordem++;
      printf ("Livro %d:\n", ordem);
      printf ("Titulo: %s\n", (*titulo)[i]);
      printf ("Autor:%s\n", (*autor)[i]);
      printf ("Ano: %d\n", *(*ano+i));
      printf ("Quantidade: %d\n", quantidade);
      getulio_vargas++;
      quantidade = 0;
    }
  }
}

void liberar_memoria (int N, char ***titulo, char ***autor, int **ano){
  int u;
  for(u=0; u<N; u++){
    free ((*titulo)[u]);
    (*titulo)[u] = NULL;
  }
  free (*titulo);
  *titulo = NULL;
  for(u=0; u<N; u++){
    free ((*autor)[u]);
    (*autor)[u] = NULL;
  }
  free (*autor);
  *autor = NULL;
  free (*ano);
  *ano = NULL;
}

int main (void){
  char **titulo, **autor;
  int N, *ano;
  scanf ("%d", &N);
  imputs (N, &titulo, &autor, &ano);
  imprimir (N, &titulo, &autor, &ano);
  liberar_memoria (N, &titulo, &autor, &ano);
  return 0;
}
