RA: 2040482513046 - Fabrício Araujo Shimabukuro
#include <stdio.h>

/* Contador global de chamadas recursivas */
int chamadasBusca = 0;


/*
    Busca binária recursiva

    Retorna:
    - índice do elemento, se encontrado
    - -1 caso contrário

    Caso base:
    - quando inicio > fim, o elemento não existe

    Caso recursivo:
    - divide o vetor ao meio
    - busca apenas na metade necessária
*/
int buscaBinaria(int *vet,
                 int inicio,
                 int fim,
                 int alvo){

    chamadasBusca++;

    /* Caso base: elemento não encontrado */
    if(inicio > fim){
        return -1;
    }

    /* Calcula o índice do meio */
    int meio = (inicio + fim) / 2;

    /* Caso base: elemento encontrado */
    if(vet[meio] == alvo){
        return meio;
    }

    /*
        Caso recursivo:
        busca na metade esquerda
    */
    if(alvo < vet[meio]){

        return buscaBinaria(vet,
                            inicio,
                            meio - 1,
                            alvo);
    }

    /*
        Caso recursivo:
        busca na metade direita
    */
    return buscaBinaria(vet,
                        meio + 1,
                        fim,
                        alvo);
}


int main(void){

    int dados[] = {
        2, 5, 8, 12, 16,
        23, 38, 45, 72, 91
    };

    int tamanho = sizeof(dados) / sizeof(dados[0]);

    int valoresBusca[] = {23, 50, 2};

    for(int i = 0; i < 3; i++){

        int alvo = valoresBusca[i];

        chamadasBusca = 0;

        int resultado = buscaBinaria(dados,
                                     0,
                                     tamanho - 1,
                                     alvo);

        printf("\nBuscando valor %d\n", alvo);

        if(resultado != -1){

            printf("Elemento encontrado no indice %d\n",
                   resultado);

        }else{

            printf("Elemento nao encontrado\n");
        }

        printf("Chamadas recursivas: %d\n",
               chamadasBusca);
    }

    return 0;
}