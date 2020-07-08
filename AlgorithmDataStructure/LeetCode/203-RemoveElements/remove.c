
#include <stdio.h>
#include <stdlib.h>

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


struct ListNode* removeElements(struct ListNode* head, int val){
    if (head == NULL) { return head; }
    
    /**
    struct ListNode *node = head, *prev = NULL;
    while (node != NULL) {
        if (node->val == val) {
            if (prev != NULL) {
                prev->next = node->next;
                node->next = NULL;
                node = prev->next;
            } else {
                head = head->next;
                node->next = NULL;
                node = head;
            }
        } else {
            prev = node;
            node = node->next;
        }
    }
     return head;
    */
    
    //优化添加哨兵节点
    struct ListNode *sentinel = (struct ListNode *)malloc(sizeof(struct ListNode));
    sentinel->next = head;
    struct ListNode *node = head, *prev = sentinel;
    
    while (node != NULL) {
        if (node->val == val) {
            prev->next = node->next;
        } else {
            prev = node;
        }
        node = node->next;
    }
    return sentinel->next;
}


int main(int argc, const char * argv[]) {
    
    struct ListNode l1 = {3, NULL};
    struct ListNode l2 = {4, &l1};
    struct ListNode l3 = {4, &l2};
    struct ListNode l4 = {5, &l3};
    dump(&l4);
    
    struct ListNode *ans = removeElements(&l4, 4);
    dump(ans);
    
    return 0;
}



