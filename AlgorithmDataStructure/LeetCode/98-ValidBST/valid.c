
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool helper(struct TreeNode* root, long lower, long upper){
    if (root == NULL) { return true; }
    if (root->val <= lower || root->val >= upper) { return false; }
    return helper(root->left, lower, root->val) && helper(root->right, root->val, upper);
}


bool isValidBST(struct TreeNode* root){
    return helper(root, LONG_MIN, LONG_MAX);
}


int main(int argc, const char * argv[]) {
    
    struct TreeNode n11 = {1, NULL, NULL};
    struct TreeNode n12 = {3, NULL, NULL};
    struct TreeNode n1 = {2, &n11, &n12};
    
    struct TreeNode n21 = {7, NULL, NULL};
    struct TreeNode n22 = {9, NULL, NULL};
    struct TreeNode n2 = {8, &n21, &n22};

    struct TreeNode n = {7, &n1, &n2};

    printf("= %d\n", isValidBST( &n));
    
    /**
     [] = true
     [1] = true
     [2,1] = true
     [1,2] = false
     
     [4,1,6,null,null,2,7] = false  右侧 > ，2<4
     [4,1,6,null,null,5,7] = true
     
     二叉搜索树，左子树所有值都要小于根节点，右子树的所有值都要大于根节点
     
     */
    
    return 0;
}

















