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
	
	  
	   
7、abort()  
C 库函数 void abort(void) 终止程序执行，直接从调用的地方跳出。  


8、realloc：
函数简介
　　原型：extern void *realloc(void *mem_address, unsigned int newsize);
　　语法：指针名=（数据类型*）realloc（要改变内存大小的指针名，新的大小）。//新的大小一定要大于原来的大小不然的话会导致数据丢失！
　　头文件：#include <stdlib.h> 有些编译器需要#include <malloc.h>，在TC2.0中可以使用alloc.h头文件
　　功能：先判断当前的指针是否有足够的连续空间，如果有，扩大mem_address指向的地址，并且将mem_address返回，如果空间不够，先按照newsize指定的大小分配空间，将原有数据从头到尾拷贝到新分配的内存区域，而后释放原来mem_address所指内存区域，同时返回新分配的内存区域的首地址。即重新分配存储器块的地址。
　　返回值：如果重新分配成功则返回指向被分配内存的指针，否则返回空指针NULL。　
　　注意：这里原始内存中的数据还是保持不变的。当内存不再使用时，应使用free()函数将内存块释放。




8、srandom((unsigned int)time(NULL));  
void srand(unsigned seed);  
它初始化随机种子，会提供一个种子，这个种子会对应一个随机数，如果使用相同的种子后面的rand()函数会出现一样的随机数，如: srand(1); 直接使用1来初始化种子。不过为了防止随机数每次重复，常常使用系统时间来初始化.  
计算机并不能产生真正的随机数，而是已经编写好的一些无规则排列的数字存储在电脑里，把这些数字划分为若干相等的N份，并为每份加上一个编号用srand()函数获取这个编号，然后rand()就按顺序获取这些数字，当srand()的参数值固定的时候，rand()获得的数也是固定的，所以一般srand的参数用time(NULL)，因为系统的时间一直在变，所以rand()获得的数，也就一直在变，相当于是随机数了。只要用户或第三方不设置随机种子，那么在默认情况下随机种子来自系统时钟。如果想在一个程序中生成随机数序列，需要至多在生成随机数之前设置一次随机种子。 即：只需在主程序开始处调用srand((unsigned)time(NULL)); 后面直接用rand就可以了。  



9、sprintf
int sprintf(char *str, const char *format, ...) 发送格式化输出到 str 所指向的字符串
返回值是 拼接后的字符串长度
char str[80];
sprintf(str, "Pi 的值 = %f", M_PI);
str = Pi 的值 = 3.141593





字符串
1、字符串截取
char dest[4] = "";
char src[] = "123456789";
strncpy(dest, src+3, 3);
puts(dest); //456

2、字符串比较
    char *a = "ad";
    char *b = "ad";
    printf("%d", strcmp(a, b));
    // ab ac -1
    // ad ac 1
    // ad ad 0

3、字符串拼接
    char *a = "ab";
    char *b = "ac";
    char *c = malloc(10 * sizeof(char));
    strcpy(c, a);
    strcat(c, b);
    printf("%s\n", c); //abac


