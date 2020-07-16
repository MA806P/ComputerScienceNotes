
#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

void treeDump(struct TreeNode *root) {
    if (root->left != NULL) {
        treeDump(root->left);
    }
    if (root->right != NULL) {
        treeDump(root->right);
    }
    printf(" %d ", root->val);
}


struct TreeNode* invertTree(struct TreeNode* root){
    if (root == NULL) { return NULL; }
    
    struct TreeNode *left = invertTree(root->left);
    struct TreeNode *right = invertTree(root->right);
    root->left = right;
    root->right = left;
    return root;
}



int main(int argc, const char * argv[]) {
    
    struct TreeNode n11 = {1, NULL, NULL};
    struct TreeNode n12 = {2, NULL, NULL};
    struct TreeNode n1 = {3, &n11, &n12};
    struct TreeNode n21 = {4, NULL, NULL};
    struct TreeNode n22 = {5, NULL, NULL};
    struct TreeNode n2 = {6, &n21, &n22};
    struct TreeNode n = {7, &n1, &n2};
    
    treeDump(&n);
    printf("\n");
    
    struct TreeNode *root = invertTree(&n);
    treeDump(root);
    printf("\n");
    
    return 0;
}



