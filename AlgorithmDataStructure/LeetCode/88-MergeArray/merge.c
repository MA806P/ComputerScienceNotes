
#include <stdio.h>
#include <stdlib.h>


//1、笨方法，比较大小 每次 A 都往后移动
void merge0(int* A, int ASize, int m, int* B, int BSize, int n){
    if (A == NULL || B == NULL) { return; }
    
    int start = 0;
    for (int i = 0; i < n; i++) {
        for (; start < ASize; start++) {
            //注意当遍历A结束了B还有值，后面B>A
            if (start >= m + i || A[start] > B[i]) {
                int p = i + m - 1;
                while (p >= start) {
                    A[p+1] = A[p];
                    p--;
                }
                A[start] = B[i];
                break;
            }
        }
    }
    
}

//2、先合并成一个数组然后，快速排序
void mySwapItem(int *a, int *b) { int temp = *a; *a = *b; *b = temp; }
int myPartition(int *array, int p, int r) {
    int i = p;
    for (int j = p; j < r; j++) {
        if (array[j] < array[r]) {
            if (i != j) { mySwapItem(array + i, array + j); }
            i++;
        }
    }
    mySwapItem(array + i, array + r);
    return i;
}
void myQuickSort(int *array, int p, int r) {
    if (p >= r) { return; }
    int q = myPartition(array, p, r);
    myQuickSort(array, p, q - 1);
    myQuickSort(array, q + 1, r);
}

void merge1(int* A, int ASize, int m, int* B, int BSize, int n){
    if (A == NULL || B == NULL) { return; }
    for (int i = m; i < m + n; i++) {
        A[i] = B[i-m];
    }
    myQuickSort(A, 0, m + n - 1);
}


//3、双指针遍历AB，用额外的空间，先保存
void merge2(int* A, int ASize, int m, int* B, int BSize, int n){
    if (A == NULL || B == NULL) { return; }
    
    int sorted[m + n];
    int pa = 0, pb = 0, r = 0;
    while (pa < m || pb < n) {
        if (pa == m) {
            r = B[pb++];
        } else if (pb == n) {
            r = A[pa++];
        } else if (A[pa] > B[pb]) {
            r = B[pb++];
        } else {
            r = A[pa++];
        }
        sorted[pa + pb - 1] = r;
    }
    for (int i = 0; i < m + n; i++) {
        A[i] = sorted[i];
    }
}


//逆向双指针，从后往前
void merge(int* A, int ASize, int m, int* B, int BSize, int n){
    if (A == NULL || B == NULL) { return; }
    
    int pa = m - 1, pb = n - 1, r = 0, i = m + n - 1;
    while (pa >= 0 || pb >= 0) {
        if (pa < 0) {
            r = B[pb--];
        } else if (pb < 0) {
            r = A[pa--];
        } else if (A[pa] > B[pb]) {
            r = A[pa--];
        } else {
            r = B[pb--];
        }
        A[i--] = r;
    }
    
}

int main(int argc, const char * argv[]) {
    int a[] = {1,2,3,4,5,6,0,0,0,0};
    int b[] = {1,2,3};
    merge(a, 10, 6, b, 3, 3);
    
    for (int i = 0; i < 10; i++) {
        printf(" %d", a[i]);
    }
    printf("\n");
    
    return 0;
}











