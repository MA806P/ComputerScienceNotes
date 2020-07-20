
#include <stdio.h>
#include <stdlib.h>
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
        printf("%d = %s\n", cnt,str);
        *size += 1; //分支路径数量统计
        //temp 用来保存分支路径上的节点，这一分支遍历结束了，值会被另一分支覆盖
        //cnt 是分支上的节点数
        return;
    }
    dfs(root->left, path, temp, cnt + 1, size);
    
    for (int i = 0; i < 10; i++) {
        printf("%d ", temp[i]);
    }
    printf("cnt = %d \n", cnt); 
    
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

int main(int argc, const char * argv[]) {
    
    struct TreeNode n11 = {1, NULL, NULL};
    struct TreeNode n12 = {2, NULL, NULL};
    struct TreeNode n1 = {3, &n11, &n12};
    struct TreeNode n21 = {4, NULL, NULL};
    struct TreeNode n22 = {5, NULL, NULL};
    struct TreeNode n2 = {6, &n21, &n22};
    struct TreeNode n = {7, &n1, &n2};

    int size = 0;
    char **path = binaryTreePaths(&n, &size);

    for (int i = 0; i < size; i++) {
        printf("%s\n", path[i]);
    }
    
    
    
    return 0;
}



