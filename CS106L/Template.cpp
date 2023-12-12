#include"Template.h"
/*
IntContainer::IntContainer(int value) {
    this->value = value;
}

int IntContainer::getvalue() {
    return this->value;
}

template<typename T>
Container<T>::Container(T value) {
    this->value = value;
}

template<typename T>
T Container<T>::getvalue() {
    return this->value;
}
*/

//What's the difference between the two?

template <class T>
Container<T>::Container(T value) {
    this->value = value;
}

//And
/*
template <class T>
Container::Container(T value) {
    this->value = value;
}
*/
/*
C++ wants us to specify our
template parameters in our
namespace because, based on the
parameters our class may behave
differently!
Note: there is no "one" Container,
there is one for an int, bool, char,
etc., there is one for an int, bool,
char, etc.*/

class IntArray {
private:
    int* _array;    // Pointer to the dynamic integer array
    size_t _size;    // Size of the array

public:
    // Constructor: Initializes the IntArray with a specified size
    IntArray(size_t size);

    // Destructor: Cleans up the dynamically allocated memory
    ~IntArray();

    // Method to access elements in the array by index
    int& at(size_t index);

    // Method to get the size of the array
    size_t size();
};

// Implementation of IntArray constructor
IntArray::IntArray(size_t size) {
    _size = size;
    _array = new int[size];
}

// Implementation of IntArray destructor
IntArray::~IntArray() {
    delete[] _array;
}

// Implementation of IntArray at method
int& IntArray::at(size_t index) {
    return _array[index];
}

// Implementation of IntArray size method
size_t IntArray::size() {
    return _size;
}

int main() {
    IntArray a(10);

    for (size_t i = 0; i < a.size(); i++) {
        a.at(i) = i * 2;
    }

    // Displaying the modified array
    for (size_t i = 0; i < a.size(); i++) {
        std::cout << a.at(i) << " ";
    }
    std::cout << "\n";

    return 0;
}