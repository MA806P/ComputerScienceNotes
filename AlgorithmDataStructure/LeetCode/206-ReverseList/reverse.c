
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

//递归
//从第二个节点开始，一直到倒数第二个 return head
//改变第二个的 next，反过来指向第一个，第一个节点的 next 置空
struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL || head->next == NULL) { return head; }
    
    struct ListNode *prev = reverseList(head->next);
    head->next->next = head;
    head->next = NULL;
    return prev; //返回的是上一个节点，这一个的 next->next 已经反转了
}


int main(int argc, const char * argv[]) {
    
    struct ListNode l1 = {1, NULL};
    struct ListNode l2 = {2, &l1};
    struct ListNode l3 = {3, &l2};
    struct ListNode l4 = {4, &l3};
    dump(&l4);
    
    struct ListNode *l = reverseList(&l4);
    dump(l);
    
    return 0;
}












