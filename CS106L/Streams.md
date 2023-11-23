# Streams

## What are streams

“为编程语言设计和实现一个通用的输入/输出设施是出了名的困难。”

- Bjarne Stroustrup

**Streams:** a general input/output(IO) **abstraction** for C++

**抽象**通常提供一个一致的*接口*，在**Streams**的情况下，*接口*用于**读取和写入数据**

## `cout` and `cin`

Known as the standard `iostreams`

- `cerr` & `clog`
  - `cerr`：用于输出错误信息。
  - `clog`：用于非关键事件的日志记录。

### `std::cout` and the IO library

![image-20231123161153477](./assets/image-20231123161153477.png)

A familiar stream:

```cpp
std::cout << “Hello, World” << std::endl;
```

`std::cout`是一个流；`std::cout`流是`std::ostream`的实例，它代表标准输出流。

### An Input Stream

How do you read a double from your console?

## Output streams

## Input streams
