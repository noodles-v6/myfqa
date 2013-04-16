Base64是干嘛的?
===============

Base64是一种把二进制数据用可见字符表示出来的表示方法. 既然是可见字符,就可以保持为文本格式了, 所以Base64常用于在通常处理文
本数据的场合，表示、传输、存储一些二进制数据。包括MIME的email，email via MIME, 在XML中存储复杂数据. 

为什么Base64? [同样看别人的疑问](http://superuser.com/questions/402193/why-is-base64-needed-aka-why-cant-i-just-email-a-binary-file)

其实, 类似Base64等编码技术都是为了解决历史原因, 可以说是兼容历史吧.

大家都知道，很早以前只有ASCII的，这是一个7-bit表示的可见字符集，而现在计算机很都是用8-bit作为一个单元(即一个字节)的。前者是7-bit (0 ~ 127), 后者是8-bit (0~256)。由于计算机处理的是0和1，所以，在传输二进制的时候就会由于7-bit和8-bit造成处理错误。（很重要的知识点是：`ASCII Text-encoding standard` 和 `Binary`（机器码，可以执行））。

现在，假设我们不用任何处理，即把一个7-bit的1110110传给计算机, 由于计算机是按8-bit处理的，结果就可能变成了11110110处理，无法解析为可见的字符，damage了。

所以，就出现了很多文本编码技术，其中就有Base64.

很相关的文章
============

* [计算机编码](https://zh.wikipedia.org/wiki/%E8%AE%A1%E7%AE%97%E6%9C%BA%E7%BC%96%E7%A0%81)

* [Binary to text encoding](http://en.wikipedia.org/wiki/8-bit_clean)

* [Binary file](http://en.wikipedia.org/wiki/Binary_file)

* [8-bit clean](http://en.wikipedia.org/wiki/8-bit_clean)

* [一个漫画](http://blog.xiqiao.info/wp-content/uploads/2013/01/historical_tragedy.gif)
