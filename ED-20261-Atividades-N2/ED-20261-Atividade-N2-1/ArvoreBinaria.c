#include <stdio.h>
#include <stdlib.h>
#include "minhabib.h"


No* criar_no(int valor) {
    No* novo = (No*) malloc(sizeof(No));

    novo->valor = valor;
    novo->esq = NULL;
    novo->dir = NULL;

    return novo;
}

No* inserir(No* raiz, int valor) {

    if(raiz == NULL)
        return criar_no(valor);

    if(valor < raiz->valor)
        raiz->esq = inserir(raiz->esq, valor);

    else if(valor > raiz->valor)
        raiz->dir = inserir(raiz->dir, valor);

    return raiz;
}

No* buscar(No* raiz, int valor) {

    if(raiz == NULL || raiz->valor == valor)
        return raiz;

    if(valor < raiz->valor)
        return buscar(raiz->esq, valor);

    return buscar(raiz->dir, valor);
}

/*  IMPRESSÃO DOS NÓS INTERNOS */

void imprimir_nos_internos(No* raiz) {

    if(raiz == NULL)
        return;

    if(raiz->esq != NULL || raiz->dir != NULL)
        printf("%d ", raiz->valor);

    imprimir_nos_internos(raiz->esq);
    imprimir_nos_internos(raiz->dir);
}

/*  IMPRESSÃO DAS FOLHAS */

void imprimir_folhas(No* raiz) {

    if(raiz == NULL)
        return;

    if(raiz->esq == NULL && raiz->dir == NULL)
        printf("%d ", raiz->valor);

    imprimir_folhas(raiz->esq);
    imprimir_folhas(raiz->dir);
}

/*  ALTURA */

int calcular_altura(No* no) {

    if(no == NULL)
        return -1;

    int alturaEsq = calcular_altura(no->esq);
    int alturaDir = calcular_altura(no->dir);

    if(alturaEsq > alturaDir)
        return alturaEsq + 1;

    return alturaDir + 1;
}

/*  IMPRIMIR NÍVEIS*/

void imprimir_nivel_especifico(No* raiz, int nivelDesejado, int nivelAtual) {

    if(raiz == NULL)
        return;

    if(nivelAtual == nivelDesejado) {
        printf("%d ", raiz->valor);
        return;
    }

    imprimir_nivel_especifico(raiz->esq, nivelDesejado, nivelAtual + 1);
    imprimir_nivel_especifico(raiz->dir, nivelDesejado, nivelAtual + 1);
}

void imprimir_niveis(No* raiz, int nivel_atual) {

    int altura = calcular_altura(raiz);

    for(int i = 0; i <= altura; i++) {

        printf("Nivel %d: ", i);

        imprimir_nivel_especifico(raiz, i, 0);

        printf("\n");
    }
}

/*  PROFUNDIDADE */

int calcular_profundidade(No* raiz, int valor, int profundidade_atual) {

    if(raiz == NULL)
        return -1;

    if(raiz->valor == valor)
        return profundidade_atual;

    if(valor < raiz->valor)
        return calcular_profundidade(
            raiz->esq,
            valor,
            profundidade_atual + 1
        );

    return calcular_profundidade(
        raiz->dir,
        valor,
        profundidade_atual + 1
    );
}

/* ANCESTRAIS */

void imprimir_ancestrais(No* raiz, int valor) {

    if(raiz == NULL)
        return;

    if(raiz->valor == valor)
        return;

    if(valor < raiz->valor) {

        printf("%d ", raiz->valor);

        imprimir_ancestrais(raiz->esq, valor);
    }

    else {

        printf("%d ", raiz->valor);

        imprimir_ancestrais(raiz->dir, valor);
    }
}

/* DESCENDENTES */

void imprimir_descendentes(No* no) {

    if(no == NULL)
        return;

    if(no->esq != NULL) {
        printf("%d ", no->esq->valor);
        imprimir_descendentes(no->esq);
    }

    if(no->dir != NULL) {
        printf("%d ", no->dir->valor);
        imprimir_descendentes(no->dir);
    }
}

/* IMPRESSÃO VISUAL DA SUBÁRVORE*/

void imprimir_subarvore(No* raiz, int espacos) {

    if(raiz == NULL)
        return;

    espacos += 5;

    imprimir_subarvore(raiz->dir, espacos);

    printf("\n");

    for(int i = 5; i < espacos; i++)
        printf(" ");

    printf("%d\n", raiz->valor);

    imprimir_subarvore(raiz->esq, espacos);
}

/* FUNÇÃO PRINCIPAL DE ANÁLISE */

void analisar_arvore(No* raiz, int valorBusca) {

    if(raiz == NULL) {
        printf("Arvore vazia!\n");
        return;
    }

    printf("=========== DIAGNOSTICO GERAL ===========\n\n");

    /* RAIZ */
    printf("Raiz da arvore: %d\n\n", raiz->valor);

    /* NÓS INTERNOS */
    printf("Nos internos: ");
    imprimir_nos_internos(raiz);
    printf("\n\n");

    /* FOLHAS */
    printf("Folhas: ");
    imprimir_folhas(raiz);
    printf("\n\n");

    /* NÍVEIS */
    printf("Exibicao por niveis:\n");
    imprimir_niveis(raiz, 0);

    printf("\n=========== DIAGNOSTICO ESPECIFICO ===========\n\n");

    No* encontrado = buscar(raiz, valorBusca);

    if(encontrado == NULL) {
        printf("Valor %d nao encontrado!\n", valorBusca);
        return;
    }

    printf("No encontrado: %d\n\n", encontrado->valor);

    /* GRAU */
    int grau = 0;

    if(encontrado->esq != NULL)
        grau++;

    if(encontrado->dir != NULL)
        grau++;

    printf("Grau do no: %d\n\n", grau);

    /* ANCESTRAIS */
    printf("Ancestrais: ");
    imprimir_ancestrais(raiz, valorBusca);
    printf("\n\n");

    /* DESCENDENTES */
    printf("Descendentes: ");
    imprimir_descendentes(encontrado);
    printf("\n\n");

    /* ALTURA */
    printf("Altura do no: %d\n\n",
           calcular_altura(encontrado));

    /* PROFUNDIDADE */
    printf("Profundidade do no: %d\n\n",
           calcular_profundidade(raiz, valorBusca, 0));

    /* SUBÁRVORE */
    printf("=========== SUBARVORE ===========\n");

    imprimir_subarvore(encontrado, 0);

    printf("\n");
}




int main() {

    No* raiz = NULL;

    /* Inserindo elementos */
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 60);
    raiz = inserir(raiz, 80);

    int valorBusca;

    printf("Digite o valor que deseja analisar: ");
    scanf("%d", &valorBusca);

    analisar_arvore(raiz, valorBusca);

    return 0;
}