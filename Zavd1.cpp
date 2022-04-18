#include <iostream>
#include <typeinfo>

using namespace std;


template <class T> 

class Massiv
{
public:
    int size;
    T * array;
    int * array_new;

public:
    Massiv()
    {
        size = 0;
        array = NULL;
    }
    
    Massiv(int m_size)
    {
        size = m_size;
        array = new T[size];
    }
    
    ~Massiv()
    {
        
    }
    
    void add()
    {
        for(int q = 0; q < size; q++)
        {
            T x;
            cout << "Enter array element №"<< q+1 << ": ";
          cin >> x;
            array[q]=x;
        }  
    }
    
    void show()
    {
        cout << "Array: ";
        for (int i=0;i < size; i++)
        {
            cout << array[i] << ", ";
        }
        cout << endl;
    }
    
    void creat_array()
    {
        array_new = new int[size-1];
        for(int p = 0; p < (size-1); p++)
        {
            array_new[p] = array[p] * array[p+1];
        }
        
        cout << "New array: ";
        for (int i=0;i < size-1; i++)
        {
            cout << array_new[i] << ", ";
        }
        cout << endl;
    }
    
};

int main()
{
    int size;
    
    cout << "Enter the size of array:" << endl;
  cin >> size;
    Massiv<int> obj1(size);
    cout << "Array type int created" << endl;
    obj1.add();
    
    cout << "Enter the size of array:" << endl;
  cin >> size;
    Massiv<string> obj2(size);
    cout << "Array type string created" << endl;
    obj2.add();
    
    cout << "Enter the size of array:" << endl;
  cin >> size;
    Massiv<float> obj3(size);
    cout << "Array type float created" << endl;
    obj3.add();
    
    cout << "Enter the size of array:" << endl;
  cin >> size;
    Massiv<char> obj4(size);
    cout << "Array type char created" << endl;
    obj4.add();
    
    obj1.show();
    obj2.show();
    obj3.show();
    obj4.show();
    
    obj1.creat_array();
    
    return 0;
}