//
//  main.c
//  CTest
//
//  Created by MA806P on 2019/4/15.
//  Copyright © 2019 myz. All rights reserved.
//

#include <stdio.h>
#include "singleList.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    
    linkedList *list = listCreate();
    int a1 = 7;
    listAddNodeHead(list, &a1);
    int a2 = 2;
    listInsertNode(list, list->head, &a2, true);
    int a3 = 3;
    listInsertNode(list, list->head, &a3, true);
    int a4 = 4;
    listInsertNode(list, list->head, &a4, true);
    int a5 = 5;
    listInsertNode(list, list->head, &a5, true);
    int a6 = 6;
    listInsertNode(list, list->head, &a6, true);
    
    int a7 = 1;
    listAddNodeTail(list, &a7);
    
    dump(list);
    printf("---------------\n");
    
    listDelNode(list, listSearchKey(list, &a7));
    dump(list);
    printf("---------------\n");
    
    listDelNode(list, listIndex(list, 2));
    dump(list);
    printf("---------------\n");
    
    listRewind(list);
    dump(list);
    printf("---------------\n");
    
    
    listRelease(list);
    
    return 0;
}
