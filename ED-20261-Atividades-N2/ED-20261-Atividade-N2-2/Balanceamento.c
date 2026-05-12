#include <stdio.h>
#include <stdlib.h>

/* Estrutura do nó */
struct No {
    int valor;
    int altura;
    struct No *esq;
    struct No *dir;
};

/* Função para calcular a altura da árvore */
int calcularAltura(struct No* n) {

    /* Caso base */
    if (n == NULL) {
        return -1;
    }

    /* Calcula altura da subárvore esquerda */
    int alturaEsq = calcularAltura(n->esq);

    /* Calcula altura da subárvore direita */
    int alturaDir = calcularAltura(n->dir);

    /* Retorna 1 + maior altura */
    if (alturaEsq > alturaDir) {
        return 1 + alturaEsq;
    } else {
        return 1 + alturaDir;
    }
}

/* Função para obter o Balanceamento */
int obterFB(struct No* n) {

    if (n == NULL) {
        return 0;
    }

    int alturaEsq = calcularAltura(n->esq);
    int alturaDir = calcularAltura(n->dir);

    return alturaEsq - alturaDir;
}

int main() {

    /* Criação dos nós */
    struct No *n20 = (struct No*) malloc(sizeof(struct No));
    struct No *n10 = (struct No*) malloc(sizeof(struct No));
    struct No *n5  = (struct No*) malloc(sizeof(struct No));
    struct No *n2  = (struct No*) malloc(sizeof(struct No));

    /* Inicialização dos valores */
    n20->valor = 20;
    n10->valor = 10;
    n5->valor = 5;
    n2->valor = 2;

    /* Inicialização dos ponteiros */
    n20->esq = n10;
    n20->dir = NULL;

    n10->esq = n5;
    n10->dir = NULL;

    n5->esq = n2;
    n5->dir = NULL;

    n2->esq = NULL;
    n2->dir = NULL;

    /* Calculando as alturas */
    printf("Altura do no 2: %d\n", calcularAltura(n2));
    printf("Altura do no 5: %d\n", calcularAltura(n5));
    printf("Altura do no 10: %d\n", calcularAltura(n10));
    printf("Altura do no 20: %d\n", calcularAltura(n20));

    /* Calculando o balanceamento */
    int fb = obterFB(n20);

    printf("\nFator de Balanceamento da raiz (20): %d\n", fb);

    if (fb > 1 || fb < -1) {
        printf("Arvore desbalanceada!\n");
    } else {
        printf("Arvore balanceada!\n");
    }

    /* Liberando a memória */
    free(n2);
    free(n5);
    free(n10);
    free(n20);

    return 0;
}