# 第7部分-3.7.linux线程全解

***********《朱有鹏老师嵌入式linux核心课程》 ***********
《3.linux应用编程和网络编程-第7部分-3.7.linux线程全解》

--------------------------------------------------------
本课程由朱老师物联网大讲堂推出并提供技术支持，课件可打包下载
网盘地址：http://yunpan.cn/cjVy3RAgfDufK 访问密码 4ad7
技术交流QQ群：朱老师物联网讲堂1群 397164505
--------------------------------------------------------
第一部分、章节目录
3.7.1.再论进程
3.7.2.线程的引入
3.7.3.线程常见函数
3.7.4.***线程同步***之信号量1
3.7.5.线程同步之信号量2
3.7.6.线程同步之互斥锁 
3.7.7.线程同步之条件变量

第二部分、章节介绍
3.7.1.再论进程
	本节再次回顾进程，使用多进程的方式解决同时读取键盘和鼠标的问题，从而让大家体会进程的调度特性带来的IO并发解决方案。
3.7.2.线程的引入
	本节使用线程再次重写解决同时读取键盘和鼠标的问题，让大家体会进程和线程的相同之处，然后再讲解线程机制的优势。
3.7.3.线程常见函数
	本节对线程编程中常用的一些主要函数进行讲解，其实围绕着讲解线程编程的细节也就出来了。
3.7.4.线程同步之信号量1
	本节开始讲解线程同步，主要是线程同步的概念和原因，然后开始讲线程同步的第一种方法信号量。
3.7.5.线程同步之信号量2
	本节接上节讲解信号量来做线程同步，并且从零开始写了一个案例来演示信号量如何实现线程同步。
3.7.6.线程同步之互斥锁 
	本节引入互斥锁，并且使用互斥锁技术来实现线程同步，再进行代码实践。
3.7.7.线程同步之条件变量
	本节讲解线程同步的第三种犯法条件变量，并且进行代码编程实践使用条件变量来完成上节课的例子。
	
	

第三部分、随堂记录
3.7.1.再论进程
3.7.1.1、多进程实现同时读取键盘和鼠标
3.7.1.2、使用进程技术的优势
(1)CPU时分复用，单核心CPU可以实现宏观上的并行
(2)实现多任务系统需求（多任务的需求是客观的）
3.7.1.3、进程技术的劣势
(1)进程间切换开销大
(2)进程间通信麻烦而且效率低
3.7.1.4、解决方案就是线程技术
(1)线程技术保留了进程技术实现多任务的特性。（参与OS调度）
(2)线程的改进就是在线程间切换和线程间通信上提升了效率。
(3)多线程在多核心CPU上面更有优势。

undefined reference to `pthread_create'
没有链接动态库
gcc 3.7.2.c -lpthread
3.7.2.线程的引入
3.7.2.1、使用线程技术同时读取键盘和鼠标
3.7.2.2、linux中的线程简介
(1)一种轻量级进程
(2)线程是参与内核调度的最小单元
(3)一个进程中可以有多个线程
3.7.2.3、线程技术的优势
(1)像进程一样可被OS调度
(2)同一进程的多个线程之间很容易高效率通信
(3)在多核心（每个核都能运行程序，单个进程线程不能分开在多个核上运行）CPU（对称多处理器架构SMP）架构下效率最大化(多进程无法保证，同时在两个核心上运行，但多线程可以安排在多核心上并运行)

3.7.3.线程常见函数
3.7.3.1、线程创建与回收
(1)pthread_create		       主线程用来创造子线程的
(2)pthread_join		       主线程用来等待（阻塞）回收子线程
(3)pthread_detach		       主线程用来分离子线程，分离后主线程不必再去回收子线程
3.7.3.2、线程取消
(1)pthread_cancel		       一般都是主线程调用该函数去取消（让它赶紧死）子线程
(2)pthread_setcancelstate      子线程设置自己是否允许被取消
(3)pthread_setcanceltype       取消类型
3.7.3.3、线程函数退出相关
(1)pthread_exit（主要）与return退出（p：posix标准，linux遵守标准）
(2)pthread_cleanup_push（压，进入）
(3)pthread_cleanup_pop（弹，弹出）
信号量的使用
void pthread_cleanup_push(void (*routine)(void *), void *arg);

```c
int cnt = 0;  //cnt 作为信号量
if(cnt ==0)
{
	cnt++; //锁机制
	pthread_cleanup_push(function, arg);
	pthread_cleanup_push(function1, arg);
	pthread_cleanup_push(function2, arg);
	// 子线程

	// 子线程在这里有可能被主线程cancel
	pthread_cleanup_pop(0); //0 拿粗来不执行， 1拿出来并执行
	pthread_cleanup_pop(0); 
	pthread_cleanup_pop(0); 
	cnt--;
}

void function(void *arg)
{
	cnt--;
}
```

3.7.3.4、获取线程id
(1)pthread_self

3.7.4_5.线程同步之信号量12
3.7.4.1、任务：用户从终端输入任意字符然后统计个数显示，输入end则结束
3.7.4.2、使用多线程实现：主线程获取用户输入并判断是否退出，子线程计数
(1)为什么需要多线程实现
(2)问题和困难点是？
(3)理解什么是线程同步
3.7.4.3、信号量的介绍和使用

```c
sem_t sem; //定义信号量
sem_init(&sem, 0, 0); //初始化信号量
sem_wait(&sem); //子线程等待主线程激活信号量
sem_post(&sem); //激活信号量
sem_destroy(&sem); //结束信号量
```

3.7.6.线程同步之互斥锁 
3.7.6.1、什么是互斥锁
(1)互斥锁又叫互斥量（mutex）
(2)相关函数：pthread_mutex_init （p:process）pthread_mutex_destroy 
			pthread_mutex_lock  pthread_mutex_unlock
(3)互斥锁和信号量的关系：可以认为互斥锁是一种特殊的信号量(只有0和1的信号量)
(4)互斥锁主要用来实现关键段保护（只准某个线程访问）
int cnt = 0；
A cnt++
B cnt++
C cnt++
ABC 排队
互斥锁最典型用法：上锁—访问—解锁
例如：上锁—open—读写—close—解锁
3.7.6.2、用互斥锁来实现上节的代码

注意：man 3 pthread_mutex_init时提示找不到函数，说明你没有安装pthread相关的man手册。安装方法：1、虚拟机上网；2、sudo apt-get install manpages-posix-dev

3.7.7.线程同步之条件变量（效率高，线程中特有的）
3.7.7.1、什么是条件变量
等待与激活
异步IO（软件中断）
3.7.7.2、相关函数
		pthread_cond_init		pthread_cond_destroy
		pthread_cond_wait		pthread_cond_signal/pthread_cond_broadcast

3.7.7.3、使用条件变量来实现上节代码
3.7.7.4、线程同步总结