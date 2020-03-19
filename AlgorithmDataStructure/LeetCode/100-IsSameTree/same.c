

#include <stdio.h>
#include <stdbool.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


bool isSameTree(struct TreeNode* p, struct TreeNode* q){
    if (p == NULL && q == NULL) { return true; }
    if (p == NULL || q == NULL) { return false; }
    if (p->val != q->val) { return false; }
    return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
}



int main(int argc, const char * argv[]) {
    
    struct TreeNode n11 = {1, NULL, NULL};
    struct TreeNode n12 = {2, NULL, NULL};
    struct TreeNode n1 = {3, &n11, &n12};
    
    struct TreeNode n21 = {1, NULL, NULL};
    struct TreeNode n22 = {2, NULL, NULL};
    struct TreeNode n2 = {3, &n21, &n22};
    
    printf("= %d\n", isSameTree(&n1, &n2));
    
    return 0;
}




