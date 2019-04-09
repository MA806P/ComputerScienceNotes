### 队列  
队列在线程池等有限资源池中的应用  

队列：先进先出。入队，出队。和栈一样，是一种操作受限的线性表数据结构。  
循环队列、阻塞队列、并发队列。  

1、顺序队列和链式队列
用数组实现的栈叫作顺序栈，用链表实现的栈叫作链式栈。  
同样，用数组实现的队列叫作顺序队列，用链表实现的队列叫作链式队列。  

2、循环队列  

3、阻塞队列  
阻塞队列其实就是在队列基础上增加了阻塞操作。简单来说，就是在队列为空的时候，从队头取数据会被阻塞。如果队列已经满了，那么插入数据的操作就会被阻塞，直到队列中有空闲位置后再插入数据，然后再返回。  
可以使用阻塞队列实现一个“生产者-消费者模型”  

4、并发队列  
在多线程情况下，会有多个线程同时操作队列，这个时候就会存在线程安全问题。  
线程安全的队列我们叫作并发队列。最简单直接的实现方式是直接在 enqueue()、dequeue() 方法上加锁，但是锁粒度大并发度会比较低，同一时刻仅允许一个存或者取操作。实际上，基于数组的循环队列，利用 CAS 原子操作，可以实现非常高效的并发队列。这也是循环队列比链式队列应用更加广泛的原因。


