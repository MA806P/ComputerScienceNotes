
#include <stdlib.h>
#include <stdio.h>

/*
int maxArea(int* height, int heightSize){
    if (height == NULL || heightSize < 2) { return 0; }
    int maxArea = 0;
    for (int i = 0; i < heightSize - 1; i++) {
        for (int j = i + 1; j < heightSize; j++) {
            int area = (j - i) * (height[i] > height[j] ? height[j] : height[i]);
            if (maxArea < area) {
                maxArea = area;
            }
        }
    }
    return maxArea;
}*/

//双指针，从两边往中间移动，找到最大值
int maxArea(int* height, int heightSize){
    int maxArea = 0, width = 0, i = 0, j = heightSize - 1;
    while (i < j) {
        width = j - i;
        int area = width * (height[i] > height[j] ? height[j--] : height[i++]);
        if (maxArea < area) {
            maxArea = area;
        }
    }
    return maxArea;
}

int main(int argc, const char * argv[]) {
    
    int height[] = {1,8,6,2,5,4,8,3,7};
    printf("%d\n", maxArea(height, 9));
    return 0;
}



