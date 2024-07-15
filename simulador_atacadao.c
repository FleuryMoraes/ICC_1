#include<stdio.h>

int main(void){
  int produto, flag;
  float compra[100], venda[100], adquirido[100], vendido[100], saldo=0, karl_marx=0;
  scanf("%d", &produto);
  if(produto==0){
    printf("Sem atividades registradas hoje\n");
  }else{
  for(int k=0; k<produto; k++){
    scanf("%f %f %f %f", (compra+k), (venda+k), (adquirido+k), (vendido+k));
    float total = *(venda+k)*(*(vendido+k))-*(compra+k)*(*(adquirido+k));
    if(total>karl_marx){
      karl_marx=(total);
      flag=k;
    }
    saldo = saldo + (total);
  }
  float lucro_relativo = *(venda+flag)*(*(vendido+flag))-*(compra+flag)*(*(adquirido+flag));
  if(saldo>=0){
    printf("lucro: %.2f\n", saldo);
  }else{
    saldo=saldo*(-1);
    printf("prejuizo: %.2f\n", saldo);
  }
  flag++;
  printf("produto: %d lucro relativo: %.2f\n", flag, lucro_relativo);
  }
  return 0;
}