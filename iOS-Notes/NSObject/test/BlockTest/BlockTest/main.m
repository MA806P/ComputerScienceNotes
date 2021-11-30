//
//  main.m
//  BlockTest
//
//  Created by MA806P on 2021/11/14.
//

#import <Foundation/Foundation.h>

typedef void(^MyBlock)(void);

MyBlock myBlock() {
    int a = 20;
    return ^{ NSLog(@"my block = %d", a); };
}

int main(int argc, const char * argv[]) {
    @autoreleasepool {
        
        /*
        int a = 1;
        void (^block)(void) = ^{
            NSLog(@"blk %d", a);
        };
        NSLog(@"%@ %@ %@", [block class], [[block class] superclass], [[[block class] superclass] superclass]); //__NSMallocBlock__ NSBlock NSObject
        NSLog(@"%@", ^{ NSLog(@"blk");}); //<__NSGlobalBlock__: 0x100004060>
        
        MyBlock blk = myBlock();
        blk(); //my block = 20
        NSLog(@"%@", [blk class]); //__NSMallocBlock__
        */
        
        MyBlock blk2 = ^{ NSLog(@"blk");};
        NSLog(@"%@", [blk2 class]);
        
        int b = 12;
        NSLog(@"%@", ^{ NSLog(@"blk %d", b);});
        
        
        NSInteger val = 3;
        NSLog(@"block = %@", ^{ NSLog(@"val = %ld", val); });
        //block = <__NSStackBlock__: 0x7ffeefbff540>
        
        
    }
    return 0;
}
