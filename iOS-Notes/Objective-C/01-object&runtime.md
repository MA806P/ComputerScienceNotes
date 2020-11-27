





https://www.sunyazhou.com/2020/07/06/20200721iOSinterviewAnswers/




# 概念  


OC 是 C 语言的超集，在 C 语言的主体上加上了面向对象的特性，这是为了方便 APP 的开发，同时也兼顾了语言的整体性能。  





## OC对象初始化  
Objective-C 在初始化时，会自动给每个属性（成员变量）赋值为 0 或者 nil，没有强制要求额外为每个属性（成员变量）赋值，方便的同时也缺少了代码的安全性。  
Objective-C 中的指定初始化器会在后面被 NS_DESIGNATED_INITIALIZER 修饰，对于多个构造方法，它可以指定一个基础的构造方法。其它快捷的构造方法都必须通过它来实现类的初始化。代码规范的一种。可以避免不必要的bug。良好的编程习惯。  
```
// NSObject
@interface NSObject <NSObject>
- (instancetype)init
#if NS_ENFORCE_NSOBJECT_DESIGNATED_INITIALIZER
    NS_DESIGNATED_INITIALIZER
#endif
    ;
@end
  
  
// UIView
@interface UIView : UIResponder
- (instancetype)initWithFrame:(CGRect)frame NS_DESIGNATED_INITIALIZER;
- (nullable instancetype)initWithCoder:(NSCoder *)coder NS_DESIGNATED_INITIALIZER;
@end
```


无论继承自什么类，都经常需要新的初始化方法，而这个新的初始化方法其实就是新的指定初始化器。如果存在一个新的指定初始化器，那么原来的指定初始化器就会自动退化成便利初始化器。
为了遵循必须要调用指定初始化器的规则，就必须重写旧的定初始化器，在里面调用新的指定初始化器，这样就能确保所有属性（成员变量）被初始化。
根据这条规则，可以从NSObject、UIView中看出，由于UIView拥有新的指定初始化器-initWithFrame:，导致父类NSObject的指定初始化器-init退化成便利初始化器。所以当调用[[UIView alloc] init]时，-init里面必然调用了-initWithFrame:
当存在一个新的指定初始化器的时候，推荐在方法名后面加上NS_DESIGNATED_INITIALIZER，主动告诉编译器有一个新的指定初始化器，这样就可以使用 Xcode 自带的Analysis功能分析，找出初始化过程中可能存在的漏洞

```
// 推荐加上NS_DESIGNATED_INITIALIZER
- (instancetype)initWithFrame:(CGRect)frame name:(NSString *)name NS_DESIGNATED_INITIALIZER;

// 旧的指定初始化器就自动退化成便利初始化器，必须在里面调用新的指定初始化器
- (instancetype)initWithFrame:(CGRect)frame {
return [self initWithFrame:frame name:@"Daniels"];
}
```

如果不想去重写旧的指定初始化器，但又不想存在漏洞和隐患，那么可以使用NS_UNAVAILABLE把旧的指定初始化器都废弃，外界就无法调用旧的指定初始化器
// 废弃旧的指定初始化器
- (instancetype)initWithFrame:(CGRect)frame NS_UNAVAILABLE;


一个新的类也可以不增加新的初始化方法，在 Objective-C 中，子类会直接继承父类所有的初始化方法



## 消息传递机制  

OC 对象都是 C 语言结构体
每个对象结构体的首个成员是Class类的变量，该变量定义了对象所属的类，通常称为 is a 指针

OC中如果向某对象传递消息，就会使用动态绑定机制来决定需要调用的方法。对象收到消息之后，究竟该调用哪个方法则完全于运行期决定，甚至可以在程序运行时改变。

向某对象传递消息，编译器将其转换为一条标准的C语言函数 objc_msgSend 调用
objc_msgSend函数会根据接收者与选择器的类型来调用适当的方法，该方法需要在接收者所属的类中搜寻其方法列表，如果能找到与选择器名称相符的方法，就跳至其实现代码。若是找不到，就沿着继承体系继续向上查找，等找到合适的方法之后再跳转。如果最终还是找不到相符的方法，就执行消息转发机制。（objc_msgSend会将匹配结果缓存在“快速映射表”里面，每个类都有这样一块缓存，若是后面还向该类发送与选择器相同的消息，那么执行起来就很快。）

OC对象的每个方法都可以视为简单的C函数，其原型如下：<return_type> Class_selector(id self, SEL _cmd, …)。每个类里都有一张表格，其中的指针都会指向这种函数，而选择器的名称则是查表时所用的“键”。objc_msgSend等函数正是通过这张表格来寻找应该执行的方法并跳至其实现的。





## 消息转发机制  

在编译期向类发送了其无法解读的消息并不会报错，因为在运行期可以继续向类中添加方法，所以编译器在编译时还无法确知类中到底会不会有某个方法实现。当对象收到无法解读的消息后，就会启用“消息转发”(message forwarding)机制，程序员可以经此过程告诉对象应该如何处理未知消息。

为防止消息转发过程中程序崩溃，可在转发的过程中设置挂钩，用于执行预定的逻辑，而不使应用程序崩溃。

消息转发分为两大阶段：
第一阶段先征询接收者，所属的类，看其是否能动态添加方法，以处理当前这个“未知的选择器”，这叫做“动态方法解析”(dynamic method resolution).
第二阶段涉及完整的消息转发机制，如运行期系统已经把第一阶段执行完了，那么接收者自己就无法再以动态新增方法的手段来响应包含该选择器的消息了。运行期系统会请求接收者以其他手段来处理与消息相关的方法调用，可细分为两步：首先，请接收者看看有没有其他对象能处理这条消息，若有，则运行期系统会把消息转给那个对象，于是消息转发结束，若没有“备援的接收者”(replacement receiver)，则启动完整的消息转发机制，运行期系统会把与消息有关的全部细节都封装到NSInvocation对象中，再给接收者最后一次机会，令其设法解决当前还未处理的这条消息。



typedef id (*IMP)(id, SEL, ...);
IMP:一个函数指针,保存了方法的地址

typedef struct objc_selector   *SEL; 
//指向 objc_selector 指针，表示方法的名字/签名。
SEL : 类成员方法的指针，但不同于C语言中的函数指针，函数指针直接保存了方法的地址，但SEL只是方法编号。可理解为“方法名的某种映射结果”

在类的结构体中有包括了指向其父类类定义的指针以及 Dispatch table. 
Dispatch table是一张SEL和IMP的对应表。

有了SEL这个中间过程，我们可以对一个编号和什么方法映射做些操作，也就是说我们可以一个SEL指向不同的函数指针，这样就可以完成一个方法名在不同时候执行不同的函数体。另外可以将SEL作为参数传递给不同的类执行。也就是说我们某些业务我们只知道方法名但需要根据不同的情况让不同类执行的时候，SEL可以帮助我们。


SEL methodId=@selector(func1);
[self performSelector:methodId withObject:nil];

IMP imp = [self methodForSelector:selector]; 
imp();




# 问题  



什么是 ARC？
automatic reference counting 内存管理机制，原先需要手动添加 retain release 来处理内存管理的引用计数，现可以自动的由编译器完成。
ARC 与 Garbage Collection 的区别，GC 在运行时管理内存，可以解决 retain cycle，而 ARC 在编译时管理内存。


什么情况下会出现循环引用？
两个或两个以上对象互相强引用，导致对象无法被释放的现象，这是内存泄漏的一种情况。可用 Xcode 的 debug memory graph 检查



instancetype和id的异同
1、相同点
都可以作为方法的返回类型
2、不同点
①instancetype可以返回和方法所在类相同类型的对象，id只能返回未知类型的对象；
②instancetype只能作为返回值，不能像id那样作为参数



基本类型的变量和对象被__block修饰与否各有什么区别？




如果用protocol和delegate（或者delegate的Array）来实现类似的功能可能吗？如果可能，会有什么潜在的问题？如果不能，为什么？







你使用过Objective-C的运行时编程（Runtime Programming）么？如果使用过，你用它做了什么？你还能记得你所使用的相关的头文件或者某些方法的名称吗？





