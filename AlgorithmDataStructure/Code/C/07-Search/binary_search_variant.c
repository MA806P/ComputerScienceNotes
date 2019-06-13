#include <stdlib.h>
#include <stdio.h>


int binary_search(int a[], int size, int value) {
    int low = 0, high = size - 1, mid;
    while (low <= high) {
        mid = low + ((high - low) >> 1);
        if (a[mid] < value) {
            low = mid + 1;
        } else if (a[mid] > value) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}


/* 查找第一个等于给定数值的元素 */
int binary_search_first_one(int a[], int size, int value) {
    int low = 0, high = size - 1, mid;
    while (low <= high) {
        mid = low + ((high - low) >> 1);
        if (a[mid] < value) {
            low = mid + 1;
        } else if (a[mid] > value) {
            high = mid - 1;
        } else {
            //当二分中间点就是时，判断前一个是不是重复值，直到找到第一个
            if (mid == 0 || a[mid - 1] != value) {
                return mid;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int binary_search_first_one2(int a[], int size, int value) {
    int low = 0, high = size - 1, mid;
    while (low <= high) {
        mid = low + ((high - low) >> 1);
        //printf("low = %d, high = %d, a[%d]=%d\n",low,high,mid,a[mid]);
        if (a[mid] >= value) {
            //这里将等于的情况和大于的一起处理了
            //不论前一个是不是重复的，缩小区间，直到low+1大于high，就是之前等于的那个mid=value
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    if (low < size && a[low] == value) {
        return low;
    } else {
        return -1;
    }
}

//递归，二分查找第一个给定数值的元素
int binary_search_first_one_r(int a[], int size, int value) {
    if (size <= 0) { return -1; }
    
    int idx, mid = size/2;
    if (a[mid] == value) {
        idx = binary_search_first_one_r(a, mid, value);
        //如果中间值就是，不确定前一个是否重复，再次的缩小范围查找
        return idx != -1 ? idx : mid;
    }
    
    if (!mid) { return -1; }
    
    if (a[mid] < value) {
        idx = binary_search_first_one_r(a + mid + 1, size - mid - 1, value);
        if (idx != -1) { idx += mid + 1;}
    } else {
        idx = binary_search_first_one_r(a, mid , value);
    }
    return idx;
}


/* 查找最后一个等于给定数值的元素 */
int binary_search_last_one(int a[], int size, int value) {
    int low = 0, high = size - 1, mid;
    while (low <= high) {
        mid = low + ((high - low) >> 1);
        if (a[mid] < value) {
            low = mid + 1;
        } else if (a[mid] > value) {
            high = mid - 1;
        } else {
            //当二分中间点就是时，判断后一个是不是重复值
            //是的话缩小区间，修改low的值，直到找到最后一个
            if (mid == size - 1 || a[mid + 1] != value) {
                return mid;
            } else {
                low = mid + 1;
            }
        }
    }
    return -1;
}

//递归，二分查找最后一个给定数值的元素
int binary_search_last_one_r(int a[], int size, int value) {
    if (size <= 0) { return -1; }
    
    int idx, mid = size/2;
    if (a[mid] == value) {
        idx = binary_search_last_one_r(a + mid + 1, size - mid - 1, value);
        //如果中间值就是，不确定后一个是否重复，再次的缩小范围查找
        return idx != -1 ? mid + idx + 1 : mid;
    }
    
    if (!mid) { return -1; }
    
    if (a[mid] < value) {
        idx = binary_search_last_one_r(a + mid + 1, size - mid - 1, value);
        if (idx != -1) { idx += mid + 1;}
    } else {
        idx = binary_search_last_one_r(a, mid , value);
    }
    return idx;
}


/* 查找第一个大于等于给定数值的元素 */
int binary_search_first_big(int a[], int size, int value) {
    int low = 0, high = size - 1, mid;
    while (low <= high) {
        mid = low + ((high - low) >> 1);
        //printf("low = %d, high = %d, a[%d]=%d\n",low,high,mid,a[mid]);
        if (a[mid] < value) {
            low = mid + 1;
        } else {
            if (mid == 0 || a[mid - 1] < value) {
                return mid;
            } else {
                high = mid - 1;
            }
        }
    }
    return -1;
}

//递归，二分查找第一个大于等于给定数值的元素
int binary_search_first_big_r(int a[], int size, int value) {
    if (size <= 0) { return -1; }

    int idx = -1, mid = size/2;
    if (a[mid] >= value) {
        idx = binary_search_first_big_r(a, mid, value);
        //如果中间值就是大于等于，不确定前一个是否也大于等于，要缩小区间继续
        if (idx == -1) { idx = mid; }
    } else {
        idx = binary_search_first_big_r(a + mid + 1, size - mid - 1, value);
        if (idx != -1) { idx += mid + 1; }
    }
    return idx;
}


/* 查找最后一个小于等于给定数值的元素 */
int binary_search_last_small(int a[], int size, int value) {
    int low = 0, high = size - 1, mid;
    while (low <= high) {
        mid = low + ((high - low) >> 1);
        printf("low = %d, high = %d, a[%d]=%d\n",low,high,mid,a[mid]);
        if (a[mid] > value) {
            high = mid - 1;
        } else {
            if (mid == size - 1 || a[mid + 1] > value) {
                return mid;
            } else {
                low = mid + 1;
            }
        }
    }
    return -1;
}

//递归，二分查找最后一个小于等于给定数值的元素
int binary_search_last_small_r(int a[], int size, int value) {
    if (size <= 0) { return -1; }
    int idx, mid = size/2;
    if (a[mid] <= value) {
        idx = binary_search_last_small_r(a + mid + 1, size - mid - 1, value);
        if (idx != -1) {
            idx += mid + 1;
        } else {
            idx = mid;
        }
    } else {
        idx = binary_search_last_small_r(a, mid, value);
    }
    return idx;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    int a[10] = {5,6,6,9,10,11,11,22,33,33};
    //int a[10] = {0,1,2,3,4,5,6,7,8,9};
    int a2[10] = {0};
    int b = binary_search_last_small_r(a, 10, 8);
    int b2 = binary_search_last_small_r(a, 10, 11);
    int b3 = binary_search_last_small_r(a, 10, 33);
    int b4 = binary_search_last_small_r(a2, 10, 0);
    printf("\n ------%d %d %d %d------ \n", b,b2,b3,b4);
    
    
    return 0;
}
