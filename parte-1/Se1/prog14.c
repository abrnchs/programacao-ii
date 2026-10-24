#include <stdio.h>
#include "norm.h"

#define MAX_LINE 2048

int main(void) {
    char buffer[MAX_LINE];

    // Processamento linha a linha do standard input com redirecionamento
    while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        normString(buffer);
        printf("%s", buffer);
    }

    return 0;
}
