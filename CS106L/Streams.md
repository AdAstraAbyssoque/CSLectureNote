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

一个例子：

```cpp
#include<bits/stdc++.h>
using namespace std;

int main(){
    string initial_quote = "Bjarne Stroustrup C makes it easy to shoot yourself in the foot";
    stringstream ss(initial_quote);
    string first;
    string last;
    string language,extracted_quote;
    ss>>first>>last>>language>>extracted_quote;
    std::cout << first << " "<< last << " said this: "<< language << " " <<extracted_quote << std::endl;
    return 0;
}
```

#### Use `getline`

```cpp
istream& getline(istream& is, string& str, char delim)
```

- getline()函数从输入流`is`中读取字符，直到遇到分隔符字 `delim`，并将其存储在缓冲区`str`中。
- 默认情况下，分隔符字符delim是`\n`（换行符）。
- getline()函数**消耗**了分隔符字符（delim）。

例如：

```cpp
getline(ss,extracted_quote,'\n');
```

### Output streams

- 向目标/外部源写入数据的方法
  - 例如将某些内容写入控制台（`std::cout`）
  - 使用 `<<` 运算符将数据发送到输出流

在输出流中的字符在被刷新到目标位置之前会被存储在一个中间缓冲区中。
`std::cout`流是行缓冲的，即在**显式刷新**之前，缓冲区中的内容不会在外部源中显示出来

> 在C++中，可以使用以下方法来进行显式刷新操作：
>
> - 使用`std::flush`：可以调用`std::flush`流操纵符来刷新缓冲区。例如，`std::cout << "Hello, World!" << std::flush;`会将缓冲区中的内容立即刷新到目标位置。
>
> - 使用`std::endl`：`std::endl`是一个特殊的流操纵符，它会在输出内容后自动插入一个换行符，并刷新缓冲区。例如，`std::cout << "Hello, World!" << std::endl`;会输出"Hello, World!"并立即刷新缓冲区。
>
> - 使用输出流的成员函数：在C++中，输出流（如`std::cout`）还提供了一个名为`flush()`的成员函数，调用该函数可以显式刷新缓冲区。例如，`std::cout.flush()`;会将缓冲区中的内容立即刷新到目标位置。

刷新是一种昂贵的操作：
>"刷新是一种昂贵的操作"的意思是指刷新操作在性能方面是昂贵的，会消耗较多的资源和时间。
>
>当执行刷新操作时，会将缓冲区中的数据传输到目标位置，通常涉及到输入/输出操作。这些操作相对于内存操作来说可能较慢，因为它们可能涉及到写入文件、发送数据到网络或在屏幕上显示内容等操作。
>
>过于频繁地进行刷新操作，特别是在循环中或处理小量数据时，会导致性能显著下降。每次刷新操作都需要消耗系统资源，并可能需要等待输入/输出操作完成。
>
>为了优化性能，流通常采用缓冲机制来减少刷新操作的次数。通过将数据存储在缓冲区中，并在批量操作或满足特定条件时进行刷新，可以减少输入/输出操作的次数，从而提高总体性能。
>
>需要平衡数据即时可见性的需求与刷新操作的性能考虑。如果实时数据可见性不是关键，可以允许流根据缓冲设置自动刷新，或者在必要时进行偶尔的手动刷新，以在响应性和性能之间取得平衡。

回顾一下：

在 C++ 中，除了标准输出流 `std::cout` 外，还有两个特殊的输出流：`std::cerr` 和 `std::clog`。

1. `std::cerr`：它用于输出错误信息，通常用于向标准错误流输出错误和异常信息。与 `std::cout` 不同的是，`std::cerr` 是一个不带缓冲的流，意味着它的输出会立即显示在终端上，而不会等待缓冲区填满或显式刷新操作。这使得 `std::cerr` 在处理错误时特别有用，因为它确保错误信息能够及时显示，而不会被缓冲区的延迟所影响。

2. `std::clog`：它用于非关键事件的日志记录，通常用于输出程序的运行状态、调试信息和其他非错误相关的日志。与 `std::cerr` 不同的是，`std::clog` 是一个带缓冲的流，意味着它的输出会先存储在缓冲区中，直到缓冲区达到一定条件（如换行符或缓冲区填满）或显式刷新操作时才会刷新到终端上。相比于 `std::cerr` 的即时输出，`std::clog` 的缓冲机制可以提高输出的效率。

## File Streams

### Output File Streams

```cpp
#include <iostream>
#include <fstream>

int main() {
    // 关联文件在构造时
    std::ofstream ofs("hello.txt");//创建文件
    if (ofs.is_open()) {
        ofs << "Hello CS106L!" << '\n';
    }
    ofs.close();

    // 这里的写入操作不会生效，因为文件已关闭
    ofs << "this will not get written";

    // 再次打开文件
    ofs.open(“hello.txt”, std::ios::app);
    ofs << "this will though! It’s open again";

    return 0;
}
```

> 在C++中，可以使用 `std::ofstream` 的 `open()` 方法来指定打开模式。常见的打开模式标志包括：
>
> `std::ios::out`：输出模式，用于写入文件。这个模式将会创建一个新文件，如果文件已经存在，则会清空文件内容。
>
> `std::ios::app`：追加模式，用于在文件末尾追加数据。
>
> `std::ios::trunc`：截断模式，用于清空文件内容。
>
> `std::ios::binary`：二进制模式，用于以二进制格式进行文件操作。

### Input File Streams

```cpp
#include <iostream>
#include <fstream>
#include <string>

int inputFileStreamExample() {
    std::ifstream ifs("append.txt");
    if (ifs.is_open()) {
        std::string line;
        std::getline(ifs, line);
        std::cout << "Read from the file: " << line << '\n';
    }
    if (ifs.is_open()) {
        std::string lineTwo;
        std::getline(ifs, lineTwo);
        std::cout << "Read from the file: " << lineTwo << '\n';
    }
    return 0;
}
```

## IO Streams

### Input Streams

输入流的类型为std::istream。

- 从目标/外部源读取数据的方法。
  - 使用 `>>` 提取运算符从输入流中读取。
  - `std::cin`是控制台输入流。

- `std::cin`是带有缓冲的。
  - 可以将其视为用户可以存储数据并从中读取的位置。
  - `std::cin`缓冲区在遇到空格时停止。

```cpp
#include <iostream>

int main()
{
    double pi;
    std::cin >> pi;
    std::cout << "pi is: " << pi << '\n';
    return 0;
}
```

cin **fails**:

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
    std::cout << "my name is: " << name << " tao is: " << tao << " pi is: " << pi << '\n';
    return 0;
}
```

**不建议**同时使用`getline()`和`std::cin()`，因为它们在解析数据时存在差异。如果确实有需要，虽然可以这样做，但并不推荐。
