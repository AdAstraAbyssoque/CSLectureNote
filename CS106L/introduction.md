# 简介

| Week | Topics                                          |
| ---- | ----------------------------------------------- |
| 1    | Admin, Brief Intro to C++ features               |
| 2    | Initialization + References, Streams            |
| 3    | Containers, Iterators, Pointers                 |
| 4    | Classes, Template Classes, Const                |
| 5    | Template Functions, Functions, Lambdas          |
| 6    | No class, extra office hours, Assn 1 Due Friday |
| 7    | Operators, Special Member Functions             |
| 8    | Move Semantics, Type safety                     |
| 9    | Bonus Topics + MORE OFFICE HOURS                |
| 10   | NO CLASS MORE OFFICE HOURS, Assn 2 Due Friday   |

> **比较: CS106B 和 CS106L**
>
> |                      CS106B                       |                    CS106L                     |
> | :-----------------------------------------------: | :-------------------------------------------: |
> | 重点是抽象、递归、指针等概念的讲述，很少使用C++。 | 专注于代码，真正的课堂，完全理解C++的制造过程 |

## 日常吹水 C++ 的好处：**为什么选择 C++？**

1. 下一阶段可以应用 C++ 的课程

   - CS 111: 操作系统原理
   - CME 253: CUDA 介绍（深度学习）
   - CS 144: 计算机网络导论
   - CS 231N: 视觉识别的卷积神经网络
   - GENE 222: 用于医疗保健的并行计算
   - ME 328: 医疗机器人
   - MUSIC 256A: 音乐、计算、设计 I
   - MUSIC 420A: 音乐声学中的信号处理模型

2. 好多大公司在使用（在实际生活中）

3. 快速的底层控制

## C++ 的历史

### 汇编

汇编的优势:

- 非常简单的指令
- 极快的执行速度（写得好时）
- 对程序完全的控制

汇编的劣势:

- 完成简单任务需要大量代码
- 非常难以理解
- 难以在不同系统上移植

### C 语言

- 问题：计算机只能理解汇编语言！

- 思路：
  - 源代码可以用更直观的语言为人类编写。
  - 另一个程序可以将其转换为汇编语言！
    - 这个额外的程序称为**编译器**！

- C 语言让编写代码变得容易:
  - 快速
  - 简单
  - 跨平台

- C 之所以流行是因为它简单。
  - 这也是它的弱点:
    - 没有对象或类
    - 编写通用代码困难
    - 编写大型程序时繁琐

### 欢迎来到 C++

- 1983 年，Bjarne Stroustrup 创造了 C++ 的雏形。
  - 他希望有一种语言:
    - 快速
    - 易于使用
    - 跨平台
    - 具有高级特性

- C++ 的设计哲学:
  - 只有在解决实际问题时才添加功能
  - 程序员应该自由选择自己的风格
  - 隔离是关键
  - 允许程序员在需要时完全控制
  - 除非别无选择，否则不要牺牲性能
  - 尽量在编译时强制执行安全性
  