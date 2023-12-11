# Containers

## Defining Containers

What is a container in C++?
An object that allows us to collect other objects together and interact with them in some way.
容器是一种对象，它允许我们将其他对象集合在一起，并以某种方式与它们进行交互。在C++中，容器是用来存储和管理数据的数据结构，例如向量（vector）、栈（stack）或队列（queue）。这些容器提供了方便的方法来添加、访问和操作存储的元素。

为什么使用容器？——编程语言中的容器类型有什么目的？
    - 有组织：相关的数据可以被打包在一起
    - 标准化：常见的特征通常被期望和实现为标准化
    - 抽象：复杂的概念可以通过简化，使客户更容易利用。

以前的代码：

```cpp
struct Student {
    string name;
    string state;
    int age;
};

int main() {
    Student s;
    s.name = "Haven";
    s.state = "AR";
    s.age = 21;
    
    // 其他代码...
    
    return 0;
}
```

>这是可以泛化的！我们不应该需要创建一个全新的系统来存储不同类型的数据...容器应运而生

## Containers in the STL vs Stanford

Types of containers and how they work

通常，容器会提供一些标准和基本的功能。

- 允许您存储多个对象（尽管类型相同）
- 通过某种方式（可能是有限的方式）允许对集合进行访问
  - 可能允许对所有对象进行迭代
- 可能允许编辑/删除操作

一些新的容器：

- **数组**（Array）是向量（Vector）的基本形式，具有固定的大小和严格的顺序。

- **双端队列**（Deque）是一种双向的队列，可以在队列的两端进行插入和删除操作。

- **链表**（List）是一种双向链表，可以在任一方向上遍历和操作链表中的元素。

![PngComparasion](/CS106L/assets/image.png)

我们注意到，**STL**没有边界检查。在选择编程语言时，速度、功能和安全性之间总是存在着权衡。

>C++的设计哲学包括：
>
>- 只提供必要的检查和安全保障：C++的设计哲学是尽可能地提供高效的编程环境，对程序员的需求给予最大程度的灵活性和控制权。因此，C++通常只提
供必要的检查和安全保障，而不会过多地增加运行时开销或限制程序员的选择。
>
>- 程序员最了解：C++鼓励程序员对代码进行全面的控制和优化。它相信程序员在编写代码时具有最适合其需求的知识和判断力。C++提供了丰富的功能和底层访问权限，以便程序员可以根据特定的要求和场景进行低级优化，并根据自己的经验和判断做出最佳的决策。

有两种类型的容器：

- 序列（Sequence）：
  - 可以按顺序进行访问的容器
  - 任何具有固有顺序的对象都适用于此类容器

- 关联（Associative）：
  - 不一定具有顺序的容器
  - 更容易进行搜索
  - 映射（Map）和集合（Set）属于此类容器

### Sequence Container

#### Vector

在高层次上，向量是一个**有序的**、**相同类型的**元素集合，它可以在*大小上增长和缩小*。
内部实现上，向量使用数组来实现！

我们会跟踪几个成员变量：

- _size = 向量中元素的数量
- _capacity = 分配给元素的空间大小

#### Deque

一种双端队列的实现方式是使用数组来**存储其他数组**，每个子数组代表队列中的一个元素。

这种实现方式可以使用数组的**索引**或**指针**来跟踪队列的前端和后端。

插入和删除操作可以通过调整指针位置和操作子数组来实现。如果需要，可以调整内部数组的大小或移动元素。

#### Summary

- 序列容器用于在信息中需要强制某种顺序时使用！
- 通常可以使用 `std::vector` 来处理大多数情况
- 如果需要在前端进行快速插入操作，请考虑使用 `std::deque`
- 如果需要合并/操作多个列表，请考虑使用 `std::list`（很少使用）

### Associative Container

Abstracting container implementation

#### Map

Map是通过pairs（`std::pair<const key, value>`）来实现的。

在C++中，Map通常是通过使用std::map或std::unordered_map来实现的。这两个容器都是关联容器，可以存储键值对，并根据键来进行快速查找。在这种实现中，每个元素都被表示为std::pair<const key, value>，其中const key是键类型，value是对应的值类型。

##### `Map`

```cpp
std::map<KeyType, ValueType> myMap;
KeyType key = // 指定要查找的键
ValueType value;

// 使用at()函数获取值
value = myMap.at(key);

// 或者使用operator[]运算符获取值
value = myMap[key];
```

- 注意const！键必须是不可变的。
- 对Map进行索引（`myMap[key]`）会在底层的键值对集合中搜索匹配的键的第一个属性，并返回其第二个属性。

##### `Unordered maps/sets`

STL中的Map和Set都有无序版本！

- 有序的Map/Set需要定义一个比较运算符。
- 无序的Map/Set需要定义一个哈希函数。

Unordered maps/sets are usually faster than ordered ones!

##### Aside: Hash

哈希函数本质上提供了从某个复杂对象到一个数字的映射！

- 计算这种映射的行为被称为哈希（Hashing）。

如果你能找到一个好的哈希函数，你几乎可以对任何东西进行哈希！

- 字符串
- 结构体（Structs）
- 对象
- 甚至其他数字！

> 如何选择好的哈希函数？
>
> - **计算速度快**
> - **总是将相同的输入映射到相同的输出**
> - **尽可能避免碰撞**
>
```python
# 糟糕的哈希函数示例
def hashFn(x):
    return 1
```

映射和集合之间的相似之处

**总体建议：**

- 无序容器更快，但在处理嵌套容器/集合时可能更难。
- 如果使用复杂的数据类型或对哈希函数不熟悉，建议使用有序容器。

## Container Adaptors

容器适配器是对现有容器的“包装”！

- 包装器修改序列容器的接口，并改变客户端允许执行的操作以及与容器的交互方式。
- 再次强调抽象化：
  - 使常用数据结构对客户端更易于使用。
  - 可以根据使用类型选择不同的后备容器。

## Sum

- 容器是将相关数据集合在一起并以逻辑方式处理的方式。
- 两种类型的容器：序列容器和关联容器。
- 容器适配器对现有容器进行包装，以允许对客户端的接口进行新的限制或访问。
