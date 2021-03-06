由 `127.0.0.2` 引发的血案
=========================

## 背景

学习 `java rmi` 中, 在一台suse上部署了server端,本地调用, 结果报什么 127.0.0.2.

## Google相关

http://blog.csdn.net/peachpi/article/details/6743974

http://blog.csdn.net/linwaterbin/article/details/7986363

## 知识点概要

### hosts

早期的互联网计算机少，单机hosts文件里足够存放所有联网计算机。不过随着互联网的发展，这就远远不够了。于是就出现了
分布式的DNS系统。由DNS服务器来提供类似的IP地址到域名的对应。Linux系统在向DNS服务器发出域名解析请求之前会查询
`/etc/hosts`文件，如果里面有相应的记录，就会使用hosts里面的记录.

### 本地回环地址

127.0.0.1，通常被称为本地回环地址(Loop back address)，不属于任何一个有类别地址类。它代表设备的本地虚拟接口，所以
默认被看作是永远不会宕掉的接口。在windows操作系统中也有相似的定义，所以通常在不安装网卡前就可以ping通这个本地回环地
址。一般都会用来检查本地网络协议、基本数据接口等是否正常的。

主要作用有两个：一是测试本机的网络配置，能PING通127.0.0.1说明本机的网卡和IP协议安装都没有问题；另一个作用是某些
SERVER/CLIENT的应用程序在运行时需调用服务器上的资源，一般要指定SERVER的IP地址，但当该程序要在同一台机器上运行而没有
别的SERVER时就可以把SERVER的资源装在本机，SERVER的IP地址设为127.0.0.1也同样可以运行。

比如我们不想让局域网的其它机器看到我们测试的网络程序，就可以用回环地址来测试.
