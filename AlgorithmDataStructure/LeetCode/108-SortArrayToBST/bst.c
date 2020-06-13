

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};


struct TreeNode* helper(int* nums, int left, int right) {
    if (left > right) { return NULL; }
    
    int p = (left + right)/2; //中序遍历：始终选择中间位置左边元素作为根节点
    //也可选择右边 if ((left + right) % 2 == 1) ++p;
    //或者任意中间位置 if ((left + right) % 2 == 1) p += rand.nextInt(2);
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = nums[p];
    root->left = helper(nums, left, p - 1);
    root->right = helper(nums, p + 1, right);
    return root;
}


struct TreeNode* sortedArrayToBST(int* nums, int numsSize){
    if (nums == NULL || numsSize <= 0) { return NULL; }
    return helper(nums, 0, numsSize - 1);
}



int main(int argc, const char * argv[]) {
    
    int nums[] = {-10,-3,0,5,9};
    //struct TreeNode *tree =
    sortedArrayToBST(nums, 5);
    
    return 0;
}

