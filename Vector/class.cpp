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
