RA: 2040482513046 - Fabrício Araujo Shimabukuro
#include <stdio.h>
#include <stdlib.h>

/* Estrutura do nó */
typedef struct No{
    int dado;
    struct No *esq;
    struct No *dir;
} No;


/* Cria um novo nó */
No *criarNo(int valor){

    No *novo = (No *)malloc(sizeof(No));

    novo->dado = valor;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}


/*
    Insere um valor na ABB

    Caso base:
    - árvore vazia

    Caso recursivo:
    - insere à esquerda ou à direita
*/
No *inserir(No *raiz, int valor){

    /* Caso base */
    if(raiz == NULL){
        return criarNo(valor);
    }

    /* Inserção à esquerda */
    if(valor < raiz->dado){

        raiz->esq =
            inserir(raiz->esq, valor);
    }

    /* Inserção à direita */
    else if(valor > raiz->dado){

        raiz->dir =
            inserir(raiz->dir, valor);
    }

    return raiz;
}


/*
    Calcula a altura de um nó

    Altura:
    maior caminho até uma folha
*/
int alturaNo(No *no){

    /* Caso base */
    if(no == NULL){
        return -1;
    }

    int alturaEsq =
        alturaNo(no->esq);

    int alturaDir =
        alturaNo(no->dir);

    if(alturaEsq > alturaDir){
        return alturaEsq + 1;
    }

    return alturaDir + 1;
}


/*
    Calcula a profundidade de um nó

    Profundidade:
    distância da raiz até o nó
*/
int profundidadeNo(No *raiz,
                   int valor,
                   int prof){

    /* Valor não encontrado */
    if(raiz == NULL){
        return -1;
    }

    /* Valor encontrado */
    if(raiz->dado == valor){
        return prof;
    }

    /* Busca à esquerda */
    if(valor < raiz->dado){

        return profundidadeNo(
            raiz->esq,
            valor,
            prof + 1
        );
    }

    /* Busca à direita */
    return profundidadeNo(
        raiz->dir,
        valor,
        prof + 1
    );
}


/*
    Calcula o grau de um nó

    Grau:
    quantidade de filhos
*/
int grauNo(No *no){

    if(no == NULL){
        return 0;
    }

    int grau = 0;

    if(no->esq != NULL){
        grau++;
    }

    if(no->dir != NULL){
        grau++;
    }

    return grau;
}