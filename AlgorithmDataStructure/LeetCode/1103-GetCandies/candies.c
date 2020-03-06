
#include <stdio.h>
#include <stdlib.h>

int* distributeCandies(int candies, int num_people, int* returnSize){
    if (num_people <= 0) { *returnSize = 0; return NULL; }
    
    *returnSize = num_people;
    int *returnArray = (int *)malloc(sizeof(int) * num_people);
    
    int sum = 0, max = 0, count = 0, cur = 0;
    for (int i = 0; i < num_people; i++) {
        cur = max = i + 1;
        sum = (cur + 1) * cur / 2;
        count = 1;
        while (sum <= candies) {
            cur = count * num_people + i + 1;
            max += cur;
            sum = (cur + 1)* cur / 2;
            count++;
        }
        printf("sum = %d, max = %d, cur = %d\n", sum, max, cur);
        if (sum - cur > candies) {
            returnArray[i] = max - cur;
        } else {
            returnArray[i] = count > 1 ? max + candies - sum : candies + cur - sum;
        }
    }
    return returnArray;
}



int main(int argc, const char * argv[]) {
    
    int candies = 7;
    int peoples = 5;
    int returnSize = 0;
    int *a = distributeCandies(candies, peoples, &returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}

