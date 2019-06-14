#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX_LEVEL 15

struct node {
    int val;
    int max_level;
    struct node *forward[MAX_LEVEL];
};

struct skip_list {
    struct node head;
    int max_level;
    int max_level_nodes;
};


void node_init(struct node *node) {
    memset(node, 0, sizeof(struct node));
}

void skip_list_init(struct skip_list *sl) {
    node_init(&sl->head);
    sl->max_level = 0;
    sl->max_level_nodes = 0;
}

void random_init() {
    static bool done = false;
    if (done) { return; }
    
    srandom((unsigned int)time(NULL));
    done = true;
}

int random_level(void) {
    int i, level = 1;
    random_init();
    for (i = 1; i < MAX_LEVEL; i++) {
        if (random()%2 == 1) {
            level++;
        }
    }
    return level;
}



void insert(struct skip_list *sl, int val) {
    int level = random_level();
    struct node *update[MAX_LEVEL];
    struct node *new, *p;
    int i;
    
    new = (struct node*)malloc(sizeof(struct node));
    if (new == NULL) { return; }
    new->max_level = level;
    new->val = val;
    
    for (int i = 0; i < MAX_LEVEL; i++) {
        update[i] = &sl->head;
    }
    p = &sl->head;
    
    for (i = level - 1; i >= 0; i--) {
        while (p->forward[i] && p->forward[i]->val < val) {
            p = p->forward[i];
        }
        update[i] = p;
    }
    
    for (i = 0; i < level; i++) {
        new->forward[i] = update[i]->forward[i];
        update[i]->forward[i] = new;
    }
    
    if (sl->max_level < level) {
        sl->max_level = level;
        sl->max_level_nodes = 1;
    } else if (sl->max_level == level)
        sl->max_level_nodes++;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    
    return 0;
}
