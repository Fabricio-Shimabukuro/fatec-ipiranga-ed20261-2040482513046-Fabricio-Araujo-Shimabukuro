RA: 2040482513046 - Fabrício Araujo Shimabukuro
#include <stdio.h>

/* Contador global */
long long movimentos = 0;


/*
    Função recursiva com nível de profundidade

    nivel -> profundidade atual da recursão
*/
void hanoi(int n,
           char origem,
           char destino,
           char auxiliar,
           int nivel){

    /* Caso base */
    if(n == 1){

        movimentos++;

        /* Indentação proporcional ao nível */
        for(int i = 0; i < nivel * 2; i++){
            printf(" ");
        }

        printf("[Nivel %d] Mover disco 1 de %c para %c\n",
               nivel,
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
          destino,
          nivel + 1);

    movimentos++;

    /* Espaços proporcionais ao nível */
    for(int i = 0; i < nivel * 2; i++){
        printf(" ");
    }

    printf("[Nivel %d] Mover disco %d de %c para %c\n",
           nivel,
           n,
           origem,
           destino);

    /*
        Move n-1 discos da auxiliar para o destino
    */
    hanoi(n - 1,
          auxiliar,
          destino,
          origem,
          nivel + 1);
}


int main(void){

    int testes[] = {1, 3, 4};

    for(int i = 0; i < 3; i++){

        int n = testes[i];

        movimentos = 0;

        printf("\n========================\n");
        printf("Teste com n = %d\n", n);
        printf("========================\n\n");

        hanoi(n, 'A', 'C', 'B', 0);

        printf("\nTotal de movimentos: %lld\n",
               movimentos);
    }

    return 0;
}