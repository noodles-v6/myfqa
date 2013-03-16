64位Linux环境下, 32位JVM加载动态库失败
======================================

在模拟 << Core Java II 第8版 >> JNI调用一节的例子时, 发生的.

## 环境

64位Linux, 32位的JVM

## 操作

1. 根据JNI原理实现本地动态连接库;
    
    .java -(javac)-> .class -(javah)-> .h -(实现)-> .c
    gcc -fPIC -I $JAVA_HOME/include -I $JAVA_HOME/include/linux -shared libXXX.so XXX.c

2. 编写测试程序, 调用 System.loadLibrary 加载库;

    System.loadLibrary("XXX");
    当然也可以直接把load过程写入生成.h的java类中.
    
3. 测试

## 错误日志

    www@linux:~/app/mess/java> java HelloNativeTest
    Exception in thread "main" java.lang.UnsatisfiedLinkError: /home/www/app/mess/java/libHelloNative.so: /home/www/app/mess/java/libHelloNative.so: wrong ELF class: ELFCLASS64 (Possible cause: architecture word width mismatch)
      at java.lang.ClassLoader$NativeLibrary.load(Native Method)
    	at java.lang.ClassLoader.loadLibrary0(ClassLoader.java:1803)
    	at java.lang.ClassLoader.loadLibrary(ClassLoader.java:1728)
    	at java.lang.Runtime.loadLibrary0(Runtime.java:823)
    	at java.lang.System.loadLibrary(System.java:1028)
    	at HelloNativeTest.<clinit>(HelloNativeTest.java:8)
    Could not find the main class: HelloNativeTest.  Program will exit.
    
错误 `wrong ELF class: ELFCLASS64 (Possible cause: architecture word width mismatch)` 是很基本的错误. Google后发现是JVM的问题.

可以通过 `java -version` 识别:

32位的jvm:

    java version "1.6.0_04"
    Java(TM) SE Runtime Environment (build 1.6.0_04-b12)
    Java HotSpot(TM) Server VM (build 10.0-b19, mixed mode)
  
64位的jvm:

    java version "1.6.0_12"
    Java(TM) SE Runtime Environment (build 1.6.0_12-b04)
    Java HotSpot(TM) **64-Bit** Server VM (build 11.2-b01, mixed mode)
