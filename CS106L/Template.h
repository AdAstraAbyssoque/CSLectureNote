#include<bits/stdc++.h>

template<typename T>
class Container {
    public:
    Container(T value);
    T getvalue();
    private:
    T value;
};

//Compare with original class

class IntContainer {
    public:
    IntContainer(int value);
    int getvalue();
    private:
    int value;
};