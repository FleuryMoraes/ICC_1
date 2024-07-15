#include<stdio.h>
#include<stdlib.h>
//armazenamento totalmente dinamico, e descobrir o tamanho do arquivo antes, para esse fim;
//liberar memoria e fechar arquivo;

int extensao_do_file (FILE **fp);
void free_the_younglings (char **str1, char **str2);

int main (void){
  FILE *fp;
  char *buffer, *arquivo;
  int tamanho;

  arquivo = (char*)malloc (sizeof(char)*50);
  scanf ("%s", arquivo);
  fp = fopen(arquivo, "rb");
  if (fp == NULL) {
    printf ("Impossivel abrir o file\n");
    free (arquivo);
    free (buffer);
    exit(1);
  }
  tamanho = extensao_do_file (&fp);
  buffer = (char*)malloc (sizeof (char)*(tamanho+1));
  if (buffer == NULL){
    printf("Cagou a alocacao dinamica!\n");
    free (arquivo);
    free (buffer);
    exit(1);
  }
  fseek(fp, 0, SEEK_SET); 
  fread (buffer, sizeof (char)*tamanho, 1, fp);
  printf ("%s\n", buffer);
  free_the_younglings (&buffer, &arquivo);
  fclose (fp);

  return 0;
}

int extensao_do_file (FILE **fp){
  int num_caracteres = 0;
  char bufferzin;
  fseek (*fp, 0, SEEK_SET);
  while (!feof (*fp)){
    bufferzin = fgetc (*fp);
    num_caracteres++;
  }
  return num_caracteres;
}

void free_the_younglings (char **str1, char **str2){
  free (*str1);
  free (*str2);
}