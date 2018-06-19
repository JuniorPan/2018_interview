#include <iostream>
using namespace std;

void swap(char* array, unsigned int i, unsigned int j)  
{  
    char t = array[i];  
    array[i] = array[j];  
    array[j] = t;  
}  
  
/* 
 * 递归输出序列的全排列 
 */  

void FullArray(char* array, int array_size,  int index, int *count)  
{  
    
    if(index >= array_size)  
    {  
        for(int i = 0; i < array_size; ++i)  
        {  
            cout << array[i] << ' ';  
        }  
        cout << '\n';  
        (*count) ++;
        return;  
    }  
  
    for(int i = index; i < array_size; ++i)  
    {  
        swap(array, i, index);  
  
        FullArray(array, array_size, index + 1, count);  
  
        swap(array, i, index);  
    }  
}  


int main()
{
    char array[] = {'a','b','c','d'};
    int count = 0;
    FullArray(array, 4, 0, &count); 
    cout << count << endl;
}