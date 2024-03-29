# 第4部分-3.4.linux进程全解

***********《朱有鹏老师嵌入式linux核心课程》 ***********
《3.linux应用编程和网络编程-第4部分-3.4.linux进程全解》

--------------------------------------------------------
本课程由朱老师物联网大讲堂推出并提供技术支持，课件可打包下载
网盘地址：http://yunpan.cn/cjVy3RAgfDufK 访问密码 4ad7
技术交流QQ群：朱老师物联网讲堂1群 397164505
--------------------------------------------------------
第一部分、章节目录
3.4.1.程序的开始和结束
3.4.2.进程环境
3.4.3.进程的正式引入
3.4.4.fork创建子进程
3.4.5.父子进程对文件的操作
3.4.6.进程的诞生和消亡
3.4.7.父进程wait回收子进程
3.4.8.waitpid介绍
3.4.9.exec族函数及实战1
3.4.10.exec族函数及实战2
3.4.11.进程状态和system函数
3.4.12.进程关系
3.4.13.守护进程的引入
3.4.14.编写简单守护进程
3.4.15.使用syslog来记录调试信息
3.4.16.让程序不能被多次运行
3.4.17.linux的进程间通信概述
3.4.18.linux的IPC机制1-管道
3.4.19.SystemV IPC介绍

第二部分、章节介绍
3.4.1.程序的开始和结束
	本节讲述一个典型程序的开始运行和结束运行，引入引导代码让大家更容易的理解操作系统是如何运行一个程序的。
3.4.2.进程环境
	本节讲解进程的环境变量和虚拟地址空间，这些都是一个进程在系统中运行时的外部环境。
3.4.3.进程的正式引入
	本节正式引入进程的概念，讲述了进程的ID以及获取进程ID的函数，多进程调度实现宏观上并行的原理。
3.4.4.fork创建子进程
	本节引入子进程，并且讲解并实战演示了fork函数如何创建子进程。
3.4.5.父子进程对文件的操作
	本节通过父子进程对文件的操作来说明父子进程的区别和联系。
3.4.6.进程的诞生和消亡
	本节讲述进程的诞生和消亡过程，着重讲了僵尸进程和孤儿进程的概念，进程资源回收和状态返回等。
3.4.7.父进程wait回收子进程
	本节讲解wait函数回收子进程的信号式异步通信工作原理，并且实战演练了使用wait来回收子进程的过程。
3.4.8.waitpid介绍
	本节首先介绍waitpid和wait函数的差别，然后实战演示了waitpid函数的3种常见用法，最后简单讲解了竟态的概念。
3.4.9.exec族函数及实战1
	本节开始讲解exec族函数的作用和各个API的差异，并且写代码进行演示。
3.4.10.exec族函数及实战2
	本节演示了exec族的p后缀和e后缀函数的用法。
3.4.11.进程状态和system函数
	本节详细讲解了linux中进程的5种状态和状态转换图，最后讲了下system函数
3.4.12.进程关系
	本节讲解进程的四种关系：无关系、父子关系、进程组和会话。
3.4.13.守护进程的引入
	本节引入守护进程的概念，并且介绍了常见的一些系统级服务器守护进程及其作用。
3.4.14.编写简单守护进程
	本节实践编程自己实现一个守护进程，让大家熟悉守护进程的创建过程。
3.4.15.使用syslog来记录调试信息
	本节讲解如何在程序中使用syslog记录日志信息，这是一种非常常见的程序调试信息输出手段，也是守护进程必用的调试信息输出手段。
3.4.16.让程序不能被多次运行
	本节介绍如何让我们的程序只能运行一次，即所谓单例运行的常规实现方法。这个在实际工作中很有用。
3.4.17.linux的进程间通信概述
	本节进行linux中进程间通信IPC的概述，指明了后面如何讲解IPC。
3.4.18.linux的IPC机制1-管道
	本节详细讲了传统Unix的进程间通信方法：管道和有名管道。
3.4.19.SystemV IPC介绍	
	本节对SystemV IPC的三种（信号量、消息队列、共享内存）方式进行概括性讲解和对比。
	

第三部分、随堂记录
3.4.1.程序的开始和结束
3.4.1.1、main函数由谁调用
(1)编译链接时的引导代码。操作系统下的应用程序其实在main执行前也需要先执行一段引导代码才能去执行main，我们写应用程序时不用考虑引导代码的问题，编译连接时（准确说是连接时）由链接器将编译器中事先准备好的引导代码给连接进去和我们的应用程序一起构成最终的可执行程序。
(2)运行时的加载器。加载器是操作系统中的程序，当我们去执行一个程序时（譬如./a.out，譬如代码中用exec族函数来运行）加载器负责将这个程序加载到内存中去执行这个程序。
(3)程序在编译连接时用链接器，运行时用加载器，这两个东西对程序运行原理非常重要。
(4)argc和argv的传参如何实现

3.4.1.2、程序如何结束
(1)正常终止：return（main函数）、exit、_exit
(2)非正常终止：自己或他人发信号（打电话）终止进程
ctrl + C   终止信号
3.4.1.3、atexit注册进程终止处理函数
(1)实验演示
(2)atexit注册多个进程终止处理函数，先注册的后执行（先进后出，和栈一样）（用栈来处理的）
(2)return、exit和_exit的区别：return和exit效果一样，都是会执行进程终止处理函数，但是用_exit终止进程时并不执行atexit注册的进程终止处理函数。

3.4.2.进程环境
3.4.2.1、环境变量（几乎可以理解为操作系统的全局变量）
(1)export命令查看环境变量
(2)进程环境表介绍.每一个进程中都有一份所有环境变量构成的一个表格，也就是说我们当前进程中可以直接使用这些环境变量。进程环境表其实是一个字符串数组，用environ变量指向它。
(3)程序中通过environ全局变量使用环境变量
(4)我们写的程序中可以无条件直接使用系统中的环境变量，所以一旦程序中用到了环境变量那么程序就和操作系统环境有关了。
(4)获取指定环境变量函数getenv
日期：12月22日

3.4.2.2、进程运行的虚拟地址空间
(1)操作系统中每个进程在独立地址空间中运行
(2)每个进程的逻辑地址空间均为4GB（32位系统）
(3)0-1G为OS，1-4G为应用
(4)虚拟地址到物理地址空间的映射
(5)意义。进程隔离，提供多进程同时运行

3.4.3.进程的正式引入
3.4.3.1、什么是进程
(1)动态过程而不是静态实物
(2)进程就是程序的一次运行过程，一个静态的可执行程序a.out的一次运行过程（./a.out去运行到结束）就是一个进程。
(3)进程控制块PCB（process control block），内核中专门用来管理一个进程的数据结构（记录各种信息）。

3.4.3.2、进程ID（与文件描述符很像）（标识进程）
(1)getpid(进程ID)、getppid(p:parent ID)、getuid（user ID）、geteuid（有效user ID）、getgid（group ID）、getegid（有效group ID）
(2)实际用户ID和有效用户ID区别（可百度）

> ps 
   PID TTY          TIME CMD
  7153 pts/1    00:00:00 bash
  7976 pts/1    00:00:00 ps
ps -aux
USER PID %CPU %MEM VSZ RSS TTY STAT START TIME COMMAND
root 1 0.0 0.4 185452 4180 ? Ss 01:27 0:02 /sbin/init splash
root 2 0.0 0.0 0 0 ? S 01:27 0:00 [kthreadd]
root 4 0.0 0.0 0 0 ? I< 01:27 0:00 [kworker/0:0H]
> 

3.4.3.3、多进程调度原理
(1)操作系统同时运行多个进程
(2)宏观上的并行和微观上的串行
(3)实际上现代操作系统最小的调度单元是线程而不是进程

3.4.4.fork创建子进程
3.4.4.1、为什么要创建子进程
(1)每一次程序的运行都需要一个进程
(2)多进程实现宏观上的并行

3.4.4.2、fork的内部原理
(1)进程的分裂生长模式。如果操作系统需要一个新进程来运行一个程序，那么操作系统会用一个现有的进程来复制生成一个新进程。老进程叫父进程，复制生成的新进程叫子进程。
(2)fork的演示
(3)fork函数调用一次会返回2次，返回值等于0的就是子进程，而返回值大于0的就是父进程。
(4)典型的使用fork的方法：使用fork后然后用if判断返回值，并且返回值大于0时就是父进程，等于0时就是子进程。
(5)fork的返回值在子进程中等于0，在父进程中等于本次fork创建的子进程的进程ID。

3.4.4.3、关于子进程
(1)子进程和父进程的关系
(2)子进程有自己独立的PCB
(3)子进程被内核同等调度
ps -aux | grep "1"

3.4.5.父子进程对文件的操作
3.4.5.1、子进程继承父进程中打开的文件
(1)上下文：父进程先open打开一个文件得到fd，然后在fork创建子进程。之后在父子进程中各自write向fd中写入内容
(2)测试结论是：接续写。实际上本质原因是父子进程之间的fd对应的文件指针是彼此关联的（很像O_APPEND标志后的样子）
(3)实际测试时有时候会看到只有一个，有点像分别写。但是实际不是，原因是

3.4.5.2、父子进程各自独立打开同一文件实现共享
(1)父进程open打开1.txt然后写入，子进程打开1.txt然后写入，结论是：分别写。原因是父子进程分离后才各自打开的1.txt，这时候这两个进程的PCB已经独立了，文件表也独立了，因此2次读写是完全独立的。
(2)open时使用O_APPEND标志看看会如何？实际测试结果标明O_APPEND标志可以把父子进程各自独立打开的fd的文件指针给关联起来，实现分别写。

3.4.5.3、总结
(1)父子进程间终究多了一些牵绊
(2)父进程在没有fork之前自己做的事情对子进程有很大影响，但是父进程fork之后在自己的if里做的事情就对子进程没有影响了。本质原因就是因为fork内部实际上已经复制父进程的PCB生成了一个新的子进程，并且fork返回时子进程已经完全和父进程脱离并且独立被OS调度执行。
(2)子进程最终目的是要独立去运行另外的程序

3.4.6.进程的诞生和消亡
3.4.6.1、进程的诞生
(1)进程0和进程1
(2)fork
(3)vfork
3.4.6.2、进程的消亡
(1)正常终止和异常终止
(2)进程在运行时需要消耗系统资源（内存（堆内存、栈内存）、IO(读写通讯)），进程终止时理应完全释放这些资源（如果进程消亡后仍然没有释放相应资源则这些资源就丢失了）
(3)linux系统设计时规定：每一个进程退出时，操作系统会自动回收这个进程涉及到的所有的资源(***第一种***)（譬如malloc申请的内容没有free时，当前进程结束时这个内存会被释放，譬如open打开的文件没有close的在程序终止时也会被关闭）。但是操作系统只是回收了这个进程工作时消耗的内存和IO，而并没有回收这个进程本身占用的内存（***第二种***）（8KB，主要是task_struct(进程pcb结构（描述进程）(如fork产生，而不是))和栈内存）（这两种分开回收进程）
(4)因为进程本身的8KB内存操作系统不能回收需要别人来辅助回收，因此我们每个进程都需要一个帮助它收尸的人，这个人就是这个进程的父进程。

3.4.6.3、僵尸进程
(1)子进程先于父进程结束。子进程结束后父进程此时并不一定立即就能帮子进程“收尸”，在这一段（子进程已经结束且父进程尚未帮其收尸）子进程就被成为僵尸进程。
(2)子进程除task_struct和栈外其余内存空间皆已清理
(3)父进程可以使用wait或waitpid以显式回收子进程的剩余待回收内存资源并且获取子进程退出状态。
(4)父进程也可以不使用wait或者waitpid回收子进程，此时父进程结束时一样会回收子进程的剩余待回收内存资源。（这样设计是为了防止父进程忘记显式调用wait/waitpid来回收子进程从而造成内存泄漏）
3.4.6.4、孤儿进程
(1)父进程先于子进程结束，子进程成为一个孤儿进程。
(2)linux系统规定：所有的孤儿进程都自动成为一个特殊进程（进程1，也就是init进程）的子进程。

3.4.7.父进程wait回收子进程
3.4.7.1、wait的工作原理
(1)子进程结束时，系统向其父进程发送SIGCHILD信号
(2)父进程调用wait函数后阻塞（等待SIGCHILD）
(3)父进程被SIGCHILD信号唤醒然后去回收僵尸子进程
(4)父子进程之间是异步的，SIGCHILD信号机制就是为了解决父子进程之间的异步通信问题，让父进程可以及时的去回收僵尸子进程。
(5)若父进程没有任何子进程则wait返回错误
3.4.7.2、wait实战编程
(1)wait的参数status。status用来返回子进程结束时的状态，父进程通过wait得到status后就可以知道子进程的一些结束状态信息。

(2)wait的返回值pid_t，这个返回值就是本次wait回收的子进程的PID。当前进程有可能有多个子进程，wait函数阻塞直到其中一个子进程结束wait就会返回，wait的返回值就可以用来判断到底是哪一个子进程本次被回收了。
对wait做个总结：wait主要是用来回收子进程资源，回收同时还可以得知被回收子进程的pid和退出状态。

(3)fork后wait回收实例
(4)WIFEXITED、WIFSIGNALED、WEXITSTATUS这几个宏用来获取子进程的退出状态。
WIFEXITED宏用来判断子进程是否正常终止（return、exit、_exit退出）
       WIFEXITED(status)
       returns  true  if  the  child  terminated normally, that is, by calling exit(3) or _exit(2), or by returning from main().
WIFSIGNALED宏用来判断子进程是否非正常终止（被信号所终止）
       returns true if the child process was terminated by a signal.
WEXITSTATUS宏用来得到正常终止情况下的进程返回值的。
       returns the exit status of the child.  This consists of the  least  significant  8 bits  of  the  status  argument  that  the child specified in a call to exit(3) or  _exit(2) or as the argument for a return statement in main().  This  macro  should be employed only if WIFEXITED returned true.

3.4.8.waitpid介绍
3.4.8.1、waitpid和wait差别
(1)基本功能一样，都是用来回收子进程
(2)waitpid可以回收指定PID的子进程
(3)waitpid可以阻塞式或非阻塞式两种工作模式
3.4.8.2、waitpid原型介绍
(1)参数
(2)返回值
3.4.8.3、代码实例
(1)使用waitpid实现wait的效果
ret = waitpid(-1, &status, 0);  	-1表示不等待某个特定PID的子进程而是回收任意一个子进程，0表示用默认的方式（阻塞式）来进行等待，返回值ret是本次回收的子进程的PID
(2)ret = waitpid(pid, &status, 0);		等待回收PID为pid的这个子进程，如果当前进程并没有一个ID号为pid的子进程，则返回值为-1；如果成功回收了pid这个子进程则返回值为回收的进程的PID
(3)ret = waitpid(pid, &status, WNOHANG);这种表示父进程要非阻塞式的回收子进程。此时如果父进程执行waitpid时子进程已经先结束等待回收则waitpid直接回收成功，返回值是回收的子进程的PID；如果父进程waitpid时子进程尚未结束则父进程立刻返回（非阻塞），但是返回值为0（表示回收不成功）。

3.4.8.4、竟态初步引入
(1)竟态全称是：竞争状态，多进程环境下，多个进程同时抢占系统资源（内存、CPU、文件IO）
(2)竞争状态对OS来说是很危险的，此时OS如果没处理好就会造成结果不确定。(父、子进程先后)
(3)写程序当然不希望程序运行的结果不确定，所以我们写程序时要尽量消灭竞争状态。操作系统给我们提供了一系列的消灭竟态的机制，我们需要做的是在合适的地方使用合适的方法来消灭竟态。

如何杀死当前进程
两种方法：一关掉父进程，二信号杀死当前进程
ps 查看当前程序pid
kill -9 pid（杀死当前程序）

3.4.9.exec族函数及实战1
3.4.9.1、为什么需要exec函数
(1)fork子进程是为了执行新程序(fork创建了子进程后，子进程和父进程同时被OS调度执行，因此子进程可以单独的执行一个程序，这个程序宏观上将会和父进程程序同时进行)
(2)可以直接在子进程的if中写入新程序的代码。这样可以，但是不够灵活，因为我们只能把子进程程序的源代码贴过来执行（必须知道源代码，而且源代码太长了也不好控制），譬如说我们希望子进程来执行ls -la 命令就不行了（没有源代码，只有编译好的可执行程序）
(3)使用exec族运行新的可执行程序（exec族函数可以直接把一个编译好的可执行程序直接加载运行）
(4)我们有了exec族函数后，我们典型的父子进程程序是这样的：子进程需要运行的程序被单独编写、单独编译连接成一个可执行程序（叫hello），（项目是一个多进程项目）主程序为父进程，fork创建了子进程后在子进程中exec来执行hello，达到父子进程分别做不同程序同时（宏观上）运行的效果。通过exec调用另一个程序，多进程项目
3.4.9.2、exec族的6个函数介绍
(1)execl和execv 	这两个函数是最基本的exec，都可以用来执行一个程序，区别是传参的格式不同。execl是把参数列表（本质上是多个字符串，必须以NULL结尾）依次排列而成（l其实就是list的缩写），execv是把参数列表事先放入一个字符串数组中，再把这个字符串数组传给execv函数。
(2)execlp和execvp	这两个函数在上面2个基础上加了p，较上面2个来说，区别是：上面2个执行程序时必须指定可执行程序的全路径（如果exec没有找到path这个文件则直接报错），而加了p的传递的可以是file（也可以是path，只不过兼容了file。加了p的这两个函数会首先去找file，如果找到则执行执行，如果没找到则会去环境变量PATH所指定的目录下去找，如果找到则执行如果没找到则报错）
(3)execle和execvpe	这两个函数较基本exec来说加了e，函数的参数列表中也多了一个字符串数组envp形参，e就是environment环境变量的意思，和基本版本的exec的区别就是：执行可执行程序时会多传一个环境变量的字符串数组给待执行的程序。
3.4.9.3、exec实战1
(1)使用execl运行ls -l -a
(2)使用execv运行ls
(3)使用execl运行自己写的程序

int execl(const char *path, const char *arg, ... /* (char  *) NULL */);
int execv(const char *path, char *const argv[]); //数组本身是const 不可改，指向的内容可以改
int execlp(const char *file, const char *arg, ... /* (char  *) NULL */);
int execle(const char *path, const char *arg, ... /*, (char *) NULL, char * const envp[] */);
int execvpe(const char *file, char *const argv[],  char *const envp[]);

3.4.10.exec族函数及实战2
3.4.10.1、execlp和execvp
(1)加p和不加p的区别是：不加p时需要全部路径+文件名，如果找不到就报错了。加了p之后会多帮我们到PATH所指定的路径下去找一下。
打印环境变量：$PATH

3.4.10.2、execle和execvpe(e:environment )
(1)main函数的原型其实不止是int main(int argc, char **argv)，而可以是
int main(int argc, char **argv, char **env)	第三个参数是一个字符串数组，内容是环境变量。
(2)如果用户在执行这个程序时没有传递第三个参数，则程序会自动从父进程继承一份环境变量（默认的，最早来源于OS中的环境变量）；如果我们exec的时候使用execlp或者execvpe去给传一个envp数组，则程序中的实际环境变量是我们传递的这一份（取代了默认的从父进程继承来的那一份）

3.4.11.进程状态和system函数
3.4.11.1、进程的5种状态
(1)就绪态。这个进程当前所有运行条件就绪，只要得到了CPU时间（调度）就能直接运行。
(2)运行态。就绪态时得到了CPU就进入运行态开始运行(宏观并行)。
(3)僵尸态。进程已经结束但是父进程还没来得及回收
(4)等待态（浅度睡眠&深度睡眠），进程在等待某种条件，条件成熟后可进入就绪态。等待态下就算你给他CPU调度进程也无法执行。浅度睡眠等待时进程可以被（信号）唤醒，而深度睡眠等待时不能被唤醒只能等待的条件到了才能结束睡眠状态。
(5)暂停态。暂停并不是进程的终止，只是被被人（信号）暂停了，还可以回复的。
3.4.11.2、进程各种状态之间的转换图

![%E7%AC%AC4%E9%83%A8%E5%88%86-3%204%20linux%E8%BF%9B%E7%A8%8B%E5%85%A8%E8%A7%A3%204d46a2a427a44189bdc288867c5d671a/Untitled.png](%E7%AC%AC4%E9%83%A8%E5%88%86-3%204%20linux%E8%BF%9B%E7%A8%8B%E5%85%A8%E8%A7%A3%204d46a2a427a44189bdc288867c5d671a/Untitled.png)

3.4.11.3、system函数简介
(1)system函数（原子操作） = fork+exec（创建子进程，并执行程序）
(1)原子操作。原子操作意思就是整个操作一旦开始就会不被打断的执行完。原子操作的好处就是不会被人打断（不会引来竞争状态），坏处是自己单独连续占用CPU时间太长影响系统整体实时性，因此应该尽量避免不必要的原子操作，就算不得不原子操作也应该尽量原子操作的时间缩短。
(2)使用system调用ls

3.4.12.进程关系
(1)无关系
(2)父子进程关系（继承文件描述符）
(3)进程组（group）由若干进程构成一个进程组（帮派，江湖）
(4)会话（session）会话就是进程组的组

3.4.13.守护进程的引入
3.4.13.1、进程查看命令ps
(1)ps -ajx	偏向显示各种有关的ID号
(2)ps -aux	偏向显示进程各种占用资源
3.4.13.2、向进程发送信号指令kill
(1)kill -信号编号 进程ID，向一个进程发送一个信号
(2)kill -9 xxx，将向xxx这个进程发送9号信号，也就是要结束进程
3.4.13.3、何谓守护进程
(1)daemon，表示守护进程，简称为d（进程名后面带d的基本就是守护进程）
(2)长期运行（一般是开机运行直到关机时关闭）
(3)与控制台脱离（普通进程都和运行该进程的控制台相绑定，表现为如果终端被强制关闭了则这个终端中运行的所有进程都被会关闭，背后的问题还在于会话）
(4)服务器（Server），服务器程序就是一个一直在运行的程序，可以给我们提供某种服务（譬如nfs服务器给我们提供nfs通信方式），当我们程序需要这种服务时我们可以调用服务器程序（和服务器程序通信以得到服务器程序的帮助）来进程这种服务操作。服务器程序一般都实现为守护进程。
3.4.13.4、常见守护进程
(1)syslogd，系统日志守护进程，提供syslog功能。
(2)cron，cron进程用来实现操作系统的时间管理，linux中实现定时执行程序的功能就要用到cron。

3.4.14.编写简单守护进程
3.4.14.1、任何一个进程都可以将自己实现成守护进程
3.4.14.2、create_daemon函数要素
(1)子进程等待父进程退出
(2)子进程使用setsid创建新的会话期，脱离控制台
(3)调用chdir将当前工作目录设置为/
(4)umask设置为0以取消任何文件权限屏蔽
(5)关闭所有文件描述符
(6)将0、1、2定位到/dev/null

3.4.15.使用syslog来记录调试信息
3.4.15.1、openlog、syslog、closelog
3.4.15.2、各种参数
3.4.15.3、编程实战
(1)一般log信息都在操作系统的/var/log/messages这个文件中存储着，但是ubuntu中是在/var/log/syslog文件中的。
21minutes30seconds
3.4.15.4、syslog的工作原理
(1)操作系统中有一个守护进程syslogd（开机运行，关机时才结束），这个守护进程syslogd负责进行日志文件的写入和维护。
(2)syslogd是独立于我们任意一个进程而运行的。我们当前进程和syslogd进程本来是没有任何关系的，但是我们当前进程可以通过调用openlog打开一个和syslogd相连接的通道，然后通过syslog向syslogd发消息，然后由syslogd来将其写入到日志文件系统中。
(3)syslogd其实就是一个日志文件系统的服务器进程，提供日志服务。任何需要写日志的进程都可以通过openlog/syslog/closelog这三个函数来利用syslogd提供的日志服务。这就是操作系统的服务式的设计。

3.4.16.让程序不能被多次运行
3.4.16.1、问题
(1)因为守护进程是长时间运行而不退出，因此./a.out执行一次就有一个进程，执行多次就有多个进程。
(2)这样并不是我们想要的。我们守护进程一般都是服务器，服务器程序只要运行一个就够了，多次同时运行并没有意义甚至会带来错误。
(3)因此我们希望我们的程序具有一个单例运行的功能。意思就是说当我们./a.out去运行程序时，如果当前还没有这个程序的进程运行则运行之，如果之前已经有一个这个程序的进程在运行则本次运行直接退出（提示程序已经在运行）。
3.4.16.2、实现方法：
(1)最常用的一种方法就是：用一个文件的存在与否来做标志。具体做法是程序在执行之初去判断一个特定的文件是否存在，若存在则标明进程已经在运行，若不存在则标明进程没有在运行。然后运行程序时去创建这个文件。当程序结束的时候去删除这个文件即可。
(2)这个特定文件要古怪一点，确保不会凑巧真的在电脑中存在的。

3.4.17.linux的进程间通信概述
3.4.17.1、为什么需要进程间通信
(1)进程间通信（IPC）指的是2个任意进程之间的通信。
(2)同一个进程在一个地址空间(0~4G:1G os 3G app)中，所以同一个进程的不同模块（不同函数、不同文件）之间都是很简单的（很多时候都是全局变量、也可以通过函数形参实参传递）
(3)2个不同的进程处于不同的地址空间，因此要互相通信很难。

3.4.17.2、什么样的程序设计需要进程间通信
(1)99%的程序是不需要考虑进程间通信的。因为大部分程序都是单进程的（可以多线程,高并发）
(2)复杂、大型的程序，因为设计的需要就必须被设计成多进程程序（我们整个程序就设计成多个进程同时工作来完成的模式），常见的如GUI、服务器。
(3)结论：IPC技术在一般中小型程序中用不到，在大型程序中才会用到。

3.4.17.3、linux内核提供多种进程间通信机制
(1)无名管道和有名管道
(2)SystemV IPC：信号量、消息队列、共享内存(同一操作系统，不同进程间通信)
(3)Socket域套接字（同一台电脑，或不同台电脑间通信）
(4)信号
3.4.17.4、为什么不详细讲IPC
(1)日常使用少，只有大型程序才能用上
(2)更为复杂，属于linux应用编程中难度最大的部分
(3)细节多
(4)面试较少涉及，对找工作帮助不大
(5)建议后续深入学习时再来实际写代码详细探讨

3.4.18.linux的IPC机制1-管道
3.4.18.1、管道（无名管道）
(1)管道通信的原理：内核维护的一块内存（相当于公共缓冲区），有读端和写端**（管道是单向通信的）**
(2)管道通信的方法：父进程创建管理后fork子进程，子进程继承父进程的管道fd
(3)管道通信的限制：只能在父子进程间通信、半双工
(4)管道通信的函数：pipe、write、read、close
3.4.18.2、有名管道（fifo） （非父子进程也能通信）
fifo first in first out   先进先出    通道   管道
stack                         后进先出
(1)有名管道的原理：实质也是内核维护的一块内存，表现形式为一个有名字的文件
(2)有名管道的使用方法：固定一个文件名，2个进程分别使用mkfifo创建fifo文件，然后分别open打开获取到fd，然后一个读一个写
(3)管道通信限制：半双工（注意不限父子进程，任意2个进程都可）
(4)管道通信的函数：mkfifo、open、write、read、close

3.4.19.SystemV IPC介绍
3.4.19.1、SystemV IPC的基本特点
(1)系统通过一些专用API来提供SystemV IPC功能
(2)分为：信号量、消息队列、共享内存
(3)其实质也是内核提供的公共内存
3.4.19.2、消息队列  (广播或 一对一)
(1)本质上是一个队列，队列可以理解为（内核维护的一个）FIFO
(2)工作时A和B2个进程进行通信，A向队列中放入消息，B从队列中读出消息。
3.4.19.3、信号量（互斥、同步）
(1)实质就是个计数器（其实就是一个可以用来计数的变量，可以理解为int a）（AB进程都能访问a）
(2)通过计数值来提供互斥和同步（信号量来控制同步，信号量可看做锁）
3.4.19.4、共享内存（进程大数据交换）
(1)大片内存直接映射
例子：两个进程映射到同一个物理地址空间，一个写（编码），一个读（解码）。
A：等S=1放图，放完 S=0
B：等S=0拿图，拿完S=1
(2)类似于LCD显示时的显存用法
3.4.19.5、剩余的2类IPC
(1)信号
(2)Unix域套接字  socket