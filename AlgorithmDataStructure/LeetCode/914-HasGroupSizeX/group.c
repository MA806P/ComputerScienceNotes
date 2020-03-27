
#include <stdio.h>
#include <stdbool.h>

int m_gcd(int a, int b) {
    return b == 0 ? a : m_gcd(b, a % b);
}

bool hasGroupsSizeX(int* deck, int deckSize){
    if (deck == NULL || deckSize < 2) { return false; }
    
    int count[10000] = {0};
    for (int i = 0; i < deckSize; i++) {
        count[deck[i]] += 1;
    }
    
    int g = -1;
    for (int i = 0; i < 10000; i++) {
        if (count[i] > 0) {
            if (g == -1) {
                g = count[i];
            } else {
                g = m_gcd(g, count[i]);
            }
        }
    }
    return g >= 2;
}

int main(int argc, const char * argv[]) {
    
    int a[] = {1,1,1,1,1,1,2,2,2,2,2,2,2,2,2};
    printf("ans = %d\n", hasGroupsSizeX(a, 15));
    
    printf("%d\n", m_gcd(8, 4));
    
    return 0;
}






