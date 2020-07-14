
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



//方法一、深度优先搜索、递归、回溯。画个树一目了然。
//超时了，有大量的重复计算。树上有交点的，都会重复计算一次
//可以改进，用数组保存计算出来的 dfs[i][j] 的值，下次直接拿来用
int m_min(int a, int b) { return  a < b ? a : b;}
int dfs(int** triangle, int triangleSize, int i, int j) {
    if (i == triangleSize) { return 0; }
    printf("i=%d j=%d == %d\n", i,j, triangle[i][j]);
    return m_min(dfs(triangle, triangleSize, i+1, j), dfs(triangle, triangleSize, i+1, j+1)) + triangle[i][j];
}
int minimumTotal0(int** triangle, int triangleSize, int* triangleColSize){
    if (triangle == NULL || triangleSize <= 0 || triangleColSize == NULL) { return 0; }
    return dfs(triangle, triangleSize, 0, 0);
}


//方法二、动态规划
int minimumTotal1(int** triangle, int triangleSize, int* triangleColSize){
    if (triangle == NULL || triangleSize <= 0 || triangleColSize == NULL) { return 0; }
    
    int **ans = (int **)malloc(sizeof(int *) * (triangleSize+1));
    for (int i = 0; i <= triangleSize; i++) {
        int *temp = (int *)malloc(sizeof(int) * (triangleSize+1));
        memset(temp, 0, sizeof(int)* (triangleSize+1));
        ans[i] = temp;
    }
    
    
    for (int i = triangleSize - 1; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            ans[i][j] = m_min(ans[i+1][j], ans[i+1][j+1]) + triangle[i][j];
        }
    }
    
    
    int result = ans[0][0];
    for (int i = 0; i < triangleSize; i++) {
        int *temp = ans[i]; free(temp);
    }
    free(ans);
    return result;
}
//上面的空间优化，一维数组就可以了
int minimumTotal2(int** triangle, int triangleSize, int* triangleColSize){
    if (triangle == NULL || triangleSize <= 0 || triangleColSize == NULL) { return 0; }
    
    int *ans = (int *)malloc(sizeof(int) * (triangleSize+1));
    memset(ans, 0, sizeof(int)* (triangleSize+1));
    
    for (int i = triangleSize - 1; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            ans[j] = m_min(ans[j], ans[j+1]) + triangle[i][j];
        }
    }
    int result = ans[0];
    free(ans);
    return result;
}


//方法三、原地修改数组
int minimumTotal(int** triangle, int triangleSize, int* triangleColSize){
    if (triangle == NULL || triangleSize <= 0 || triangleColSize == NULL) { return 0; }
    for (int i = triangleSize - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            triangle[i][j] = m_min(triangle[i+1][j], triangle[i+1][j+1]) + triangle[i][j];
        }
    }
    return triangle[0][0];
}



int main(int argc, const char * argv[]) {
    
    int a[3][3] = {{-1},{2,3},{1,-1,-3}};
    int b[3] = {1,2,3};
    int **triangle = (int **)malloc(sizeof(int **) * 3);
    for (int i = 0; i < 3; i++) {
        int size = b[i];
        int *temp = (int *)malloc(sizeof(int) * size);
        for (int j = 0; j < size; j++) {
            temp[j] = a[i][j];
            printf("   %d   ", a[i][j]);
        }
        triangle[i] = temp;
        printf("\n");
    }
    
    
    int ans = minimumTotal(triangle, 3, b);
    printf("ans = %d \n", ans);
    
    return 0;
}



