
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <math.h>

void dump(int a[], int size) {
    if (size <= 0) { return; }
    printf("\n");
    int i = 0;
    for (i = 0; i < size; i++) { printf("%d ", a[i]); }
    printf("\n");
    return;
}

//----------------------------

//桶排序
//将数据分在一个个桶里，每个桶里面用快速排序

int partition(int a[], int left, int right) {
    int i = left, j = left, key = a[right];
    
    for (; j < right; j++) {
        if (a[j] < key ) {
            if (i != j) {
                int tmp1 = a[j];
                a[j] = a[i];
                a[i] = tmp1;
            }
            i++;
        }
    }
    int tmp2 = a[i];
    a[i] = a[right];
    a[right] = tmp2;
    return i;
}

void quick_sort(int a[], int left, int right) {
    if (left >= right) { return; }
    
    int m = partition(a, left, right);
    quick_sort(a, left, m - 1);
    quick_sort(a, m + 1, right);
}



struct barrel {
    int node[10];
    int count;
};
void bucket_sort(int data[], int size) {
    
    int max, min, num, pos;
    int i, j, k;
    struct barrel *pBarrel;
    
    max = min = data[0];
    for (i = 1; i < size; i++) {
        if (data[i] > max) {
            max = data[i];
        } else if(data[i] < min) {
            min = data[i];
        }
    }
    num = (max - min + 1) / 10 + 1; //根据数据范围，确定要创建多少个桶，每个桶里放的不多于10个
    pBarrel = (struct barrel *)malloc(sizeof(struct barrel) * num);
    memset(pBarrel, 0, sizeof(struct barrel) * num);
    
    //将数据放入对应的桶中，每个桶中的数据范围 k*10+(0...9)
    for (i = 0; i < size; i++) {
        k = (data[i] - min + 1) / 10;
        (pBarrel + k)->node[(pBarrel + k)->count] = data[i];
        (pBarrel + k)->count++;
    }
    
    //分别对各个桶中的数据进行排序
    pos = 0;
    for (i = 0; i < num; i++) {
        if ((pBarrel + i)->count > 0) {
            quick_sort((pBarrel + i)->node, 0, (pBarrel + i)->count - 1);
            
            for (j = 0; j < (pBarrel + i)->count; j++) {
                data[pos] = (pBarrel + i)->node[j];
                pos++;
            }
        }
    }
    free(pBarrel);
}


//----------------------------

//计数排序。跟桶排序类似，排序的数据非负数，只能用在数据范围不大的场景中
//时间复杂度 O(n), 非原地排序

void count_sort(int a[], int size) {
    
    int max = 0, i = 0, *count = 0, *res = 0;
    
    //找到最大值
    for (i = 0; i < size; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    
    //计数
    count = (int *)malloc(sizeof(int) * (max + 1));
    if (count == NULL) { return; }
    memset(count, 0, sizeof(int) * (max + 1));
    
    for (i = 0; i < size; i++) {
        count[a[i]]++;
    }
    
    //依次累加，当前位的值是前面累加的和
    for (i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    
    
    //核心代码，count[a[i]] - 1 就是排序好的s下标。思考一下为什么
    res = (int *)malloc(sizeof(int) * size);
    if (res == NULL) { return; }
    for (i = size - 1; i >= 0; i--) {
        res[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }
    
    memcpy(a, res, sizeof(int) * size);
    
    free(res);
    free(count);
    return;
}

//----------------------------

//基数排序
//

#define NUM_OF_POS(a,pval) ((a)/pval)%10
void radix_sort(int a[], int size, int num_count) {
    
    int count[10] = {0};
    int *pres = NULL;
    int i = 0, j = 0, pval = 10, index = 0, break_flg = 0;
    
    pres = (int *)malloc(sizeof(int) * size);
    if (pres == NULL) { return; }
    
    for (i = 0; i < num_count; i++) {
        memset(count, 0, sizeof(int) * 10);
        //求当前的基数
        pval = pow(10, i);
        
        //计数
        for (j = 0; j < size; j++) {
            index = (a[j]/pval)%10;
            count[index]++;
        }
        
        if (count[0] == 9) {
            break_flg++;
        }
        
        if (break_flg >= 2) {
            printf("%i", i);
            break;
        }
        
        for (j = 1; j < 10; j++) {
            count[j] += count[j - 1];
        }
        
        for (j = size - 1; j >= 0; j--) {
            index = (a[j]/pval)%10;
            pres[count[index] - 1] = a[j];
            count[index]--;
        }
        
        memcpy(a, pres, sizeof(int) * size);
    }
    return;
}



//----------------------------


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    int a[] = {2,7,6,8,1,3,0,9,5,11,15,23,16,4,18,26};
    int size = sizeof(a)/sizeof(int);
    bucket_sort(a, size);
    //count_sort(a, size);
    dump(a, size);
    
    
    //    //桶排序
    //    int testa1[200][2000];
    //    int i = 0, j = 0;
    //    for (i = 0; i < 200; i++) {
    //        for (j = 0; j < 2000; j++) {
    //            int value = arc4random() % 100000;
    //            testa1[i][j] = value + 1;
    //        }
    //    }
    //
    //    clock_t start1, end1;
    //    double cpu_time_used;
    //    start1 = clock();
    //    for (i = 0; i < 200; i++) {
    //        bucket_sort(testa1[i], 2000);
    //    }
    //    end1 = clock();
    //    cpu_time_used = ((double) (end1 - start1)) / CLOCKS_PER_SEC;
    //    printf("--------- = %.8lf\n", cpu_time_used);
    //    //--------- = 0.02081200
    
    
    //基数排序
    int a2[10] = {123,12341,1232134,124,236,128,1112313129,98,9,8989};
    radix_sort(a2,10,10);
    dump(a2,10);
    
    return 0;
}


