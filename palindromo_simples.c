#include<stdio.h>

int main (void){
  int numero, flag=0;
  char palavra[100]={'\0'}, palavra_invertida[100]={'\0'};
  scanf("%d\n", &numero);
  for(int i=0; i<numero; i++){
    for(int z=0;z<100;z++){
      palavra_invertida[z]='\0';
      palavra[z]='\0';
    }
    scanf("%s", palavra);
    for(int h=0, j=0; h<100; h++){
      if(palavra[99-h]!='\0'){
        palavra_invertida[j]=palavra[99-h];
        j++;
      }
    }
    for(int y=0; y<100; y++){
      if(*(palavra+y)=='\0' || *(palavra_invertida+y)=='\0'){
        break;
      }
      if(*(palavra+y)!=*(palavra_invertida+y)){
        flag=1;
        break;
      }
    }
    if(flag==0){
      printf("%s eh um palindromo\n", palavra);
    }else{
      printf("%s nao eh um palindromo\n", palavra);
    }
    flag=0;
  }

  return 0;
}