





# 概念

 

runloop

相当一个循环，使程序一直运行并接受用户事件，没事的时候闲着有事处理事。

NSRunLoop 简单的封装，CFRunLoop(core fundation)，

相关的类 NSTimer UIEvent Autorelease NSObject(NSDelayedPerforming、NSThreadPerformAddition)





# 问题  







RunLoop 和线程有什么关系？

runloop 是每一个线程一直运行的一个对象，主要用来负责响应需要处理的各种事件和消息。每一个线程都有且仅有一个runloop与其对应，没有线程就没有runloop。

在所有线程中，只有主线程的 runloop 是默认启动的，main 函数会设置一个 nsrunloop 对象，而其他线程的 runloop 默认是没有启动的，可以通过 [NSRunLoop currentRunLoop] 来启动。





利用RunLoop可以实现哪些功能？