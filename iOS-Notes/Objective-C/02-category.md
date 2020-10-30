

https://tech.meituan.com/2015/03/03/diveintocategory.html
https://tech.meituan.com/2018/11/08/ios-category-module-communicate.html


### category 使用场景  
category的主要作用是为已经存在的类添加方法。  
1、可以把类的实现分开在几个不同的文件里面。这样做有几个显而易见的好处  
a)可以减少单个文件的体积   
b)可以把不同的功能组织到不同的category里  
c)可以由多个开发者共同完成一个类   
d)可以按需加载想要的category 等等。  
2、声明私有方法  

不过除了apple 推荐的使用场景，还有 category 的其他几个使用场景：  
1、模拟多继承  
2、把framework的私有方法公开  

###  category 和 extension  
extension 看起来很像一个匿名的 category，但是 extension 和有名字的 category 几乎完全是两个东西。   
extension在编译期决议，它就是类的一部分，在编译期和头文件里的 @interface 以及实现文件里的@implement 一起形成一个完整的类，它伴随类的产生而产生，亦随之一起消亡。extension一般用来隐藏类的私有信息，你必须有一个类的源码才能为一个类添加extension，所以你无法为系统的类比如NSString添加extension。（详见
https://developer.apple.com/library/mac/documentation/Cocoa/Conceptual/ProgrammingWithObjectiveC/CustomizingExistingClasses/CustomizingExistingClasses.html）  

category 则完全不一样，它是在运行期决议的。 就 category 和 extension 的区别来看，我们可以推导出一个明显的事实，extension可以添加实例变量，而category是无法添加实例变量的（因为在运行期，对象的内存布局已经确定，如果添加实例变量就会破坏类的内部布局，这对编译型语言来说是灾难性的）。  



所有的OC类和对象，在runtime层都是用struct表示的，category也不例外，在runtime层，category用结构体category_t（在objc-runtime-new.h中可以找到此定义）  
```
typedef struct category_t {
    const char *name;  //类的名字
    classref_t cls;  //类
    struct method_list_t *instanceMethods; //给类添加的实例方法的列表
    struct method_list_t *classMethods; //添加的类方法的列表
    struct protocol_list_t *protocols; //category 实现的所有协议的列表
    struct property_list_t *instanceProperties;  //添加的所有属性
} category_t;
```
可将 category 转换为 C 语言查看， clang -rewrite-objc MyClass.m  



### category如何加载  
Objective-C的运行是依赖OC的runtime的，而OC的runtime和其他系统库一样，是OS X和iOS通过dyld动态加载的。  
OC 运行时，入口方法 *_objc_init()* (在 objc-os.mm文件中)，在这个方法里，category被附加到类上面是在map_images的时候发生的，在new-ABI的标准下，*_objc_init* 里面的调用的map_images最终会调用objc-runtime-new.mm里面的 *_read_images* 方法，而在 *_read_images* 方法的结尾代码有，遍历 category_t 数组，然后：  
1)、把category的实例方法、协议以及属性添加到类上  
2)、把category的类方法和协议添加到类的metaclass上  

*_read_images* 方法中调用的两个方法：  
1、addUnattachedCategoryForClass(cat, cls, hi);  把类和 category 做个关联映射  
2、remethodizeClass(cls); 处理添加实例方法等，这个方法里又调用方法  attachCategoryMethods(cls, cats, ..);  

attachCategoryMethods 做的工作相对比较简单，它只是把所有category的实例方法列表拼成了一个大的实例方法列表，然后转交给了attachMethodLists方法，然后完成添加。  

需要注意的有两点：  
1)、category的方法没有“完全替换掉”原来类已经有的方法，也就是说如果category和原来类都有methodA，那么category附加完成之后，类的方法列表里会有两个methodA  

2)、category的方法被放到了新方法列表的前面，而原来类的方法被放到了新方法列表的后面，这也就是我们平常所说的category的方法会“覆盖”掉原来类的同名方法，这是因为运行时在查找方法的时候是顺着方法列表的顺序查找的，它只要一找到对应名字的方法，就会罢休^_^，殊不知后面可能还有一样名字的方法。  
oc 方法调用顺序优先级 cache->category->self->super  




### category 和 +load 方法

load类方法的调用时机比main函数还要靠前。load方法是由系统来调用的，并且在整个程序运行期间，只会调用一次，所以可以在load方法中执行一些只执行一次的操作。
一般Method Swizzling都会放在load方法中执行，这样在执行main函数前，就可以对类方法进行交换。可以确保正式执行代码时，方法肯定是被交换过的。
如果对一个类添加Category后，并且重写其原有方法，这样会导致Category中的方法覆盖原类的方法。但是load方法却是例外，所有Category和原类的load方法都会被执行。


在 person 、student继承person、student+category1、student+category2 里都有方法  +load  +initialize  -init(除了category) 和自定义的方法 -doSomething

然后调用：
Student * student = [[Student alloc] init];
[student allDoSomething];

打印结果顺序为：
super - load
self - load
category1 - load
category2 - load //在 build pahases 的 compile sources 看编译顺序，1 在前 2 在后，调整顺序打印顺序也会变
super - initialize
category2 - initialize //这个打印调整1 2编译顺序的话，也会变调用 1
super - init
self - init
category2 do something  //覆盖了方法，只会调用 category 中的方法。这个打印调整1 2编译顺序的话，也会变调用 1
对于“覆盖”掉的方法，则会先找到最后一个编译的category里的对应方法。


1)、在类的+load方法调用的时候，我们可以调用 category 中声明的方法么？
可以调用，因为附加 category 到类的工作会先于+load方法的执行

2)、这么些个+load方法，调用顺序是咋样的呢
+load的执行顺序是先类，后category，而category的+load执行顺序是根据编译顺序决定的。


怎么调用到原来类中被category覆盖掉的方法？ 
我们已经知道category其实并不是完全替换掉原来类的同名方法，只是category在方法列表的前面而已，所以我们只要顺着方法列表找到最后一个对应名字的方法，就可以调用原来类的方法，如下代码：
```
        #import <objc/runtime.h>
        Student * student = [[Student alloc] init];
        //[student allDoSomething];
        
        Class currentClass = [Student class];
        if (currentClass) {
            unsigned int methodCount;
            Method *methodList = class_copyMethodList(currentClass, &methodCount);
            IMP lastImp = NULL;
            SEL lastSel = NULL;
            for (NSInteger i = 0; i < methodCount; i++) {
                Method method = methodList[i];
                NSString *methodName = [NSString stringWithCString:sel_getName(method_getName(method))
                                                encoding:NSUTF8StringEncoding];
                if ([@"allDoSomething" isEqualToString:methodName]) {
                    lastImp = method_getImplementation(method);
                    lastSel = method_getName(method);
                }
            }
            typedef void (*fn)(id,SEL);
            
            if (lastImp != NULL) {
                fn f = (fn)lastImp;
                f(student,lastSel);
            }
            free(methodList);
        }

```


### category 和关联对象 

category加实例变量
关联对象的set函数有几个参数: 4个 关联者，关联的key，关联的value，和内存类型
objc_setAssociatedObject(self, @selector(stID), stID, OBJC_ASSOCIATION_COPY_NONATOMIC);
get2个
objc_getAssociatedObject(self, @selector(stID));


关联对象又是存在什么地方呢？ 如何存储？ 对象销毁时候如何处理关联对象呢？
runtime的源码，在objc-references.mm文件中有个方法_object_set_associative_reference：可以看到所有的关联对象都由AssociationsManager管理。
AssociationsManager里面是由一个静态AssociationsHashMap来存储所有的关联对象的。这相当于把所有对象的关联对象都存在一个全局map里面。而map的的key是这个对象的指针地址（任意两个不同对象的指针地址一定是不同的），而这个map的value又是另外一个AssociationsHashMap，里面保存了关联对象的kv对。

而在对象的销毁逻辑里面，见objc-runtime-new.mm。runtime的销毁对象函数objc_destructInstance里面会判断这个对象有没有关联对象，如果有，会调用_object_remove_assocations做关联对象的清理工作。








Sunny 题目：
@interface NSObject (Sark)
+ (void)foo;
- (void)foo;
@end

@implementation NSObject (Sark)
- (void)foo {    NSLog(@"IMP: -[NSObject(Sark) foo]"); }
@end

调用方法，会不会报错，能正确执行吗？
[NSObject foo];
[[NSObject new] foo];

根据上面的解析，在加载NSObject的Category中，在编译期会提示我们没有实现+(void)foo的方法，因为在.m文件中并没有找到+的方法，而是一个-号的方法，所以会提示。
在实际加载Category的时候，会把-(void)foo加载进去，由于是实例方法，所以会放在NSObject的实例方法列表里面。

调用[NSObject foo]的时候，会先在NSObject的meta-class中去查找foo方法的IMP，未找到，继续在superClass中去查找，NSObject的meta-class的superClass就是本身NSObject，于是又回到NSObject的类方法中查找foo方法，于是乎找到了，执行foo方法，打印输出。
在调用[[NSObject new] foo]的时候，会先生成一个NSObject的对象，用这个NSObject实例对象再去调用foo方法的时候，会去NSObject的实例方法里面去查找，找到，于是也会打印输出。












