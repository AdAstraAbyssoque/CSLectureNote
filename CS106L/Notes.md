# CS106L

## 简介

| Week | Topics                                          |
| ---- | ----------------------------------------------- |
| 1    | Admin, Brief Intro to C++ feature               |
| 2    | Initialization + References, Streams            |
| 3    | Containers, Iterators, Pointers                 |
| 4    | Classes, Template Classes, Const                |
| 5    | Template Functions, Functions, Lambdas          |
| 6    | No class, extra office hours, Assn 1 Due Friday |
| 7    | Operators, Special Member Functions             |
| 8    | Move Semantics, Type safety                     |
| 9    | Bonus Topics + MORE OFFICE HOURS                |
| 10   | NO CLASS MORE OFFICE HOURS, Assn 2 Due Friday   |

> 比较:CS106B和CS106L
>
> |                      CS106B                       |                    CS106L                     |
> | :-----------------------------------------------: | :-------------------------------------------: |
> | 重点是抽象、递归、指针等概念的讲述，很少使用C++。 | 专注于代码，真正的课堂，完全理解c++的制造过程 |

### 日常吹水C++的好处：**为什么选择C++？**

1. 下一阶段可以应用C++的课程

   - CS 111: 操作系统原理

   - CME 253: CUDA介绍（深度学习）

   - CS 144: 计算机网络导论

   - CS 231N: 视觉识别的卷积神经网络

   - GENE 222: 用于医疗保健的并行计算

   - ME 328: 医疗机器人

   - MUSIC 256A: 音乐、计算、设计I

   - MUSIC 420A: 音乐声学中的信号处理模型

2. 好多大公司在使用 (在实际生活中)

3. 快速的底层控制

### C++ 的历史

#### 汇编

汇编的优势:

- 非常简单的指令
- 极快的执行速度（写得好时）
- 对程序完全的控制

汇编的劣势:

- 完成简单任务需要大量代码
- 非常难以理解
- 难以在不同系统上移植

#### C语言

- 问题：计算机只能理解汇编语言！

- 思路：
  - 源代码可以用更直观的语言为人类编写。
  - 另一个程序可以将其转换为汇编语言！
    - 这个额外的程序称为**编译器**！

- C语言让编写代码变得容易:
  - 快速
  - 简单
  - 跨平台

- C之所以流行是因为它简单。
  - 这也是它的弱点:
    - 没有对象或类
    - 编写通用代码困难
    - 编写大型程序时繁琐

#### 欢迎来到C++

- 1983年，Bjarne Stroustrup创造了C++的雏形。
  - 他希望有一种语言:
    - 快速
    - 易于使用
    - 跨平台
    - 具有高级特性

- C++的设计哲学:
  - 只有在解决实际问题时才添加功能
  - 程序员应该自由选择自己的风格
  - 隔离是关键
  - 允许程序员在需要时完全控制
  - 除非别无选择，否则不要牺牲性能
  - 尽量在编译时强制执行安全性

## 类型和结构体

### C++ 基础

C++：基本语法 + STL（标准模板库）

#### **基本语法**

- 在行尾使用分号
- 原始类型（整数、双精度等）
- 基本语法规则

#### **STL（标准模板库）**

- 提供了大量的通用功能
- 包含了诸如 maps、sets、vectors 等内置类
- 通过命名空间 `std::` 访问

##### **命名空间**

- 许多东西都在 `std::` 命名空间中
  - 例如：`std::cout`、`std::cin`、`std::lower_bound`
- CS 106B 通常使用 `using namespace std;` 声明，它会自动为您添加 `std::`
- 我们大多数时候不会使用
  - 这不是良好的编程风格！

##### **STL 命名约定**

STL = 标准模板库

- 包含大量功能（算法、容器、函数、迭代器等），我们将在本课程中探讨其中一些。
- `STD::` = STL 命名空间
- 因此，要访问 STL 的元素，请使用 `std::`

### 类型

#### Fundamental Types

```cpp
int val = 5; //32 bits
char ch = 'F'; //8 bits (usually)
float decimalVal1 = 5.0; //32 bits (usually)
double decimalVal2 = 5.0; //64 bits (usually)
bool bVal = true; //1 bit
```

#### Fundamental Types++

```cpp
#include <string>
int val = 5; //32 bits
char ch = 'F'; //8 bits (usually)
float decimalVal1 = 5.0; //32 bits (usually)
double decimalVal2 = 5.0; //64 bits (usually)
bool bVal = true; //1 bit
std::string str = "Haven";
```

#### C++ 是一种静态类型语言

静态类型：所有具有名称的事物（变量、函数等）在运行时之前都被赋予一种类型。 与之不同，像 Python 这样的语言是动态类型的： 所有具有名称的事物（变量、函数等）在运行时基于其当前值被赋予一种类型。

| 特征         | 编译                                   | 解释                                           |
| ------------ | -------------------------------------- | ---------------------------------------------- |
| **定义**     | 将源代码转换为机器代码或中间代码。     | 逐行解释和执行源代码的过程。                   |
| **检查类型** | 静态类型，编译时检查变量和函数类型。   | 动态类型，运行时根据当前值确定变量和函数类型。 |
| **执行时间** | 在程序运行之前，生成独立的可执行文件。 | 源代码直接在解释器中执行，无需生成可执行文件。 |
| **效率**     | 通常更高，因为代码在运行之前已经优化。 | 通常较低，因为代码在运行时逐行解释。           |
| **例子**     | C++                                    | Python                                         |

动态 VS 静态类型

```python
a = 3
b = "test”
def func(c):
 # do something
```

```cpp
int a = 3;
string b = "test”;
char func(string c) {
 // do something
}
```

```cpp
int add(int a, int b);
//int, int -> int
string echo(string phrase);
//string -> string
string helloworld();
//void -> string
double divide(int a, int b);
//int, int -> double
```

#### Function overloading
