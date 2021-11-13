# 第9部分-3.9.linux网络编程实践

***********《朱有鹏老师嵌入式linux核心课程》 ***********
《3.linux应用编程和网络编程-第9部分-3.9.linux网络编程实践》

--------------------------------------------------------
本课程由朱老师物联网大讲堂推出并提供技术支持，课件可打包下载
网盘地址：http://yunpan.cn/cjVy3RAgfDufK 访问密码 4ad7
技术交流QQ群：朱老师物联网讲堂1群 397164505
--------------------------------------------------------
第一部分、章节目录
3.9.1.linux网络编程框架
3.9.2.TCP协议的学习1
3.9.3.TCP协议的学习2
3.9.4.socket编程接口介绍
3.9.5.IP地址格式转换函数实践
3.9.6.soekct实践编程1
3.9.7.soekct实践编程2
3.9.8.socket实践编程3
3.9.9.socket编程实践4

第二部分、章节介绍
3.9.1.linux网络编程框架
	本节讲述网络编程的框架，分层思想和TCP/IP协议的介绍，BS架构和CS架构的介绍等。
3.9.2.TCP协议的学习1
	本节详细介绍TCP协议的特点，其中重点讲述了TCP协议保证实现可靠传输的机制。
3.9.3.TCP协议的学习2
	本节接上节继续讲解TCP协议，主要讲了TCP协议建立连接和关闭连接时的握手方法，最后讲了使用TCP来实现的常见应用层协议。
3.9.4.socket编程接口介绍
	本节介绍linux API中与网络编程相关的接口函数，后面的实战编程中都要用到这些函数。
3.9.5.IP地址格式转换函数实践
	本节通过代码实践来给大家演示IP地址格式转换的几个函数
3.9.6.soekct实践编程1
	本节开始编写基于TCP的客户端和服务器连接通信程序
3.9.7.soekct实践编程2
	本节接上节继续编写，并且已经实现客户端和服务器的连接。
3.9.8.socket实践编程3
	本节实现客户端和服务器之间的任意发送和接收、反复发送接收等功能
3.9.9.socket编程实践4	
	本节通过定义一个简单的应用层协议，来向大家介绍TCP连接建立后如何通过应用层协议来实现业务逻辑。
	

第三部分、随堂记录
3.9.1.linux网络编程框架
3.9.1.1、网络是分层的
(1)OSI 7层模型
(2)网络为什么要分层
(3)网络分层的具体表现
3.9.1.2、TCP/IP协议引入
(1)TCP/IP协议是用的最多的网络协议实现
(2)TCP/IP分为4层，对应OSI的7层

![%E7%AC%AC9%E9%83%A8%E5%88%86-3%209%20linux%E7%BD%91%E7%BB%9C%E7%BC%96%E7%A8%8B%E5%AE%9E%E8%B7%B5%20609114c7ea2f429486d7a78ea9454086/Untitled.png](%E7%AC%AC9%E9%83%A8%E5%88%86-3%209%20linux%E7%BD%91%E7%BB%9C%E7%BC%96%E7%A8%8B%E5%AE%9E%E8%B7%B5%20609114c7ea2f429486d7a78ea9454086/Untitled.png)

[https://blog.csdn.net/qq_38872310/article/details/79923253](https://blog.csdn.net/qq_38872310/article/details/79923253)
(3)我们编程时最关注应用层，了解传输层，网际互联层和网络接入层不用管
3.9.1.3、BS和CS
(1)CS架构介绍（client server，客户端服务器架构）
(2)BS架构介绍（broswer server，浏览器服务器架构）

3.9.2.TCP协议的学习1
3.9.2.1、关于TCP理解的重点
(1)TCP协议工作在传输层，对上服务socket接口（APP），对下调用IP层
(2)TCP协议面向连接（面向连接：打电话。非面向连接：对方qq离线也可以给他发送消息），通信前必须先3次握手建立连接关系后才能开始通信。
(3)TCP协议（一堆代码）提供可靠传输，不怕丢包、乱序等。

![%E7%AC%AC9%E9%83%A8%E5%88%86-3%209%20linux%E7%BD%91%E7%BB%9C%E7%BC%96%E7%A8%8B%E5%AE%9E%E8%B7%B5%20609114c7ea2f429486d7a78ea9454086/Untitled%201.png](%E7%AC%AC9%E9%83%A8%E5%88%86-3%209%20linux%E7%BD%91%E7%BB%9C%E7%BC%96%E7%A8%8B%E5%AE%9E%E8%B7%B5%20609114c7ea2f429486d7a78ea9454086/Untitled%201.png)

3.9.2.2、TCP如何保证可靠传输
(1)TCP在传输有效信息前要求通信双方必须先握手，建立连接才能通信（电话（建立连接才能通讯）和qq（不用建立通讯才能通讯））
(2)TCP的接收方收到数据包后会ack（反馈信号）给发送方，若发送方未收到ack会丢包重传
(3)TCP的有效数据内容会附带校验，以防止内容在传递过程中损坏
(4)TCP会根据网络带宽来自动调节适配速率（滑动窗口技术）（根据上一次收到包的效果（丢包率），来调整发送的时间和发送包的个数）
(5)发送方会给各分割报文编号，接收方会校验编号，一旦顺序错误即会重传。（每个包的顺序不会丢错）

3.9.3.TCP协议的学习2
3.9.3.1、TCP的三次握手
(1)建立连接需要三次握手
(2)建立连接的条件：服务器listen（监听）时客户端主动发起connect

![%E7%AC%AC9%E9%83%A8%E5%88%86-3%209%20linux%E7%BD%91%E7%BB%9C%E7%BC%96%E7%A8%8B%E5%AE%9E%E8%B7%B5%20609114c7ea2f429486d7a78ea9454086/Untitled%202.png](%E7%AC%AC9%E9%83%A8%E5%88%86-3%209%20linux%E7%BD%91%E7%BB%9C%E7%BC%96%E7%A8%8B%E5%AE%9E%E8%B7%B5%20609114c7ea2f429486d7a78ea9454086/Untitled%202.png)

[https://blog.csdn.net/qq_38950316/article/details/81087809](https://blog.csdn.net/qq_38950316/article/details/81087809)
3.9.3.2、TCP的四次握手
(3)关闭连接需要四次握手
(4)服务器或者客户端都可以主动发起关闭
注：这些握手协议已经封装在TCP协议内部，socket编程接口平时不用管

![%E7%AC%AC9%E9%83%A8%E5%88%86-3%209%20linux%E7%BD%91%E7%BB%9C%E7%BC%96%E7%A8%8B%E5%AE%9E%E8%B7%B5%20609114c7ea2f429486d7a78ea9454086/Untitled%203.png](%E7%AC%AC9%E9%83%A8%E5%88%86-3%209%20linux%E7%BD%91%E7%BB%9C%E7%BC%96%E7%A8%8B%E5%AE%9E%E8%B7%B5%20609114c7ea2f429486d7a78ea9454086/Untitled%203.png)

[https://blog.csdn.net/qq_38950316/article/details/81087809](https://blog.csdn.net/qq_38950316/article/details/81087809)
3.9.3.3、基于TCP通信的服务模式
(1)具有公网IP地址的服务器（或者使用动态IP地址映射技术）
(2)服务器端socket、bind、listen后处于监听状态
(3)客户端socket后，直接connect去发起连接。
(4)服务器收到并同意客户端接入后会建立TCP连接，然后双方开始收发数据，收发时是双向的，而且双方均可发起
(5)双方均可发起关闭连接
3.9.3.4、常见的使用了TCP协议的网络应用
(1)http（底层是TCP协议）、ftp
(2)QQ服务器
(3)mail服务器

3.9.4.socket编程接口介绍
3.9.4.1、建立连接
(1)socket。socket函数类似于open，用来打开一个网络连接，如果成功则返回一个网络文件描述符（int类型），之后我们操作这个网络连接都通过这个网络文件描述符。
(2)bind
(3)listen
(4)connect
3.9.4.3、发送和接收
(1)send和write
(2)recv和read
3.9.4.4、辅助性函数

```c
(1)inet_aton、inet_addr、inet_ntoa
(2)inet_ntop（net（32位二进制IP地址） to p(字符串，点分十进制)）、inet_pton
3.9.4.5、表示IP地址相关数据结构
(1)都定义在 netinet/in.h
(2)struct sockaddr，这个结构体是网络编程接口中用来表示一个IP地址的，注意这个IP地址是
不区分IPv4和IPv6的（或者说是兼容IPv4和IPv6的）
(3)typedef uint32_t in_addr_t;		网络内部用来表示IP地址的类型
(4)struct in_addr
  {
    in_addr_t s_addr;
  };
(5)struct sockaddr_in //ipv4   ipv6  struct sockaddr_in6
  {
    __SOCKADDR_COMMON (sin_);           /* sin_family */
    in_port_t sin_port;                 /* Port number.  */
    struct in_addr sin_addr;            /* Internet address.  */

    /* Pad to size of `struct sockaddr'.  */
    unsigned char sin_zero[sizeof (struct sockaddr) -
                           __SOCKADDR_COMMON_SIZE -
                           sizeof (in_port_t) -
                           sizeof (struct in_addr)];
  };
(6)struct sockaddr			这个结构体是linux的网络编程接口中用来表示IP地址的标准结构体，
bind、connect等函数中都需要这个结构体，这个结构体是兼容IPV4和IPV6的。在实际编程中这个
结构体会被一个struct sockaddr_in或者一个struct sockaddr_in6所填充。

```

3.9.5.IP地址格式转换函数实践
3.9.5.1、inet_addr、inet_ntoa、inet_aton
3.9.5.2、inet_pton、inet_ntop

?
3.9.6_7.soekct实践编程1_2 
3.9.6.1、服务器端程序编写
(1)socket
(2)bind
(3)listen
(4)accept，返回值是一个fd，accept正确返回就表示我们已经和前来连接我的客户端之间建立了一个TCP连接了，以后我们就要通过这个连接来和客户端进行读写操作，读写操作就需要一个fd，这个fd就由accept来返回了。
注意：socket返回的fd叫做监听fd，是用来监听客户端的，不能用来和任何客户端进行读写；accept返回的fd叫做连接fd，用来和连接那端的客户端程序进行读写。
3.9.6.2、客户端程序编写
(1)socket
(2)connect

概念：端口号，实质就是一个数字编号，用来在我们一台主机中（主机的操作系统中）唯一的标识一个能上网的进程。端口号和IP地址一起会被打包到当前进程发出或者接收到的每一个数据包中。每一个数据包将来在网络上传递的时候，内部都包含了发送方和接收方的信息（就是IP地址和端口号），所以IP地址和端口号这两个往往是打包在一起不分家的。

3.9.8.socket实践编程3
3.9.8.1、客户端发送&服务器接收
3.9.8.2、服务器发送&客户端接收
3.9.8.3、探讨：如何让服务器和客户端好好沟通
(1)客户端和服务器原则上都可以任意的发和收，但是实际上双方必须配合：client发的时候server就收，而server发的时候client就收
(2)必须了解到的一点：client和server之间的通信是异步的，这就是问题的根源
(3)解决方案：依靠应用层协议来解决。说白了就是我们server和client事先做好一系列的通信约定。

3.9.9.socket编程实践4
3.9.9.1、自定义应用层协议第一步：规定发送和接收方法
(1)规定连接建立后由客户端主动向服务器发出1个请求数据包，然后服务器收到数据包后回复客户端一个回应数据包，这就是一个通信回合
(2)整个连接的通信就是由N多个回合组成的。

3.9.9.2、自定义应用层协议第二步：定义数据包格式
3.9.9.3、常用应用层协议：http、ftp······
3.9.9.4、UDP简介
非连接，不可靠

![%E7%AC%AC9%E9%83%A8%E5%88%86-3%209%20linux%E7%BD%91%E7%BB%9C%E7%BC%96%E7%A8%8B%E5%AE%9E%E8%B7%B5%20609114c7ea2f429486d7a78ea9454086/Untitled%204.png](%E7%AC%AC9%E9%83%A8%E5%88%86-3%209%20linux%E7%BD%91%E7%BB%9C%E7%BC%96%E7%A8%8B%E5%AE%9E%E8%B7%B5%20609114c7ea2f429486d7a78ea9454086/Untitled%204.png)