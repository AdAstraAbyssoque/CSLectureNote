# Initialization and References

## Initialization

**Definition:** initial values at the time of construction

1. Direct initialization
2. Uniform initialization
3. Structured Binding

### Direct initialization

```cpp
#include <iostream>

int main(){
    int numOne 12.0;
    int numTwo(12.5);
    std::cout<<"numOne is:"<<numOne<<std::endl;//cout12
    std::cout<<"numTwo is:"<<numTwo<<std::endl;//cout12
    return 0;
}
```

> narrowing conversion(缩小转换):
>
> 将一个具有较大范围的数据类型转换为较小范围的数据类型的过程。这种转换可能导致数据丢失或截断，因为目标类型的范围无法完全表示源类型的所有可能值。

### Uniform initialization

#### Uniform initialization(C++11)

```cpp
#include <iostream>

int main(){
    int numOne{12.0};//Error
    int numTwo{12.5};//Error
    std::cout<<"numOne is:"<<numOne<<std::endl;
    std::cout<<"numTwo is:"<<numTwo<<std::endl;
    return 0;
}
```

使用Uniform initialization，C++确实care类型。**safe** and **ubiquitous**

#### Uniform initialization (Map)

```cpp
#include <iostream>
#include <map>
int main(){
    //Uniform initialization of a map
    std::map<std :string,int> ages{
        {"Alice",25},
        {"Bob",30},
        {"Charlie",35}
    };
    //Accessing map elements
    std::cout << "Alice's age:"<<ages["Alice"]<<std::endl;
    std::cout <<"Bob's age:"<<ages.at("Bob")<<std :endl;
    return 0;
}
```

#### Uniform initialization (Vector)

```cpp
#include <iostream>
#include <vector>
int main(){
    std vector<int>numbers{1,2,3,4,5};//Uniform initialization of a vector
    //Accessing vector elements
    for (int num numbers){
        std::cout<<num <<" ";
    }
    std::cout<<std::endl;
    return 0;
}
```

#### Uniform initialization (Struct)

```cpp
struct Student{
    string name;
    string state;
    int age;
}
Student s{"Haven","AR",21};
```

### Structured Binding

- 在编译时从具有固定大小的数据结构初始化某些变量的一种有用方式
- 能够访问函数返回的多个值

```cpp
std::tuple<int, double, std::string> person = std::make_tuple(25, 175.5, "Alice");

auto [age, height, name] = person;

std::cout << "Name: " << name << std::endl;
std::cout << "Age: " << age << std::endl;
std::cout << "Height: " << height << std::endl;
```

## References

**Definition:** Declares a name variable as a reference

**tldr def:** a reference is an alias to an already-existing thing

**How:** 使用**与**符号 (&)

### The & and the how

```cpp
int num 5;
int&ref num;
ref 10;//Assigning a new value through the reference
std::cout<<num<<std::endl;//Output:10
```

num是一个类型为int的变量，被赋予值为5。

ref是一个类型为int&的变量，它是对num的别名。

当我们改变ref时，我们也会改变num，因为它是一个引用。

### Pass by reference

```cpp
#include <iostream>
#include <math.h>
//note the ampersand!
void squareN(int& n){
    std:pow(n,2);//calculates n to the power of 2
int main(){
    int num 2;
    squareN(num)
    std::cout<<num<<std::endl;
}
```

n通过引用传递给squareN函数，用&号表示，这意味着n实际上会在squareN函数内部被修改，**Reference**引用与其关联变量相同的内存空间。将一个变量**通过**引用传递给一个函数只是意味着"接受实际的内存块，不要复制"。将一个变量通过**值**传递给一个函数只是意味着"复制一份，不要接受实际的变量"。

### Edge cases

> A classic reference-copy bug

```cpp
#include<iostream>
#include<math.h>
#include<vector>
void shift(std::vector<std::pair<int,int>> &nums){
    for (auto [numl,num2]:nums){
    numl++;
    num2++;
    }
}
int main(){
    std::vector<std::pair<int,int>> nums;
    nums.push_back(std::make_pair(1,2));
    nums.push_back(std::make_pair(3,4));
    shift(nums);
    for (auto [numl,num2]:nums){
    std::cout<<numl<<" "<<num2<<std::endl;
    }
    return 0;
}
```

我们在这个函数中没有修改nums。 我们修改的是nums中的std::pair,所以num1++的生命周期就只在函数内。

如果要解决，要写    `for (auto [numl,num2]:nums){`

## L-values vs R-values

### L-values

一个l-value可以位于等号的左侧或右侧。
`x`是一个l-value，因为你可以有类似下面的表达式：`int y = x` ✅ AND ✅ `x = 344`

### R-values

一个r-value只能位于等号的右侧。

21是一个r-value，因为你只可以有类似下面的表达式：`int y = 21`❌ BUT NOT ❌`21 = x`

### Example

```cpp
#include <stdio.h>
#include <cmath>
#include <iostream>

int squareN(int& num) {
    return std::pow(num, 2);
}

int main() {
    int lValue = 2;
    auto four = squareN(lValue);
    auto fourAgain = squareN(2);//非常量引用的初始值必须为左值C/C++(461)
    std::cout << four << std::endl;
    return 0;
}
```

num是一个l-value！
1.记住我们说过的r-value是临时的。注意num是通过引用传递的。
2.我们不能通过引用传递一个r-value，因为它们是临时的。

## Const

**Definition:** A qualifier for objects that declares they cannot be modified.

```cpp
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec{1, 2, 3}; // a normal vector
    const std::vector<int> const_vec{1, 2, 3}; // a const vector
    std::vector<int>& ref_vec{vec}; // a reference to 'vec'
    const std::vector<int>& const_ref{vec}; // a const reference

    vec.push_back(3); // this is OKAY!
    // const_vec.push_back(3); // No, this is const! (compile error)
    ref_vec.push_back(3); // this is ok, just a reference!
    // const_ref.push_back(3); // this is const, compile error

    return 0;
}
```

```cpp
#include <iostream>
#include <vector>

int main()
{
    const std::vector<int> vec{1, 2, 3}; // a const vector
    std::vector<int>& bad_ref{const vec}; // BAD

    return 0;
}
```

```cpp
#include <iostream>
#include <vector>

int main() {
    const std::vector<int> const_vec{1, 2, 3}; // a const vector!
    const std::vector<int>& const_ref_vec{const_vec}; // Good!
    return 0;
}
```
