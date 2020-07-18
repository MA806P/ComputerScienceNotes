
#include <stdio.h>

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


/**
 
 二叉搜索树（BST）的性质：
 节点 N 左子树上的所有节点的值都小于等于节点 N 的值
 节点 N 右子树上的所有节点的值都大于等于节点 N 的值
 左子树和右子树也都是 BST
 
 */
//递归
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    
    int rVal = root->val;
    int pVal = p->val;
    int qVal = q->val;
    
    if (pVal > rVal && qVal > rVal) {
        return lowestCommonAncestor(root->right, p, q);
    } else if (pVal < rVal && qVal < rVal) {
        return lowestCommonAncestor(root->left, p, q);
    } else {
        return root;
    }
}

//迭代
struct TreeNode* lowestCommonAncestor1(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    
    int pVal = p->val;
    int qVal = q->val;
    
    struct TreeNode* node = root;
    
    while (node != NULL) {
        int rVal = node->val;
        if (pVal > rVal && qVal > rVal) {
            node = node->right;
        } else if (pVal < rVal && qVal < rVal) {
            node = node->left;
        } else {
            return node;
        }
    }
    return NULL;
}



int main(int argc, const char * argv[]) {
    
    struct TreeNode n11 = {0, NULL, NULL};
    struct TreeNode n12 = {4, NULL, NULL};
    struct TreeNode n1 = {2, &n11, &n12};
    struct TreeNode n21 = {7, NULL, NULL};
    struct TreeNode n22 = {9, NULL, NULL};
    struct TreeNode n2 = {8, &n21, &n22};
    struct TreeNode n = {6, &n1, &n2};
    
    treeDump(&n);
    
    struct TreeNode *ans = lowestCommonAncestor(&n, &n2, &n1);
    printf("ans = %d \n", ans->val);
    
}



