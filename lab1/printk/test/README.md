# Lab1 printk 测试数据

## 运行测试

### 测试依赖

要运行本测试，需要如下工具：

- `gcc`
- `make`
- `bash`
- `awk`
- `diff`
- `lib32-gcc-libs`、`lib32-glibc`（若需要 32 位构建）

### 测试准备

将要测试的`printk`实现（`vprintfmt`函数）放置到`src/print_impl.c`中（仅需用实现的`vprintfmt`函数**替换**给出的`vprintfmt`函数，**不要修改其他部分**）。

### 注意事项

默认情况下，测试代码将使用本机的原生工具链进行原生（Native）编译。这与实验中代码实际运行的`MIPS32`环境不同。

对于常见的`x86_64 GNU/Linux`系统，其 C 类型`long`为 64 位，与`MIPS32`环境中的 32 位不同。一般情况下，这不会导致问题，但在课程组提供的`vprintfmt`框架代码中，有如下代码：

```c
case 'U':
    if (long_flag) {
        num = va_arg(ap, long int);
    } else {
        num = va_arg(ap, int);
    }
    print_num(out, data, num, 10, 0, width, ladjust, padc, 0);
    break;
```

（在之前的定义中，`num`是`long`类型）

此处对应"%U"的格式符，按照标准，应当将输入作为`unsigned int`进行输出，但此处将输入作为`int`类型，赋值给了`long`类型的变量。

在大多数 32 位平台上（包括实验环境），`int`和`long`的长度相同，不会出现问题。

但在大多数 64 位平台上，`int`为 4 字节，`long`为 8 字节。若输入不在`int`的范围，但在`unsigned int`范围（如`4294967295U`），则按`int`解析时，该数为负数，并将**符号拓展**到`long`，得到`0xFFFF FFFF FFFF FFFF`，之后在`print_num`的参数中，又作为`unsigned long`传递，最后打印出`18446744073709551615`。

由于测试数据中包含相关测试点，上述行为将导致测试不通过。

可任选如下方法之一解决：

- 修复`vprintfmt`框架代码中的问题，将应当进行无符号解析的地方改为使用`unsigned int`；
- 使用`ARCH=x86 make test`运行测试，此时将生成 32 位可执行文件，避免上述符号拓展问题。注意，要生成 32 位可执行文件，可能需要安装对应版本的`glibc`以及`gcc`库文件。

### 运行

- `make generate`可通过`../generate`目录中的输入数据，使用标准库`printf`生成对应的预期输出，并复制到`test_data`目录中，作为测试数据。
- `make source`可根据测试数据中的输入数据生成测试所需的`.c`源文件（每组输入数据将被转化为对`printk`函数的调用，写入到`.c`文件中）。
- `make compile`可将`make source`生成的`.c`文件与`src`目录中的实现一同编译，生成测试所用的二进制。
- `make test`可运行测试并显示结果。

对于失败的测试，可使用`./show_diff.sh <测试名>`查看与预期输出的差异。

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
