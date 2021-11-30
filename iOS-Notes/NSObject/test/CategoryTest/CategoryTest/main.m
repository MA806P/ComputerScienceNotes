//
//  main.m
//  CategoryTest
//
//  Created by MA806P on 2021/11/12.
//

#import <Foundation/Foundation.h>
#import "Student.h"
#import "Student+Test1.h"
#import "Teacher.h"

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        Student *st = [[Student alloc] init];
        st.name = @"hello";
        NSLog(@"Student = %@", st.name);
        
        
    }
    return 0;
}
