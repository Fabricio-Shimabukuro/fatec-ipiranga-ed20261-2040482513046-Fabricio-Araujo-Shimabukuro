RA: 2040482513046 - Fabrício Araujo Shimabukuro
#include <stdio.h>

/* Calcula e retorna a média aritmética */
float calcularMedia(float *vet, int n){

    float soma = 0.0f;

    /* Ponteiro auxiliar para percorrer o vetor */
    float *ptr = vet;

    for(int i = 0; i < n; i++){

        /* *ptr acessa o valor apontado */
        soma += *ptr;

        /* Avança para o próximo elemento */
        ptr++;
    }

    return soma / n;
}


/* Encontra maior e menor valor do vetor */
void encontrarExtremos(float *vet, int n,
                       float *maior, float *menor){

    float *ptr = vet;

    /* Inicializa maior e menor com o primeiro valor */
    *maior = *ptr;
    *menor = *ptr;

    ptr++;

    for(int i = 1; i < n; i++){

        /* *ptr acessa o valor atual do vetor */

        if(*ptr > *maior){

            /* Escreve diretamente no endereço apontado por maior */
            *maior = *ptr;
        }

        if(*ptr < *menor){

            /* Escreve diretamente no endereço apontado por menor */
            *menor = *ptr;
        }

        ptr++;
    }
}


/* Normaliza o vetor */
void normalizar(float *vet, int n){

    float maior;
    float menor;

    encontrarExtremos(vet, n, &maior, &menor);

    float *ptr = vet;

    for(int i = 0; i < n; i++){

        /* Divide o valor atual pelo maior valor */
        *ptr = *ptr / maior;

        ptr++;
    }

    /*
       A função altera o vetor original porque vet
       recebe o endereço do primeiro elemento do array.

       Assim, ao modificar *ptr, estamos alterando
       diretamente os dados armazenados na memória
       do vetor original, e não uma cópia.
    */
}


/* Imprime o vetor formatado */
void imprimirVetor(float *vet, int n, const char *titulo){

    printf("%s\n", titulo);

    float *ptr = vet;

    for(int i = 0; i < n; i++){

        /* *ptr acessa o elemento atual */
        printf("%.2f ", *ptr);

        ptr++;
    }

    printf("\n\n");
}


int main(void){

    float notas[] = {7.5f, 3.2f, 9.8f, 6.0f, 5.5f, 8.1f};

    int tamanho = (int)(sizeof(notas) / sizeof(notas[0]));

    float media;
    float maior;
    float menor;

    imprimirVetor(notas, tamanho, "Vetor original:");

    media = calcularMedia(notas, tamanho);

    encontrarExtremos(notas, tamanho, &maior, &menor);

    printf("Media: %.2f\n", media);
    printf("Maior valor: %.2f\n", maior);
    printf("Menor valor: %.2f\n\n", menor);

    normalizar(notas, tamanho);

    imprimirVetor(notas, tamanho, "Vetor normalizado:");

    return 0;
}