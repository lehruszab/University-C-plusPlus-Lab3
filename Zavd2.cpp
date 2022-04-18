#include <iostream>

using namespace std;

template<class T>

class TArray
{
    public:
        T** array;
        T* array_odnovimir;
        int row, col; 
        T sredne = 0;
        
    TArray()
    {
        row = 2;
	    col = 2;
        array = (T**)malloc(row*sizeof(T*));
	    for(int i=0; i<row; i++)
    		array[i] = (T*)malloc(col*sizeof(T));
    }
    
    TArray(int rows, int colums)
    {
        row = rows;
	    col = colums;
	    array = (T**)malloc(row*sizeof(T*));
	    for(int i=0; i<row; i++)
    		array[i] = (T*)malloc(col*sizeof(T));
    }
    
    ~TArray()
    {
        
    }
    
    
    
    void set_array()
    {
	    cout<<endl<< "Enter numbers of array:" <<endl;
	    for(int i=0; i<row; i++)
	    {
    		for(int j=0; j<col; j++)
		    {    
    			cout <<"array["<< i <<"]["<< j << "] = ";
			    cin >> array[i][j];
		    }
	    } 
    }
    
    void get_array()
    {
	    for(int i=0; i < row; i++)
	    {
	        for(int q = 0; q < col; q++)
	        {
    		    cout<<array[i][q]<< " | ";
	        }
	    cout<<endl;
    	}
    }
    
    
    void seredne_arefmet()
    {
        int size = col;
    	array_odnovimir = new T[size];
    	int p = 0;
        for(int y = 0; y < col; y++)
        {
            for(int x = 0; x < row; x++)
            {
                if(array[x][y] > 0)
                {
                    p++;
                    sredne = array[x][y] + sredne;   
                }
            }
            float j = (sredne/p);
            array_odnovimir[y] = j;
            p = 0;
            sredne = 0;
        } 
    }
    
    void print_array()
    {
    cout << endl << "Новий одновмірний масив:" << endl;
	    for(int i=0; i < col; i++)
	    {
    		cout<<endl<<"Array["<<i<<"] = "<<array_odnovimir[i];
    	}
    }
    
    
};


int main()
{
    int rows,colums;
	cout << "Enter the rows of array:" << endl;
	cin >> rows;
	cout << "Enter the colums of array:" << endl;
	cin >> colums;
	
	TArray<float> obj1(rows, colums);
	
	obj1.set_array();
    obj1.get_array();
    
    /******************************************************************************
    Завдання з лабораторної роботи №1 Варіант 7 
    Розробити метод-член класу для створення нового одновимірного масиву 
    з середнім арифметичним значенням всіх позитивних елементів
    кожного стовпця заданого двовимірного динамічного масиву.
    *******************************************************************************/
    
    obj1.seredne_arefmet();
    obj1.print_array();
    
    return 0;
}
