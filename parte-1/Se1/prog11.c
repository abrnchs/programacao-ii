#include <stdio.h>

int bitField(int siz, int pos, char val) {
    char deslocado = ((unsigned char) val) >> pos;
    int mascara = (1 << siz) -1;
    return deslocado & mascara;
}

int main() {
    int pos, siz;
    int val_int;

    while (scanf("%d %d %i", &siz, &pos, &val_int) == 3) {
        char val = (char)val_int;
        int res = bitField(siz, pos, val);
        printf("bitField(siz=%d, pos=%d, val=0x%02X) = %d\n", 
               siz, pos, (unsigned char)val, res);
    }

    return 0;
}