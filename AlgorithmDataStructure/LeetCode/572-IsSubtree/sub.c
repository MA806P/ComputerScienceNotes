

#include <stdio.h>
#include <stdbool.h>


struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

bool check(struct TreeNode* s, struct TreeNode* t) {
    if (s == NULL && t == NULL) { return true; }
    if ((s != NULL && t == NULL) || (s == NULL && t != NULL) || (s->val != t->val)) { return false; }
    return check(s->left, t->left) && check(s->right, t->right);
}

bool dfs(struct TreeNode* s, struct TreeNode* t) {
    if (s == NULL) { return false; }
    return check(s, t) || dfs(s->left, t) || dfs(s->right, t);
}

bool isSubtree(struct TreeNode* s, struct TreeNode* t){
    return dfs(s, t);
}


int main(int argc, const char * argv[]) {
    
    struct TreeNode n11 = {1, NULL, NULL};
    struct TreeNode n12 = {2, NULL, NULL};
    struct TreeNode n1 = {3, &n11, &n12};
    
    struct TreeNode n21 = {1, NULL, NULL};
    struct TreeNode n22 = {2, NULL, NULL};
    struct TreeNode n2 = {3, &n21, &n22};
    
    printf("= %d\n", isSubtree(&n1, &n2));
    
    return 0;
}


