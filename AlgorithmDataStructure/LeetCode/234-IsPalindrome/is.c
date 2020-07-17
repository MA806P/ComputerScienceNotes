
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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



//方法一、中间节点翻转
bool isPalindrome0(struct ListNode* head){
    if (head == NULL || head->next == NULL) { return true; }
    
    
    //快慢指针找到中点
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while (fast != NULL && fast->next !=  NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    //从中点开始翻转
    struct ListNode *prev = NULL;
    struct ListNode *next = NULL;
    while (slow != NULL) {
        next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }
    
    dump(head);
    dump(prev);
    
    //从开始点，与从中点翻转后比较，是否相等
    while (head != NULL && prev != NULL) {
        if (head->val != prev->val) {
            return false;
        }
        head = head->next;
        prev = prev->next;
    }
    
    return true;
}

//方法二、递归
static struct ListNode *frontNode = NULL;
bool check(struct ListNode *currentNode) {
    if (currentNode != NULL) {
        if (check(currentNode->next) == false) { return false; }
        printf("aaa %d == %d\n", currentNode->val, frontNode->val);
        if (currentNode->val != frontNode->val) { return false; }
        frontNode = frontNode->next;
    }
    return true;
}

bool isPalindrome(struct ListNode* head){
    if (head == NULL || head->next == NULL) { return true; }
    frontNode = head;
    return check(head);
}


int main(int argc, const char * argv[]) {
    
    struct ListNode l1 = {1, NULL};
    struct ListNode l2 = {2, &l1};
    struct ListNode l22 = {3, &l2};
    struct ListNode l3 = {2, &l22};
    struct ListNode l4 = {1, &l3};
    dump(&l4);
    
    printf("ans = %d\n", isPalindrome(&l4));
}



