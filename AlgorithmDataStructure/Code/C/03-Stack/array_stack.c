#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct _array_statck {
    int size;
    int pos;
    int *array;
}stArrayStack;

stArrayStack *array_stack_create(int size) {
    if (size <= 0) {
        return NULL;
    }
    
    stArrayStack *stack = (stArrayStack *)malloc(sizeof(stArrayStack));
    if (stack == NULL) {
        return NULL;
    }
    
    int *tmpArray = (int *)malloc(size * sizeof(int));
    if (tmpArray == NULL) {
        free(stack);
        return NULL;
    }
    stack->array = tmpArray;
    stack->size = size;
    stack->pos = -1;
    return stack;
}


void array_stack_destory(stArrayStack *stack) {
    
    if (stack == NULL) {
        return;
    }
    
    if (stack->array != NULL) {
        free(stack->array);
    }
    free(stack);
    return;
}

bool array_stack_is_empty(stArrayStack *stack) {
    if (stack == NULL || stack->array == NULL || stack->pos == -1) {
        return true;
    }
    return false;
}

bool array_stack_is_full(stArrayStack *stack) {
    if (stack->pos == stack->size - 1) {
        return true;
    }
    return false;
}

int array_stack_pop(stArrayStack *stack) {
    if (array_stack_is_empty(stack)) {
        return -1;
    }
    int data = stack->array[stack->pos];
    stack->pos--;
    return data;
}

bool array_stack_push(stArrayStack *stack, int data) {
    if (array_stack_is_full(stack)) {
        return false;
    }
    stack->pos++;
    stack->array[stack->pos] = data;
    return true;
}

bool array_stack_push_new(stArrayStack *stack, int data) {
    if (array_stack_is_full(stack) == false) {
        return array_stack_push(stack, data);
    }
    
    int *tmpArray = (int *)malloc(sizeof(int) * 2 * stack->size);
    if (tmpArray == NULL) {
        return false;
    }
    
    memcpy(tmpArray, stack->array, stack->size * sizeof(int));
    free(stack->array);
    
    stack->array = tmpArray;
    stack->size = 2 * stack->size;
    stack->pos++;
    stack->array[stack->pos] = data;
    return true;
}

void array_stack_dump(stArrayStack *stack) {
    if (array_stack_is_empty(stack)) {
        printf("array stack is empty\n");
        return;
    }
    
    printf("array stack size = %d, pos = %d\n", stack->size, stack->pos);
    
    int i = 0;
    for (i = 0; i <= stack->pos; i++) {
        printf("array[%d] = %d\n", i, stack->array[i]);
    }
}

int main() {
    
    stArrayStack *stack = array_stack_create(2);
    if (stack == NULL) {
        return 0;
    }
    
    array_stack_push_new(stack, 2);
    array_stack_dump(stack);
    array_stack_push_new(stack, 3);
    array_stack_dump(stack);
    array_stack_push_new(stack, 4);
    array_stack_dump(stack);
    
    printf("\n");
    
    int a = array_stack_pop(stack);
    printf("pop %d\n", a);
    array_stack_dump(stack);
    
    printf("\n");
    
    int b = array_stack_pop(stack);
    printf("pop %d\n", b);
    array_stack_dump(stack);
    
    printf("\n");
    
    int c = array_stack_pop(stack);
    printf("pop %d\n", c);
    array_stack_dump(stack);
    
    printf("\n");
    
    int d = array_stack_pop(stack);
    printf("pop %d\n", d);
    array_stack_dump(stack);
    
    printf("\n");
    
    
    return 0;
}
