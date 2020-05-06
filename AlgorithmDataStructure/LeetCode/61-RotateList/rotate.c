
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

//迭代的方法，一个一个顺序的改变指向
struct ListNode* reverseList0(struct ListNode* head){
    if (head == NULL || head->next == NULL) { return head; }
    
    struct ListNode *prev = NULL;
    struct ListNode *next = NULL;
    while (head != NULL) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}



struct ListNode* rotateRight(struct ListNode* head, int k){
    if (head == NULL || head->next == NULL || k <= 0) { return head; }
    
    //计算链表长度
    int length = 1;
    struct ListNode *prev = head;
    while (prev->next != NULL) {
        prev = prev->next; length++;
    }
    
    
    //这个是循环的一个个的移动，k 可能超出链表的长度，超出的继续移动
    int count = k%length;
    if (count == 0) { return head; }
    
    //定位到移动点
    struct ListNode *fast = head;
    while (count > 0 && fast != NULL) {
        fast = fast->next; count--;
    }
    if (fast == NULL) { return head; }
    
    struct ListNode *slow = head;
    while (fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    
    //修改指向
    struct ListNode *ans = slow->next;
    fast->next = head;
    slow->next = NULL;
    return ans;
}


int main(int argc, const char * argv[]) {
    
    struct ListNode l1 = {1, NULL};
    struct ListNode l2 = {2, &l1};
    struct ListNode l3 = {3, &l2};
    struct ListNode l4 = {4, &l3};
    dump(&l4);
    
    struct ListNode *l = rotateRight(&l4, 9);
    dump(l);
    
    return 0;
}

















