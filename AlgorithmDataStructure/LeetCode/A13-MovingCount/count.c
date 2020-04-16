 
#include <stdio.h>

/**
0 1 2 3 4 5 6
1 2 3 4 5 6 7
2 3 4 5 6 7 8
3 4 5 6 7 8 9
4 5 6 7 8 9 10
5
6
7
8
9
10
 注意如果 k = 4, (10,0)这点虽然满足条件，但是机器人在(4,0)点就被阻挡了
 到不了 (10,0) 过不去，不能计算在内
 
*/

int eachSum(int a) {
    if (a <= 0 ) return 0;
    if (a > 0 && a < 10) { return a; }
    int temp = a, sum = 0;
    while (temp > 0) {
        sum += temp % 10;
        temp = temp/10;
    }
    return sum;
}

/*
 这个遍历坐标的方法不行，有阻挡的，就算符合条件，但是过不去也不行
int movingCount(int m, int n, int k){
    if (m <= 0 || n <= 0) { return 0; }
    int ans = 0, sum = 0;
    for (int i = 0; i < m; i++) {
        if (eachSum(i) > k) { break; }
        for (int j = 0; j < n; j++) {
            //if (eachSum(j) > k) { break; }
            sum = eachSum(i) + eachSum(j);
            printf("(%d,%d) ", i, j);
            if (sum <= k) { ans += 1; } else {  break; }
        }
        printf("\n");
    }
    return ans;
}
*/

int movingCount(int m, int n, int k){
    if (m <= 0 || n <= 0) { return 0; }
    
    int visited[101][101] = {0};
    visited[0][0] = 1;
    
    int ans = 1;
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if ((i == 0 && j == 0) || eachSum(i) + eachSum(j) > k) { continue; }
            if (i - 1 >= 0) {
                visited[i][j] = (visited[i][j] || visited[i-1][j]) ? 1 : 0;
            }
            if (j - 1 >= 0) {
                visited[i][j] = (visited[i][j] || visited[i][j-1]) ? 1 : 0;
            }
            ans += visited[i][j];
        }
    }

    return ans;
}

int main(int argc, const char * argv[]) {
    
    
    printf("%d %d %d %d\n", 1|1, 1|0, 0|1, 0|0);
    printf("ans = %d\n", movingCount(38, 15, 9));
    
    return 0;
}





