
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

#define NUM 100

void dfs(struct TreeNode* root, char ** path, char *temp, int cnt, int *size){
    if (root == NULL) { return; }
    
    temp[cnt] = root->val;
    if (root->left == NULL && root->right == NULL) {
        char *str = (char *)malloc(sizeof(char) * NUM * 2);
        int len = 0;
        for (int i = 0; i < cnt; i++) {
            len += sprintf(&str[len], "%d->", temp[i]);
        }
        sprintf(str + len, "%d", temp[cnt]);
        path[*size] = str;
        //printf("%d = %s\n", cnt,str);
        *size += 1; //分支路径数量统计
        //temp 用来保存分支路径上的节点，这一分支遍历结束了，值会被另一分支覆盖
        //cnt 是分支上的节点数
        return;
    }
    dfs(root->left, path, temp, cnt + 1, size);
    
    //for (int i = 0; i < 10; i++) { printf("%d ", temp[i]); }
    //printf("cnt = %d \n", cnt);
    dfs(root->right, path, temp, cnt + 1, size);
}

char ** binaryTreePaths(struct TreeNode* root, int* returnSize){
    
    char **path = (char **)malloc(sizeof(char *) * NUM);
    char temp[NUM] = {0}; //缓存分支路径上的节点
    int cnt = 0, size = 0;
    dfs(root, path, temp, cnt, &size);
    *returnSize = size;
    return path;
}



//二叉搜索树 BST）： 左 < n < 右
struct TreeNode** buildTree(int start, int end, int* returnSize){
    if (start > end) {
        (*returnSize) = 1;
        struct TreeNode ** ans = malloc(sizeof(struct TreeNode *));
        ans[0] = NULL;
        return ans;
    }
    
    (*returnSize) = 0;
    struct TreeNode ** ans = malloc(0);
    
    for (int i= start; i <= end; i++) {
        //左子树集合
        int leftTreesSize = 0;
        struct TreeNode **leftTrees = buildTree(start, i-1, &leftTreesSize);
        //右子树集合
        int rightTreesSize = 0;
        struct TreeNode **rightTrees = buildTree(i+1, end, &rightTreesSize);
        
        //左右子树选出一棵，拼接到根节点上
        for (int left = 0; left < leftTreesSize; left++) {
            for (int right = 0; right < rightTreesSize; right++) {
                struct TreeNode *currentTree = malloc(sizeof(struct TreeNode));
                currentTree->val = i;
                currentTree->left = leftTrees[left];
                currentTree->right = rightTrees[right];
                
                (*returnSize) += 1;
                ans = realloc(ans, sizeof(struct TreeNode *) * (*returnSize));
                ans[(*returnSize) - 1] = currentTree;
            }
        }
        free(rightTrees);
        free(leftTrees);
    }
    
    return ans;
}

struct TreeNode** generateTrees(int n, int* returnSize){
    if (n <= 0) {
        (*returnSize) = 0;
        return NULL;
    }
    return buildTree(1, n, returnSize);
}



int main(int argc, const char * argv[]) {
    
    int trees = 0;
    struct TreeNode **ans = generateTrees(3, &trees);
    
    for (int i = 0; i < trees; i++) {
        int size = 0;
        char **path = binaryTreePaths(ans[i], &size);
        for (int j = 0; j < size; j++) {
            printf("%s\n", path[j]);
        }
        printf("---- i=%d -----\n", i);
    }
    
    return 0;
}



