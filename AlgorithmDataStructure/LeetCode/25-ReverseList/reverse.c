
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

struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL) { return NULL; }
    if (head->next == NULL) { return head; }
    
    struct ListNode *prev = NULL;
    struct ListNode *next = NULL;
    while ( head != NULL ) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k){
    if (head == NULL) { return NULL; }
    if (head->next == NULL || k <= 1) { return head; }
    
    struct ListNode returnHead = {-1, head};
    struct ListNode *start = &returnHead;
    struct ListNode *end = &returnHead;
    while (end != NULL) {
        for (int i = 0; i < k && end != NULL; i++) {
            end = end->next;
        }
        if (end == NULL) { break; }
        struct ListNode *tempStart = start->next;
        struct ListNode *tempEnd = end->next;
        end->next = NULL;
        //下面这里第一次翻转的时候 改变了 returnHead.next。然后后面 start 指向变了，不会修改 returnHead 了
        start->next = reverseList(tempStart); //这里头部，断开了老的链接，接上翻转后新的 head
        tempStart->next = tempEnd; //这里翻转后的尾部，接上了等待下次翻转的尾部
        end = start = tempStart;
    }
    return returnHead.next;
}


int main(int argc, const char * argv[]) {
    
    struct ListNode l1 = {8, NULL};
    struct ListNode l2 = {4, &l1};
    struct ListNode l3 = {1, &l2};

    struct ListNode l4 = {9, &l3};
    struct ListNode l5 = {6, &l4};
    struct ListNode l6 = {2, &l5};
    dump(&l6);
    
    struct ListNode *l = reverseKGroup(&l6, 3);
    dump(l);
    
    return 0;
}





