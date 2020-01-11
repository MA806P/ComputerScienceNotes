
#include <stdlib.h>
#include <stdio.h>

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



/*
//递归，找到两个数组中，第 k 小的那个数
// 1 3 5 7 9
// 2 4 6 8 10
// 当想在两个有序数组中，找到第 k 小的那个数。
// 分别在数组中排除前 k/2 个元素。
// 因为第 k 小的那个数，要么在第1个数组的前k/2中，要么在第2个数组的前k/2中。
// 分别比较 1 2 数组中第 k/2 这个数的大小，小的那个数组前 k/2 个元素就可以排除了，
// 因为 假设小的那个数组前 k/2 个元素中要是有第k小的数，那么一个index < k/2 + k/2 不可能等于 k，所以可以排除。
// 排除了 k/2 之后，然后就是要找新的小数组和原来那个较大值的那个数组中，第 k - k/2 小的那个数，
// 如此下去，直到排除到，k - k/2 == 1 就是两个数组中第一个数小的那个值。
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
        return getSortNumber(nums1, 0, nums1Size - 1, nums2, 0, nums2Size - 1, allSize/2 + 1);
    } else {
        int a = getSortNumber(nums1, 0, nums1Size - 1, nums2, 0, nums2Size - 1, allSize/2);
        int b = getSortNumber(nums1, 0, nums1Size - 1, nums2, 0, nums2Size - 1, allSize/2 + 1);
        return (a + b) * 0.5;
    }
}
*/


//中位数，就是集合中一个数，可将集合划分为相等的上下两部分。
//将两数组划分两半

//偶数：i + j = m - i + n - j  ===>  j = (m + n)/2 - i
//如果两数组总长度为偶数，可保证划分后前后长度相等，这时中位数=(左半部分最大值+右半部分最小值)/2
//奇数：i + j = m - i + n - j + 1  ===>  j = (m + n + 1)/2 - i
//如果数组总长度为奇数，划分后左半部分比右半部分多一个数，这时中位数=左半部分最大值

//无论奇偶，都可用 j = (m + n + 1)/2 - i，m+n是偶数 整数/2取整，+1值一样。
//0<=i<=m，j = (m + n + 1)/2 - i 为了保证 0<=j<=n，则必须保证 m<=n

//划分好之后就是要判断是否满足条件。两个数组根据 i 确定 j 的位置划分，确保划分的左右个数相等
//且满足条件 max(A [i - 1] , B [j - 1]) <= min(A[i] , B[j]）
// 只需要保证 B[j - 1] < = A[i] 和 A [i - 1] <= B[j]
//还要考虑边界条件

//所以最后要解决的问题就是找到满足条件的 i，用二分法确定 i
//i 从中间位置开始，然后减半找中间的，知道找到



double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    //确保数组2的长度大于数组1
    if (nums1Size > nums2Size) {
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    
    int iMin = 0, iMax = nums1Size;
    while (iMin <= iMax) {
        int i = (iMin + iMax)/2; //i 的值每次循环都是在上次 1/2 的基础上再 1/2
        int j = (nums1Size + nums2Size + 1)/2 - i;
        
        if (j != 0 && i != nums1Size && nums1[i] < nums2[j - 1]) {
            //不满足条件，左边 < 右边，划分后，数组2左边的值 > 数组1右边的值，需要增加 i ，同时根据公式 j 的值也变小了
            iMin = i + 1;
        } else if (i != 0 && j != nums2Size && nums1[i - 1] > nums2[j]) {
            //不满足条件，数组1左边的值 > 数组2右边的值，需要减小 i
            iMax = i - 1;
        } else {
            //找到了满足条件的 i
            //边界判断
            int maxLeft = 0;
            if (i == 0) {
                //划分后的数组1左边为空，即数组1最值小都比2[j]大，左边最大值2[j-1]
                maxLeft = nums2[j - 1];
            } else if (j == 0) {
                //划分后数组2左边为空，即数组2最小值都比1[i]大，左边最大值1[i-1]
                maxLeft = nums1[i - 1];
            } else {
                //划分后 1 2 左边都不为空，找到左边最大数
                maxLeft = nums1[i-1] > nums2[j-1] ? nums1[i-1] : nums2[j-1];
            }
            
            if ((nums1Size + nums2Size)%2 == 1) {
                //奇数，不用考虑右半部分，直接返回
                return maxLeft;
            } else {
                //偶数，找到右半部分最小值
                int minRight = 0;
                if (i == nums1Size) {
                    //划分后1的右边为空，即1的最大值都比2[j]小，右边最小值2[j]
                    minRight = nums2[j];
                } else if (j == nums2Size) {
                    //划分后2的右边为空，即2的最大值都比1[i]小，右边最小值1[i]
                    minRight = nums1[i];
                } else {
                    //划分后 1 2 右边都不为空，找到右边最小值
                    minRight = nums1[i] < nums2[j] ? nums1[i] : nums2[j];
                }
                return (maxLeft + minRight) * 0.5;
            }
        }
    }
    return 0.0;
}
int main(int argc, const char * argv[]) {
    int a[] = {1,3};
    int b[] = {2};
    printf("\n%lf\n", findMedianSortedArrays(a, 2, b, 1));
    return 0;
}
