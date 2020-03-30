

#include <stdio.h>
#include <stdlib.h>


struct MyListNode {
    int val;
    struct MyListNode *next;
};

struct MyListNode *createCycleList(int n) {
    struct MyListNode *head = (struct MyListNode *)malloc(sizeof(struct MyListNode));
    head->val = 0;
    head->next = head;
    struct MyListNode *next = head;
    for (int i = 1; i < n; i++) {
        struct MyListNode *node = (struct MyListNode *)malloc(sizeof(struct MyListNode));
        node->val = i;
        node->next = head;
        next->next = node;
        next = node;
    }
    return head;
}

void deleteListNextNode(struct MyListNode *prev) {
    if (prev == NULL || prev->next == NULL || prev->next == prev) { return; }
    struct MyListNode *node = prev->next;
    prev->next = node->next;
    node->next = NULL;
    free(node);
}

int lastRemaining0(int n, int m){
    if (n <= 1 || m <= 1) { return n - 1; }
    
    struct MyListNode *list = createCycleList(n);
    int count = 1;
    struct MyListNode *node = list;
    while (node != node->next) {
        if (count == m - 1) {
            deleteListNextNode(node);
            count = 1;
        } else {
            count += 1;
        }
        node = node->next;
    }
    
    int ans = 0;
    if (node == node->next) {
        ans = node->val;
        node->next = NULL;
        free(node);
    }
    return ans;
}


/**
 长度为 n 的序列会先删除第 m % n 个元素，然后剩下一个长度为 n - 1 的序列。
 那么可以递归地求解 f(n - 1, m)，就可以知道对于剩下的 n - 1 个元素，最终会留下第几个元素，
设答案为 x = f(n - 1, m)。

 由于我们删除了第 m % n 个元素，将序列的长度变为 n - 1。当我们知道了 f(n - 1, m) 对应的答案 x 之后，我们也就可以知道，长度为 n 的序列最后一个删除的元素，应当是从 m % n 开始数的第 x 个元素。因此有 f(n, m) = (m % n + x) % n = (m + x) % n。
 
 f(n,m) = (m%n + f(n-1,m)) %n = (m%n + (m%n + f(n-2, m))%n  ) %n
 
 f(3,2)   0  1  2  = 2
 f(4,2)   0  1  2  3     =>  0  2  3
                                    先去掉m%n=2%4=2第2个数，只剩三个数了，f(3,2)也只有三个数，已知f(3,2)最后一个删除的元素是 2
                                    剩下三个数(0 2 3)起始位置是 2, 从f(3, 2)可知最后一个删除的是第2个，
                                    所以(0 2 3)从起始位置2开始往后数2个，就是最后的值，0
                                    = ( 2%4 + f(3,2) ) % 4 = ( 2 + 2) % 4 = 0
 
 
 
 */

//递归
int f(int n, int m) {
    if (n == 1) { return 0; }
    int x = f(n-1, m);
    return (m+x)%n;
}
int lastRemaining1(int n, int m) {
    if (n <= 1 || m <= 1) { return n - 1; }
    return f(n, m);
}

//迭代
int lastRemaining(int n, int m) {
    int f = 0;
    for (int i = 2; i != n+1; i++) {
        f = (f + m) % i;
    }
    return f;
}


int main(int argc, const char * argv[]) {
    
    printf("ans = %d\n", lastRemaining(2, 2));
    
    return 0;
}


