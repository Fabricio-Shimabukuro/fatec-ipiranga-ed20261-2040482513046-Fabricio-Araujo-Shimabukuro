RA: 2040482513046 - Fabrício Araujo Shimabukuro
#include <stdio.h>

/* Contadores globais */
int chamadasRapida = 0;
int chamadasIngenua = 0;


/*
    Potenciação rápida

    Complexidade:
    O(log exp)

    Caso base:
    - exp == 0

    Caso recursivo:
    - divide o expoente pela metade
*/
long long potenciaRapida(long long base,
                         int exp){

    chamadasRapida++;

    /* Caso base */
    if(exp == 0){
        return 1;
    }

    /*
        Caso recursivo:
        expoente par
    */
    if(exp % 2 == 0){

        long long metade =
            potenciaRapida(base, exp / 2);

        return metade * metade;
    }

    /*
        Caso recursivo:
        expoente ímpar
    */
    return base *
           potenciaRapida(base, exp - 1);
}


/*
    Potenciação ingênua

    Complexidade:
    O(n)

    Apenas para comparação
*/
long long potenciaIngenua(long long base,
                          int exp){

    chamadasIngenua++;

    /* Caso base */
    if(exp == 0){
        return 1;
    }

    /* Caso recursivo */
    return base *
           potenciaIngenua(base, exp - 1);
}


int main(void){

    long long bases[] = {2, 3, 5, 7};
    int expoentes[] = {10, 7, 0, 12};

    for(int i = 0; i < 4; i++){

        long long base = bases[i];
        int exp = expoentes[i];

        chamadasRapida = 0;
        chamadasIngenua = 0;

        long long resultadoRapido =
            potenciaRapida(base, exp);

        long long resultadoIngenuo =
            potenciaIngenua(base, exp);

        printf("\n========================\n");
        printf("%lld ^ %d\n", base, exp);
        printf("========================\n");

        printf("Resultado rapido : %lld\n",
               resultadoRapido);

        printf("Resultado ingenuo: %lld\n",
               resultadoIngenuo);

        printf("Chamadas (rapida) : %d\n",
               chamadasRapida);

        printf("Chamadas (ingenua): %d\n",
               chamadasIngenua);
    }

    return 0;
}


/*

========================================
COMPARACAO DE COMPLEXIDADE
========================================

Potenciação ingênua:
    b^n = b * b^(n-1)

Complexidade:
    O(n)

Número de chamadas cresce linearmente.


Potenciação rápida:
    se n for par:
        b^n = (b^(n/2))²

Complexidade:
    O(log n)

O expoente é reduzido pela metade
a cada chamada recursiva.


========================================
EXEMPLO
========================================

2^10

Ingênua:
    aproximadamente 11 chamadas

Rápida:
    aproximadamente 6 chamadas


7^12

Ingênua:
    aproximadamente 13 chamadas

Rápida:
    aproximadamente 6 chamadas


A diferença cresce muito para
expoentes grandes.

*/