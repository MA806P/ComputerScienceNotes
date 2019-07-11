#include <stdio.h>

int main() {
    
    int i, j;
    
    for (i = 0; i < 6; i++) {
        printf("--- %d\n", i);
        for (j = 11; j < 19; j++) {
            printf("*** %d\n", j);
            if (j == 13) {
                break;
            }
        }
    }
    
    return 0;
}
