

#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode *listCreate(int val) {
    struct ListNode *list = NULL;
    list = malloc(sizeof(*list));
    if (list == NULL) {
        return NULL;
    }
    list->val = val;
    list->next = NULL;
    return list;
}

void addNodeToTail(struct ListNode *list, int val) {
    if (list == NULL) {
        return;
    }
    
    struct ListNode *node = malloc(sizeof(struct ListNode));
    if (node == NULL) {
        return;
    }
    node->val = val;
    node->next = NULL;
    
    struct ListNode *tmpNode = list;
    while (tmpNode->next != NULL) {
        tmpNode = tmpNode->next;
    }
    tmpNode->next = node;
}

//链表翻转
struct ListNode *reverseList(struct ListNode *head) {
    if (head == NULL || head -> next == NULL) { return head; }
    struct ListNode *prev = NULL;
    struct ListNode *next = NULL;
    while (head != NULL) {
        next = head -> next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

void listDump(struct ListNode *list) {
    if (list == NULL) {
        printf("empty list!\n");
    }
    struct ListNode *tmpNode = list;
    while (tmpNode !=  NULL) {
        printf("%d -> ", tmpNode->val);
        tmpNode = tmpNode->next;
    }
    printf("\n--------\n");
}


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    
    //先把两个链表翻转，然后相加
    struct ListNode *tempL1 = reverseList(l1);
    struct ListNode *tempL2 = reverseList(l2);
    
    struct ListNode *result = malloc(sizeof(struct ListNode));
    if (result == NULL) { return NULL; }
    struct ListNode *tempResult = result;
    int flag = 0, sum = 0;
    
    while (tempL1 || tempL2) {
        struct ListNode *node = malloc(sizeof(struct ListNode));
        node -> next = NULL;
        
        sum = (tempL1 ? tempL1->val : 0) + (tempL2 ? tempL2->val : 0) + flag;
        if (sum >= 10) {
            sum = sum%10;
            flag = 1;
        } else {
            flag = 0;
        }
        node -> val = sum;
        
        tempResult -> next = node;
        tempResult = tempResult -> next;
        
        tempL1 = tempL1 ? tempL1->next : NULL;
        tempL2 = tempL2 ? tempL2->next : NULL;
    }
    
    //这里要注意有进位的情况
    if (flag == 1) {
        struct ListNode *node = malloc(sizeof(struct ListNode));
        node -> next = NULL;
        node -> val = 1;
        tempResult -> next = node;
    }
    
    //加完之后，再把链表翻转回去
    result = reverseList(result->next);
    
    return result;
}



int main(int argc, const char * argv[]) {
    
    struct ListNode *l1 = listCreate(1);
    addNodeToTail(l1, 4);
//    addNodeToTail(l1, 3);
    listDump(l1);

    struct ListNode *l2 = listCreate(9);
    addNodeToTail(l2, 9);
    addNodeToTail(l2, 4);
    listDump(l2);
    
    struct ListNode *result = addTwoNumbers(l1, l2);
    listDump(result);
    
    return 0;
}




