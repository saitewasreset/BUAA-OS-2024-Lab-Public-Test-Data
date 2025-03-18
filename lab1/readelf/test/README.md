# Lab1 readelf 测试数据

## 运行测试

### 测试依赖

要运行本测试，需要如下工具：

- `gcc`
- `make`
- `bash`
- `diff`

### 测试准备

将要测试的`readelf`实现放置到`src/readelf.c`中。

### 运行

- `make compile`可构建将要测试的`readelf`。
- `make test`可运行测试并显示结果。

对于失败的测试，可使用`./show_diff <测试名>`查看与预期输出的差异。

## 测试数据格式

输入：32 位 ELF 文件。
预期输出：`id:addr`，其中`id`表示每个节（section）的编号，从 0 开始；`addr`为十六机制表示的该节（section）的地址（`0xfffff`格式，无前导零）。

## 许可证

使用到的第三方文件及其许可，许可文本可在`lincense`目录下找到：

- `src`目录中的基本`.c`文件：`MulanPSL2`
- `src`目录中的`elf.h`：`LGPLv2`
- `test_data/input`目录中的`busybox`二进制：`GPLv2`，[源代码](https://www.busybox.net/downloads/busybox-1.37.0.tar.bz2)
