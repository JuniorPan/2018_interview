#include <iostream>
#include <vector> 
using namespace std;





void bubble_sort(vector<int> &nums)
{
    for(int i = 0; i < nums.size()-1; i++)
    {
        cout << "i: " << i << endl;
        cout << "j: " << nums.size() - i -1 << endl;
        for(int j = 0; j < nums.size() - i -1; j++)
        {
            // cout << "j: " << j << endl;
            if (nums[j] > nums[j+1])
            {
                swap(nums[j], nums[j+1]);
            }
        }
    }
}

// var len = arr.length;
//     var minIndex, temp;
//     for (var i = 0; i < len - 1; i++) {
//         minIndex = i;
//         for (var j = i + 1; j < len; j++) {
//             if (arr[j] < arr[minIndex]) {     // 寻找最小的数
//                 minIndex = j;                 // 将最小数的索引保存
//             }
//         }
//         temp = arr[i];
//         arr[i] = arr[minIndex];
//         arr[minIndex] = temp;
//     }
//     return arr;
void select_sort(vector<int> &nums)
{
    if (nums.empty())
        return;
    int min_index;
    for(int i = 0 ; i < nums.size(); i++)
    {
        min_index = i;
        for(int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] < nums[min_index])  // 寻找最小的数
            {
                min_index = j;              // 将最小数的索引保存
            }
        }
        swap(nums[min_index], nums[i]);
    }
}

void insertion_sort(vector<int> &nums)
{
    int i,j;
    for (int i = 1; i < nums.size(); i++) {
        int tmp = nums[i];
        for (j = i; j > 0 && nums[j - 1] > tmp; j--) {
            nums[j] = nums[j - 1];
        }
        nums[j] = tmp;
    }
}

void insert_sort(vector<int> &nums)
{
    if (nums.empty())
        return;

    for(int i = 1; i < nums.size(); i++)
    {
        if (nums[i] < nums[i-1])
        {
            int temp = nums[i];
            int j = i;
            while(j > 0 && temp < nums[j-1])
            {
                nums[j] = nums[j-1];
                j--;
            }
            nums[j] = temp;
        }
    }
}


int partition(vector<int> &nums, int left, int right)
{
    int small = left -1;
    for(int i = left; i < right; i++)
    {
        if (nums[i] < nums[right])
            swap(nums[i], nums[++small]);
    }
    swap(nums[++small], nums[right]);
    return small;
}
// 快排差点忘了。。。
void quickSort(vector<int> &nums, int left, int right)
{
    if (left < right)
    {
        int index = partition(nums, left, right);
        quickSort(nums, left, index - 1);
        quickSort(nums, index + 1, right);
    }
}


void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // 将最大元素设置为堆顶元素
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // 如果 left 比 root 大的话
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // I如果 right 比 root 大的话
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        // 递归地定义子堆
        heapify(arr, n, largest); 
    } 
} 

void heapSort(int arr[], int n) 
{ 
    // 建立堆
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // 一个个从堆顶取出元素
    for (int i=n-1; i>=0; i--) 
    { 
        swap(arr[0], arr[i]);  
        heapify(arr, i, 0); 
    } 
} 


void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 

    int L[n1], R[n2]; 

    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 

    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            i++; 
        } 
        else
        { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    while (i < n1) 
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    while (j < n2) 
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  
void mergeSort(int arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        int m = l+(r-l)/2; 
  
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
} 

int main()
{

    vector<int> nums =  {4,3,1,2,6,5,0,9,8,7};
    // quickSort(nums, 0, nums.size()-1);
    insertion_sort(nums);

    for(int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}




// public void BubbleSort(int[] arr){
// 		for(int i=0;i<arr.length-1;i++){ 
// 			for(int j=0;j<arr.length-1-i;j++){
// 				if(arr[j]>arr[j+1]){ //相邻两个元素作比较，如果前面元素大于后面，进行交换
// 					int temp = arr[j+1];
// 					arr[j+1] = arr[j];
// 					arr[j] = temp;
// 				}
// 			}
// 		}
// 	}
