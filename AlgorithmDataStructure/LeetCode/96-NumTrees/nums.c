
#include <stdio.h>
#include <string.h>


/**
 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
 1、G(n): 长度为 nn 的序列能构成的不同二叉搜索树的个数。
 2、F(i, n): 以 ii 为根、序列长度为 nn 的不同二叉搜索树个数 (1<= i <= n)。

 n=7,  i=3  [1,2] [4,5,6,7],  F(3,7)=G(2)*G(4)
F(i,n) = G(i-1)*G(n-i)
 G(n)= ∑ G(i−1)⋅G(n−i) (i=1...n)
 */
int numTrees0(int n){
    if (n < 2) { return 1; }
    
    int G[n+1];
    memset(G, 0, sizeof(G));
    G[0] = 1; G[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            G[i] += G[j-1] * G[i - j];
        }
    }
    return G[n];
}

//数学方法
/**
 C0 =1,
 C(n+1) = [2(2n+1)/(n+2)] * C(n)
 */
int numTrees(int n){
    if (n < 2) { return 1; }
    
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans = ans * 2 * (2*i+1)/(i+2);
    }
    return ans;
}


int main(int argc, const char * argv[]) {
    printf("ans = %d \n", numTrees(7));
    return 0;
}



