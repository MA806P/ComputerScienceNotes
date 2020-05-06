

#include <stdio.h>

typedef struct _mountain_array {
    int a[7];
    int l;
} MountainArray;

int get(MountainArray *m, int index) {
    if (index < m->l) {
        return m->a[index];
    }
    return -1;
}

int length(MountainArray *m) {
    return m->l;
}


//reverse 用来表示，升序，倒序。山顶左边升序，右边倒序。
//升序 * 1 不变。倒序 * -1 变成升序。都按照升序来处理。
int binarySearch(int target, MountainArray* mountainArr, int left, int right, int reverse) {
    target = target * reverse;
    while (left <= right) {  //注意，<=  还是 <
        int mid = left + (right - left)/2;
        int cur = reverse * get(mountainArr, mid);
        printf("%d-%d-%d = %d\n", left, mid, right, cur);
        if (target == cur) {
            return mid;
        } else if (cur < target) {
            left = mid + 1; //注意 +1 -1
        } else {
            right = mid - 1;
        }
        printf("%d-%d\n", left,right);
    }
    return -1;
}


int findInMountainArray(int target, MountainArray* mountainArr) {
    
    //二分查找，找到山顶
    int left = 0, right = length(mountainArr) - 1, mid = 0;
    while (left < right) {  //注意，<=  还是 <
        mid = left + (right - left)/2;
        if (get(mountainArr, mid) < get(mountainArr, mid + 1)) {
            left = mid + 1;
        } else {
            right = mid; //注意， = mid 不是 =mid-1
        }
    }
    
    //山顶
    int peak = left;
    //先在山顶左边，升序，搜索
    int ans = binarySearch(target, mountainArr, 0, peak, 1);
    if (ans != -1) { return ans;}
    //左边没有，就在山顶右边，降序，搜索
    return binarySearch(target, mountainArr, peak + 1, length(mountainArr) - 1, -1);
}

int main(int argc, const char * argv[]) {
    MountainArray m = {{1,2,3,4,5,3,1}, 7};
    int a = findInMountainArray(2, &m);
    printf("ans = %d\n", a);
    return 0;
}
















