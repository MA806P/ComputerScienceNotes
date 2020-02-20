
#include <stdio.h>
#include <stdlib.h>

//快速排序
void swap_item(int *a, int *b) { int temp = *a; *a = *b; *b = temp; }
int partition(int *array, int p, int r) {
    int i = p;
    for (int j = p; j < r; j++) {
        if (array[j] < array[r]) {
            if (i != j) { swap_item(array + i, array + j); }
            i++;
        }
    }
    swap_item(array + i, array + r);
    return i;
}
void quick_sort(int *array, int p, int r) {
    if (p >= r) { return; }
    int q = partition(array, p, r);
    quick_sort(array, p, q - 1);
    quick_sort(array, q + 1, r);
}

//栈
typedef int  DATATYPE;
typedef struct _list_stack {
    DATATYPE data;
    int count;
    struct _list_stack *next;
} stack;
stack *stackCreate() {
    stack *s = (stack *)malloc(sizeof(stack));
    if (s == NULL) { return NULL; }
    s->next = NULL;
    s->count = 0;
    return s;
}
void stackDestroy(stack *s) {
    stack *tempS = NULL;
    while (s->next != NULL) {
        tempS = s->next;
        s->next = tempS->next;
        free(tempS);
    }
    free(s);
}
void stackPush(stack *s, DATATYPE data) {
    stack *node = (stack *)malloc(sizeof(stack));
    if (node == NULL) { return; }
    s->count += 1;
    node->data = data;
    node->count = s->count;
    node->next = s->next;
    s->next = node;
}
DATATYPE stackPop(stack *s) {
    if (s->next == NULL) { return 0; }
    stack *next = s->next;
    DATATYPE data = next->data;
    s->count -= 1;
    s->next = next->next;
    free(next);
    return data;
}
void stackDump(stack *s) {
    if (s->next == NULL) { printf("stack empty!\n"); return; }
    stack *next = s->next;
    while (next != NULL) {
        printf("-> %d ", next->data);
        next = next->next;
    }
    printf("\n");
}


void dfs(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes, stack *s, int **result, int index) {
    
    if (target == 0) {
        int count = s->count;
        int *columns = (int *)malloc(sizeof(int) * count);
        stack *node = s->next;
        for (int i = count - 1; i >= 0; i--) {
            columns[i] = node->data;
            node = node->next;
        }
        result[*returnSize] = columns;
        (*returnColumnSizes)[*returnSize] = count;
        (*returnSize) += 1;
        return;
    }
    
    for (int i = index; i < candidatesSize; i++) {
        //剪枝，和超过 target 了
        if (target < candidates[i]) { break; }
        //剪枝，如果数组里有重复元素，前面的分支已经处理过了 前面分支处理的范围大
        //这里数组的元素和前一个元素一样，就不要走这个分支了，会有重复的。
        //举个例子 2，2，2，3，7 画个图就理解了
        if (i > index && candidates[i] == candidates[i-1]) { continue; }
        stackPush(s, candidates[i]);
        //这里把 i + 1 传过去，是因为题目要求，数组每个元素在每个组合中只能用一次
        //画图可帮助理解，数组排序后从 i + 1 开始遍历保证分支上只使用数组中的元素一次
        dfs(candidates, candidatesSize, target - candidates[i], returnSize, returnColumnSizes, s, result, i + 1);
        stackPop(s);
    }
    
}


int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    
    *returnSize = 0;
    *returnColumnSizes = (int *)malloc(sizeof(int) * 10);
    (*returnColumnSizes)[0] = 0;
    int **result = (int **)malloc(sizeof(int *) * 10);
    if (candidatesSize <= 0) { return result; }
    
    //排序
    quick_sort(candidates, 0, candidatesSize - 1);
    
    stack *s = stackCreate();
    dfs(candidates, candidatesSize, target, returnSize, returnColumnSizes, s, result, 0);
    
    return result;
}



int main(int argc, const char * argv[]) {
    
    int candidates[] = {2,3,2,7};
    int returnSize = 0;
    int *returnColumnSizes;
    int **res = combinationSum2(candidates, 4, 7, &returnSize, &returnColumnSizes);
    
    for (int n = 0; n < returnSize; n++) {
        int *column = res[n];
        int columnSize = returnColumnSizes[n];
        for (int i = 0; i < columnSize; i++) {
            printf("%d ", column[i]);
        }
        printf("\n");
    }
    return 0;
}





