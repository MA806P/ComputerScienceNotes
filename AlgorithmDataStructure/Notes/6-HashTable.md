
### 散列表 (Hash Table)

散列表用的是数组支持按照下标随机访问数据的特性，所以散列表其实就是数组的一种扩展，由数组演化而来。可以说，如果没有数组，就没有散列表。  

编号：键key 或者 关键字  
把编号转化为数组下标的映射方法叫作，散列函数 或者 Hash函数  
散列函数计算得到的值叫作，散列值 或者 Hash值  

如果关键字是随机的数字、字符串，怎么构造散列函数？
散列函数设计的基本要求：  
1、散列函数计算得到的散列值是一个非负整数；   
2、如果 key1 = key2，那 hash(key1) == hash(key2)；   
3、如果 key1 ≠ key2，那 hash(key1) ≠ hash(key2)。  
在真实的情况下，要想找到一个不同的 key 对应的散列值都不一样的散列函数，几乎是不可能的。即便像业界著名的MD5、SHA、CRC等哈希算法，也无法完全避免这种散列冲突。而且，因为数组的存储空间有限，也会加大散列冲突的概率。
我们几乎无法找到一个完美的无冲突的散列函数，即便能找到，付出的时间、计算成本也是很大的，需要通过其他途径来解决。  


散列冲突，解决方法：  
1、开放寻址法   
如果出现了散列冲突，我们就重新探测一个空闲位置，将其插入。  
那如何重新探测新的位置呢？  
一个比较简单的探测方法，线性探测。当我们往散列表中插入数据时，如果某个数据经过散列函数散列之后，存储位置已经被占用了，我们就从当前位置开始，依次往后查找，看是否有空闲位置，直到找到为止。  

在散列表中查找元素的过程有点儿类似插入过程。我们通过散列函数求出要查找元素的键值对应的散列值，然后比较数组中下标为散列值的元素和要查找的元素。如果相等，则说明就是我们要找的元素；否则就顺序往后依次查找。如果遍历到数组中的空闲位置，还没有找到，就说明要查找的元素并没有在散列表中。  

散列表跟数组一样，不仅支持插入、查找操作，还支持删除操作。删除操作稍微有些特别。我们不能单纯地把要删除的元素设置为空。如果这个空闲位置是我们后来删除的，就会导致原来的查找算法失效。本来存在的数据，会被认定为不存在。可以将删除的元素，特殊标记为 deleted。当线性探测查找的时候，遇到标记为 deleted 的空间，并不是停下来，而是继续往下探测。  

线性探测法其实存在很大问题。当散列表中插入的数据越来越多时，散列冲突发生的可能性就会越来越大，空闲位置会越来越少，线性探测的时间就会越来越久。极端情况下，我们可能需要探测整个散列表，所以最坏情况下的时间复杂度为 O(n)。同理，在删除和查找时，也有可能会线性探测整张散列表，才能找到要查找或者删除的数据。  


2、二次探测  
跟线性探测很像，线性探测每次探测的步长是 1，那它探测的下标序列就是 hash(key)+0，hash(key)+1，hash(key)+2……而二次探测探测的步长就变成了原来的“二次方”，也就是说，它探测的下标序列就是 hash(key)+0，hash(key)+12，hash(key)+22……


3、双重散列  
不仅要使用一个散列函数。我们使用一组散列函数 hash1(key)，hash2(key)，hash3(key)……我们先用第一个散列函数，如果计算得到的存储位置已经被占用，再用第二个散列函数，依次类推，直到找到空闲的存储位置。  



不管采用哪种探测方法，当散列表中空闲位置不多的时候，散列冲突的概率就会大大提高。为了尽可能保证散列表的操作效率，一般情况下，我们会尽可能保证散列表中有一定比例的空闲槽位。我们用装载因子（load factor）来表示空位的多少。   
装载因子的计算公式是： 散列表的装载因子 = 填入表中的元素个数 / 散列表的长度  
装载因子越大，说明空闲位置越小，冲突越多，散列表的性能会下降。  


4、链表法  
一种更加常用的散列冲突解决办法，在散列表中，每个桶或者槽会对应一条链表，所有散列值相同的元素都放到相同槽位对应的链表中。  
当插入的时候，我们只需要通过散列函数计算出对应的散列槽位，将其插入到对应链表中即可，所以插入的时间复杂度是 O(1)。当查找、删除一个元素时，我们同样通过散列函数计算出对应的槽，然后遍历链表查找或者删除。查找、删除操作时间复杂度 O(k)。  























