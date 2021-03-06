

### 十、UDP协议

传输层比较重要的两个协议，TCP、UDP
区别：
1、TCP 是面向连接的，UDP 是面向无连接的。所谓建立连接，是为了在客户端和服务端维护连接，而建立一定的数据结构来维护双方交互的状态，用这样的数据结构来保证所谓的面向连接的特性。
2、TCP 提供可靠交付，通过TCP连接传输的数据，无差错、不丢失、不重复、并且按顺序到达。IP包是没有任何可靠性保证的，UDP继承了IP包的特性，不保证不丢失，不保证按顺序到达。
3、TCP是面向字节流的，发送的时候发的是一个流，没头没尾，IP包是一个个的IP包，UDP继承了IP的特性，基于数据报的，一个一个的发收。
4、TCP可以有拥塞控制的。UDP就不会。
5、TCP其实是一个有状态服务，有脑子的。UDP没有，发出去就发了。

网络传输是以包为单位，二层叫帧，网络层叫包，传输层叫段。我们笼统地称为包。包单独传输，自行选路，在不同的设备封装解封装，不保证到达。
UDP包头：
当发送的UDP包到达目标机器后，发现MAC地址匹配，就取下来，将剩下的包传给处理IP层的代码，把IP头取下来，发现目标IP匹配，进行处理，IP头里有个8位协议说明数据里面是TCP还是UDP，知道UDP头的格式，就能解析数据。
无论TCP还是UDP包头里应该有端口号，根据端口号，将数据交给相应的应用程序。
源端口号16位  目的端口号16位  UDP长度16位  UDP校验和16位  数据

UDP三大特点：沟通简单 轻信他人 不懂权变
UDP三大使用场景：
1、需要资源少，在网络情况比较好的内网，或者对于丢包不敏感的应用
2、不需要一对一沟通，建立连接，而是可以广播的应用
3、需要处理速度快，时延低，可以容忍少数丢包，但是要求即便网络拥塞，也毫不退缩，一往无前的时候

QUIC（全称Quick UDP Internet Connections，快速 UDP 互联网连接）是 Google 提出的一种基于 UDP 改进的通信协议，其目的是降低网络通信协议，其目的是降低网络通信的延迟，提供更好的用户互动体验。
流媒体的协议
实时游戏
IoT 物联网
移动通信领域

小结：
1、如果将 TCP 比作成熟的社会人，UDP 则是头脑简单的小朋友。TCP 复杂，UDP 简单；TCP 维护连接，UDP 谁都相信；TCP 会坚持知进退；UDP 愣头青一个，勇往直前
2、UDP 虽然简单，但它有简单的用法。它可以用在环境简单、需要多播、应用层自己控制传输的地方。例如 DHCP、VXLAN、、QUIC 等。



### 十一、TCP 协议（上）

TCP 包头格式，比 UDP 复杂的多。
源端口号16位  目的端口号16位  序号32位  确认序号32位  首部长度4位  保留位6位
URG ACK PSH RST SYN FIN   窗口大小16位  校验和16位 紧急指针16位 选项 数据
1、端口号，可知道应该发给哪个应用
2、序号，为了解决乱序的问题，确认哪个先来，哪个后到
3、确认序号，发出的包应有确认，没收到重新发，直到送达，
4、状态位。SYN 是发起一个连接，ACK 是回复，RST 是重新连接，FIN 是结束连接等。TCP面向连接的，双方要维护连接的状态，带状态位的包发送，会引起双方的状态变更。
5、窗口大小。TCP要做流量控制，窗口标识自己当前能够处理能力
顺序问题，稳重不乱
丢包问题，承诺靠谱
连接维护，有始有终
流量控制，把我分寸
拥塞控制，知进知退


<br>

TCP 三次握手：请求 - 应答 - 应答之应答
为何是三次，两次不靠谱，三次只是最优的办法，严格来说三十次都不能确定

三次握手除了双方建立连接外，主要还是为了沟通 TCP包的序号问题，A B 互相告诉，我这面发起的包的序号起始是从哪个号开始的
每个链接都要有不同的序号，随着时间变化，可看成32位计数器，每 4ms +1，IP 包头里有个 TTL 生存时间。
双方建立了信任，建立了链接，需要维护一个状态机。
<br>
![](https://github.com/MA806P/ComputerScienceNotes/blob/master/ComputerNetwork/Images/5-Transfer-Connect.jpg)

<br>

TCP 四次挥手
<br>
![](https://github.com/MA806P/ComputerScienceNotes/blob/master/ComputerNetwork/Images/5-Transfer-Disconnect.jpg)

断开的时候，当 A 说不玩了，就进入 FIN_WAIT_1 的状态，B 收到消息后，发送知道了。就进入 CLOSE_WAIT 的状态。
A 收到 ”B说知道了“ 就进入 FIN_WAIT_2 的状态。
如果B这时直接跑了，A将永远在这个状态，TCP协议没对这个状态处理，但Linux可以调整tcp_fin_timeout参数设置一个超时时间。
如果B没跑，发送了”B也不玩了“到A，A发送”知道B不玩了“的ACK后，从FIN_WAIT_2状态结束，为了防止最后的ACK B收不到，B要是收不到B会重新发一个”B不玩了“，为了防止这中情况，TCP协议要求A最后等待一段时间TIME_WAIT,这个时间要足够长，长到B没收到ACK的话，”B说不玩了“重发。
A不等待直接跑了，还有一个问题，A的端口就空出来了，但是B不知道，B还有很多包，可能还在路上，如A的端口被一个新的应用占用了，这个新的应用会收到B的发来的包，虽然序列号是重新生成的，但也要上个双保险防止产生混乱，因而也要等足够长的时间，等B的包都结束生命，再空出端口出来。

等待时间设置为 2MSL，Maximum Segment LifeTime 报文最大生存时间，是任何报文在网络上存在的最长时间，超过这个时间报文将被丢弃。TCP报文是基于 IP 协议的，IP头中有 TTL 域，是IP数据报可以经过的最大路由数，每经过一个路由器此值-1，当为0就丢弃，同时发送ICMP报文通知源主机。协议规定 MSL 为 2分钟，实际常用的 30s,1分钟，2分钟。

如果B超过2MSL依然没有收到A发的FIN的ACK，怎么办，当然B会重发FIN，A已经等了足够长的时间已跑了，A收到B重发的包后，直接发送RST，B就知道A早跑了。

<br>

TCP 状态机

![](https://github.com/MA806P/ComputerScienceNotes/blob/master/ComputerNetwork/Images/5-Transfer-status.jpg)

<br>

小结
1、TCP包头复杂，主要关注五个问题，顺序问题、丢包问题、连接维护、流量控制、拥塞控制
2、三次握手  四次挥手

如何在系统中查看某个连接的状态？
连接维护问题解决了。用什么数据结构来处理其他的四个问题




### 十二、TCP 协议（下）
出了网关，要保证传输的可靠性，需要各种重传的策略，包含大量的算法。

如何做个靠谱的人？
客户端发送一个包，服务器端应该有个回复，如果超时未回复，客户端重新发送
上一个收到了应答，再发送下一个。效率比较低。
可先将事情记录下来，办完一件回复一件。在处理事件的过程中可以向他交代新的事情，这样双方就能并行了。
事件多了就需要给每个事情编号，防止弄错。

如何实现一个靠谱的协议？
TCP 协议，为了保证顺序性，每个包都有一个 ID，建立连接的时候，商议起始的 ID 是什么，然后按照 ID 一个个发送，为了保证不丢包，对于发送的包都要进行应答，应答不是一个个来的，会应答某个之前的 ID，表示都收到了，这种模式称为累计确认或者累计应答。

为了记录发送的包和接收的包，TCP需要发送端和接收端分别都有缓存来保存这些记录。
发送端的缓存里是按照包的 ID 一个个排列，处理的情况分四部分：
第一部分，发送了并且已经确认的。
第二部分，发送了尚未确认。
第三部分，未发送，等待发送。
第四部分，未发送，暂时不会发送。
流量控制，把握分寸

在 TCP 里接收端会给发送端报一个窗口的大小 Advertised window 大小对应上面的第二部分和第三部分。
发送端：
LastByteAcked: 第一部分和第二部分分界线
LastByteSent: 二三分界线
LastByteAcked + AdvertisedWindow: 三四部分分界线
接收端：
第一部分：接收并且确认过的
第二部分：还没接收，马上就能接收的
第三部分：还没接收，也没法接收的。超过工作量，做不完。
MaxRcvBuffer: 最大换存量
LastByteRead: 之后都是已经接收了，但还没被应用层读取的
LastByteExpected: 一二分界线
NextByteExpected 和 LastByteRead 的差其实是还没被应用层读取的部分，占用掉的 MaxRcvBuffer 的量 A。
Advertised window = MaxRcvBuffer - A
Advertised window = MaxRcvBuffer - （NextByteExpected - 1 - LastByteRead）
二三部分分界线 = NextByteExpected + Advertised window = LastByteRead + MaxRcvBuffer



顺序问题与丢包问题
发送端：
1 2 3 已发送已确认。4 5 6 7 8 9 已发送未确认。10 11 12 还没发出。13 14 15 不准备发。

接收端：
1 2 3 4 5 完成ACK，没读取。6 7 等待接收。8 9 已接收，没有ACK

* 4 5 接收方说ACK了，但是发送方没收到，可能丢了，可能在路上。
* 8 9 已经到了，但 6 7 没到，出现了乱序，缓存着但是没办法ACK

确认与重发机制：
超时重试，对每个发送了，但是没有ACK的包，都设定一个定时器，超过了一定时间，重新发送。时间必须大于往返时间RTT，不宜过长 超时时间变长 访问变慢。
估计往返时间，需要TCP通过采样RTT的时间，进行加权平均，算出一个值，这个值根据网络状况不断地变化。除了采样RTT，还要采样RTT的波动范围，计算出一个估计的超时时间。重传时间是不断变化的，称为自适应重传算法。

发送端，一段时间后，5 6 7 都超时了，就会重新发送。接收端发现 5 原来接收过，于是丢弃 5，6 收下，发送 ACK，要求下一个是 7，7 又丢了，7 再次超时的时候，有需要重传的时候，TCP 策略是超时间加倍。每当遇到一次超时重传的时候，都会将下一次超时时间间隔设为先前的两倍。两次超时，就说明网络环境差，不宜频繁反复发送。



流量控制
在对包的确认中，同时会携带一个窗口的大小。
如果接收方处理太慢，导致缓存中没有空间，可以通过确认信息修改窗口的大小，设置可以设置为0，发送方将暂时停止发送。

拥塞控制
也是通过窗口的大小来控制的，前面的滑动窗口 rwnd 是怕发送方把接收方缓存塞满，而拥塞窗口 cwnd 是怕把网络塞满。
LastByteSent - LastByteAcked <= min {cwnd, rwnd}，拥塞窗口和滑动窗口共同控制发送的速度。
拥塞控制主要来避免两种现象，包丢失和超时重传。


小结：
* 顺序问题、丢包问题、流量控制都是通过滑动窗口来解决的，相当于领导和你的工作备忘录，工作有编号，干完了有反馈，活不能太多，也不能太少
* 拥塞控制是通过拥塞窗口来解决的，相当于网管道里倒水，快慢找到最优值。





### 十三、套接字 Socket
Socket 这个名字可以作插口或者插槽讲。客户端、服务端，在通信之前，双方都要建立一个 Socket，应该配置上面参数？Socket 编程进行的是端到端的通信，往往意识不到中间经过多少局域网，多少路由器，因而能够设置的参数，也只能是端到端协议上网络层和传输层的。
在网络层，Socket 函数需要指定到底是 IPv4 还是 IPv6，分别对应设置为 AF_INET 和 AF_INET6。还要指定是 TCP 还是 UDP。TCP协议是基于数据流的，设置为 SOCK_STREAM。UDP 是基于数据报的，设置为 SOCK_DGAM。

1、基于 TCP 协议的 Socket 程序函数调用过程
TCP的服务端要先监听一个端口，一般是先调用 bind 函数，给这个 Socket 赋予一个 IP 地址和端口。当服务端有了 IP 和端口号，就可以调用 listen 函数进行监听，进入 listen 状态，这时候客户端就可以发起连接了。
内核中改为每个 Socket 维护两个队列。一个是已经建立连接的队列，这时候三次握手已经完毕，处于 establish 状态；一个是还没有完全建立连接的队列，三次握手还没完成，处于 syn_rcvd 的状态。
接下来，服务端调用 accept 函数，拿出一个已经完成的连接进行处理。如果还没有完成，就要等着。在服务端等待的时候，客户端可以通过 connect 函数发起连接。先在参数中指明要连接的 IP 地址和端口号，然后开始发起三次握手。内核会给客户端分配一个临时的端口，一旦握手成功，服务端的 accept 就会返回另一个 Socket。
监听的Socket和真正用来传数据的Socket是两个，一个叫做监听Socket，一个叫做已连接Socket。
连接建立成功后，双方开始通过read和write函数来读写数据，就像往一个文件流里面写东西一样。
<br>
![](https://github.com/MA806P/ComputerScienceNotes/blob/master/ComputerNetwork/Images/5-Transfer-Socket-Connect.jpg)
TCP 的 Socket 就是一个文件流，Socket 在 Linux 中就是以文件的形式存在的。除此之外，还存在文件描述符，写入和读出，也是通过文件描述符。

在内核中，Socket是一个文件，对应就有文件描述符，每一个进程都有一个数据结构 task_struct 文件描述数组，列出这个进程打开的所有文件的文件描述符，是一个整数，是这个数组的下标。task_struct 数组中的内容是一个指针，指向内核中所有打开文件的列表。文件有一个inode，在 inode 中指向了Socket在内核中的Socket结构。这个结构里，主要是两个队列，一个是发送队列，一个是接收队列，在这两个队列里保存的是一个缓存 sk_buff，这个缓存里能看到完整的包的结构。
<br>
![](https://github.com/MA806P/ComputerScienceNotes/blob/master/ComputerNetwork/Images/5-Transfer-Socket-FileNode.jpg)

<br>

2、基于 UDP 协议的 Socket 程序函数调用过程
UDP 是没有连接的，所以不需要三次握手，也就不需要调用 listen 和 connect，但是 UDP 的交互任然需要 IP 和端口号，因而也需要 bind。
UDP 没有维护连接的状态，不需要每对连接建立一组 Socket ，而是只要有一个 Socket 就能够和多个客户端通信，没有连接状态，每次通信的时候都调用 sendto 和 recvfrom 都可以传入 IP 地址和端口。
<br>
![](https://github.com/MA806P/ComputerScienceNotes/blob/master/ComputerNetwork/Images/5-Transfer-Socket-UDPConnect.jpg)

<br>
3、服务器如何接更多的项目  
最大连接数，系统会用四个元组来标识一个 TCP 连接
{本机 IP, 本机端口, 对端 IP, 对端端口}
服务器通常固定在某个本地端口上监听，等待客户端的连接请求。
最大 TCP 连接数 = 客户端 IP 数 X客户端端口数 = 2^32 * 2^16 = 2^48
当然服务端最大并发 TCP 连接数远不能达到理论上限。首先主要是文件描述符限制，Socket 都是文件，所以首先要通过 ulimit 配置文件描述符的数目；另一个限制是内存，每个 TCP 连接都要占用一定内存，操作系统是有限的。要想接更多的项目就需要降低每个项目消耗的资源数目。<br>
a、多进程方式  
相当于你是一个代理，在那里监听来的请求，一旦建立了一个连接，就会有一个已连接 Socket ，这是可以创建一个子进程，然后将基于已连接 Socket 的交互交给这个新的子进程来做。  
b、多线程方式  
线程，相比于进程来说，轻量级的多  
c、IO 多路复用，一个线程维护多个 Socket  
由于 Socket 是文件描述符，因而某个线程管理的所有 Socket 都放在一个文件描述符集合 fd_set 中，项目进度墙，然后调用 select 函数来监听文件描述符集合是否有变化。有变化就会查看每个文件描述符，有变化的文件描述符在 fd_set 对应的位置都设为 1，表示 Socket 可读或者可写，从而可以进行读写操作，然后再调用 select 观察变化。  
d、IO 多路复用，有事通知  
项目组不需要通过轮询挨个盯着这些项目，而是当项目进度发生的时候，主动通知项目组，然后项目组再根据项目进展情况做相应的操作。
能完成这个的函数叫做 epoll 它在内核中的实现不是通过轮询的方式，而是通过注册 callBack 函数的方式，当某个文件描述符发生变化时，就会通知。

<br>

小结<br>
1、TCP UDP Socket 编程中，客户端 服务端 调用的函数  
2、能够支撑大量连接的高并发的服务端不容易，需要多进程、多线程， epoll 机制能解决 C10K 问题。







