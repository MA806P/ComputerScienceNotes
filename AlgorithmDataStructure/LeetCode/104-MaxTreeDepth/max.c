
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

/*
 int maxDepth(struct TreeNode* root) {
     if (root == NULL) { return 0; }
     if (root->left == NULL && root->right == NULL) { return 1; }
     int l = 1, r = 1;
     if (root->left != NULL) { r += maxDepth(root->left); }
     if (root->right != NULL) { l += maxDepth(root->right); }
     return l > r ? l : r;
 } */

//递归
int maxDepth(struct TreeNode* root) {
    if (root == NULL) { return 0; }
    
    int l = maxDepth(root->left);
    int r = maxDepth(root->right);
    return l > r ? (l + 1) : (r + 1);
}

//迭代


int main(int argc, const char * argv[]) {
    
    struct TreeNode n11 = {4, NULL, NULL};
    struct TreeNode n12 = {3, NULL, NULL};
    struct TreeNode n1 = {2, &n11, &n12};
    
    struct TreeNode n21 = {3, NULL, NULL};
    struct TreeNode n22 = {4, NULL, NULL};
    struct TreeNode n2 = {2, &n21, &n22};
    
    struct TreeNode n = {1, &n1, &n2};
    
    printf("= %d\n", maxDepth(&n));
    
    return 0;
}






