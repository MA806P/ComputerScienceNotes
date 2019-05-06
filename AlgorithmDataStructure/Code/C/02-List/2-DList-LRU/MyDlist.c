#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct listNode {
    int value;
    struct listNode *next;
}ListNode;

typedef struct linkedList {
    ListNode *head;
}LinkedList;

void dump(LinkedList *list) {
    if (list == NULL) {
        printf("list is NULL! \n");
        return;
    }
    ListNode *head = list->head;
    if (head == NULL) {
        printf("list is empty! \n");
    }
    int index = 0;
    while (head != NULL) {
        printf("[%02d] = %d\n", index, head->value);
        index += 1;
        head = head->next;
    }
}

void insert_node(LinkedList *list, ListNode *node) {
    if (list == NULL || node == NULL) {
        return;
    }
    
    ListNode **head = &(list->head);
    if (*head == NULL) {
        //printf("000--- head null; node value = %d\n", node->value);
        node->next = NULL;
        *head = node;
        return;
    }
    
    if ((*head)->value >= node->value) {
        //printf("111--- %d\n", (*head)->value);
        node->next = *head;
        *head = node;
    } else {
        ListNode *tmpHead = list->head;
        while (tmpHead != NULL) {
            ListNode *headNext = tmpHead->next;
            if (headNext != NULL) {
                //printf("222--- %d %d\n", tmpHead->value, headNext->value);
                if ( headNext->value >= node->value) {
                    node->next = headNext;
                    tmpHead->next = node;
                    break;
                }
            } else {
                //printf("22-- headNext NULL\n");
                tmpHead->next = node;
                break;
            }
            tmpHead = tmpHead->next;
        }
    }
}

void delete_node(LinkedList *list, ListNode *node) {
    if (list == NULL || node == NULL) {
        return;
    }
    
    ListNode *head = list->head;
    if (head == NULL) {
        return;
    }
    
    if (node == list->head) {
        list->head = list->head->next;
        return;
    }
    
    ListNode *pre = list->head;
    ListNode *cur = list->head;
    
    while (cur != NULL && cur != node) {
        pre = cur;
        cur = cur->next;
    }
    
    if (cur != NULL) {
        pre->next = cur->next;
        cur = NULL;
    }
}

void insert_head(LinkedList *list, ListNode *node) {
    if (list == NULL || node == NULL) {
        return;
    }
    
    ListNode **head = &(list->head);
    if (*head != NULL) {
        node->next = *head;
    }
    *head = node;
}

ListNode * delete_head(LinkedList *list) {
    if (list == NULL) {
        return NULL;
    }
    
    ListNode **head = &(list->head);
    if (*head == NULL) {
        return NULL;
    }
    
    ListNode *tmpHead = *head;
    *head = (*head)->next;
    
    tmpHead->next = NULL;
    return tmpHead;
}

void delete_tail(LinkedList *list) {
    if (list == NULL) {
        return;
    }
    
    ListNode *head = list->head;
    if (head == NULL) {
        return;
    }
    
    ListNode *next = head;
    ListNode *pre = next;
    while (next) {
        pre = next;
        next = next->next;
    }
    delete_node(list, pre);
}

bool is_exist_node(LinkedList *list, ListNode *node) {
    if (list == NULL || node == NULL) {
        return false;
    }
    
    ListNode *head = list->head;
    while (head) {
        if (head->value == node->value) {
            return true;
        }
        head = head->next;
    }
    return false;
}

bool is_list_empty(LinkedList *list) {
    return list == NULL || list->head == NULL;
}

void reverse_list(LinkedList *list) {
    
    if (list == NULL) {
        return;
    }
    
    ListNode *head = list->head;
    if (head == NULL) {
        return;
    }
    
    ListNode *pre = list->head;
    ListNode *next = pre->next;
    while (next != NULL) {
        pre->next = next->next;
        next->next = head;
        head = next;
        
        next = pre->next;
    }
    list->head = head;
    
    //    LinkedList newList = { NULL };
    //    ListNode *elemNode;
    //    while (!is_list_empty(list)) {
    //        elemNode = delete_head(list);
    //        insert_head(&newList, elemNode);
    //    }
    //    list->head = newList.head;
}

ListNode * half_node(LinkedList *list) {
    if (list == NULL) {
        return NULL;
    }
    
    ListNode *head = list->head;
    if (head == NULL) {
        return head;
    }
    
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

bool is_cyclic(LinkedList *list) {
    if (list == NULL) {
        return false;
    }
    
    ListNode *head = list->head;
    if (head == NULL) {
        return false;
    }
    
    ListNode *fast = head;
    ListNode *slow = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) {
            return true;
        }
    }
    return false;
}

int list_size(LinkedList *list) {
    if (list == NULL) {
        return -1;
    }
    int size = 0;
    ListNode *head = list->head;
    while (head) {
        size += 1;
        head = head->next;
    }
    return size;
}

//LRU 最近最少使用
void LRU_list(LinkedList *list, ListNode *node) {
    if (list == NULL) {
        return;
    }
    
    if (list->head == NULL) {
        insert_node(list, node);
        return;
    }
    
    if (is_exist_node(list, node)) {
        delete_node(list, node);
    } else if (list_size(list) >= 5) {
        delete_tail(list);
    }
    insert_head(list, node);
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    LinkedList list = { NULL };
    ListNode nodes[10];
    for (int i = 0; i < 10; i++) {
        nodes[i].value = i;
        nodes[i].next = NULL;
    }
    
    insert_node(&list, &nodes[0]);
    insert_node(&list, &nodes[9]);
    insert_node(&list, &nodes[3]);
    insert_node(&list, &nodes[5]);
    insert_node(&list, &nodes[1]);
    
    dump(&list);
    printf("\n");
    
    //    delete_tail(&list);
    //    dump(&list);
    //    printf("\n");
    
    //    insert_head(&list, &nodes[7]);
    //    dump(&list);
    //    printf("\n");
    //
    //    ListNode *tmpNode = delete_head(&list);
    //    dump(&list);
    //    printf("delete head = %d\n", tmpNode != NULL ? tmpNode->value : -1);
    
    
    //    ListNode *halfNode = half_node(&list);
    //    printf("half node = %d\n", halfNode->value);
    
    //    delete_node(&list, &nodes[3]);
    //    dump(&list);
    
    //    printf("*************\n");
    //    reverse_list(&list);
    //    dump(&list);
    
    
    //    printf("is cyclic = %d\n", is_cyclic(&list));
    //    nodes[1].next = &nodes[0];
    //    printf("is cyclic = %d\n", is_cyclic(&list));
    
    
    
    //    LRU_list(&list, &nodes[7]);
    //    dump(&list);
    //    printf("\n");
    
    //    LRU_list(&list, &nodes[1]);
    //    dump(&list);
    //    printf("\n");
    
    
    return 0;
}
