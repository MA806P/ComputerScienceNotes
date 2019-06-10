#include <stdlib.h>
#include <stdio.h>

int binary_search_i(int a[], int size, int value) {
    
    int low = 0, high = size - 1, mid;
    
    while (low <= high) {
        
        mid = (low + high) / 2;
        // 防止size数量太大时，（left + right）可能溢出，导致问题
        //mid = low + (high - low) / 2;
        //mid = low + ((high - low)>>1);
        
        
        if (a[mid] == value) {
            return mid;
        } if (a[mid] < value) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}


int binary_search_r(int a[], int size, int value) {
    int mid = size/2, index;
    
    if (a[mid] == value) { return mid; }
    if (!mid) { return -1; }
    
    if (a[mid] < value) {
        index = binary_search_r(a + mid + 1, size - mid - 1, value);
        if (index != -1) { index += mid + 1; }
    } else {
        index = binary_search_r(a, mid, value);
    }
    return index;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    
    int arr[10] = {1, 4, 5, 9, 12, 19, 21, 28, 31, 36};
    int idx;
    
    idx = binary_search_i(arr, 10, 12);
    if (idx != -1) {
        printf("find 12 at %d\n", idx);
    } else {
        printf("12 not in arr \n");
    }
    
    idx = binary_search_i(arr, 10, 13);
    if (idx != -1) {
        printf("find 13 at %d\n", idx);
    } else {
        printf("13 not in arr \n");
    }
    
    
    
    idx = binary_search_r(arr, 10, 12);
    if (idx != -1) {
        printf("find 12 at %d\n", idx);
    } else {
        printf("12 not in arr \n");
    }
    
    idx = binary_search_r(arr, 10, 13);
    if (idx != -1) {
        printf("find 13 at %d\n", idx);
    } else {
        printf("13 not in arr \n");
    }
    
    return 0;
}

