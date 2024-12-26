#include <iostream>

using namespace std;

template<typename T>
class Vector
{
public:

    Vector();
    Vector(int size);
    Vector(const Vector<T> &other);
    ~Vector();

public:

    T& operator[](const int &index) { return data[index]; }

    int Size(){ return size; }
    int Capacity(){ return capacity; }
    
    void insert(const T &value,int index);
    void push_back(const T &value);
    void pop_back();
    void clear();

private:
    T *data;
    int size;
    int capacity;
};

template <typename T>
Vector<T>::Vector()
{
    data = nullptr;
    size = 0;
    capacity = 0;
}

template <typename T>
Vector<T>::Vector(int size)
{
    this->size = size;
    this->capacity = size + 2;
    this->data = new T[capacity];
}

template <typename T>
Vector<T>::Vector(const Vector<T> &other)
{
    this->size = other.size;
    this->capacity = other.capacity;
    this->data = new T[other.capacity];

    for (int i = 0 ; i < size; i ++)
    {
        this->data[i] = other.data[i];
    }
}

template <typename T>
Vector<T>::~Vector()
{
    delete[] data;   
}

template <typename T>
void Vector<T>::insert(const T &value,int index)
{
    if(index < 0 || index > size)
    {
        cout << "Doesn't memmory" << endl;
    }
    else
    {   
        size++;
        for(int i = index; i < size; ++i)
        {
            data[i+1] = data[i];
        }
        data[index] = value;

    }
    
    
}

template <typename T>
void Vector<T>::push_back(const T &value)
{   
    
    T *new_data = new T[size];

    for (int i = 0; i < size; i++)
    {
        new_data[i] = data[i];
    }

    new_data[size] = value;

    delete[] data;
    data = new_data;
    size++;
    capacity++;

}

template <typename T>
void Vector<T>::pop_back()
{
    T *tmp = new T[size];
    for (int i = 0; i < size-1; ++i)
    {
        tmp[i] = data[i];
    }

    delete[] data;
    data = tmp;
    size--;
    capacity--;
}

template <typename T>
void Vector<T>::clear()
{
    for(int i = 0; i < size+2; ++i)
    {
        pop_back();
    }
}


int main()
{   
    
    Vector<int> arr;

    arr.push_back(10);
    arr.push_back(12);
    arr.push_back(34);
   
    for(int i = 0; i < arr.Size(); ++i)
    {
        cout << arr[i] << " | ";
    }

    cout << "\n";

    arr.pop_back();
    
    for(int i = 0; i < arr.Size(); ++i)
    {
        cout << arr[i] << " | ";
    }

    arr.clear();

    cout << "\n" << arr.Size() << endl;
    
    return 0;
}
