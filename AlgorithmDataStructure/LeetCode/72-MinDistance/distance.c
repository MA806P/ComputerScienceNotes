

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int minDistance(char * word1, char * word2){
    int n = (int)strlen(word1);
    int m = (int)strlen(word2);
    if (m == 0 || n == 0) { return n + m; }
    
    
    //dp[i][j] 表示 word1 到 i 位置，转换为 word2 到 j 位置，最少多少步
    int **dp = (int **)malloc(sizeof(int *)*(n + 1));
    for (int i = 0; i < n + 1; i++) {
        int *a = (int *)malloc(sizeof(int) * (m + 1));
        memset(a, 0, sizeof(int) * (m + 1));
        dp[i] = a;
    }
    
    //边界状态初始化。从空字符，到0 1 2 .. 个字符，步数能先确定好
    //画个表格二维，从空到一个字符，多少步，方便理解
    for (int i = 0; i < n+1; i++) { dp[i][0] = i; }
    for (int i = 0; i < m+1; i++) { dp[0][i] = i; }
    
    //计算 dp
    //当 word1[i] == word2[j]，dp[i][j] = dp[i-1][j-1]；
    //当 word1[i] != word2[j]，dp[i][j] = min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]) + 1
    for (int i = 1; i < n+ 1; i++) {
        for (int j = 1; j < m + 1; j++) {
            int left = dp[i - 1][j] + 1;
            int down = dp[i][j - 1] + 1;
            int left_down = dp[i - 1][j - 1];
            
            if (word1[i - 1] != word2[j - 1]) { left_down += 1; }
            
            int minDown = down < left_down ? down : left_down;
            dp[i][j] = left < minDown ? left : minDown;
        }
    }
    return dp[n][m];
}
int main(int argc, const char * argv[]) {
    
    char *a = "intention";
    char *b = "execution";
    printf("ans = %d \n", minDistance(a, b));
    
    return 0;
}




