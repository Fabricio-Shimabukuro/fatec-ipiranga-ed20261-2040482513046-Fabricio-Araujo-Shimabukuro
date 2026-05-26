RA: 2040482513046 - Fabrício Araujo Shimabukuro
#include <stdio.h>
#include <stdlib.h>

/* Estrutura do nó */
typedef struct No{
    int dado;
    struct No *esq;
    struct No *dir;
} No;


/* Cria nó */
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
    Percurso em-ordem
    imprimindo grau dos nós
*/
void imprimirGraus(No *raiz){

    if(raiz != NULL){

        imprimirGraus(raiz->esq);

        printf("No %d -> grau %d\n",
               raiz->dado,
               grauNo(raiz));

        imprimirGraus(raiz->dir);
    }
}


int main(void){

    int valores[] = {
        50, 30, 70, 20, 40,
        60, 80, 10, 25, 45, 65
    };

    int tamanho =
        sizeof(valores) /
        sizeof(valores[0]);

    No *raiz = NULL;

    /* Construção da ABB */
    for(int i = 0; i < tamanho; i++){

        raiz =
            inserir(raiz,
                     valores[i]);
    }

    printf("=================================\n");
    printf("ALTURA DOS NOS\n");
    printf("=================================\n");

    int nosAltura[] = {
        50, 30, 70, 20, 10
    };

    for(int i = 0; i < 5; i++){

        No *no =
            buscar(raiz,
                   nosAltura[i]);

        printf("Altura do no %d = %d\n",
               nosAltura[i],
               alturaNo(no));
    }


    printf("\n=================================\n");
    printf("PROFUNDIDADE DOS NOS\n");
    printf("=================================\n");

    int nosProf[] = {
        50, 30, 70, 45, 10
    };

    for(int i = 0; i < 5; i++){

        printf("Profundidade do no %d = %d\n",
               nosProf[i],

               profundidadeNo(
                   raiz,
                   nosProf[i],
                   0
               ));
    }


    printf("\n=================================\n");
    printf("GRAU DOS NOS (EM-ORDEM)\n");
    printf("=================================\n");

    imprimirGraus(raiz);


    printf("\n=================================\n");
    printf("ALTURA TOTAL DA ARVORE\n");
    printf("=================================\n");

    printf("Altura total = %d\n",
           alturaNo(raiz));

    return 0;
}