
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>


/*
// 暴力解决方法，合并两个数组，找到中位数
#define INT_MAX 2147483647
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int allSize = nums1Size + nums2Size;
    int *allNums = malloc(sizeof(int) * allSize);
    
    int index1 = 0, index2 = 0;
    for (int i = 0; i < allSize/2 + 1; i++) {
        int tmpNum1 = index1 < nums1Size ? nums1[index1] : INT_MAX;
        int tmpNum2 = index2 < nums2Size ? nums2[index2] : INT_MAX;
        if (tmpNum1 > tmpNum2) {
            allNums[i] = tmpNum2;
            index2++;
        } else {
            allNums[i] = tmpNum1;
            index1++;
        }
        printf("%d ", allNums[i]);
    }
    if (allSize % 2 == 1) {
        return allNums[allSize/2];
    } else {
        return (allNums[allSize/2 - 1] + allNums[allSize/2]) * 0.5;
    }
}
*/


/*
// 不用合并数组，只要找到中间那个数就好，判断奇数偶数。
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int allSize = nums1Size + nums2Size;
    int index1 = 0, index2 = 0, left = 0, right = 0;
    
    for (int i = 0; i <= allSize/2 ; i++) {
        left = right;
        //这里需要注意，两个数组别越界了。数组 A 比 B 小 或者 B 已经遍历完了，取 A 的值。否则就取 B 的值。
        if (index1 < nums1Size && (index2 >= nums2Size || nums1[index1] < nums2[index2]) ) {
            right = nums1[index1++];
            printf("1-%d-%d  ", index1 - 1, right);
        } else if (index2 < nums2Size) {
            right = nums2[index2++];
            printf("2-%d-%d  ", index2 - 1, right);
        }
        printf("%d %d\n", left, right);
    }
    
    if (allSize % 2 == 1) {
        return right;
    } else {
        return (right + left) * 0.5;
    }
}
*/



//递归，找到两个数组中，第 k 小的那个数
/**
 1 3 5 7 9
 2 4 6 8 10
 当想在两个有序数组中，找到第 k 小的那个数。
 分别在数组中排除前 k/2 个元素。
 因为第 k 小的那个数，要么在第1个数组的前k/2中，要么在第2个数组的前k/2中。
 分别比较 1 2 数组中第 k/2 这个数的大小，小的那个数组前 k/2 个元素就可以排除了，
 因为 假设小的那个数组前 k/2 个元素中要是有第k小的数，那么一个index < k/2 + k/2 不可能等于 k，所以可以排除。
 排除了 k/2 之后，然后就是要找新的小数组和原来那个较大值的那个数组中，第 k - k/2 小的那个数，
 如此下去，直到排除到，k - k/2 == 1 就是两个数组中第一个数小的那个值。
 */
#define M_MIN(x, y) ((x) < (y) ? (x) : (y))
int getSortNumber(int *nums1, int start1, int end1, int *nums2, int start2, int end2, int k) {
    int length1 = end1 - start1 + 1, length2 = end2 - start2 + 1;
    //让数组1的长度，小于数组2的长度
    if (length1 > length2) {
        return getSortNumber(nums2, start2, end2, nums1, start1, end1, k);
    }
    //当数组长度小的那个，已经排除完了，那就直接返回另个数组中第 k 小的那个值就行了
    if (length1 == 0) {
        return nums2[start2 + k - 1];
    }
    //结束递归
    if (k == 1) {
        return M_MIN(nums1[start1], nums2[start2]);
    }
    
    //比较 1 2 数组中第 k/2 这个数的大小，小的那个数组前 k/2 个元素就可以排除了
    int i = start1 + M_MIN(length1, k/2) - 1;
    int j = start2 + M_MIN(length2, k/2) - 1;
    if (nums1[i] > nums2[j]) {
        return getSortNumber(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1));
    } else {
        return getSortNumber(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1));
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int allSize = nums1Size + nums2Size;
    if (allSize % 2 == 1) {
        return getSortNumber(nums1, 0, nums1Size, nums2, 0, nums2Size, allSize/2 + 1);
    } else {
        return (getSortNumber(nums1, 0, nums1Size, nums2, 0, nums2Size, allSize/2)+ getSortNumber(nums1, 0, nums1Size, nums2, 0, nums2Size, allSize/2 + 1)) * 0.5;
    }
    return 0;
}



int main(int argc, const char * argv[]) {
    
    int a[] = {0, 0} ;
    int b[] = {0, 0};
    printf("\n%lf\n", findMedianSortedArrays(b, 2, a, 2));
    return 0;
}
