//
//  array.h
//  Array
//
//  Created by MA806P on 2019/4/11.
//  Copyright © 2019 myz. All rights reserved.
//

#ifndef array_h
#define array_h

#include <stdio.h>

struct array {
    int size;
    int len;
    int *arr;
};

void dump(struct array *array);
void alloc(struct array *array);
int insert(struct array *array, int elem);
int delete(struct array *array, int idx);
int search(struct array *array, int elem);

#endif /* array_h */
