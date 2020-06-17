
#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


bool helper(struct TreeNode* root, int sum, int res) {
    if (root == NULL) { return res == sum; }
    res += root->val;
    if (root->left == NULL && root->right == NULL) { return res == sum; }
    //注意这要判断左右为空，不然只有一支的话 5-2，sum=5, 这时会返回true，是错误的
    return (root->left != NULL &&helper(root->left, sum, res)) || (root->right != NULL && helper(root->right, sum, res));
}

bool hasPathSum(struct TreeNode* root, int sum){
    if (root == NULL) { return false; }
    return helper(root, sum, 0);
}

bool hasPathSum1(struct TreeNode* root, int sum){
    if (root == NULL) { return false; }
    sum -= root->val;
    if (root->left == NULL && root->right == NULL) { return 0 == sum; }
    return hasPathSum1(root->left, sum) || hasPathSum1(root->right, sum);
}


int main(int argc, const char * argv[]) {
    
    struct TreeNode n11 = {1, NULL, NULL};
    struct TreeNode n12 = {2, NULL, NULL};
    struct TreeNode n1 = {3, &n11, &n12};
    
    struct TreeNode n21 = {6, NULL, NULL};
    struct TreeNode n22 = {5, NULL, NULL};
    struct TreeNode n2 = {4, &n21, &n22};
    
    struct TreeNode n = {0, &n1, &n2};
    struct TreeNode n0 = {7, &n11, NULL};
    
    printf("= %d\n", hasPathSum(&n, 4));
    printf("= %d\n", hasPathSum(&n0, 7));
    
    return 0;
}



