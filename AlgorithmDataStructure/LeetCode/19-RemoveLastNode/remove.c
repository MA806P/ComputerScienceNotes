
#include <stdlib.h>
#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

void dump(struct ListNode * list) {
    if (NULL == list) { return; }
    struct ListNode *head = list;
    int idx = 0;
    while (head) {
        printf("[%02d]: %02d \n", idx, head->val);
        idx++;
        head = head->next;
    }
}


struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    if (head == NULL) { return NULL; }
    if (n <= 0) { return head; }
    
    struct ListNode *fast = head;
    int k = n;
    while (k > 1 && fast != NULL) {
        fast = fast->next;
        k--;
    }
    
    if (fast == NULL) { return head; }
    //printf("\n fast = %d \n", fast->val);
    
    struct ListNode *prev = NULL;
    struct ListNode *next = head;
    while (fast->next != NULL) {
        fast = fast->next;
        prev = next;
        next = next -> next;
    }
    
    if (prev == NULL) {
        head = head->next;
    } else {
        prev -> next = prev -> next -> next;
    }
    return head;
}



int main(int argc, const char * argv[]) {
    
    struct ListNode l1 = {1, NULL};
    struct ListNode l2 = {2, &l1};
    struct ListNode l3 = {3, &l2};
    struct ListNode l4 = {4, &l3};
    dump(&l4);
    
    
    removeNthFromEnd(&l4, 0);
    printf("\n");
    dump(&l4);
    
    return 0;
}




