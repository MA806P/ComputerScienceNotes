
#include <stdlib.h>
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


//迭代，时间复杂度O(n), 空间复杂度 O(1)
struct ListNode* swapPairs(struct ListNode* head){
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode *prev = NULL;
    struct ListNode *one = head;
    struct ListNode *two = one->next;
    struct ListNode *list = two;
    
    
    while (two != NULL) {
        if (prev != NULL) {
            prev->next = two;
        }
        one->next = two->next;
        two->next = one;
        prev = one;
        
        one = one->next;
        if (one != NULL) {
            two = one->next;
        } else {
            break;
        }
        
    }
    return list;
}

//递归的方法，时间复杂度O(n), 空间复杂度 O(n)
//每次递归等待的返回值，就是上一次交换后的第二个节点，也就是新的头部
struct ListNode* swapPairs2(struct ListNode* head){
    if (head == NULL || head->next == NULL) {
        if (head == NULL) { printf("\n head  \n"); }
        else { printf("\n head = %d \n", head->val); }
        return head;
    }
    
    struct ListNode *one = head;
    struct ListNode *two = one->next;
    printf("-- %d  %d  ", one->val, two->val);
    one->next = swapPairs2(two->next);
    two->next = one;
    printf("** %d  %d\n", one->val, two->val);
    return two;
}

int main(int argc, const char * argv[]) {
    
    struct ListNode l1 = {1, NULL};
    struct ListNode l2 = {2, &l1};
    struct ListNode l3 = {3, &l2};
    struct ListNode l4 = {4, &l3};
    struct ListNode l5 = {5, &l4};
    struct ListNode l6 = {6, &l5};
    
    dump(&l6);
    struct ListNode *l = swapPairs(&l6);
    dump(l);
    
    return 0;
}




