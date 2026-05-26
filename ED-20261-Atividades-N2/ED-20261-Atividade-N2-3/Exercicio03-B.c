RA: 2040482513046 - Fabrício Araujo Shimabukuro
#include <stdio.h>

/* Contador global */
long long movimentos = 0;


/* Função recursiva */
void hanoi(int n,
           char origem,
           char destino,
           char auxiliar){

    if(n == 1){

        movimentos++;

        printf("Mover disco 1 de %c para %c\n",
               origem,
               destino);

        return;
    }

    hanoi(n - 1,
          origem,
          auxiliar,
          destino);

    movimentos++;

    printf("Mover disco %d de %c para %c\n",
           n,
           origem,
           destino);

    hanoi(n - 1,
          auxiliar,
          destino,
          origem);
}


int main(void){

    for(int n = 1; n <= 6; n++){

        movimentos = 0;

        printf("\n====================\n");
        printf("n = %d\n", n);
        printf("====================\n");

        hanoi(n, 'A', 'C', 'B');

        printf("\nMovimentos realizados: %lld\n",
               movimentos);
    }

    return 0;
}


/*

========================================
TABELA DE COMPLEXIDADE
========================================

n | Movimentos (contado) | 2^n - 1 (esperado)

1 | 1                    | 1
2 | 3                    | 3
3 | 7                    | 7
4 | 15                   | 15
5 | 31                   | 31
6 | 63                   | 63


========================================
ANALISE
========================================

A recorrência da Torre de Hanói é:

            T(n) = 2*T(n-1) + 1

Isso ocorre porque:
- movemos n-1 discos
- movemos o maior disco
- movemos novamente n-1 discos

A solução da recorrência é:

            T(n) = 2^n - 1

Portanto:
- Complexidade temporal: O(2^n)
- Profundidade da recursão: O(n)

*/