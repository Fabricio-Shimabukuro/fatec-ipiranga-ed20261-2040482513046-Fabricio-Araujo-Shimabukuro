RA: 2040482513046 - Fabrício Araujo Shimabukuro
#include <stdio.h>

/* Função que troca os valores usando apenas ponteiros */
void trocar(int *a, int *b){

    /* *a acessa o valor armazenado no endereço apontado por a */
    /* *b acessa o valor armazenado no endereço apontado por b */
    *a = *a + *b;

    /* Subtrai o novo valor de *a pelo valor de *b */
    /* O resultado original de *a passa para *b */
    *b = *a - *b;

    /* Subtrai novamente para recuperar o valor original de *b */
    /* O resultado final passa para *a */
    *a = *a - *b;
}

int main(){

    /* ==========================
       PARTE A — TROCA
       ========================== */

    int x = 10;
    int y = 20;

    printf("ANTES DA TROCA\n");
    printf("x = %d | endereco = %p\n", x, &x);
    /* &x retorna o endereco de memoria da variavel x */

    printf("y = %d | endereco = %p\n", y, &y);
    /* &y retorna o endereco de memoria da variavel y */

    trocar(&x, &y);
    /* &x envia o endereco de x */
    /* &y envia o endereco de y */

    printf("\nDEPOIS DA TROCA\n");
    printf("x = %d | endereco = %p\n", x, &x);
    /* &x retorna novamente o endereco de x */

    printf("y = %d | endereco = %p\n", y, &y);
    /* &y retorna novamente o endereco de y */

