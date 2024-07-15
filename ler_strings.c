#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* mallocar (char **string, int size){
  (*string) = (char*)malloc (sizeof(char)*size);
  return *string;
}

void reallocar (char **string){
  int tamanho;
  tamanho = strlen (*string);
  (*string) = realloc (*string, tamanho+1);
}

void ler_inputs (char **strA,char **strB,char **parametro){
  *strA = mallocar (strA, 121);//estudar esse caso aq;
  *strB = mallocar (strB, 121);
  *parametro = mallocar (parametro, 30);
  scanf (" %[^\n\r]s", *strA);
  scanf (" %[^\n\r]s", *strB);
  scanf (" %[^\n\r]s", *parametro);
  reallocar (strA);
  reallocar (strB);
  reallocar (parametro);
}

void printar_resultados (char **strA,char **strB,char **parametro){
  int tamanho, count=0, flag=0;
  char *vetor, *vetor2;

  if (*strA != NULL){
    vetor = strstr (*strA, *parametro);
    if(vetor != NULL){
      int marajo = strlen (*strA) - strlen (vetor);
      while (marajo>0){
        printf ("%c", *(*strA+count));
        count++;
        marajo--;
      }
      }else{
        printf ("%s", *strA);
    }  
  }


  count = 0;
    tamanho = strlen (*parametro);
    if (*strB != NULL){
      vetor2 = strstr (*strB, *parametro);
      if(vetor == NULL && (*strB)[tamanho]==32){
        printf(" ");
      }
      if (vetor2 != NULL){ 
        while (*(vetor2 + count + tamanho +1) != '\0'){
          printf ("%c", *(vetor2 + count + tamanho +1));
          count++;
        }
      }  
    }  
  }


void livrar_servos (char **strA,char **strB,char **parametro){
  free (*strA);
  *strA = NULL;
  free (*strB);
  *strB = NULL;
  free (*parametro);
  *parametro = NULL;
}

int main (void){
  char *strA, *strB, *parametro;
  ler_inputs(&strA, &strB, &parametro);
  printar_resultados(&strA, &strB, &parametro);
  livrar_servos(&strA, &strB, &parametro);//lembrar que tu mudou o vetor com string.h ent nn da pora dar free;
  return 0;
}