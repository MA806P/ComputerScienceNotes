
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define SWAP(a, b) \
do { \
(a) ^= (b);\
(b) ^= (a);\
(a) ^= (b);\
} while(0)


void dump(int a[], int size) {
    if (size <= 0) {
        return;
    }
    int i = 0;
    for (i = 0; i < size; i++) {
        printf("a[%d] = %d\n", i, a[i]);
    }
    printf("\n");
    return;
}

void bubble_sort(int a[], int size) {
    if (size <= 1) { return; }
    int i = 0, j = 0, swap_flag = 0;
    for (i = size - 1; i > 0; i--) {
        swap_flag = 0;
        for (j = 0; j < i; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                
                //SWAP(a[j], a[j + 1]);
                swap_flag = 1;
            }
        }
        if (swap_flag == 0) { break; }
    }
    return;
}

void my_bubble_sort(int a[], int size) {
    if (size <= 1) { return; }
    int i = 0, j = 0, swap_flag = 0;
    for (i = 0; i < size; i++) {
        swap_flag = 0;
        for (j = 0; j < size - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                SWAP(a[j], a[j + 1]);
                swap_flag = 1;
            }
        }
        if (swap_flag == 0) { break; }
    }
    return;
}

void insert_sort(int a[], int size) {
    if (size <= 1) { return; }
    int i = 0, j = 0, key = 0;
    for (i = 1; i < size; i++) {
        key = a[i];
        // i 之前的都是有序的，找到比 i 位的值小的插入到后面
        // 比 i 位值大的，往后移一位
        for (j = i - 1; j >= 0; j--) {
            if (a[j] > key) {
                a[j + 1] = a[j];
            } else {
                break;
            }
        }
        //j = i - 1;
        //while (j >= 0 && a[j] > key) { a[j + 1] = a[j]; j--; }
        
        a[j + 1] = key;
    }
    return;
}

void select_sort(int a[], int size) {
    if (size <= 1) {
        return;
    }
    //已排序区，未排序区
    //在未排序区找到最小的，插入到已排序区的最后
    int i = 0, j = 0, min = 0;
    for (i  = 0; i < size - 1; i++) {
        min = i;
        for (j = i + 1; j < size; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        if (min != i) {
            SWAP(a[i], a[min]);
        }
    }
    return;
}


//--------------------------------

void merge(int a[], int p, int q, int r) {
    int *tmp = malloc(sizeof(int) * (r - p + 1));
    if (!tmp) {
        abort();
    }
    
    int i = p, j = q + 1, k = 0;
    while (i <= q && j <= r) {
        if (a[i] <= a[j]) {
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++];
        }
    }
    
    if (i == q + 1) {
        while (j <= r) {
            tmp[k++] = a[j++];
        }
    } else {
        while (i <= q) {
            tmp[k++] = a[i++];
        }
    }
    
    memcpy(a + p, tmp, (r - p + 1) * sizeof(int));
    free(tmp);
}

void merge_sort(int a[], int p, int r) {
    if (p >= r) {
        return;
    }
    
    int q = (p + r) / 2;
    merge_sort(a, p, q);
    merge_sort(a, q + 1, r);
    merge(a, p, q, r);
}

void merge_sort_size(int a[], int size) {
    merge_sort(a, 0, size - 1);
}




int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    //int a[10] = {7,5,6,8,1,2,3,4,9,0};
    //int size = sizeof(a)/sizeof(a[0]);
    //bubble_sort(a, size);
    //insert_sort(a, size);
    //select_sort(a, size);
    
    //my_bubble_sort(a, size);
    
    //dump(a, size);
    
    
//    int testa1[200][2000], testa2[200][2000], testa3[200][2000];
//    int i = 0, j = 0;
//    for (i = 0; i < 200; i++) {
//        for (j = 0; j < 2000; j++) {
//            int value = arc4random() % 100000;
//            testa1[i][j] = value + 1;
//            testa2[i][j] = value + 2;
//            testa3[i][j] = value + 3;
//        }
//    }
//
//
//
//    clock_t start1, end1;
//    double cpu_time_used;
//    start1 = clock();
//    for (i = 0; i < 200; i++) {
//        bubble_sort(testa1[i], 2000);
//    }
//    end1 = clock();
//    cpu_time_used = ((double) (end1 - start1)) / CLOCKS_PER_SEC;
//    printf("---------1 = %.8lf\n", cpu_time_used);
//
//
//    start1 = clock();
//    for (i = 0; i < 200; i++) {
//        insert_sort(testa2[i], 2000);
//    }
//    end1 = clock();
//    cpu_time_used = ((double) (end1 - start1)) / CLOCKS_PER_SEC;
//    printf("---------2 = %.8lf\n", cpu_time_used);
//
//
//    start1 = clock();
//    for (i = 0; i < 200; i++) {
//        select_sort(testa3[i], 2000);
//    }
//    end1 = clock();
//    cpu_time_used = ((double) (end1 - start1)) / CLOCKS_PER_SEC;
//    printf("---------3 = %.8lf\n", cpu_time_used);
//
//
//    //---------1 = 1.53191600
//    //---------2 = 0.54968900
//    //---------3 = 0.87126800
    
    
    
//--------------------------------
    
    
    int testa1[200][2000];
    int i = 0, j = 0;
    for (i = 0; i < 200; i++) {
        for (j = 0; j < 2000; j++) {
            int value = arc4random() % 100000;
            testa1[i][j] = value + 1;
        }
    }
    
    clock_t start1, end1;
    double cpu_time_used;
    start1 = clock();
    for (i = 0; i < 200; i++) {
        merge_sort_size(testa1[i], 2000);
    }
    end1 = clock();
    cpu_time_used = ((double) (end1 - start1)) / CLOCKS_PER_SEC;
    printf("---------4 = %.8lf\n", cpu_time_used);
    //---------4 = 0.07637700
    
    
    
    return 0;
}


