
#include <stdio.h>

#define INT_MAX 2147483647

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


int m_min(int a, int b) { return  a < b ? a : b;}

//递归，从底到上 min(ans)+1
int minDepth(struct TreeNode* root) {
    if (root == NULL) { return 0; }
    if (root->left == NULL && root->right == NULL) { return 1; }
    
    int ans = INT_MAX;
    if (root->left != NULL) {
        ans = m_min(minDepth(root->left), ans);
    }
    if (root->right != NULL) {
        ans = m_min(minDepth(root->right), ans);
    }
    return ans + 1;
}

int main(int argc, const char * argv[]) {
    
    struct TreeNode n11 = {1, NULL, NULL};
    struct TreeNode n12 = {2, NULL, NULL};
    struct TreeNode n1 = {3, &n11, &n12};
    
    struct TreeNode n21 = {1, NULL, NULL};
    struct TreeNode n22 = {2, NULL, NULL};
    struct TreeNode n2 = {3, &n21, &n22};
    
    struct TreeNode n = {0, &n1, &n2};
    
    printf("= %d\n", minDepth(&n));
    
    return 0;
}



