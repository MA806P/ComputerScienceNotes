
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
};
bool hasCycle0(struct ListNode *head) {
    if (head == NULL || head->next == NULL) { return false; }
    struct ListNode *n1 = head, *n2 = head->next;
    while (n1 != NULL && n2 != NULL) {
        n1 = n1->next;
        n2 = n2->next == NULL ? n2->next : n2->next->next;
    }
    return n1 == n2;
}

bool hasCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) { return false; }
    struct ListNode *n1 = head, *n2 = head->next;
    while (n1 != n2) {
        if (n2 == NULL || n2->next == NULL) { return false; }
        n1 = n1->next;
        n2 = n2->next->next;
    }
    return true;
}



int main(int argc, const char * argv[]) {
    struct ListNode l1 = {1, NULL};
    struct ListNode l2 = {2, &l1};
    struct ListNode l3 = {3, &l2};
    struct ListNode l4 = {4, &l3};
    printf("ans = %d\n", hasCycle(&l4));
    return 0;
}



