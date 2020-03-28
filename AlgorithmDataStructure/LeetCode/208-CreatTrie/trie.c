
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//字典树
typedef struct trie_node {
    struct  trie_node *children[26];
    int end;
} Trie;

/** Initialize your data structure here. */
Trie* trieCreate() {
    Trie *root = (Trie *)malloc(sizeof(Trie));
    //root 前 sizeof(struct TreeNode) 个字节设置为0
    memset(root, 0, sizeof(Trie));
    root->end = 0;
    return root;
}

/** Inserts a word into the trie. */
void trieInsert(Trie* obj, char * word) {
    Trie *cur = obj;
    long wordl = strlen(word);
    for (long i = 0; i < wordl; i++) {
        char c = word[i];
        if (cur->children[c-'a'] == NULL) {
            cur->children[c-'a'] = trieCreate();
        }
        cur = cur->children[c-'a'];
    }
    cur->end = 1;
}

/** Returns if the word is in the trie. */
bool trieSearch(Trie* obj, char * word) {
    Trie *node = obj;
    long wordl = strlen(word);
    for (long i = 0; i < wordl; i++) {
        char c = word[i];
        if (node->children[c-'a'] == NULL) {
            return false;
        }
        node = node->children[c-'a'];
    }
    return node->end > 0;
}

/** Returns if there is any word in the trie that starts with the given prefix. */
bool trieStartsWith(Trie* obj, char * prefix) {
    Trie *node = obj;
    for (long i = 0; prefix[i] != '\0'; i++) {
        char c = prefix[i];
        if (node->children[c-'a'] == NULL) {
            return false;
        }
        node = node->children[c-'a'];
    }
    return true;
}

void trieFree(Trie* obj) {
    if (obj == NULL) { return; }
    for (int i = 0; i < 26; i++) {
        if (obj->children[i]) {
            trieFree(obj->children[i]);
        }
    }
    free(obj);
}




int main(int argc, const char * argv[]) {
    
    Trie* obj = trieCreate();
    char *word = "hello";
    trieInsert(obj, word);
    bool param_2 = trieSearch(obj, word);
    bool param_3 = trieStartsWith(obj, "hel");
    bool param_4 = trieStartsWith(obj, "app");
    printf("%d %d %d\n", param_2, param_3, param_4);
    trieFree(obj);

    return 0;
}






