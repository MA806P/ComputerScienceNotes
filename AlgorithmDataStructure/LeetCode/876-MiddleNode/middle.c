
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

//方法一，遍历两遍，第一遍计算链表有多长，第二遍走到中间返回
struct ListNode* middleNode0(struct ListNode* head) {
    if (head == NULL || head->next == NULL) { return head; }
    
    int count = 1;
    struct ListNode *temp = head;
    while (temp->next != NULL) {
        count++;
        temp = temp->next;
    }
    
    int middle = count/2;
    temp = head;
    for (int i = 0; i < middle; i++) {
        temp = temp->next;
    }
    return temp;
}

//方法二，快慢指针，快指针一次走两步，慢指针一次走一步，快指针走到最后，慢指针就在中间了
struct ListNode* middleNode(struct ListNode* head) {
    if (head == NULL || head->next == NULL) { return head; }
    
    struct ListNode *fast = head, *slow = head;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    return slow;
}



int main(int argc, const char * argv[]) {
    
    
    struct ListNode l1 = {6, NULL};
    struct ListNode l2 = {5, &l1};
    struct ListNode l3 = {4, &l2};
    struct ListNode l4 = {3, &l3};
    struct ListNode l5 = {2, &l4};
    struct ListNode l6 = {1, &l5};
    
    struct ListNode *middle = middleNode(&l6);
    printf("middle = %d\n", middle->val);
    
    return 0;
}






