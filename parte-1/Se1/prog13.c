#include <stdio.h>

#define BUFFER_SIZE 4096

int utf8Print( const char *data ) {
    if (data == NULL || data[0] == '\0') {
        return 0;
    }

    unsigned char primeiro = (unsigned char) data[0];
    int num_bytes = 1;

    if ((primeiro & 0x80) == 0) {
        // Bit 7 a 0: 0xxxxxxx (ASCII normal) -> 1 byte
        num_bytes = 1;
    } 
    else if ((primeiro & 0xE0) == 0xC0) {
        // Começa por 110xxxxx (0xE0 é 11100000; 0xC0 é 11000000) -> 2 bytes
        num_bytes = 2;
    }
    else if ((primeiro & 0xF0) == 0xE0) {
        // Começa por 1110xxxx (0xF0 é 11110000; 0xE0 é 11100000) -> 3 bytes
        num_bytes = 3;
    }
    else if ((primeiro & 0xF8) == 0xF0) {
        // Começa por 11110xxx (0xF8 é 11111000; 0xF0 é 11110000) -> 4 bytes
        num_bytes = 4;
    }

    for (int i = 0; i < num_bytes; i++) {
        if (data[i] == '\0') {
            return i;
        }
        putchar(data[i]);
    }

    return num_bytes;
}

void arrayPrintHex( const char *data, int size ) {
    putchar('{');

    for (int i = 0; i < size; i++) {
        if (i > 0) {
            putchar(' ');
        }

        printf("%02x", (unsigned char)data[i]);
    }

    putchar('}');
}

void utf8ShowCode( const char *data ) {
    if (data == NULL) {
        return;
    }

    while (*data != '\0') {
        
        int size = utf8Print(data);

        if (size <= 0) {
            break;
        }

        arrayPrintHex(data, size);

        data += size;
    }
}

int main() {
    char linha[BUFFER_SIZE];

    while(fgets(linha, sizeof(linha), stdin) != NULL) {
        utf8ShowCode(linha);
    }

    return 0;
}

