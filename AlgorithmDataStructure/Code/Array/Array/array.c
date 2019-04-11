//
//  array.c
//  Array
//
//  Created by MA806P on 2019/4/11.
//  Copyright © 2019 myz. All rights reserved.
//

#include "array.h"

struct array {
    int size;
    int len;
    int *arr;
};


void dump(struct array *array) {
    for (int idx = 0; idx < array->len; idx++) {
        printf("[%02d]:%08d\n", idx, array->arr[idx]);
    }
}

void alloc(struct array *array) {
    array->arr = (int *)malloc(array->size * sizeof(int));
}

int insert(struct array *array, int elem) {
    if (array->len >= array->size) {
        return -1;
    }
    
    int idx = 0;
    for (; idx < array->len; idx++) {
        if (array->arr[idx] > elem) {
            break;
        }
    }
    
    if (idx < array->len) {
        memmove(&array->arr[idx+1], &array->arr[idx], (array->len - idx) * sizeof(int));
    }
    
    array->arr[idx] = elem;
    array->len++;
    
    return idx;
}

void find(struct array *array) {
    
}


