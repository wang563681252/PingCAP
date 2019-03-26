# PingCAP-homework-dreamstar(王朝鹏)

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

首先将100GB的url根据hash值分到200个子文件（可能会出现某一个文件很大的情况），对每一个文件求一个每个文件中url出现次数的top100，然后将200个文件的top100合并，这样就可以求出来出现次数top100的url和它的次数。

### 发现的问题

在子文件生成后可能会出现某一个文件很大的情况，这个时候再将这个文件中的url用另外一个hash函数将他们分成一半。

### 步骤

- 首先将100GB的url文件分散到200个子文件中，用的方法是：按hash值模200之后的值进行文件写入，如模后的值为126那么就放到solve_url_126.txt
- 对每个子文件中的URL进行出现次数的统计，并且统计出top100的url出现次数
- 将所有子文件中的top100写入一个文件，利用200个文件的top100求出总的top100

## Test result

- **System:** Windows 10 64-bit  &  macOS Mojave 10.14
- **CPU:** AMD Ryzen 5 2600X Six-Core Processor @ 3.6 GHz  &  Inter Core i5 2.7GHz
- **RAM:** 16.0GB  &  8GB