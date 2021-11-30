//
//  Student+Test1.m
//  CategoryTest
//
//  Created by MA806P on 2021/11/12.
//

#import "Student+Test1.h"
#import <objc/runtime.h>

@implementation Student (Test1)

+ (void)load {
    NSLog(@"Student (Test1) load");
}

//+ (void)initialize {
//    NSLog(@"Student (Test1) initialize");
//}


//const void *NameKey = &NameKey; //值就是自己的地址
static const char NameKey;
- (void)setName:(NSString *)name {
    objc_setAssociatedObject(self, &NameKey, name, OBJC_ASSOCIATION_COPY_NONATOMIC);
}
- (NSString *)name {
    return objc_getAssociatedObject(self, &NameKey);
}

@end
