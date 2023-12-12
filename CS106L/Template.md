# C++ 模板笔记

## Template classes

### 介绍

C++ 模板是一项强大的功能，允许你编写通用代码，从而创建可以与不同数据类型一起工作的类和函数。这份笔记使用一个实际示例简要介绍了 C++ 模板。

```cpp
#include<bits/stdc++.h>

template<typename T>
class Container {
public:
    Container(T value);
    T getvalue();
private:
    T value;
};

// 用于比较的原始类

class IntContainer {
public:
    IntContainer(int value);
    int getvalue();
private:
    int value;
};

#include"Template.h"

// 使用模板的 Container 成员函数的定义
template<typename T>
Container<T>::Container(T value) {
    this->value = value;
}

template<typename T>
T Container<T>::getvalue() {
    return this->value;
}
```

### 模板声明

在使用模板时，正确声明模板非常重要。在提供的示例中，有一种正确的声明方式和一种错误的声明方式。

#### 正确声明

```cpp
template <class T>
Container<T>::Container(T value) {
    this->value = value;
}
```

#### 错误声明

```cpp
template <class T>
Container::Container(T value) {
    this->value = value;
}
```

解释：
正确的模板声明在类名 'Container' 之后明确指定了模板参数 'T'。而错误的声明缺少了这个规定，将导致编译错误。

注意：
C++ 要求在类或函数范围内明确指定模板参数，因为不同的类型可能导致类的不同行为（例如 int、bool、char）。

### 类和类型名称在模板声明列表中可以互换使用

```cpp
template <class T>
class Container {
public:
    // ...
private:
    T value;
};
```

完全等价

```cpp
template <typename T>
class Container {
public:
    // ...
private:
    T value;
};
```

### C++模板类实现的怪癖

在使用C++模板类时，将模板的实现包含在头文件中而不是单独的.cpp文件中是一种常见的做法。这样做是为了确保编译器在模板实例化点能够访问到模板的定义。以下是一个简要的解释：

#### 头文件（Container.h）

```cpp
#ifndef CONTAINER_H
#define CONTAINER_H

template<typename T>
class Container {
public:
    Container(T value);
    T getvalue();
private:
    T value;
};

#include "Container.cpp"  // 在头文件末尾包含实现文件

#endif
```

#### 实现文件（Container.cpp）

```cpp
template<typename T>
Container<T>::Container(T value) {
    this->value = value;
}

template<typename T>
T Container<T>::getvalue() {
    return this->value;
}
```

在这个示例中，模板类`Container`在头文件（`Container.h`）中声明，其实现在相同的头文件末尾被包含进来。尽管这种做法被广泛使用并得到许多编译器的支持，但它被认为是一种怪癖，因为它不是严格的语言要求，不同的编译器可能以不同的方式处理单独的模板实现文件。

在处理模板类时，请记住采用这种做法，以避免链接错误并确保顺利编译。

## Const correctness

在C++中，常量接口指的是类中一组可以在处理标记为const的对象时访问和调用的函数。当将对象声明为const时，意味着对象的状态不能被修改。常量接口由不修改对象内部状态的成员函数组成。

### 定义

const对象只能与常量接口交互。常量接口由被标记为const且不修改类的对象或实例的函数组成。

下面是一个例子来说明这个概念：

```cpp
class MyClass {
public:
    // 非const成员函数
    void modifyState() {
        // 修改内部状态的代码
    }

    // const成员函数（常量接口的一部分）
    int getState() const {
        // 访问并返回内部状态的代码
    }
};

int main() {
    const MyClass obj;  // 声明一个const对象

    // obj.modifyState();  // 错误！不能在const对象上调用非const函数

    int stateValue = obj.getState();  // 可以，因为getState是常量接口的一部分

    return 0;
}
```

在上面的示例中，`modifyState`是一个非const成员函数，用于修改对象的内部状态。这个函数不能在const对象上调用。另一方面，`getState`是一个const成员函数，不修改对象的状态，可以在const对象上调用。

通过定义常量接口，可以确保const对象只能调用保证对象不可变性的函数。这是设计支持const正确性并遵循最小特权原则的类的关键方面。

### 强制类型转换

- **语法：**

  ```cpp
  const_cast<目标类型>(表达式)
  ```

- **目的：**
  - `const_cast` 用于去除指针或引用的 const 修饰符。

- **用途：**
  - 当你有一个 const 指针或引用，并且需要执行一个需要非 const 版本对象的操作时，这就显得很有用。

- **示例：**

  ```cpp
  const int value = 10;
  const int* constPtr = &value;

  // 尝试修改 const 变量（错误）
  // *constPtr = 20;

  // 使用 const_cast 去除 const 修饰符，从而修改变量
  int* nonConstPtr = const_cast<int*>(constPtr);
  *nonConstPtr = 20;

  // 现在，'value' 已通过非 const 指针被修改
  ```

在这个例子中，`const_cast` 用于从 const 指针 (`constPtr`) 中创建一个非 const 指针 (`nonConstPtr`)。这使得通过非 const 指针修改原始 const 变量成为可能。

### 为何有用？

- **灵活性：**
  - `const_cast` 在处理可能未明确设计为处理 const 修饰符的 API 或函数时提供了灵活性。

- **遗留代码：**
  - 在涉及不使用 const-correctness 的遗留代码时，`const_cast` 可以用于调整代码而无需更改其核心逻辑。

- **与非 const 函数接口：**
  - 当你有一个 const 限定对象，但需要将其传递给期望非 const 对象的函数时，`const_cast` 允许执行这种类型的转换。

需要谨慎使用 `const_cast`，因为修改原始的 const 限定对象可能导致意外行为，违反 const-correctness 原则。确保在给定上下文中修改是安全和必要的。
