# PingCAP-homework-dreamstart(王朝鹏)

## 开始截至时间

- 开始时间 | 北京时间：2019 年 3 月 25 日，16:30
- 截止时间 | 北京时间：2019 年 4 月 1 日，16:30

## 要求

- 在 GitHub 上实现，截止时间前提交项目链接
- 100GB url 文件，使用 1GB 内存计算出出现次数 top100 的 url 和出现的次数

## 提示

- 注意代码可读性，添加必要的注释（英文）
- 注意代码风格与规范，添加必要的单元测试和文档
- 注意异常处理，尝试优化性能

## 解决思路

首先将100GB的url根据hash值分到200个子文件，对每一个文件求一个每个文件中url出现次数的top100，然后将200个文件的top100合并，这样就可以求出来出现次数top100的url和它的次数。

### 发现的问题

在子文件生成后可能会出现某一个文件很大的情况，那么会计算每个文件的大小，如果该url放入炒过多少个的时候会在以后将此hash值的url放到以后的一个文件中。

### 步骤

- 首先将100GB的url文件分散到200个子文件中，用的方法是：按hash值模200之后的值进行文件写入，如模后的值为126那么就放到solve_url_126.txt
- 对每个子文件中的URL进行出现次数的统计，并且统计出top100的url出现次数
- 将所有子文件中的top100写入一个文件，利用200个文件的top100求出总的top100

## 开发环境

语言：C++11

## 项目文件解释

- solve文件夹下是所有解决文件以及C++的运行配置文件
- test是一些测试数据，还有一些生成测试数据的代码
- main.cpp程序运行的主函数，里面有三个大的子函数，函数分别对应以下文件：
  - split_file函数是在split_url_file.cpp文件中，具体作用是输入一个需要计算top100的url文件名（需要在同一文件夹下），将这个文件分解成多个子文件。
  - count_top100函数是在count_subfile_top100.cpp文件中，具体作用是输入一个已经生成文件的个数，然后求出每个子文件的top100，并且输出在一个文件里。
  - solve_top100函数是在ALL_TOP100.cpp文件中，具体作用是将综合起来的所有子文件的top100求一个top100
- Makefile为脚本文件
- CMakeLists.txt是cmake的配置文件
- build文件夹是cmake的配置文件

## 产生文件解释

- split_file.cpp运行后会生成对应个数的hash之后的子文件，例如："hash_url_1.txt"，"hash_url_123.txt"
- count_subfile_top100.cpp运行后会生成一个"subfile_top100.txt"文件，这里面放的是每个子文件的top100的url及其出现次数（每行有一组数据，为：出现次数和url，出现次数在前面，url在后面）
- ALL_TOP100.cpp运行后会生成"url_top100.txt"文件，里面存的是总的top100的url及其出现次数（每三行有一组数据，第一行为url，第二行为出现次数）

## 心路历程

开始看到任务的时候就想出了思路，我想的是先把小的点实现了之后再去总和，然后我就把需要写的功能写了出来。但是在实现的时候我发现了hash之后的子文件会出问题，于是解决了一下，但是又发现了新的问题，暂时没有特别好的想法。因为课还不少我就从台式和mac之间来回切换，感觉提交数有点多。其实写注释有点苦恼，因为之前没写过，写起来就很别扭，如果在写代码的途中来写的话，写代码的时候就不顺畅，如果结束之后再写的话又不清楚在哪写，最后我写完注释后找了一个队友让他看一下哪一眼看不出来是什么，我就在哪再加注释。

第一次把函数写成子文件，第一次用cmake，第一次了解CI并写了点没什么大用的配置文件，第一次用github写项目，第一次写了这么多的注释，第一次写这么多英文注释。

## 未解决问题

如果某一个字文件的size很大之后会把之后的url放入到另外一个文件，这个时候会出现每个文件url统计的问题，也就是说同一个url在两个文件中出现的情况，但是暂时没想到比较好的解决方法。

## test result

- **System:** Windows 10 64-bit  &  macOS Mojave 10.14
- **CPU:** AMD Ryzen 5 2600X Six-Core Processor @ 3.6 GHz  &  Inter Core i5 2.7GHz
- **RAM:** 16.0GB  &  8GB