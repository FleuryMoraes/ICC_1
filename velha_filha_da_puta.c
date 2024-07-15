#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
  int farinha;
  int ovos;
  int oleo;
  int acucar;
  int chocolate;
} lista;

typedef struct {
  char *nome_da_receita;
  int farinha;
  int ovos;
  int oleo;
  int acucar;
  int chocolate;
} receitas;

void receita (receitas **receitinhas, int *cont){
  int i = (*cont);
  receitinhas[i]->nome_da_receita = (char*)malloc(20 * sizeof(char));
  scanf (" %19s", receitinhas[i]->nome_da_receita);
  scanf ("%d", &(receitinhas[i]->farinha));
  scanf ("%d", &(receitinhas[i]->ovos));
  scanf ("%d", &(receitinhas[i]->oleo));
  scanf ("%d", &(receitinhas[i]->acucar));
  scanf ("%d", &(receitinhas[i]->chocolate));
  *cont += 1;
}

void compras (lista *ingredientes, receitas **receitinhas){
  int f, ov, ol, a, c;
  scanf ("%d", &f);
  scanf ("%d", &ov);
  scanf ("%d", &ol);
  scanf ("%d", &a);
  scanf ("%d", &c);
  (*ingredientes).farinha += f;
  (*ingredientes).ovos += ov;
  (*ingredientes).oleo += ol;
  (*ingredientes).acucar += a;
  (*ingredientes).chocolate += c;
}

void fazer (lista *ingredientes, receitas **receitinhas, int *cont){
  int tipo;
  scanf ("%d", &tipo);
  if (tipo < *cont){
    if ((*ingredientes).farinha >= receitinhas[tipo]->farinha){
      if ((*ingredientes).ovos >= receitinhas[tipo]->ovos){
        if ((*ingredientes).oleo >= receitinhas[tipo]->oleo){
          if ((*ingredientes).acucar >= receitinhas[tipo]->acucar){
            if ((*ingredientes).chocolate >= receitinhas[tipo]->chocolate){
              (*ingredientes).farinha -= receitinhas[tipo]->farinha;
              (*ingredientes).ovos -= receitinhas[tipo]->ovos;
              (*ingredientes).oleo -= receitinhas[tipo]->oleo;
              (*ingredientes).acucar -= receitinhas[tipo]->acucar;
              (*ingredientes).chocolate -= receitinhas[tipo]->chocolate;
              printf ("%s feita com sucesso!\n", receitinhas[tipo]->nome_da_receita);
            }else{printf ("Chocolate insuficiente\n");}
          }else{printf ("Acucar insuficiente\n");}
        }else{printf ("Oleo insuficiente\n");}
      }else{printf ("Ovos insuficientes\n");}
    }else{printf ("Farinha insuficiente\n");}
  }else{printf("Receita nao encontrada!\n");}
}

void partiu_mandela (lista *ingredientes, receitas **receitinhas, int *cont){
  //dar free em tudo;
  printf ("Quantidade no estoque:\n");
  printf ("Acucar: %d\n", (*ingredientes).acucar);
  printf ("Chocolate: %d\n", (*ingredientes).chocolate);
  printf ("Farinha: %d\n", (*ingredientes).farinha);
  printf ("Oleo: %d\n", (*ingredientes).oleo);
  printf ("Ovos: %d\n", (*ingredientes).ovos);
  printf ("Receitas cadastradas: %d\n", *cont);
  for (int i=0; i<*cont; i++){
    free (receitinhas[i]->nome_da_receita);
    receitinhas[i]->nome_da_receita = NULL;
  }
  free (*receitinhas);
  *receitinhas = NULL;
  exit(1);
}

void checar_comando (char index, lista *ingredientes, receitas **receitinhas, int *cont){
  if (index == 'R') {receita (receitinhas, cont);}else{
  if (index == 'C') {compras (ingredientes, receitinhas);}else{
  if (index == 'F') {fazer (ingredientes, receitinhas, cont);}else{
  if (index == 'S') {partiu_mandela (ingredientes, receitinhas, cont);}else{
    printf("Codigo invalido\n");
  }}}}  
}

int main (void){
  int cont=0;
  char comando;
  lista ingredientes = {0,0,0,0,0};
  receitas **receitinhas = (receitas **)malloc(70*sizeof(receitas *));
  for(int i = 0; i < 70; i++){
    receitinhas[i] = (receitas *)malloc(sizeof(receitas));
  }
  while (1){
    scanf (" %c", &comando);
    checar_comando(comando, &ingredientes, receitinhas, &cont);
  }
  return 0;
}