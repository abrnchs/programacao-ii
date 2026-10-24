#include <ctype.h>
#include <string.h>
#include "norm.h"

// Normaliza o primeiro símbolo da string e retorna o seu número de bytes
int normSymb(char *str) {
    unsigned char c = (unsigned char)str[0];

    // Tratamento de símbolos básicos ASCII
    if (c < 0x80) {
        if (isalnum(c)) {
            str[0] = tolower(c);
        } else if (c != '-') {
            str[0] = ' ';
        }
        return 1;
    }
    
    // Letras acentuadas
    if (c == 0xc3 && (unsigned char)str[1] >= 0x80) {
        unsigned char c2 = (unsigned char)str[1];
        if (c2 >= 0x80 && c2 < 0xa0) {
            str[1] = c2 + 0x20;
        }
        return 2;
    }
    
    // Outros símbolos compostos: calcula a dimensão em bytes e substitui por espaços
    int nbytes = 1;
    if ((c & 0xE0) == 0xC0) nbytes = 2;
    else if ((c & 0xF0) == 0xE0) nbytes = 3;
    else if ((c & 0xF8) == 0xF0) nbytes = 4;

    for (int i = 0; i < nbytes; i++) {
        str[i] = ' ';
    }
    return nbytes;
}

// Normaliza todos os símbolos de uma string e valida a posição dos hífens em duas passagens
void normString(char *str) {
    int len = (int)strlen(str);
    int i = 0;

    /* Passagem 1: Normaliza símbolos e pontuação (convertendo pontuação em espaços), saltando os hífens */
    while (i < len) {
        if (str[i] == '-') {
            i++;
        } else {
            i += normSymb(&str[i]);
        }
    }

    /* Passagem 2: Com a pontuação já convertida em espaços, valida a posição dos hífens com segurança */
    for (i = 0; i < len; i++) {
        if (str[i] == '-') {
            int isStart = (i == 0 || str[i - 1] == ' ');
            int isEnd = (i + 1 >= len || str[i + 1] == ' ' || str[i + 1] == '\n' || str[i + 1] == '\r');

            if (isStart || isEnd) {
                str[i] = ' ';
            }
        }
    }
}
