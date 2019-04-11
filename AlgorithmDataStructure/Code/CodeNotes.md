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




