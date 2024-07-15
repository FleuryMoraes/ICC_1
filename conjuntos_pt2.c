#include<stdio.h>
#include<stdlib.h>

void ler_vetor(int size, int **vetor){
  *vetor=(int*)malloc(sizeof(int)*size);
  for (int i=0; i<size; i++){
    scanf("%d", *vetor+i);
  }
  int armazem;
  for(int y=0; y<size-1; y++){
    for(int x=0; x<size-1-y; x++){
      if(*(*vetor+x)>*(*vetor+x+1)){
        armazem=*(*vetor+x);
        *(*vetor+x)=*(*vetor+x+1);
        *(*vetor+x+1)=armazem;
      }
    }
  }
}//funcionando!

int bubble_sort(int size, int **vetor){
  int armazem;
  for(int y=0; y<size-1; y++){
    for(int x=0; x<size-1-y; x++){
      if(*(*vetor+x)>*(*vetor+x+1)){
        armazem=*(*vetor+x);
        *(*vetor+x)=*(*vetor+x+1);
        *(*vetor+x+1)=armazem;
      }
    }
  }
}

int* unir_conjuntos(int size1,int size2,int **vetor1,int **vetor2, int *size3){
  int *uniao;
  uniao=(int *)malloc(sizeof(int)*(size1*size2));
  int y=0, flag, k=0;
  for(int i=0;i<size1;i++,y++){
    *(uniao+y)=*(*vetor1+i);//uniao=A
  }
  for(int u=0;u<size2;u++){
    flag=0;
    for(int h=0;h<size1;h++){
      if(*(uniao+h)==*(*vetor2+u)){
        flag=1;
        break;
      }
    }
    if(flag==0){
      *(uniao+y+k)=*(*vetor2+u);//se esse elemento de B nn estiver la, adicione-o;
      k++;
    }
  }
  *size3=y+k;
  uniao=(int*)realloc(uniao, (*size3)*sizeof(int));//devolvo soh o suficiente;
  return uniao;//igualar a um ponteiro
}

int* ultimo_treco(int size1,int size2,int **vetor1,int **vetor2,int **uniao, int size3, int *size4){//revisar esse garotao
  int *outro;
  int *finalzin;
  outro=(int*)malloc(sizeof(int)*10000);
  finalzin=(int*)malloc(sizeof(int)*10000);
  int bilau=0, calcinha=0;
  for(int u=0; u<size1; u++){
    bilau=0;
    for(int h=0; h<size2; h++){
      if(*(*vetor1+u)==*(*vetor2+h)){
        bilau++;
      }
    }
    if(bilau>0){
      *(outro+calcinha)=*(*vetor1+u);
      calcinha++;
    }
  }//o exclusivo de A ta pronto ja;
  int carlos=0, clash_royale=0;
  for(int u=0; u<size3; u++){
    carlos=0;
    for(int h=0; h<calcinha; h++){
      if(*(*uniao+u)!=*(outro+h)){
        carlos++;
      }
    }
    if(carlos==calcinha){
      *(finalzin+clash_royale)=*(*uniao+u);
      clash_royale++;
    }
  }//era pra estar show de bola;
  *size4=clash_royale;
  finalzin=(int*)realloc(finalzin, sizeof(int)*clash_royale);
  return finalzin;
}

void imprimir (int **vetor1,int **vetor2,int **vetor_treco,int **uniao,int size1,int size2,int size3,int size4){
  int ai;
  printf("conjunto A: ");
  for(ai=0;ai<size1;ai++){
    printf("%d ", *(*vetor1+ai));
  }
  if(size1==0){printf("vazio");}
  printf("\n");
  printf("conjunto B: ");
  for(ai=0;ai<size2;ai++){
    printf("%d ", *(*vetor2+ai));
  }
  if(size2==0){printf("vazio");}
  printf("\n");
  printf("A uniao B: ");
  for(ai=0;ai<size3;ai++){
    printf("%d ", *(*uniao+ai));
  }
  if(size3==0){printf("vazio");}
  printf("\n");
  printf("(A uniao B) - (A interseccao B): ");
  for(ai=0;ai<size4;ai++){
    printf("%d ", *(*vetor_treco+ai));
  }
  if(size4==0){printf("vazio");}
  printf("\n");
}

int main (void){
  int tam1, tam2, tam3, tam4, *V1, *V2, oloco;
  scanf("%d", &tam1);
  ler_vetor(tam1, &V1);
  scanf("%d", &tam2);
  ler_vetor(tam2, &V2);
  int *VUV;
  VUV=unir_conjuntos(tam1, tam2, &V1, &V2, &tam3);//tem que determinar o tamanho e fazer o bubble
  int *VV;
  VV=ultimo_treco(tam1, tam2, &V1, &V2, &VUV, tam3, &tam4);//retornam vetores;
  bubble_sort(tam3, &VUV);
  bubble_sort(tam4, &VV);
  imprimir(&V1, &V2, &VV, &VUV, tam1, tam2, tam3, tam4);
  free(V1);
  free(V2);
  free(VUV);
  free(VV);
  return 0;
}