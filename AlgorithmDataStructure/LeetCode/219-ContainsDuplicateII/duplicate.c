
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


//#define INT_MAX 2147483647
//#define INT_MIN (-INT_MAX - 1)




//自己实现 hash 表。保存的索引值有点绕，画图方便理解
bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    if (nums == NULL || numsSize < 2) { return false; }
    
    int map[numsSize];
    memset(map, -1, sizeof(map));
    
    int temp = 0;
    for (int i = 0; i < numsSize; i++) {
        //hash 函数。temp 作为 map 的索引值 < numsSize
        temp = nums[i]%numsSize;
        if (temp < 0) { // nums[i] 可能为负数，temp 转换为正数
            temp += numsSize - 1;
        }
        printf("[%d]=%d key=%d\n",i,nums[i], temp);
        
        
        if (map[temp] == -1) {
            //没有出现重复的。把下标存入 hash 表
            map[temp] = i;
            
            for (int i = 0; i < numsSize; i++) { printf("%d ", map[i]); }
            printf(" a\n");
            
        } else {
            
            for (int i = 0; i < numsSize; i++) { printf("%d ", map[i]); }
            printf(" b\n");
            
            //hash 冲突处理。就是通过 hash 函数处理后，
            //不同的值对应 hash 表是相同的 key
            //发生 hash 冲突后按照“线性探测”往后探测到第一个空位置填入
            while (nums[i] != nums[map[temp]]) { //判断是否有冲突
                temp++; temp %= numsSize;
                if (map[temp] == -1) { //空位置填入
                    map[temp] = i;
                    printf("temp=%d i=%d\n", temp, i);
                }
            }
            
            //出现重复的
            if (i != map[temp] && i - map[temp] <= k) {
                printf("end=%d %d %d", i, nums[i],map[temp]);
                return true;
            } else {
                //这里更新最新的相同索引值
                //因为可能i=6时 [0]=9 [6]=9, 6-0>k，这时需要
                //map[temp]=6，替换之前的旧值 map[temp]=0
                map[temp] = i;
            }
            
            for (int i = 0; i < numsSize; i++) { printf("%d ", map[i]); }
            printf(" c\n");
        }
        
        
    }
    return false;
}


int main(int argc, const char * argv[]) {
    
    int nums[4] = {9,0,9,9};
    printf("ans = %d \n", containsNearbyDuplicate(nums, 4, 1));
    return 0;
}



