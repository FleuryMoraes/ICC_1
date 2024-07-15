#include<stdio.h>
#include<ctype.h>//pro upper;

int main(void){
  int v[2000], p, k, i=0, indice, j=1, fibonacci=1;
  char comando;
  while(1>0){
    scanf(" %d", (v+i));
    if(*(v+i)==1){break;}
    else {i++;}
  }
  scanf("\n%c", &comando);
 if((int)comando==97){
   printf("vetor ordenado:");
   for(k=0; k<=i+1; k++){
     for(int y=0; y<i-1; y++){
       if(*(v+y)>*(v+y+1)){
         p=*(v+y);
         *(v+y)=*(v+y+1);
         *(v+y+1)=p;
      }
    }
  }
   for(int g=0;g<i;g++){
     printf("%d ", *(v+g));
   }
  }
  if((int)comando==98){
    printf("Numeros de Fibonacci:");
    for(int u=0; u<i; u++){
      for(k=0; k<23; k++){
        fibonacci=fibonacci+j;
        j=fibonacci-j;
        if(fibonacci==*(v+u)){
        printf("%d ", *(v+u));
        }
      }
      fibonacci=1; j=1;
    }
  }
  if((int)comando==99){
    printf("Vetor maiusculo:");
    for(int r=0; r<i; r++){
      printf("%c ", toupper((char)*(v+r)));
    }
  }
  if((int)comando<97 || (int)comando>99){
  printf("Comando inexistente\n");
  }
  return 0;
}