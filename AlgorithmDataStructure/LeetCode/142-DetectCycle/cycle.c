

#include <stdio.h>
#include <stdlib.h>

//287. 寻找重复数   142. 环形链表 II

struct ListNode {
    int val;
    struct ListNode *next;
};


/**
 这题目和 287-寻找重复数 类似
 快慢指针先重合后，然后记住重合点，然后另起一点从头开始，两点一步步走，然后两点重合就是入环的节点。
 
 1 2 3 4 5 6
          9 8 7
 分析：
 设开头，到入环处有 a 步，整个环总共 a+b 步
 第一阶段，快慢指针，慢指针走到入环处时=a步，快指针=2a步 已经在环里了离入环口有 a 步 另一侧离环口还剩 b 步，
     然后快慢指针就在环里一圈一圈的走 abababab.. ，
     慢指针入环走了 b 步后 则它离环口有 a 步，
     这时快指针则走了 2b 步 则它离环口也有 a 步
     为啥？ 入环开始时 慢走b步=0 + b 离环口还有 a 步， 快走2b步= a + 2b 绕了一圈了 -(a+b) = b 所以离环口还有 a 步
     这时快慢指针相遇了
 第二阶段，相遇点离环口还有 a 步，开头离环口也有 a 步，所以两点一步步走，然后两点重合就是入环的节点。
 */


struct ListNode *detectCycle(struct ListNode *head) {
    if (head == NULL || head->next == NULL) { return NULL; }
    
    struct ListNode *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            break;
        }
    }
    
    if (fast == NULL || fast->next == NULL) { return NULL; }
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
}



int main(int argc, const char * argv[]) {
    
    struct ListNode l1 = {1, NULL};
    struct ListNode l2 = {2, &l1};
    struct ListNode l3 = {3, &l2};
    struct ListNode l4 = {4, &l3};
    struct ListNode l5 = {5, &l4};
    struct ListNode l6 = {6, &l5};
    
    l1.next = &l2;
    struct ListNode *ans = detectCycle(&l6);
    printf("ans = %d\n", ans->val);
    
    return 0;
}


