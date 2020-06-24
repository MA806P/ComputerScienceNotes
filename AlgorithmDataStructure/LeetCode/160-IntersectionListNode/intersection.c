

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

/**
 a + b = b + a
  a = 1-2-3-4-5
               |
  b =         6
 指针 A 沿着链表 a 走，走到尾再沿着链表 b 走
 指针 B 沿着链表 b 走，走到尾再沿着链表 a 走
 如有相交，A B肯定会相遇，走到 3 相遇了返回。如没有相交都走到尾返回 NULL
 A = 1 2 3 4 5 6 3
 B = 6 3 4 5 1 2 3
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) { return NULL; }
    struct ListNode *pA = headA, *pB = headB;
    while (pA != pB) {
        pA = pA == NULL ? headB : pA->next;
        pB = pB == NULL ? headA : pB->next;
    }
    return pA;
}

//暴力解法
struct ListNode *getIntersectionNode0(struct ListNode *headA, struct ListNode *headB) {
    if (headA == NULL || headB == NULL) { return NULL; }
    struct ListNode *pA = headA, *pB = headB;
    while (pA != NULL) {
        while (pB != NULL) {
            if (pA == pB) {
                return pA;
            } else {
                pB = pB->next;
            }
        }
        pA = pA->next;
        pB = headB;
    }
    return NULL;
}

int main(int argc, const char * argv[]) {
    struct ListNode l1 = {1, NULL};
    struct ListNode l2 = {2, &l1};
    struct ListNode l3 = {3, &l2};
    struct ListNode l4 = {4, &l3};
    dump(&l4);
    
    struct ListNode l5 = {5, &l3};
    struct ListNode l6 = {6, &l5};
    dump(&l6);
    
    struct ListNode *ans = getIntersectionNode(&l4, &l6);
    dump(ans);
    
    return 0;
}



