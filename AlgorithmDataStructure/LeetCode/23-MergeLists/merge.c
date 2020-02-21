
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

struct ListNode *mergeTwoList(struct ListNode *l1, struct ListNode *l2) {
    if (l1 == NULL) { return l2; }
    if (l2 == NULL) { return l1; }
    
    struct ListNode *head = (struct ListNode *)malloc(sizeof(struct ListNode));
    head->val = 0;
    head->next = NULL;
    struct ListNode *returnList = head;
    
    struct ListNode *node1 = l1, *node2 = l2;
    
    while (1) {
        if (node1 == NULL) {
            head->next = node2;
            break;
        } else if (node2 == NULL) {
            head->next = node1;
            break;
        }
        
        if (node1->val < node2->val) {
            head->next = node1;
            node1 = node1->next;
        } else {
            head->next = node2;
            node2 = node2->next;
        }
        head = head->next;
    }
    return returnList->next;
}
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if (lists == NULL || listsSize <= 0) { return NULL; }
    if (listsSize == 1) { return lists[0]; }
    
    while (listsSize > 1) {
        for (int i = 0; i < listsSize/2; i++) {
            lists[i] = mergeTwoList(lists[i], lists[listsSize - 1 - i]);
        }
        listsSize = (listsSize + 1)/2;
    }
    return lists[0];
}

int main(int argc, const char * argv[]) {
    
    
    struct ListNode l1 = {8, NULL};
    struct ListNode l2 = {4, &l1};
    struct ListNode l3 = {1, &l2};

    struct ListNode l4 = {9, NULL};
    struct ListNode l5 = {6, &l4};
    struct ListNode l6 = {2, &l5};
    
    struct ListNode **lists = (struct ListNode **)malloc(sizeof(struct ListNode *) * 2);
    lists[0] = &l3;
    lists[1] = &l6;
    struct ListNode *l = mergeKLists(lists, 2);
    dump(l);
    
    return 0;
}






