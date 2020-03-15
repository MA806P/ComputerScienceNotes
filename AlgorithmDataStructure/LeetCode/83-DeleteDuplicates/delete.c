
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

struct ListNode* deleteDuplicates(struct ListNode* head){
    if (head == NULL) { return head; }
    
    struct ListNode *temp = head;
    while (temp != NULL && temp -> next != NULL) {
        if (temp->val == temp ->next->val) {
            struct ListNode *node = temp->next;
            temp->next = node->next;
            node->next = NULL;
            //free(node);
        } else {
            temp = temp->next;
        }
    }
    
    return head;
}

int main(int argc, const char * argv[]) {
    
    struct ListNode l1 = {3, NULL};
    struct ListNode l2 = {3, &l1};
    struct ListNode l3 = {2, &l2};
    struct ListNode l4 = {2, &l3};
    struct ListNode l5 = {2, &l4};
    struct ListNode l6 = {1, &l5};
    dump(&l6);
    
    struct ListNode *l = deleteDuplicates(&l6);
    dump(l);
    
    return 0;
}





