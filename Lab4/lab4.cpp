#include <iostream>
using namespace std;

template <typename T>
class DynamicArray {
private:
    T* arr;         // указатель на массив
    int capacity;   // максимальный размер
    int size;       // текущий размер

public:
    // Конструкторы
    DynamicArray();                     // по умолчанию
    DynamicArray(int initCapacity);     // с заданной емкостью
    DynamicArray(const DynamicArray& other); // копирования

    // Деструктор
    ~DynamicArray();

    // Оператор присваивания
    DynamicArray& operator=(const DynamicArray& other);

    // Методы ввода/вывода
    void input();
    void print() const;

    // Доступ по индексу
    T& operator[](int index);
    const T& operator[](int index) const;

    // Проверка на равенство
    bool operator==(const DynamicArray& other) const;

    // Проверка на неравенство
    bool operator!=(const DynamicArray& other) const;

    // Получение размера
    int getSize() const;
};

template <typename T>
DynamicArray<T>::DynamicArray() : arr(nullptr), capacity(0), size(0) {}

template <typename T>
DynamicArray<T>::DynamicArray(int initCapacity) : capacity(initCapacity), size(0) {
    arr = new T[capacity];
}

template <typename T>
DynamicArray<T>::DynamicArray(const DynamicArray& other) : capacity(other.capacity), size(other.size) {
    arr = new T[capacity];
    for (int i = 0; i < size; i++) {
        arr[i] = other.arr[i];
    }
}

template <typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] arr;
}

template <typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray& other) {
    if (this != &other) {
        delete[] arr;
        capacity = other.capacity;
        size = other.size;
        arr = new T[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }
    return *this;
}

template <typename T>
void DynamicArray<T>::input() {
    cout << "Enter size: ";
    cin >> size;
    if (size > capacity) {
        delete[] arr;
        capacity = size;
        arr = new T[capacity];
    }
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}

template <typename T>
void DynamicArray<T>::print() const {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
T& DynamicArray<T>::operator[](int index) {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    return arr[index];
}

template <typename T>
const T& DynamicArray<T>::operator[](int index) const {
    if (index < 0 || index >= size) {
        throw out_of_range("Index out of range");
    }
    return arr[index];
}

template <typename T>
bool DynamicArray<T>::operator==(const DynamicArray& other) const {
    if (size != other.size) return false;
    for (int i = 0; i < size; i++) {
        if (arr[i] != other.arr[i]) return false;
    }
    return true;
}

template <typename T>
bool DynamicArray<T>::operator!=(const DynamicArray& other) const {
    return !(*this == other);
}

template <typename T>
int DynamicArray<T>::getSize() const {
    return size;
}

class Complex {
private:
    int re;
    int im;

public:
    Complex(int r = 0, int i = 0) : re(r), im(i) {}

    bool operator==(const Complex& other) const {
        return re == other.re && im == other.im;
    }

    bool operator!=(const Complex& other) const {
        return !(*this == other);
    }

    friend ostream& operator<<(ostream& os, const Complex& c) {
        os << c.re << "+" << c.im << "i";
        return os;
    }

    friend istream& operator>>(istream& is, Complex& c) {
        is >> c.re >> c.im;
        return is;
    }
};

int main() {
    // Тест для int
    DynamicArray<int> arr1, arr2;
    arr1.input();
    arr2.input();

    cout << "Array 1: ";
    arr1.print();
    cout << "Array 2: ";
    arr2.print();

    cout << "arr1 == arr2: " << (arr1 == arr2) << endl;
    cout << "arr1 != arr2: " << (arr1 != arr2) << endl;

    // Тест для Complex
    DynamicArray<Complex> cArr1, cArr2;
    cArr1.input();
    cArr2.input();

    cout << "Complex Array 1: ";
    cArr1.print();
    cout << "Complex Array 2: ";
    cArr2.print();

    cout << "cArr1 == cArr2: " << (cArr1 == cArr2) << endl;
    cout << "cArr1 != cArr2: " << (cArr1 != cArr2) << endl;

    return 0;
}