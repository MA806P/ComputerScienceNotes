### C语言  

C库函数  
1、malloc，calloc，realloc，free   
(类型 \*)malloc(size) 在内存的动态存储区中分配一块长度为“size”字节的连续区域，返回该区域的首地址。 
(类型\*)calloc(n，size) 在内存的动态存储区中分配n块长度为“size”字节的连续区域，返回首地址。 
(类型\*)realloc(\*ptr，size) 将ptr内存大小增大到size。 
free(void*ptr)：释放ptr所指向的一块内存空间。  


2、memcpy  
void *memcpy(void *str1, const void *str2, size_t n)   
从存储区 str2 复制 n 个字符到存储区 str1  


3、memcmp  
int memcmp (const void *s1, const void *s2, size_t n);
用来比较s1 和s2 所指的内存区间前n 个字符。  
若参数 s1 和 s2 所指的内存内容都完全相同则返回0 值。s1 若大于s2 则返回大于0 的值。s1 若小于s2 则返回小于0 的值。  

4、memmove  
用来复制内存内容  
void * memmove(void *dest, const void *src, size_t num);  
memmove() 与 memcpy() 类似都是用来复制 src 所指的内存内容前 num 个字节到 dest 所指的地址上。不同的是，memmove() 更为灵活，当src 和 dest 所指的内存区域重叠时，memmove() 仍然可以正确的处理，不过执行效率上会比使用 memcpy() 略慢些。  

5、点运算符 . 和箭头运算符 -> 的区别  
    两者都是二元操作符，而且右边的操作数都是成员的名称。  
    点运算符( . )的左边操作数是一个结果为结构的表达式；  
    箭头运算符( -> )的左边的操作数是一个指向结构体的指针。  
    
    

6、memset
memset() 函数用来将指定内存的前n个字节设置为特定的值：
    void * memset( void * ptr, int value, size_t num );
	ptr 为要操作的内存的指针。
	value 为要设置的值。可以向 value 传递 int 类型的值，也可以传递 char 类型的值，int 和 char 可以根据 ASCII 码相互转换。
	num 为 ptr 的前 num 个字节，size_t 就是unsigned int。


