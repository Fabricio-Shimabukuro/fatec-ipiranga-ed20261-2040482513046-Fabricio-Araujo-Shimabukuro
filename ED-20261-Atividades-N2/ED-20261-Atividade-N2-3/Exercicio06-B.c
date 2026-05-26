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
    PARTE B
    Relatório completo
*/
void relatorioNo(No *raiz,
                 int valor){

    No *no = buscar(raiz, valor);

    if(no == NULL){

        printf("\nValor %d nao encontrado na arvore.\n",
               valor);

        return;
    }

    printf("\n+----------------------------------+\n");
    printf("| RELATORIO DO NO: %-14d |\n",
           valor);
    printf("+----------------------------------+\n");

    printf("| Profundidade : %-16d |\n",
           profundidadeNo(
               raiz,
               valor,
               0
           ));

    printf("| Altura       : %-16d |\n",
           alturaNo(no));

    printf("| Grau         : %-16d |\n",
           grauNo(no));

    printf("| Ancestrais   : ");

    imprimirAncestral(raiz, valor);

    printf("\n");

    printf("| Descendentes : ");

    imprimirDescendentes(raiz, valor);

    printf("\n");

    /*
        Subtrai 1 para não contar
        o próprio nó
    */
    printf("| Qtd Descend. : %-16d |\n",
           contarDescendentes(no) - 1);

    printf("+----------------------------------+\n");
}


/* Função principal */
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
