
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int depth(struct TreeNode *node, int *res) {
    if (node == NULL) { return 0; }
    int left = depth(node->left, res);
    int right = depth(node->right, res);
    int sum = left + right;
    *res = *res < sum ? sum : *res;
    return left < right ? right + 1 : left + 1;
}

int diameterOfBinaryTree(struct TreeNode* root){
    if (root == NULL) { return 0; }
    int res = 0;
    depth(root, &res);
    return res;
}


int main(int argc, const char * argv[]) {
    
    struct TreeNode r1 = {9, NULL, NULL};
    struct TreeNode l1 = {7, NULL, NULL};
    struct TreeNode left = {6, &l1, NULL};
    struct TreeNode right = {5, NULL, &r1};
    
    struct TreeNode t1 = {1, &left, &right};
    
    
    int a = diameterOfBinaryTree(&t1);
    printf("=== %d\n", a);
    return 0;
}





