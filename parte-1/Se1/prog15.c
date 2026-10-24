#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "norm.h"

#define MAX 4096

int main(int argc, char *argv[]){

    
    char palavra[MAX];
    char linha[MAX];
    char linhaNormalizada[MAX];
    int numeroLinha = 0;

    if (argc != 2) {
        printf("Utilização: %s palavra\n", argv[0]);
        return 1;
    }


    if (strlen(argv[1]) >= MAX) {
        printf("A palavra é demasiado comprida.\n");
        return 1;
    }

    strcpy(palavra, argv[1]);
    normString(palavra);

    
    while (fgets(linha, MAX, stdin) != NULL) {
        char *palavraLinha;
        int encontrou = 0;

        numeroLinha++;

        /* Mantém 'linha' original para a apresentar no resultado. */
        strcpy(linhaNormalizada, linha);
        normString(linhaNormalizada);

        palavraLinha = strtok(linhaNormalizada, " \t\r\n");
        while (palavraLinha != NULL) {
            if (strcmp(palavraLinha, palavra) == 0) {
                encontrou = 1;
                break;
            }

            palavraLinha = strtok(NULL, " \t\r\n");
        }

        if (encontrou) {
            printf("%d: %s", numeroLinha, linha);
            if (strchr(linha, '\n') == NULL) {
                printf("\n");
            }
        }
    }

    return 0;
}
