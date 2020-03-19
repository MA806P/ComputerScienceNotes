

#include <stdio.h>
#include <stdbool.h>

/*
 //不重叠的情况
 rec1[2] <= rec2[0]   // left
 rec1[3] <= rec2[1]   // bottom
 rec1[0] >= rec2[2]   // right
 rec1[1] >= rec2[3]    // top
 */
bool isRectangleOverlap(int* rec1, int rec1Size, int* rec2, int rec2Size){
    if (rec1 == NULL || rec2 == NULL || rec1Size < 4 || rec2Size < 4) { return false; }
    return !(rec1[2] <= rec2[0] ||  rec1[3] <= rec2[1] || rec1[0] >= rec2[2] ||  rec1[1] >= rec2[3]);
    return false;
    
}



int main(int argc, const char * argv[]) {
    
    int a[] = {0,0,1,1};
    int b[] = {1,0,2,1};
    
    printf("= %d\n", isRectangleOverlap(a, 4, b, 4));
    
    return 0;
}




