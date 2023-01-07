#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

int trap_1(vector<int> &height)
    {
        if (height.empty())
            return 0;
        int res = 0;
        int i = 0;

        stack<int> monoStack;
        // height.push_back(0);
        for (int i = 0; i < height.size(); i++)
        {
            while (!monoStack.empty() && height[i] > height[monoStack.top()]) // 但栈非空时，且当前元素大于栈顶元素时，进行弹出操作，并且结算该弹出元素
            // 栈顶元素的下一个元素则为左边界，当前遍历到的height[i]则为右边界
            {
                int tmp = monoStack.top();
                monoStack.pop();
                if (monoStack.empty())
                    continue;

                int h = min(height[i], height[monoStack.top()]);

                cout << "i: " << i <<  " cur_area: " << (h - height[tmp]) * (i - monoStack.top() - 1) << endl;
                res = res + (h - height[tmp]) * (i - monoStack.top() - 1);
            }
            monoStack.push(i);
        }
        return res;
    }

int main()
{


    vector<int> height = {2,1,0,1,3};
    int res = trap_1(height);
    cout << "res: " << res << endl;
    return 0;
}