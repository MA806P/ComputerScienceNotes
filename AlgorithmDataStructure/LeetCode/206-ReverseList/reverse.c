
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
/**
 1->2->3->4
 head=1  next=2  head->next=NULL  ==>  1->NULL prev=head=1->NUll   head=next=2->3->4
 next=head->next=3->4   head->next=prev ==> 2->1->NULL  prev=head=2->1->NUll
 
 head=1->2->3->4
 prev=NULL
 
 head=2->3->4
 prev=1
 
 head=3->4
 prev=2->1
 
 */
struct ListNode* reverseList0(struct ListNode* head){
    if (head == NULL || head->next == NULL) { return head; }
    
    struct ListNode *prev = NULL;
    struct ListNode *next = NULL;
    //两个链表，旧的(head)接到新的(prev)上面
    while (head != NULL) {
        next = head->next;
        head->next = prev;
        prev = head; //这里切断，prev 指向一个新的链表，也就是翻转后的
        head = next;
    }
    return prev;
}

//递归
//从第二个节点开始，一直到倒数第二个 return head
//改变第二个的 next，反过来指向第一个，第一个节点的 next 置空
struct ListNode* reverseList(struct ListNode* head){
    if (head == NULL || head->next == NULL) { return head; }
    
    //1->2->3->4  这时 head=2
    struct ListNode *prev = reverseList(head->next);
    //reverseList(2->next)= reverseList(3) = return 4->3->NULL
    //这时  2和4的next都 -> 3
    head->next->next = head; //然后 2->3-> = 2
    head->next = NULL; // 2-> = null 然后 return prev = 4->3->2->null
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












