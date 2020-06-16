
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


//先计算节点的高度，然后比较每个节点左右子树的高度。向上递归。
int m_max(int a, int b) { return  a > b ? a : b;}
int height(struct TreeNode *root) {
    if (root == NULL) { return -1; }
    return 1 + m_max(height(root->left), height(root->right));
}


bool isBalanced(struct TreeNode* root){
    if (root == NULL) { return true; }
    return abs(height(root->right) - height(root->left)) < 2 && isBalanced(root->left) && isBalanced(root->right);
}


int main(int argc, const char * argv[]) {
    
    struct TreeNode n11 = {1, NULL, NULL};
    struct TreeNode n12 = {2, NULL, NULL};
    struct TreeNode n1 = {3, &n11, &n12};
    
    struct TreeNode n21 = {1, NULL, NULL};
    struct TreeNode n22 = {2, NULL, NULL};
    struct TreeNode n2 = {3, &n21, &n22};
    
    struct TreeNode n = {0, &n1, &n2};
    
    printf("= %d\n", isBalanced(&n));
    
    return 0;
}



