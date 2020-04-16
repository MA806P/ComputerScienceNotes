

#include <stdio.h>
#include <stdlib.h>

//快速排序
//选择一元素(一般是最后一个)作为分界点，分界点前比它小，后面都是比它大的
//然后子分区继续这样分，直到最后只有一个元素
void swap_item(int **a, int **b) { int *temp = *a; *a = *b; *b = temp; }
int partition(int **array, int p, int r) {
    int i = p;
    for (int j = p; j < r; j++) {
    //这里把大于 r 位的数，换到后面，小的换到前面
    //保证了，i 位前的都小于 r，i 位是第一个大于 r 的，遍历完 i r 互换
        if (array[j][0] < array[r][0]) {
            if (i != j) { swap_item(array + i, array + j); }
            i++;
        }
    }
    swap_item(array + i, array + r);
    return i;
}
void quick_sort(int **array, int p, int r) {
    if (p >= r) { return; }
    int q = partition(array, p, r);
    quick_sort(array, p, q - 1);
    quick_sort(array, q + 1, r);
}




int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    
    if (intervals == NULL || intervalsSize < 2 || intervalsColSize == NULL) {
        *returnSize = intervalsSize;
        *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
        for (int i = 0; i < (*returnSize); i++) {
            (*returnColumnSizes)[i] = intervalsColSize[i];
        }
        return intervals;
    }
    
    //先进行排序
    quick_sort(intervals, 0, intervalsSize - 1);
    
    for (int i = 0; i < intervalsSize; i++) {
        int column = intervalsColSize[i];
        for (int j = 0; j < column; j++) {
            printf("%d  ", intervals[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    
    
    *returnSize = 0;
    int **ans = (int **)malloc(sizeof(int **) * intervalsSize);
    for (int i = 0; i < intervalsSize; i++) {
        ans[i] = NULL;
    }
    
    //然后遍历数组，查看是否包含
    int left = intervals[0][0], right = intervals[0][1];
    for (int i = 1; i < intervalsSize; i++) {
        int *items = intervals[i];
        
        if (right < items[0]) {
            int *temp = (int *)malloc(sizeof(int) * 2);
            temp[0] = left; temp[1] = right;
            ans[(*returnSize)] = temp;
            (*returnSize) += 1;
            
            left = items[0];
            right = items[1];
        } if (right >= items[0] && right <= items[1]) {
            right = items[1];
        }
    }
    
    int *temp = (int *)malloc(sizeof(int) * 2);
    temp[0] = left; temp[1] = right;
    ans[(*returnSize)] = temp;
    (*returnSize) += 1;
    
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < (*returnSize); i++) {
        (*returnColumnSizes)[i] = 2;
    }
    
    return ans;
}



int main(int argc, const char * argv[]) {
    
    int a[4][2] = {{8,6},{9,18},{1,3},{8,10}};
    int b[4] = {2,2,2,2};
    int **intervals = (int **)malloc(sizeof(int **) * 4);
    for (int i = 0; i < 4; i++) {
        int *temp = (int *)malloc(sizeof(int) * 2);
        for (int j = 0; j < 2; j++) {
            temp[j] = a[i][j];
        }
        intervals[i] = temp;
    }
    
    
    
    
    int returnSize = 0;
    int *columnSize;
    int **ans = merge(intervals, 4, b, &returnSize, &columnSize);
    
    for (int i = 0; i < returnSize; i++) {
        int column = columnSize[i];
        for (int j = 0; j < column; j++) {
            printf("%d  ", ans[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    return 0;
}




