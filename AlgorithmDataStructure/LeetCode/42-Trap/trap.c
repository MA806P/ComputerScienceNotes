

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//方法一，暴力遍历
//遍历数组，以当前为起点，分别向左右两边遍历，
//分别找到最大值 l r,较小的与当前相减，得到值累加就是结果
//找左右最大值，是为了看能不能存住水
//时间复杂度 O(n^2) 会超时 空间复杂度 O(1)
/*
            0  1    0    2    1    0    1   3   2    1    2    1
 maxL        1    1    2    2    2    2   3   3    3    3    3
 maxR        3    3    3    3    3    3   3   2    2    2    1
 ans   +(1-1)+1  +0   +1  +2   +1 +0 +0  +1   +0   +0 = 6
 */

int m_max(int a, int b) { return  a > b ? a : b;}
int m_min(int a, int b) { return  a < b ? a : b;}
int trap0(int* height, int heightSize){
    if (height == NULL || heightSize < 3) { return 0; }
    
    int ans = 0;
    for (int i = 1; i < heightSize - 1; i++) {
        int maxL = 0, maxR = 0;
        for (int j = i; j >= 0; j--) {
            maxL = m_max(maxL, height[j]);
        }
        for (int j = i; j < heightSize; j++) {
            maxR = m_max(maxR, height[j]);
        }
        ans += m_min(maxR, maxL) - height[i];
    }
    return ans;
}


//方法二，一 的改进遍历一遍把左右最大值存起来
//时间复杂度：O(n) 空间复杂度 O(n)
int trap1(int* height, int heightSize){
    if (height == NULL || heightSize < 3) { return 0; }
    
    int ans = 0;
    //左边最大值
    int *maxL = (int *)malloc(sizeof(int)*heightSize);
    memset(maxL, 0, sizeof(int)*heightSize);
    maxL[0] = height[0];
    for (int i = 1; i < heightSize; i++) {
        maxL[i] = m_max(maxL[i-1], height[i]);
    }
    //右边最大值
    int *maxR = (int *)malloc(sizeof(int)*heightSize);
    memset(maxR, 0, sizeof(int)*heightSize);
    maxR[heightSize - 1] = height[heightSize - 1];
    for (int i = heightSize - 2; i >= 0; i--) {
        maxR[i] = m_max(maxR[i+1], height[i]);
    }
    
    for (int i = 1; i < heightSize - 1; i++) {
        ans += m_min(maxR[i], maxL[i]) - height[i];
    }
    return ans;
}



//方法三、双指针
//从两边向中间比较，左右分别计算
//左边，看左边最大值，累加与当前的差
//右边，看右边最大值，累加与当前的差
int trap(int* height, int heightSize){
    if (height == NULL || heightSize < 3) { return 0; }
    int ans = 0;
    
    int left = 0, right = heightSize - 1;
    int leftMax = 0, rightMax = 0;
    while (left < right) {
        if (height[left] < height[right]) {
            if (height[left] >= leftMax) {
                leftMax = height[left];
            } else {
                ans += (leftMax - height[left]);
            }
            left += 1;
        } else {
            if (height[right] >= rightMax) {
                rightMax = height[right];
            } else {
                ans += (rightMax - height[right]);
            }
            right -= 1;
        }
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    
    int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    printf("ans = %d \n", trap(a,12));
    return 0;
}




