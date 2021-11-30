//
//  ViewController.m
//  KVOTest
//
//  Created by MA806P on 2021/11/10.
//

#import "ViewController.h"
#import "MYPerson.h"
#import <objc/runtime.h>

@interface ViewController ()

@property (nonatomic, strong) MYPerson *person1;
@property (nonatomic, strong) MYPerson *person2;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.person1 = [[MYPerson alloc] init];
    self.person1.age = 1;
    
    self.person2 = [[MYPerson alloc] init];
    self.person2.age = 2;
    
    [self.person1 addObserver:self forKeyPath:@"age" options:NSKeyValueObservingOptionNew | NSKeyValueObservingOptionOld context:@"person1"];
    
    NSLog(@"%d", [self.person1 isMemberOfClass:[MYPerson class]]); //1
    NSLog(@"%d", [self.person2 isMemberOfClass:[MYPerson class]]); //1
    
    [self printMetod:object_getClass(self.person1)]; //NSKVONotifying_MYPerson --- setAge:, class, dealloc, _isKVOA,
    [self printMetod:object_getClass(self.person2)]; //MYPerson --- setAge:, age,
}

- (void)printMetod:(Class)cls {
    unsigned int count;
    Method *methodList = class_copyMethodList(cls, &count);
    
    NSMutableString *result = [NSMutableString string];
    
    for (int i = 0; i < count; ++i) {
        Method m = methodList[i];
        NSString *mname = NSStringFromSelector(method_getName(m));
        [result appendString:mname];
        [result appendString:@", "];
    }
    
    free(methodList);
    NSLog(@"%@ --- %@", cls, result);
    
}


- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event {
    self.person1.age = 10;
}

- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context
{
    NSLog(@"%@ %@ %@ %@", keyPath, object, change, context);
}

@end
