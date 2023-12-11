#include <iostream>
#include <string>
#include <map>
/*#include <vector>
#include <list>
#include <algorithm> //
#include <iterator> // for ostream_iterator*/

using namespace std;

 // returns an iterator to the first element in the range [first,last) that compares equal to val. If no such element is found, the function returns last.



/*int main(){
    std::vector<int> vector0={1,2,3,4,5,6,7,8,9,10};
    std::list<int> list0={1,2,3,4,5,6,7,8,9,10};

    for (std::vector<int>::iterator it = vector0.begin(); it != vector0.end(); it++) {
        std::cout << *it << " ";
        }
    
    std::find(vector0.begin(), vector0.end(), 5);
    std::find(list0.begin(), list0.end(), 5);


    std::cout << std::endl;

    for (std::list<int>::iterator it = list0.begin(); it != list0.end(); it++) {
        std::cout << *it << " ";
        }
}*/

/*
class Greaterthan{
    public:
        Greaterthan(int p):p(p){}
        bool operator()(int a){
            return a>=p;
        }
    private:
        int p;
};
*/

/*int main(){
    auto f = [](int a, int b) -> int { return a + b; };

    std::cout << f(5, 6) << std::endl;
}
*/
int main() {
    std::map<string, int> map0;
    string ss;
    int ii;

    // 介绍 map 容器
    std::cout << "map 容器是一个关联容器，它将键值对存储在一个有序的容器中。" << std::endl;
    std::cout << "键是唯一的，因此您可以使用键快速访问值。" << std::endl;

    // 初始化 map 容器
    map0["apple"] = 1;
    map0["banana"] = 2;
    map0["orange"] = 3;

    // 遍历 map 容器
    for (auto it = map0.begin(); it != map0.end(); ++it) {
    std::cout << "键：" << it->first << "，值：" << it->second << std::endl;
    }

    // 插入元素
    map0["pear"] = 4;

    // 查找元素
    ii = map0.at("apple");
    std::cout << "查找元素 apple 的值：" << ii << std::endl;

    // 删除元素
    map0.erase("apple");

    // 判断元素是否存在
    if (map0.count("apple") > 0) {
    std::cout << "元素 apple 存在。" << std::endl;
    } else {
    std::cout << "元素 apple 不存在。" << std::endl;
    }

    return 0;
}
