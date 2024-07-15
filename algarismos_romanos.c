#include <stdio.h>

void ROMANOS(
    int x,
    char *resposta) { // criei a funcao pra transformar em algarismo romano
  char caracteres[13][3] = {"M\0\0", "CM\0",  "D\0\0", "CD\0",  "C\0\0",
                            "XC\0",  "L\0\0", "XL\0",  "X\0\0", "IX\0",
                            "V\0\0", "IV\0",  "I\0\0"};
  int numeros[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
  int desconto = 0, i = 0, t = 0, j = 0;
  for (int y = 0; y < 13;
       y++) { // vai passando do M ate o I, ou seja, do maior ao menor;
    if (x >= numeros[y]) { // vai checando ate qual numero o input eh maior; ex:
                           // 35>+10;
      desconto =
          (int)x /
          numeros[y]; // desconto: quantas vezes o algarismo "cabe" no input;
      x = x - desconto * numeros[y]; // subtrai o numero de algarismos romanos
                                     // (em numero) do input;
      while (desconto > 0) {
        t = 0;
        j = 0;
        desconto--;
        while (j < 3) {
          j++;
          if (caracteres[y][t] != '\0') {
            resposta[i] = caracteres[y][t];
            t++;
            i++;
          } else {
            break;
          } // o plano era: somar o algarismo no vetor resposta o n° de vezes do
            // desconto;
        }
      }
    }
  }
}

int main(void) {
  int N, numero;
  char resposta[20] = {"\0"};
  scanf("%d", &N);
  for (; N > 0; N--) {
    scanf("%d", &numero);
    ROMANOS(numero, resposta);
    printf("%s\n", resposta);
    for(int r=0;r<20;r++){
      resposta[r]='\0';
    }
  }
  return 0;
}