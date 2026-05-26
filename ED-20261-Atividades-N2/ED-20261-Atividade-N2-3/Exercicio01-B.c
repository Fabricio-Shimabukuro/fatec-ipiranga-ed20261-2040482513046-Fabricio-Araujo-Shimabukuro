RA: 2040482513046 - Fabrício Araujo Shimabukuro
    /* ==========================
       PARTE B — VETOR
       ========================== */

    int v[] = {10, 20, 30, 40, 50};

    /* Ponteiro apontando para o primeiro elemento do vetor */
    int *p = v;

    int soma = 0;

    printf("\nELEMENTOS DO VETOR\n");

    /* Percorre o vetor usando apenas ponteiros */
    for(p = v; p < v + 5; p++){

        /* *p acessa o valor armazenado no endereco apontado por p */
        printf("Valor = %d | Endereco = %p\n", *p, p);

        /* *p pega o valor apontado por p e soma em soma */
        soma = soma + *p;
    }

    printf("\nSoma dos elementos = %d\n", soma);


    /* ==========================
       INVERSAO DO VETOR
       ========================== */

    int *inicio = v;
    /* inicio aponta para o primeiro elemento */

    int *fim = v + 4;
    /* fim aponta para o ultimo elemento */

    while(inicio < fim){

        /* Troca os valores apontados pelos ponteiros */

        *inicio = *inicio + *fim;
        /* *inicio acessa o valor do inicio */
        /* *fim acessa o valor do fim */

        *fim = *inicio - *fim;
        /* recupera o valor original de *inicio */

        *inicio = *inicio - *fim;
        /* recupera o valor original de *fim */

        inicio++;
        /* avanca o ponteiro para a proxima posicao */

        fim--;
        /* retorna o ponteiro uma posicao */
    }

    printf("\nVETOR INVERTIDO\n");

    for(p = v; p < v + 5; p++){

        /* *p acessa o valor armazenado no endereco apontado */
        printf("%d ", *p);
    }

    printf("\n");

    return 0;
}