//
//  Array_test.h
//  Array
//
//  Created by MA806P on 2019/4/10.
//  Copyright © 2019 myz. All rights reserved.
//

#ifndef Array_test_h
#define Array_test_h

#include <stdio.h>

typedef struct Array {
    size_t size;
    size_t len;
    size_t typeSize;
    void(*dup)(void *ptr, void *key);
    void(*free)(void *ptr);
    int(*match)(void *ptr, void *key);
    void *p;
} Array;

#define arraySetDupMethod(a, m) ((a)->dup = (m))
#define arraySetFreeMethod(a, m) ((a)->free = (m))
#define arraySetMatchMethod(a, m) ((a)->match = (m))

#define arrayGetDupMethod(a) ((a)->dup)
#define arrayGetFreeMethod(a) ((a)->free)
#define arrayGetMatchMethod(a) ((a)->match)

Array* arrayCreate(void);
void arrayInit(Array *array, int size, int typeSize);

int arrayInsert(Array *array, size_t pos, void *const value);
size_t arraySearchValue(Array *array, void *const value);
void* arrayIndex(Array *array, size_t index);
int arrayModify(Array *array, size_t pos, void *const value);

size_t arrayLen(Array *array);
size_t arraySize(Array *array);

void arrayEmpty(Array *array);
void arrayDelValue(Array *array, void *value);
void arrayDelIndex(Array *array, size_t pos);

#endif /* Array_test_h */
