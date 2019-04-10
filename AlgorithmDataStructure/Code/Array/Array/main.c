//
//  main.c
//  Array
//
//  Created by MA806P on 2019/4/10.
//  Copyright © 2019 myz. All rights reserved.
//

#include <stdio.h>
#include "Array_test.h"



void tempArrayPrint(Array *array) {
    
    if (NULL == array || array->len <= 0) {
        printf("this array is empty\n");
        return;
    }
    
    char *pBegin = array->p;
    for (size_t i = 0; i < array->len; i++) {
        char *arrayitem = pBegin + i * array->typeSize;
        printf("array[%ld] = %s \n", i, arrayitem);
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    Array *array = arrayCreate();
    arrayInit(array, 10, sizeof(char));
    
    tempArrayPrint(array);
    char a = 'a';
    int result = arrayInsert(array, 1, &a);
    printf("result = %d\n", result);
    char b = 'b';
    arrayInsert(array, 2, &b);
    tempArrayPrint(array);
    
    return 0;
}


