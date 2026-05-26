RA: 2040482513046 - Fabrício Araujo Shimabukuro
#include <stdio.h>

/*
    Função recursiva da Torre de Hanói

    n        -> quantidade de discos
    origem   -> haste de origem
    destino  -> haste de destino
    auxiliar -> haste auxiliar
*/
void hanoi(int n,
           char origem,
           char destino,
           char auxiliar){

    /* Caso base */
    if(n == 1){

        printf("Mover disco 1 de %c para %c\n",
               origem,
               destino);

        return;
    }

    /*
        Move n-1 discos da origem para a auxiliar
    */
    hanoi(n - 1,
          origem,
          auxiliar,
          destino);

    /*
        Move o maior disco
    */
    printf("Mover disco %d de %c para %c\n",
           n,
           origem,
           destino);

    /*
        Move n-1 discos da auxiliar para o destino
    */
    hanoi(n - 1,
          auxiliar,
          destino,
          origem);
}


int main(void){

    int n = 3;

    hanoi(n, 'A', 'C', 'B');

    return 0;
}