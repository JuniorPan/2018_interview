#include <iostream>
#include <vector>
#include <set>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int Partition(int *a, int n, int start, int end)
{
    int pivot = a[end];
    while(start < end)
    {
        while(start < end && a[start] < pivot)
            start++;
        if (start < end)
        {
            a[end] = a[start];
            end--;
        }

        while(start < end && a[end] > pivot)
            end--;
        if (start < end)
        {
            a[start] = a[end];
            start++;
        }
    }
    a[start] = pivot;
    return start;
}

void getLastKnumbers(int *a, int n, int k)
{
    int index = Partition(a, n, 0, n-1);

    while(index != k-1)
    {
        if (index > k-1)
        {
            index = Partition(a, n, 0, index-1);
        }
        else{
            index = Partition(a, n, index+1, n-1);
        }
    }

    for(int i = 0; i < k; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void TraverseArray(int *a, int n)
{
    for(int i = 0; i < n; i++)
    {
        cout << a[i] << " "; 
    }
    cout << endl;
}



int main()
{


    int a[] = {4,5,1,8,2,7,3,6};
    int n = sizeof(a)/sizeof(a[0]);

    getLastKnumbers(a, n, 4);
    TraverseArray(a, n);
    // int index = Partition(a, n, 0, n-1);
  
    cout << "hello " << endl;
    return 0;
}
// // 利用最大堆
// void getLastKnumbers_2(const vector<int> &data, multiset<int, greater<int>> &leastNumbers, int k)
// {


//     leastNumbers.clear();

//     if (k < 1 || data.size() < k)
//     {
//         return;
//     }

    
//     vector<int>::const_iterator iter = data.begin();

//     for(; iter != data.end(); ++iter)
//     {
//         cout << *iter << endl;
//         if (leastNumbers.size() < k)
//         {
//             leastNumbers.insert(*iter);
            
//         }
//         else
//         {
            
//             if ((*iter) < *(leastNumbers.begin()))
//             {
//                 leastNumbers.erase(leastNumbers.begin());
//                 leastNumbers.insert(*iter);
//             }
//         }
//     }


// }
// int main()
// {
//     vector<int> data = {4,5,1,8,2,7,3,6};
//     multiset<int, greater<int>> leastNumbers;

//     getLastKnumbers_2(data, leastNumbers, 4);

//     multiset<int, greater<int>>::iterator setIter = leastNumbers.begin();
//     while(setIter != leastNumbers.end())
//     {
//         cout << *setIter << " ";
//         ++setIter;
//     }
//     cout << endl;
// }