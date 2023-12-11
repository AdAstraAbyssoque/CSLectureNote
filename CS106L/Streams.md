# 流（Streams）

## 什么是流

“为编程语言设计和实现通用输入/输出（IO）工具是非常困难的。”

- Bjarne Stroustrup

**流（Streams）：** C++ 中的通用输入/输出（IO）**抽象**。

**抽象**通常提供一致的*接口*。在**流（Streams）**的情况下，*接口* 用于**读取和写入数据**。

## `cout` 和 `cin`

被称为标准 `iostreams`。

- `cerr` 和 `clog`
  - `cerr`：用于输出错误消息。
  - `clog`：用于非关键事件记录。

### `std::cout` 和 IO 库

![image-20231123161153477](./assets/image-20231123161153477.png)

一个熟悉的流：

```cpp
std::cout << "Hello, World" << std::endl;
```

`std::cout` 是一个流；`std::cout` 流是 `std::ostream` 的实例，表示标准输出流。

### 输入流

一个例子：

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    string initial_quote = "Bjarne Stroustrup C makes it easy to shoot yourself in the foot";
    stringstream ss(initial_quote);
    string first;
    string last;
    string language, extracted_quote;
    ss >> first >> last >> language >> extracted_quote;
    std::cout << first << " "<< last << " 说：" << language << " " << extracted_quote << std::endl;
    return 0;
}
```

#### 使用 `getline`

```cpp
istream& getline(istream& is, string& str, char delim)
```

- `getline()` 函数从输入流 `is` 中读取字符，直到遇到分隔符字符 `delim` 并将它们存储在缓冲区 `str` 中。
- 默认情况下，分隔符字符 `delim` 是 `\n`（换行符）。
- `getline()` **消耗** 分隔符字符（`delim`）。

例如：

```cpp
getline(ss, extracted_quote, '\n');
```

### 输出流

- 用于将数据写入目标/外部源的方法。
  - 例如，将内容输出到控制台（`std::cout`）。
  - 使用 `<<` 运算符将数据发送到输出流。

输出流中的字符存储在中间缓冲区中，直到刷新到目标。`std::cout` 是行缓冲的，这意味着直到显式刷新之前，缓冲区的内容不会显示在外部源中。

> 在 C++ 中，您可以使用以下方法执行显式刷新：
>
> - 使用 `std::flush`：您可以调用 `std::flush` 流操作器来刷新缓冲区。例如，`std::cout << "Hello, World!" << std::flush;` 将立即刷新缓冲区的内容到目标。
>
> - 使用 `std::endl`：`std::endl` 是一个特殊的流操作器，它在输出后插入一个换行符并刷新缓冲区。例如，`std::cout << "Hello, World!" << std::endl;` 将输出 "Hello, World!" 并立即刷新缓冲区。
>
> - 使用输出流的成员函数：在 C++ 中，输出流（例如 `std::cout`）还提供了一个名为 `flush()` 的成员函数。调用此函数将立即刷新缓冲区的内容到目标。例如，`std::cout.flush();` 将立即刷新缓冲区的内容到目标。

总结一下：

在 C++ 中，除了标准输出流 `std::cout` 外，还有两个特殊的输出流：`std::cerr` 和 `std::clog`。

1. `std::cerr`：用于输出错误消息，通常用于将错误和异常输出到标准错误流。与 `std::cout` 不同，`std::cerr` 是一个无缓冲流，这意味着其输出会立即显示在终端上，无需等待缓冲区填充或显式刷新。这确保了错误消息的及时显示，而不受缓冲延迟的影响。

2. `std::clog`：用于非关键事件记录，通常用于输出程序的运行时状态、调试信息和其他非错误相关的日志。与 `std::cerr` 不同，`std::clog` 是一个缓冲流，这意味着其输出被存储在缓冲区中，直到触发某些条件（例如换行符或缓冲区填充）或显式刷新操作。与 `std::cerr` 的立即输出相比，`std::clog` 的缓冲机制增强了输出效率。

## 文件流

### 输出文件流

```cpp
#include <iostream>
#include <fstream>

int main() {
    // 在构造时关联文件
    std::ofstream ofs("hello.txt"); // 创建一个文件
    if (ofs.is_open()) {
        ofs << "Hello CS106L!" << '\n';
    }
    ofs.close();

    // 在此处写入将不起作用，因为文件已关闭
    ofs << "这将不会被写入";

    // 重新打开文件
    ofs.open("hello.txt", std::ios::app);
    ofs << "但这将！它再次打开了";
    
    return 0;
}
```

> 在 C++ 中，您可以使用 `std::ofstream` 的 `open()` 方法指定打开模式。常见的打开模式标志包括：
>
> - `std::ios::out`：用于向文件写入的输出模式。如果文件已存在，此模式会创建一个新文件并清除文件的内容。
>
> - `std::ios::app`：用于在文件末尾添加数据的追加模式。
>
> - `std::ios::trunc`：用于清除文件内容的截断模式。
>
> - `std::ios::binary`：用于以二

进制格式执行文件操作的二进制模式。

### 输入文件流

```cpp
#include <iostream>
#include <fstream>
#include <string>

int inputFileStreamExample() {
    std::ifstream ifs("append.txt");
    if (ifs.is_open()) {
        std::string line;
        std::getline(ifs, line);
        std::cout << "从文件读取：" << line << '\n';
    }
    if (ifs.is_open()) {
        std::string lineTwo;
        std::getline(ifs, lineTwo);
        std::cout << "从文件读取：" << lineTwo << '\n';
    }
    return 0;
}
```

## IO 流

### \输入流

输入流的类型是 `std::istream`。

- 用于从目标/外部源读取数据的方法。
  - 使用 `>>` 提取运算符从输入流读取。
  - `std::cin` 是控制台输入流。

- `std::cin` 是有缓冲的。
  - 可以将其视为用户可以存储数据并从中读取的位置。
  - `std::cin` 缓冲区在空格处停止。

```cpp
#include <iostream>

int main()
{
    double pi;
    std::cin >> pi;
    std::cout << "π 是：" << pi << '\n';
    return 0;
}
```

`cin` **失败**：

```cpp
#include <iostream>
#include <string>

int main()
{
    double pi;
    double tao;
    std::string name;
    std::cin >> pi;
    std::cin >> name;
    std::cin >> tao;
    std::cout << "我的名字是：" << name << " tao 是：" << tao << " π 是：" << pi << '\n';
    return 0;
}
```

**不建议**同时使用 `getline()` 和 `std::cin()`，因为它们在解析数据时行为不同。虽然如果需要可以这样做，但这并不推荐。
