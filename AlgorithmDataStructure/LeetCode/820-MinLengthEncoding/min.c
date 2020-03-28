
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//题目208，创建 字典树
typedef struct trie_node {
    struct  trie_node *children[26];
    int count;
} Trie;

Trie* trieCreate() {
    Trie *root = (Trie *)malloc(sizeof(Trie));
    //root 前 sizeof(struct TreeNode) 个字节设置为0
    memset(root, 0, sizeof(Trie));
    root->count = -1;
    return root;
}

//倒着插入单词
Trie * trieInsert(Trie* obj, char * word) {
    Trie *cur = obj;
    int wordl = (int)strlen(word);
    for (int i = wordl - 1; i >= 0; i--) {
        char c = word[i];
        if (cur->children[c-'a'] == NULL) {
            cur->children[c-'a'] = trieCreate();
        }
        
        printf("1111 %c=%d \n", c, cur->children[c-'a']->count);
        //可能前先插入了短的，em => e=-1:1  m=-1:0，emit => e=1:1不变 m=0:2 i=-1:1 t=-1:0
        //也可能先插入了长的，emit => e=-1:3 m=-1:2 i=-1:1 t=-1:0， em => e=3:3 m=2:2不变
        if (cur->children[c-'a']->count < 1) { cur->children[c-'a']->count = i; }
        cur = cur->children[c-'a'];
        printf("222 %c=%d \n", c, cur->count);
    }
    printf("\n---\n");
    return cur;
}

bool trieSearch(Trie* obj, char * word) {
    Trie *node = obj;
    int wordl = (int)strlen(word);
    for (int i = wordl - 1; i >= 0; i--) {
        char c = word[i];
        if (node->children[c-'a'] == NULL) {
            return false;
        }
        node = node->children[c-'a'];
    }
    printf("search - %s %d\n", word, node->count);
    return node->count == 0;
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



/*
 注意：
 长短前后的区别，和重复的单词，别重复计算
 time  me
 me time
 time time
 
 或者先按照，长短排序，
 
 */

int minimumLengthEncoding(char ** words, int wordsSize){
    if (words == NULL || wordsSize < 1) { return 0; }
    
    Trie *trie = trieCreate();
    //用来记录单词倒序插入的最右一个节点，用来统计长度
    Trie **lastNodes = (Trie **)malloc(sizeof(Trie *)*wordsSize);
    memset(lastNodes, 0, sizeof(Trie *) * wordsSize);
    
    for (int i = 0; i < wordsSize; i++) {
        char *w = words[i];
        //判断单词是否已经插入过了
        if (trieSearch(trie, w) == false) {
            Trie *node = trieInsert(trie, w);
            lastNodes[i] = node;
        }
        
    }
    
    int ans = 0;
    for (int i = 0; i < wordsSize; i++) {
        Trie *node = lastNodes[i];
        if (node != NULL && node->count == 0) {
            printf("%s %d\n",words[i], node->count);
            ans += strlen(words[i]) + 1;
            free(node);
        }
        
    }
    free(trie);
    
    free(lastNodes);
    return ans;
}


int main(int argc, const char * argv[]) {
    
    char **ss = (char **)malloc(sizeof(char *) * 3);
    ss[0] = "time";
    ss[1] = "me";
    ss[2] = "time";
    printf("ans = %d\n", minimumLengthEncoding(ss, 3));
    
    return 0;
}





