





GCD 捕获 self 是否会造成内存泄漏？  
```
- (void)viewDidLoad {
    [super viewDidLoad];
    self.queue = dispatch_queue_create("com.mayc.concurrent", DISPATCH_QUEUE_CONCURRENT);
    dispatch_async(self.queue, ^{
        [self test];
    });
}

- (void)test { NSLog(@"test"); }
- (void)dealloc { NSLog(@"dealloc"); }
```  
运行上面代码，dealloc会调用，正常释放，不会造成内存泄漏。  
dispatch_async 会在 block 执行完成后将其释放。因此 _self->queue->block->self 这个循环引用只是暂时的（block 执行完成后被释放，打断了循环引用）。  

换成 dispatch_sync 也不会造成内存泄漏。原因跟 dispatch_async 有所不同，不是因为执行完成后被 release，我们看一下官方关于 dispatch_sync 的文档有段说明：大致意思是说，queue 不会对 block 进行持有，也不会进行 Block_copy 操作。既然 queue -> block 这一层引用不存在，自然也不会造成循环引用。  






  

