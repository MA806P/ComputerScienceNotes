#include <stdio.h>
#include <stdlib.h>


#define HASH_SHIFT 4

struct hash_table {
    unsigned int used;
    unsigned long entry[HASH_SHIFT];
}


