//
//  main.c
//  Array
//
//  Created by MA806P on 2019/4/10.
//  Copyright © 2019 myz. All rights reserved.
//

#include <stdio.h>
#include "Array_test.h"
#include "array.h"


void tempArrayPrint(Array *array) {
    
    if (NULL == array || array->len <= 0) {
        printf("this array is empty\n");
        return;
    }
    
    char *pBegin = array->p;
    for (size_t i = 0; i < array->len; i++) {
        char *arrayitem = pBegin + i * array->typeSize;
        printf("array[%ld] = %c \n", i, *arrayitem);
    }
}

void callFunction () {
    
    Array *array = arrayCreate();
    arrayInit(array, 10, sizeof(char));
    
    tempArrayPrint(array);
    
    char a = 'a';
    arrayInsert(array, 1, &a);
    
    char z = 'Z';
    arrayInsert(array, 2, &z);
    
    char b = 'b';
    arrayInsert(array, 3, &b);
    
    tempArrayPrint(array);
    
    char searchItem = 'b';
    size_t index = arraySearchValue(array, &searchItem);
    printf("search 'b' result = %ld\n", index);
    
    char *indexItem = arrayIndex(array, 2);
    printf("index of 2 = %c\n", *indexItem);
    
    char changeItem = 'y';
    arrayModify(array, 1, &changeItem);
    tempArrayPrint(array);
    
    printf("array len = %ld; array size = %ld\n", arrayLen(array), arraySize(array));
    
    arrayEmpty(array);
    
    
    
    printf("\n");
    
    
    Array *array2 = arrayCreate();
    arrayInit(array2, 6, sizeof(char));
    
    char a2 = '1';
    arrayInsert(array2, 1, &a2);
    
    char b2 = '2';
    arrayInsert(array2, 2, &b2);
    
    char c2 = '3';
    arrayInsert(array2, 3, &c2);
    
    tempArrayPrint(array2);
    
    char delItem = '2';
    arrayDelValue(array2, &delItem);
    tempArrayPrint(array2);
    
    arrayDelIndex(array2, 1);
    tempArrayPrint(array2);
    
    arrayEmpty(array2);
    
}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    callFunction();
    
    //int idx;
    //struct array ten_int = {10, 0, NULL};
    
    
    return 0;
}


