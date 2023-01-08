


#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;


 bool isPerfectSquare(int num) {
        int left = 1, right = num;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if(mid  == num / mid)
                return true;
            else if (mid   < num / mid) 
                left = mid;
            else 
                right = mid - 1;
        }
        return right * right == num;
    }


int main()
{

    cout << "is_ok: " << isPerfectSquare(14) << endl;

    return 0;


}