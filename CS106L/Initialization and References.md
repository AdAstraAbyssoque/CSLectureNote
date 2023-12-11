# Initialization and References

## 初始化

### 直接初始化

```cpp
#include <iostream>

int main() {
    int numOne = 12.0;
    int numTwo(12.5);
    std::cout << "numOne is: " << numOne << std::endl;
    std::cout << "numTwo is: " << numTwo << std::endl;
    return 0;
}
```

在直接初始化中，您在声明变量时为其赋值。然而，代码中的注释需要稍作更正：

```cpp
#include <iostream>

int main() {
    int numOne = 12.0; // 错误：这将无法成功编译。值的类型为double，但被赋给了int。
    int numTwo(12.5); // 错误：这将无法成功编译。值的类型为double，但被赋给了int。
    std::cout << "numOne is: " << numOne << std::endl;
    std::cout << "numTwo is: " << numTwo << std::endl;
    return 0;
}
```

### 统一初始化

#### 示例1

```cpp
#include <iostream>

int main() {
    int numOne{12.0}; // 错误：尝试进行缩小转换，这将无法成功编译。
    int numTwo{12.5}; // 错误：尝试进行缩小转换，这将无法成功编译。
    std::cout << "numOne is: " << numOne << std::endl;
    std::cout << "numTwo is: " << numTwo << std::endl;
    return 0;
}
```

#### 示例2（Map）

```cpp
#include <iostream>
#include <map>

int main() {
    // 对map进行统一初始化
    std::map<std::string, int> ages{
        {"Alice", 25},
        {"Bob", 30},
        {"Charlie", 35}
    };

    // 访问map元素
    std::cout << "Alice的年龄：" << ages["Alice"] << std::endl;
    std::cout << "Bob的年龄：" << ages.at("Bob") << std::endl;
    return 0;
}
```

#### 示例3（Vector）

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers{1, 2, 3, 4, 5}; // 对vector进行统一初始化

    // 访问vector元素
    for (int num : numbers) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}
```

#### 示例4（Struct）

```cpp
struct Student {
    std::string name;
    std::string state;
    int age;
};

int main() {
    Student s{"Haven", "AR", 21};
    return 0;
}
```

### 结构化绑定

```cpp
#include <iostream>
#include <tuple>

int main() {
    std::tuple<int, double, std::string> person = std::make_tuple(25, 175.5, "Alice");

    auto [age, height, name] = person;

    std::cout << "姓名：" << name << std::endl;
    std::cout << "年龄：" << age << std::endl;
    std::cout << "身高：" << height << std::endl;
    return 0;
}
```

## 引用

### & 和 How

```cpp
#include <iostream>

int main() {
    int num = 5;
    int &ref = num;
    ref = 10; // 通过引用修改原始变量的新值
    std::cout << num << std::endl; // 输出：10
    return 0;
}
```

在注释中，说明引用`ref`是如何通过修改原始变量`num`来进行修改的。

```cpp
#include <iostream>

int main() {
    int num = 5;
    int &ref = num;
    ref = 10; // 通过引用‘ref’修改原始变量‘num’
    std::cout << num << std::endl; // 输出：10
    return 0;
}
```

### 通过引用传递

```cpp
#include <iostream>
#include <cmath>

// 注意这个引用符号！
void squareN(int &n) {
    std::pow(n, 2); // 计算n的2次方
}

int main() {
    int num = 2;
    squareN(num);
    std::cout << num << std::endl;
    return 0;
}
```

考虑提供一个通过引用成功修改传递变量的函数的例子。

```cpp
#include <iostream>
#include <cmath>

void squareN(int &n) {
    n = std::

pow(n, 2); // 通过引用‘n’修改原始变量‘n’
}

int main() {
    int num = 2;
    squareN(num);
    std::cout << num << std::endl; // 输出：4
    return 0;
}
```

### 边缘案例

#### 经典引用复制错误

```cpp
#include <iostream>
#include <vector>

void shift(std::vector<std::pair<int, int>> &nums) {
    for (auto &[num1, num2] : nums) {
        num1++;
        num2++;
    }
}

int main() {
    std::vector<std::pair<int, int>> nums;
    nums.push_back(std::make_pair(1, 2));
    nums.push_back(std::make_pair(3, 4));
    shift(nums);
    for (const auto &[num1, num2] : nums) {
        std::cout << num1 << " " << num2 << std::endl;
    }
    return 0;
}
```

在注释中，澄清`const auto &[num1, num2]`中的`const`是为了防止意外修改。

```cpp
#include <iostream>
#include <vector>

void shift(std::vector<std::pair<int, int>> &nums) {
    for (auto &[num1, num2] : nums) {
        num1++;
        num2++;
    }
}

int main() {
    std::vector<std::pair<int, int>> nums;
    nums.push_back(std::make_pair(1, 2));
    nums.push_back(std::make_pair(3, 4));
    shift(nums);
    for (const auto &[num1, num2] : nums) {
        std::cout << num1 << " " << num2 << std::endl;
    }
    return 0;
}
```

## 左值 vs 右值

### 示例

```cpp
#include <iostream>

int squareN(int &num)

 {
    return std::pow(num, 2);
}

int main() {
    int lValue = 2;
    auto four = squareN(lValue);
    auto fourAgain = squareN(2); // 错误：不允许对右值进行非const引用
    std::cout << four << std::endl;
    return 0;
}
```

在注释中，澄清为什么`auto fourAgain = squareN(2);`是一个错误，提到非const引用不能用于右值。

```cpp
#include <iostream>

int squareN(int &num) {
    return std::pow(num, 2);
}

int main() {
    int lValue = 2;
    auto four = squareN(lValue);
    auto fourAgain = squareN(2); // 错误：不允许对右值进行非const引用
    std::cout << four << std::endl;
    return 0;
}
```

## Const

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec{1, 2, 3}; // 一个普通的vector
    const std::vector<int> const_vec{1, 2, 3}; // 一个const vector
    std::vector<int> &ref_vec{vec}; // 对'vec'的引用
    const std::vector<int> &const_ref{vec}; // 一个const引用

    vec.push_back(3); // 这是可以的！
    // const_vec.push_back(3); // 不可以，这是const！（编译错误）
    ref_vec.push_back(3); // 这是可以的，只是一个引用！
    // const_ref.push_back(3); // 这是const，编译错误

    return 0;
}
```

添加注释以澄清代码中每行的目的和功能。

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec{1, 2, 3}; // 一个普通的vector
    const std::vector<int> const_vec{1, 2, 3}; // 一个const vector
    std::vector<int> &ref_vec{vec}; // 对'vec'的引用
    const std::vector<int> &const_ref{vec}; // 一个const引用

    vec.push_back(3); // 这是可以的！修改原始向量'vec'
    // const_vec.push_back(3); // 不可以，这是const！（编译错误）
    ref_vec.push_back(3); // 这是可以的，只是一个引用！通过引用'ref_vec'修改原始向量'vec'
    // const_ref.push_back(3); // 这是const，编译错误

    return 0;
}
```
