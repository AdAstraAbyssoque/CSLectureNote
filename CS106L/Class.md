# Class

## Introduction to Classes

### C++语言的设计前提

- **前提：** C++语言整体设计基于C语言，其中一个重要前提是C语言中缺乏对面向对象编程（OOP）的支持。

### 类的概念与作用

- **类的定义：** 类是用户自定义的数据类型，用于封装数据和功能。
  
- **成员变量与成员函数：** 类中可以包含成员变量（用于表示数据）和成员函数（用于实现功能）。这种封装方式使得程序更有组织性和可维护性。

引入类和对象的概念使得C++程序员能够更好地组织代码、实现数据的封装和抽象，从而提高代码的可读性和可维护性。

### 面向对象编程（OOP）

- **定义：** 面向对象编程是围绕对象展开的一种编程范式。
  
- **核心概念：** OOP侧重于设计和实现类。
  
- **类的重要性：** 类是用户自定义的类型，可以声明为对象。
  
OOP通过引入类和对象的概念，集中关注于对象的设计和实现。类是其中的核心，作为用户自定义类型，可以被声明为对象，实现了数据和功能的封装，提高了代码的组织性和可维护性。

### 比较 'struct' 和 'class'

在C++中，'struct' 和 'class' 是用于定义用户自定义类型的关键字，它们有一些相似之处，但也存在一些区别。

- **相似点：**
  - 都可以包含一系列不同类型的对象。
  - 都可以包含一组用于操作这些对象的函数。

- **区别：**
  - **'class' 的访问限制：** 'class' 具有对成员的默认私有（private）访问权限，需要使用关键字 'public' 或 'protected' 明确指定访问级别。
  - **'struct' 的访问限制：** 'struct' 默认的成员访问权限是公有（public），不需要额外的关键字来指定。

引用来源：Bjarne Stroustrup，《The C++ Programming Language-Reference Manual》，54.4 Derived Types。

### 创建基于结构体的 Student 类

#### Student 类定义

首先，我们可以基于之前定义的结构体创建一个 Student 类，增加一些额外的功能和控制访问权限。

```cpp
// Student.h (Header File)

#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
public:
    // 构造函数
    Student();

    // 设置学生信息的函数
    void setInfo(const std::string& name, const std::string& state, int age);

    // 获取学生姓名的函数
    std::string getName() const;

    // 获取学生州份的函数
    std::string getState() const;

    // 获取学生年龄的函数
    int getAge() const;

private:
    // 学生信息的私有成员变量
    std::string name;
    std::string state;
    int age;
};

#endif
```

#### 学生类的实现

然后，我们可以在一个源文件中实现上述类的功能。

```cpp
// Student.cpp (Source File)

#include "Student.h"

// 构造函数的实现
Student::Student() : age(0) {}

// 设置学生信息的函数实现
void Student::setInfo(const std::string& n, const std::string& s, int a) {
    name = n;
    state = s;
    // 在这里可以添加对年龄的合法性检查，例如防止负数
    age = a;
}

// 获取学生姓名的函数实现
std::string Student::getName() const {
    return name;
}

// 获取学生州份的函数实现
std::string Student::getState() const {
    return state;
}

// 获取学生年龄的函数实现
int Student::getAge() const {
    return age;
}
```

#### 类设计 - 学生类

在设计学生类时，通常遵循以下结构：

1. **构造函数（Constructor）：** 初始化新创建对象的状态。
2. **私有成员函数/变量：** 用于类内部实现和数据封装。
3. **公有成员函数（Public Member Functions）：** 提供给用户的接口，用于访问类的功能。
4. **析构函数（Destructor）：** 在对象生命周期结束时进行资源释放。

##### 学生类设计示例

```cpp
// Student.h (Header File)

#ifndef STUDENT_H
#define STUDENT_H

#include <string>

class Student {
private:
    std::string name;
    std::string state;
    int age;

public:
    // 构造函数
    Student(std::string name, std::string state, int age);

    // 获取姓名的方法
    std::string getName() const;

    // 获取州份的方法
    std::string getState() const;

    // 获取年龄的方法
    int getAge() const;

    // 析构函数
    ~Student();
};

#endif
```

##### Header 文件与 Source 文件的区别

- **Header File (.h):**
  - 用于定义类的接口。
  - 包含函数原型、变量声明、类定义、类型定义、宏和常量、模板定义等。
  
- **Source File (.cpp):**
  - 用于定义在头文件中声明的函数和类的实现。
  - 包含函数实现和可执行代码。

这样的组织结构使得代码更模块化，便于维护和重用。

#### Parameterized Constructor Implementation

在C++中，实现带参数的构造函数需要注意一些重要的细节。以下是一个示例，说明了如何在类的 .cpp 文件中正确实现带参数的构造函数。

##### Student.cpp

```cpp
#include

 "Student.h"
#include <string>

// Implementing the parameterized constructor
Student::Student(std::string name, std::string state, int age) : name(name), state(state), age(age) {}

```

在这个示例中，我们使用了成员初始化列表，这是一种在构造函数中初始化成员变量的推荐方式。这样的写法更为简洁，并提高了代码的可读性。

确保在 .cpp 文件中包含正确的头文件，例如 `<string>`，以引入C++标准库的相关定义。另外，在定义成员函数时，使用类名作为命名空间（例如 `Student::`），以确保在类中正确定义成员函数。

这种组织结构使得代码更清晰、可维护，并符合C++的最佳实践。

##### 使用 `this` 关键字

在C++中，`this` 关键字用于引用当前对象的指针，特别是在类的成员函数中，以区分成员变量和同名的参数。以下是一个带有注释的示例，演示如何在构造函数中使用 `this` 关键字。

**Student.cpp**:

```cpp
#include "Student.h"
#include <string>

// 实现带参数的构造函数，使用 'this' 关键字以明确指示成员变量
Student::Student(std::string name, std::string state, int age) {
    this->name = name;    // 使用 'this' 指针引用成员变量，以区分参数和成员变量
    this->state = state;  // 使用 'this' 指针引用成员变量，以区分参数和成员变量
    this->age = age;      // 使用 'this' 指针引用成员变量，以区分参数和成员变量
}
```

#### 使用列表初始化构造函数（C++11）

在C++11及更高版本中，引入了列表初始化构造函数，它可以通过成员变量的列表直接进行初始化。以下是一个示例，演示了如何在类的构造函数中使用列表初始化。

```cpp
#include "Student.h"
#include <string>

// 实现列表初始化构造函数（C++11）
Student::Student(std::string name, std::string state, int age) 
    : name{name}, state{state}, age{age} {
    // 不需要执行额外的初始化代码，因为已经通过成员初始化列表完成了初始化
}
```

#### 构造函数重载和成员方法

在C++中，通过构造函数重载，我们可以为类提供不同的初始化方式。以下是一个示例，展示了默认构造函数和带参数的构造函数的设计。

```cpp
// 默认构造函数
Student::Student() : name("John Appleseed"), state("CA"), age(18) {}

// 带参数的构造函数
Student::Student(std::string name, std::string state, int age) 
    : name(name), state(state), age(age) {}
```

#### 析构函数

在C++中，析构函数（Destructor）是对象生命周期的一部分，用于释放或回收对象占用的资源。以下是关于析构函数的一些笔记：

```cpp
#include "Student.h"
#include <string>

// 析构函数的实现
Student::~Student() {
    // 在这里释放/回收任何数据
    // 例如：delete [] my_array; （这里仅作为示例）
}
```

在上述示例中，虽然在学生类中没有使用 `new` 关键字进行动态内存分配，但是析构函数仍然是对象生命周期中的重要部分。它提供了释放任何可能占用的资源的机会，即使这些资源并非动态分配。

请注意，析构函数通常不需要显式调用，它会在对象超出作用域时自动调用。这是C++中自动管理资源的一部分，确保资源在不再需要时得到释放。

### 一些其他有趣的类特性

#### 类型别名（Type Aliasing）

类型别名允许你为类型创建同义标识符，提供了一种更直观和可读的方式来表示数据类型。

在C++中，使用 `using` 关键字可以创建类型别名。以下是一个简单的例子：

```cpp
// Type alias for integer
using MyInt = int;

// 使用类型别名
MyInt myVariable = 42;
```

在这个例子中，`MyInt` 被定义为 `int` 的同义标识符，从而使代码更加清晰和易读。

类型别名对于简化复杂的类型声明、提高代码的可读性以及减少重复工作都非常有用。

## Container adapters

All containers in the STL are ⭐classes⭐

## Inheritance

### 为什么使用继承？

- **多态性（Polymorphism）：** 不同的对象可能需要具有相同的接口，以便能够以统一的方式进行处理。通过继承，可以实现多态性，使得不同类型的对象能够被同一种方式使用。

- **可扩展性（Extensibility）：** 继承允许通过创建子类来扩展一个类，从而添加特定的属性或功能。这使得代码更具灵活性，能够在不破坏现有代码的情况下进行扩展。

>virtual function
>
>一个虚函数，意味着它在基类中被实例化，但在子类中被重写。这与多态性（Polymorphism）相关。
>
>在面向对象编程中，虚函数是在基类中声明的函数，它的实现可以在派生类中被覆盖（重写）。通过使用虚函数，可以实现运行时多态性，即在程序运行时确定调用哪个版本的函数，以适应实际的对象类型。
>
>具体而言，当基类中的函数被声明为虚函数时，派生类可以通过提供相同签名的函数来覆盖该函数。在程序执行时，如果使用基类指针或引用调用虚函数，实际调用的是派生类中的版本。
>
>例如：

```cpp
class Base {

public:

  virtual void someFunction() {

​    // Base class implementation

  }

};

class Derived : public Base {

public:

  void someFunction() override {

​    // Derived class implementation, overrides the base class version

  }

};

// 使用虚函数的多态性

Base* ptr = new Derived();

ptr->someFunction();  // 调用的是 Derived 类中的 someFunction
```

>在上述示例中，`someFunction` 被声明为虚函数，因此在运行时，通过基类指针调用该函数时，实际上会调用派生类中的版本。这种机制有助于实现多态性，使得程序能够更灵活地处理不同类型的对象。

面向对象程序设计中最重要的一个概念是继承。继承允许我们依据另一个类来定义一个类，这使得创建和维护一个应用程序变得更容易。这样做，也达到了重用代码功能和提高执行效率的效果。

当创建一个类时，您不需要重新编写新的数据成员和成员函数，只需指定新建的类继承了一个已有的类的成员即可。这个已有的类称为基类，新建的类称为派生类。

继承代表了 is a 关系。例如，哺乳动物是动物，狗是哺乳动物，因此，狗是动物，等等。

### 代码示例

```cpp
// 基类
class Animal {
    // eat() 函数
    // sleep() 函数
};

// 派生类
class Dog : public Animal {
    // bark() 函数
};
```

### 基类 & 派生类

一个类可以派生自多个类，这意味着，它可以从多个基类继承数据和函数。定义一个派生类，我们使用一个类派生列表来指定基类。类派生列表以一个或多个基类命名，形式如下：

```cpp
class derived-class: access-specifier base-class
```

其中，访问修饰符 `access-specifier` 是 `public`、`protected` 或 `private` 其中的一个，`base-class` 是之前定义过的某个类的名称。如果未使用访问修饰符 `access-specifier`，则默认为 `private`。

假设有一个基类 `Shape`，`Rectangle` 是它的派生类，如下所示：

```cpp
#include <iostream>

using namespace std;

// 基类
class Shape 
{
   public:
      void setWidth(int w)
      {
         width = w;
      }
      void setHeight(int h)
      {
         height = h;
      }
   protected:
      int width;
      int height;
};

// 派生类
class Rectangle: public Shape
{
   public:
      int getArea()
      { 
         return (width * height); 
      }
};
```

当上面的代码被编译和执行时，它会产生下列结果：

```cpp
Total area: 35
```

### 访问控制和继承

派生类可以访问基类中所有的非私有成员。因此基类成员如果不想被派生类的成员函数访问，则应在基类中声明为 `private`。

我们可以根据访问权限总结出不同的访问类型，如下所示：

| 访问     | public | protected | private |
|----------|--------|-----------|---------|
| 同一个类  | yes    | yes       | yes     |
| 派生类    | yes    | yes       | no      |
| 外部的类  | yes    | no        | no      |

一个派生类继承了所有的基类方法，但下列情况除外：

- 基类的构造函数、析构函数和拷贝构造函数。
- 基类的重载运算符。
- 基类的友元函数。

### 继承类型

当一个类派生自基类，该基类可以被继承为 `public`、`protected` 或 `private` 几种类型。继承类型是通过上面讲解的访问修饰符 `access-specifier` 来指定的。

我们几乎不使用 `protected` 或 `private` 继承，通常使用 `public` 继承。当使用不同类型的继承时，遵循以下几个规则：

- **公有继承（public）：** 当一个类派生自公有基类时，基类的公有成员也是派生类的公有成员，基类的保护成员也是派生类的保护成员，基类的私有成员不能直接被派生类访问，但是可以通过调用基类的公有和保护成员来访问。

- **保护继承（protected）：** 当一个类派生自保护基类时，基类的公有和保护成员将成为派生类的保护成员。

- **私有继承（private）：** 当一个类派生自私有基类时，基类的公有和保护成员将成为派生类的私有成员。

### 多继承

多继承即一个子类可以有多个父类，它继承了多个父类的特性。

C++ 类可以从多个类继承成员，语法如下：

```cpp
class <派生类名>:<继承方式1><基类名1>,<继承方式2><基类名2>,…
{
<派生类类体>
};
```

其中，访问修饰符继承

方式是 `public`、`protected` 或 `private` 其中的一个，用来修饰每个基类，各个基类之间用逗号分隔。现在让我们一起看看下面的实例：

```cpp
#include <iostream>

using namespace std;

// 基类 Shape
class Shape 
{
   public:
      void setWidth(int w)
      {
         width = w;
      }
      void setHeight(int h)
      {
         height = h;
      }
   protected:
      int width;
      int height;
};
 
// 基类 PaintCost
class PaintCost 
{
   public:
      int getCost(int area)
      {
         return area * 70;
      }
};
 
// 派生类
class Rectangle: public Shape, public PaintCost
{
   public:
      int getArea()
      { 
         return (width * height); 
      }
};

int main(void)
{
   Rectangle Rect;
   int area;

   Rect.setWidth(5);
   Rect.setHeight(7);

   area = Rect.getArea();
   
   // 输出对象的面积
   cout << "Total area: " << Rect.getArea() << endl;

   // 输出总花费
   cout << "Total paint cost: $" << Rect.getCost(area) << endl;

   return 0;
}
```

>Total area: 35
>
>Total paint cost: $2450
