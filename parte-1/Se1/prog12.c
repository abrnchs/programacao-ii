#include <stdio.h>

typedef enum {
    S_ASC,
    S_INIT,
    S_CONT
} ClassId;

ClassId utf8Class (unsigned char c) {
    if ((c & 0x80) == 0 ){
        return S_ASC;
    }
    if ((c & 0x40) == 0 ){
        return S_CONT;
    }
    return S_INIT;
}

// Função auxiliar para imprimir o nome do enum em texto legível
const char* className(ClassId classe) {
    switch (classe) {
        case S_ASC:  return "S_ASC";
        case S_INIT: return "S_INIT";
        case S_CONT: return "S_CONT";
        default:     return "DESCONHECIDO";
    }
}

int main () {
    int byte_lido;

    while ((byte_lido = getchar()) != EOF) {
        unsigned char c = (unsigned char) byte_lido;
        ClassId classe = utf8Class(c);

        printf("Byte: 0x%02x -> %s\n", c, className(classe));
    }

    return 0;
}