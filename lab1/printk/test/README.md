# Lab1 printk 测试数据

## 运行测试

### 测试依赖

要运行本测试，需要如下工具：

- `gcc`
- `make`
- `bash`
- `awk`

### 测试准备

将要测试的`printk`实现（`vprintfmt`函数）放置到`src/print_impl.c`中。

### 运行

- `make generate`可通过`../generate`目录中的输入数据，使用标准库`printf`生成对应的预期输出，并复制到`test_data`目录中，作为测试数据。
- `make source`可根据测试数据中的输入数据生成测试所需的`.c`源文件（每组输入数据将被转化为对`printk`函数的调用，写入到`.c`文件中）。
- `make compile`可将`make source`生成的`.c`文件与`src`目录中的实现一同编译，生成测试所用的二进制。
- `make test`可运行测试并显示结果。

## 测试数据格式

输入：假设每行输入为`X`，则将为每行输入，生成`printk(X);`形式的调用。
预期输出：假设`printk(X);`的输出为`Y`，当前对应输入文件中的第`i`次调用，则其对应的预期输出记录为：

```text
--------i--------
X
--------i--------
```

可以使用`../generate`目录中的脚本自动生成预期输出。

## 许可证

使用到的第三方文件及其许可，许可文本可在`lincense`目录下找到：

- `src`目录中的`print.c`、`print_impl.c`文件：`MulanPSL2`
