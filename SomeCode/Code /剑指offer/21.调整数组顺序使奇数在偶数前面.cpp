#include <iostream>
#include <vector>
using namespace std;


void reOrderArray(vector<int> &array) {
        
        int n = array.size();
        if (n <= 0)
            return ;
        
        int low = 0; 
        int high = n-1;
        
        while(low < high)
        {
            while(low < high && (array[low] % 2) != 0) 
                low ++;
            
            while(low < high && (array[high] % 2) == 0)
                high --;
            
            if (low < high)
            {
                int temp = array[low];
                array[low] = array[high];
                array[high] = temp;
            }
        }
    }

    int main()
    {
        vector<int> array = {1,2,3,4,5,6,7};
        reOrderArray(array);

        for(int i = 0; i < array.size(); i++)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }