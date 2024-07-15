#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//usar struct, malloc (usar funcao), char*, realloc, usar free;

struct individuo {
  int idade;
  float saldo;
  float credito;
  char *nome;
  char *CPF;
};
typedef struct individuo pessoa;

pessoa* mallocar (int N, pessoa *vetor){//passe o espaço que vc quer alocar pra esse vetor;
  vetor = (pessoa*)malloc(sizeof(pessoa)*N);
  return vetor;
}//na real isso daq eh meio inutil :( ;

void ler_dados (int inputs, pessoa **pessoas){
  int tamanho;
  char descarte;

  for (int i=0; i<inputs; i++){
    (*pessoas+i)->nome = (char*)malloc(sizeof(char)*31);
    scanf ("%s", (*pessoas+i)->nome);
    tamanho = strlen((*pessoas+i)->nome);
    (*pessoas+i)->nome[tamanho-1] = '\0';//tirando a virgula;
    (*pessoas+i)->nome = realloc ((*pessoas + i)->nome, tamanho);//checar isso daqui;

    (*pessoas+i)->CPF = (char*)malloc (sizeof(char)*12);
    scanf ("%s", (*pessoas+i)->CPF);
    tamanho = strlen ((*pessoas+i)->CPF);
    (*pessoas+i)->CPF[tamanho-1] = '\0';

    scanf ("%d", &((*pessoas+i)->idade));//pq? perguntar pro rudinei..;
    scanf ("%c", &descarte);//absorve a virgula;

    scanf ("%f", &((*pessoas+i)->saldo));
    scanf ("%c", &descarte);

    scanf ("%f", &((*pessoas+i)->credito));
  }
}

void agiotagem (int inputs, pessoa **pessoas){
  float tenho, devo;
  short unsigned int count=0;
  printf ("\n");
  printf ("Pessoas endividadas:");

  for(int i=0;i<inputs;i++){
    if ((*pessoas+i)->saldo < (*pessoas+i)->credito){
      tenho = (*pessoas+i)->saldo;
      devo = (*pessoas+i)->credito;
      printf ("\n");
      printf ("Nome: %s\n", (*pessoas+i)->nome);
      printf ("CPF: %s\n", (*pessoas+i)->CPF);
      printf ("Divida: %.2f\n", devo-tenho);
      count++;
    }
  }
  if (count == 0){
    printf("\n");
    printf("Nenhuma pessoa endividada encontrada.");
  }
}

void printar_tudo (int inputs, pessoa **pessoas){
  for (int i=0; i<inputs; i++){
    if (i>0){
      printf("\n");
    }  
    printf ("Dados da pessoa %d:\n", (i+1));
    printf ("Nome: %s\n", (*pessoas+i)->nome);
    printf ("CPF: %s\n", (*pessoas+i)->CPF);
    printf ("Idade: %d\n", (*pessoas+i)->idade);
    printf ("Saldo: %.2f\n", (*pessoas+i)->saldo);
    printf ("Credito: %.2f\n", (*pessoas+i)->credito);
  }  
}

void free_my_boy (int inputs, pessoa **pessoas){
  for (int i=0; i<inputs; i++){
    free ((*pessoas+i)->nome);
    (*pessoas+i)->nome = NULL;
    free ((*pessoas+i)->CPF);
    (*pessoas+i)->CPF = NULL;
  }
  free (*pessoas);
  *pessoas = NULL;//oxe;
}

int main (void){
  int inputs;
  scanf("%d", &inputs);
  pessoa *pessoas;
  pessoas = mallocar(inputs, pessoas);
  ler_dados (inputs, &pessoas);
  printar_tudo (inputs, &pessoas);
  agiotagem(inputs, &pessoas);
  free_my_boy(inputs, &pessoas);//usar o free bicho
  return 0;
}
