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


/* Inserção na ABB */
No *inserir(No *raiz, int valor){

    if(raiz == NULL){
        return criarNo(valor);
    }

    if(valor < raiz->dado){

        raiz->esq =
            inserir(raiz->esq, valor);

    }else if(valor > raiz->dado){

        raiz->dir =
            inserir(raiz->dir, valor);
    }

    return raiz;
}


/* Busca um nó */
No *buscar(No *raiz, int valor){

    if(raiz == NULL ||
       raiz->dado == valor){

        return raiz;
    }

    if(valor < raiz->dado){

        return buscar(raiz->esq,
                      valor);
    }

    return buscar(raiz->dir,
                  valor);
}


/* Altura do nó */
int alturaNo(No *no){

    if(no == NULL){
        return -1;
    }

    int esq = alturaNo(no->esq);
    int dir = alturaNo(no->dir);

    if(esq > dir){
        return esq + 1;
    }

    return dir + 1;
}


/* Profundidade */
int profundidadeNo(No *raiz,
                   int valor,
                   int prof){

    if(raiz == NULL){
        return -1;
    }

    if(raiz->dado == valor){
        return prof;
    }

    if(valor < raiz->dado){

        return profundidadeNo(
            raiz->esq,
            valor,
            prof + 1
        );
    }

    return profundidadeNo(
        raiz->dir,
        valor,
        prof + 1
    );
}


/* Grau do nó */
int grauNo(No *no){

    int grau = 0;

    if(no->esq != NULL){
        grau++;
    }

    if(no->dir != NULL){
        grau++;
    }

    return grau;
}
 /*
        PARTE C
        Testes sistemáticos
    */

    relatorioNo(raiz, 50);

    relatorioNo(raiz, 30);

    relatorioNo(raiz, 10);

    relatorioNo(raiz, 70);

    return 0;
}