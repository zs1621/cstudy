## know about gcc
 - Gcc


 > [参考](http://blog.chinaunix.net/uid-20672257-id-3408132.html)


###了解gcc的一些常用配置

 - `-g`: 在可执行程序中包含标准调试信息
 - `-Wall`: 允许发出Gcc提供的所有有用的报警信息
 - `-o file`: 把文件输出到file里
 - `static`: 链接静态库

```
#上面这些参数放在Makefile里
CFLAGS= -g -Wall
```



