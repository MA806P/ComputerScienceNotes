//
//  main.m
//  NSObject-test
//
//  Created by MA806P on 2021/11/7.
//

#import <Foundation/Foundation.h>
#import <objc/runtime.h>
#import <malloc/malloc.h>


struct method_t {
    SEL sel;
    char *types;
    IMP imp;
};


@interface Person : NSObject

- (void)other;
- (void)test;
+ (void)test;

@end

@implementation Person

void c_other(id self, SEL _cmd) {
    NSLog(@"c_other - %@ %@", self, NSStringFromSelector(_cmd));
}

- (void)other {
    NSLog(@"%s", __func__);
}

+ (BOOL)resolveInstanceMethod:(SEL)sel {
    if (sel == @selector(test)) {
        
        //动态添加方法
        /*
         Method method = class_getInstanceMethod(self, @selector(other));
        class_addMethod(self, sel,
                        method_getImplementation(method),
                        method_getTypeEncoding(method));
        */
        
        //添加c函数
        class_addMethod(self, sel, (IMP)c_other, "v16@0:8");
        //c_other - <Person: 0x105806150> test
        
        //返回YES代表有动态添加方法
        return YES;
    }
    return [super resolveInstanceMethod:sel];
}

+ (BOOL)resolveClassMethod:(SEL)sel {
    if (sel == @selector(test)) {
        //添加c函数。注意传进去的是元类对象object_getClass(self)，类方法要添加到元类对象上
        class_addMethod(object_getClass(self), sel, (IMP)c_other, "v16@0:8");
        //c_other - Person test
        return YES;
    }
    return [super resolveClassMethod:sel];
}

@end




@interface Student : Person

@end

@implementation Student

@end

struct my_person_struct {
    Class isa;
    Class superclass;
};


int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        /*
        Person *person = [[Person alloc] init];
        Class cls = [Person class]; //Person 类对象
        Class metaCls = object_getClass(cls); //Person 元类对象
        struct my_person_struct *personClass = (__bridge struct my_person_struct *)([Person class]);
        //personClass = { isa = (Class)0x100008160; superclass = (Class)NSObject 0x7fff889c0cc8; }
        //类对象的 isa 指针指向元类对象
        
        NSLog(@"%p %p %p", person, cls, metaCls); //0x10580c9f0 0x100008188 0x100008160
        */
        
        Person *person = [[Person alloc] init];
        [person test];
        
        
        [Person test];
        
    }
    return 0;
}
