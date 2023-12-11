# 类型和结构体

## C++ 基础

C++：基本语法 + STL（标准模板库）

### **基本语法**

- 在语句末尾使用分号。
- 原始数据类型（整数、双精度等）。
- 基本语法规则。

### **STL（标准模板库）**

- 提供了丰富的通用功能。
- 包括 maps、sets、vectors 等内置类。
- 通过命名空间 `std::` 访问。

#### **命名空间**

- 许多元素都在 `std::` 命名空间中。
  - 例如：`std::cout`、`std::cin`、`std::lower_bound`。
- 在 CS 106B 中通常使用 `using namespace std;` 声明，它会自动添加 `std::`。
- 大多数情况下不建议使用。
  - 这不是良好的编程风格！

#### **STL 命名约定**

STL = 标准模板库

- 包含大量功能（算法、容器、函数、迭代器等），我们将在本课程中探讨其中一些。
- `STD::` = STL 命名空间。
- 因此，要访问 STL 的元素，请使用 `std::`。

## 类型

### Fundamental Types

```cpp
int val = 5; //32 位
char ch = 'F'; //8 位（通常）
float decimalVal1 = 5.0; //32 位（通常）
double decimalVal2 = 5.0; //64 位（通常）
bool bVal = true; //1 位
```

### Fundamental Types++

```cpp
#include <string>
int val = 5; //32 位
char ch = 'F'; //8 位（通常）
float decimalVal1 = 5.0; //32 位（通常）
double decimalVal2 = 5.0; //64 位（通常）
bool bVal = true; //1 位
std::string str = "Haven";
```

### C++ 是一种静态类型语言

静态类型：所有命名实体（变量、函数等）在运行之前都被赋予一种类型。相比之下，像 Python 这样的语言是动态类型的：所有命名实体在运行时根据其当前值被赋予一种类型。

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

### Function Overloading (函数重载)

```cpp
int half(int x) {
    std::cout << "1" << std::endl; // (1)
    return x / 2;
}
double half(double x) {
    std::cout << "2" << std::endl; // (2)
    return x / 2;
}
half(3) // 使用版本 (1)，返回 1
half(3.0) // 使用版本 (2)，返回 1.5
```

```cpp
int half(int x, int divisor = 2) { // (1)
    return x / divisor;
}
double half(double x) { // (2)
    return x / 2;
}
half(4) // 使用版本 (1)，返回 2
half(3, 3) // 使用版本 (1)，返回 1
half(3.0) // 使用版本 (2)，返回 1.5
```

## 结构体

- 目前为止，类型的问题
  - 很难知道变量的类型是什么
  - 任何给定的函数只能有一个返回类型
  - C++ 原始类型（甚至 STL 中的类型）可能存在限制

> **Auto**
>
> 在声明变量时用来代替 type 的关键字，它告诉编译器推断该类型。
>
> 这和没有类型是不一样的!
>
> 编译器无需显式告知即可自行确定类型。

```cpp
auto a = 3; // int
auto b = 4.3; // double
auto c = 'X'; // char
auto d = "Hello"; // char*（C 字符串）
```

对于类型后两点的不足，需要使用结构体来补充。

### 定义

**结构体**是一组具有各自类型的**命名变量**，允许程序员将**不同类型**的变量**捆绑**在一起！

```cpp
#include <iostream>
#include <string>
#include <cstdlib>

struct Student {
    std::string name;
    std::string state;
    int age;
};

void printStudentInfo(Student s) {
    std::cout << s.name << " from " << s.state;
    std::cout << " (" << s.age << ")" << std::endl;
}

Student randomStudentFrom(std::string state) {
    Student s;
    s.name = "Haven";
    s.state = state;
    s.age = std::rand() %

 101; // 生成 0 到 100 之间的随机数
    return s;
}

int main() {
    Student s;
    s.name = "Haven";
    s.state = "AR";
    s.age = 21;

    printStudentInfo(s);

    Student foundStudent = randomStudentFrom("AR");
    std::cout << foundStudent.name << std::endl;

    return 0;
}
```

`std::pair`：具有两个任意类型字段的 STL 内置结构体

- `std::pair` 是一个模板：您需要在<>中为每个 pair 对象指定字段的类型。
- `std::pair` 中的字段分别命名为 `first` 和 `second`。

```cpp
std::pair<int, std::string> numSuffix = {1, "st"};
std::cout << numSuffix.first << numSuffix.second; // 输出 1st
```

```cpp
std::pair<bool, Student> lookupStudent(std::string name) {
    Student blank;
    if (notFound(name)) return std::make_pair(false, blank);
    Student result = getStudentWithName(name);
    return std::make_pair(true, result);
}
auto output = lookupStudent("Julie"); // 或者 std::pair<bool, Student> output = lookupStudent("Julie");
```
