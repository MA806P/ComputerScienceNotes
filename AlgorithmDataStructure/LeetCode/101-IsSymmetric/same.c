
#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


bool isSameLeftRight(struct TreeNode* left, struct TreeNode* right){
    if (left == NULL && right == NULL) { return true; }
    if (left == NULL || right == NULL) { return false; }
    if (left->val != right->val) { return false; }
    return isSameLeftRight(left->left, right->right) && isSameLeftRight(left->right, right->left);
}

bool isSymmetric(struct TreeNode* root){
    if (root == NULL) { return true; }
    return isSameLeftRight(root->left, root->right);
}


int main(int argc, const char * argv[]) {
    
    struct TreeNode n11 = {4, NULL, NULL};
    struct TreeNode n12 = {3, NULL, NULL};
    struct TreeNode n1 = {2, &n11, &n12};
    
    struct TreeNode n21 = {3, NULL, NULL};
    struct TreeNode n22 = {4, NULL, NULL};
    struct TreeNode n2 = {2, &n21, &n22};
    
    struct TreeNode n = {1, &n1, &n2};
    
    printf("= %d\n", isSymmetric(&n));
    
    return 0;
}









