
#include <stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
};

void dump(struct ListNode *head) {
    if (head == NULL) { printf("list null! \n"); }
    struct ListNode *node = head;
    while (node != NULL) {
        printf("%d -> ", node->val);
        node = node -> next;
    }
    printf("\n");
}



/**
 这题有点意思，删除当前节点，没有给出头结点
 直接修改当前节点的值，值为下一个节点，然后跳过下一个节点
 */
void deleteNode(struct ListNode* node) {
    
    *node = *(node->next);
    
    /**
     node->val = node->next->val;
     node->next = node->next->next;
     */
    
}

int main(int argc, const char * argv[]) {
    
    struct ListNode l1 = {1, NULL};
    struct ListNode l2 = {2, &l1};
    struct ListNode l3 = {3, &l2};
    struct ListNode l4 = {4, &l3};
    dump(&l4);
    deleteNode(&l3);
    dump(&l4);
    
}



