## LeetCode 刷题记录
### 滑动窗口问题
核心思想: 我们可以用滑动窗口的思想解决这个问题，在滑动窗口类型的问题中都会有两个指针。一个用于「延伸」现有窗口的 rr 指针，和一个用于「收缩」窗口的 ll 指针。在任意时刻，只有一个指针运动，而另一个保持静止。我们在 ss 上滑动窗口，通过移动 rr 指针不断扩张窗口。当窗口包含 tt 全部所需的字符后，如果能收缩，我们就收缩窗口直到得到最小窗口。
![滑动窗口示意](https://assets.leetcode-cn.com/solution-static/76/76_fig1.gif)

```
// 基本框架
int left = 0, right = 0;
while (right < s.size()) {
    // 增大窗口
    window.add(s[right]);
    right++;
    
    while (window needs shrink) {
        // 缩小窗口
        window.remove(s[left]);
        left++;
    }
}
```

#### [424. Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/)   
见https://www.cnblogs.com/grandyang/p/5999050.html 

**不太懂的地方在于窗口是如何移动的**

```
 
/*
如果没有k的限制，让我们求把字符串变成只有一个字符重复的字符串需要的最小置换次数，那么就是字符串的总长度减去出现次数最多的字符的个数。如果加上k的限制，我们其实就是求满足 (子字符串的长度减去出现次数最多的字符个数)<=k 的最大子字符串长度即可，搞清了这一点，我们也就应该知道怎么用滑动窗口来解了吧。我们用一个变量 start 记录滑动窗口左边界，初始化为0，然后遍历字符串，每次累加出现字  符的个数，然后更新出现最多字符的个数，然后我们判断当前滑动窗口是否满足之前说的那个条件，如果不满足，我们就把滑动窗口左边界向右移动一个，并注意去掉的字符要在 counts 里减一，直到满足条件，我们更新结果 res 即可。需要注意的是，当滑动窗口的左边界向右移动了后，窗口内的相同字母的最大数貌似可能会改变啊，为啥这里不用更新 maxCnt 呢？这是个好问题，原因是此题让求的是最长的重复子串，maxCnt 相当于卡了一个窗口大小，我们并不希望窗口变小，虽然窗口在滑动，但是之前是出现过跟窗口大小相同的符合题意的子串，缩小窗口没有意义，并不会使结果 res 变大，所以我们才不更新 maxCnt 的
*/
int characterReplacement(string s, int k)
{
    int res = 0, maxCnt = 0, start = 0;
    vector<int> counts(26, 0);
    for (int i = 0; i < s.size(); ++i)
    {
        maxCnt = max(maxCnt, ++counts[s[i] - 'A']); // 不断记录当前窗口中出现最多的字符的个数
        while (i - start + 1 - maxCnt > k) // 不满足的条件已经理解了
        {
            --counts[s[start] - 'A'];
            ++start;
        }
        res = max(res, i - start + 1);
    }
    return res;
}
```
#### [438. Find All Anagrams in a String](https://leetcode.com/problems/find-all-anagrams-in-a-string/)

```
vector<int> findAnagrams(string s, string p)
{
    vector<int> pv(26, 0), sv(26, 0), res;
    if (s.size() < p.size())
        return res;
    // fill pv, vector of counters for pattern string and sv, vector of counters for the sliding window
    for (int i = 0; i < p.size(); ++i)
    {
        ++pv[p[i] - 'a'];
        ++sv[s[i] - 'a'];
    }
    if (pv == sv)
        res.push_back(0);

    //here window is moving from left to right across the string.
    //window size is p.size(), so s.size()-p.size() moves are made
    for (int i = p.size(); i < s.size(); ++i)
    {
        // window extends one step to the right. counter for s[i] is incremented
        ++sv[s[i] - 'a'];

        // since we added one element to the right,
        // one element to the left should be discarded.
        //counter for s[i-p.size()] is decremented
        --sv[s[i - p.size()] - 'a'];

        // if after move to the right the anagram can be composed,
        // add new position of window's left point to the result
        if (pv == sv) // this comparison takes O(26), i.e O(1), since both vectors are of fixed size 26. Total complexity O(n)*O(1) = O(n)
            res.push_back(i - p.size() + 1);
    }
    return res;
}
```





#### [567. Permutation in String](https://leetcode.com/problems/permutation-in-string/)

 解法一 其他解法见 [[LeetCode] Permutation in String 字符串中的全排列](https://www.cnblogs.com/grandyang/p/6815227.html)

```
// 解法一 
// 先来分别统计s1和s2中前n1个字符串中各个字符出现的次数，其中n1为字符串s1的长度，  
这样如果二者字符出现次数的情况完全相同，说明s1和s2中前n1的字符互为全排列关系，那么符合题意了，
直接返回true。如果不是的话，那么我们遍历s2之后的字符，对于遍历到的字符，对应的次数加1，
由于窗口的大小限定为了n1，所以每在窗口右侧加一个新字符的同时就要在窗口左侧去掉一个字符，
每次都比较一下两个哈希表的情况，如果相等，说明存在
bool checkInclusion(string s1, string s2)
{
    int n1 = s1.size(), n2 = s2.size();
    vector<int> m1(128), m2(128);
    for (int i = 0; i < n1; ++i)
    {
        ++m1[s1[i]];
        ++m2[s2[i]];
    }
    if (m1 == m2)
        return true;
    for (int i = n1; i < n2; ++i) // 窗口滑动
    {
        ++m2[s2[i]];
        --m2[s2[i - n1]];
        if (m1 == m2)
            return true;
    }
    return false;
}
```

### 单调栈系列问题  [LeetCode Monotone Stack Summary 单调栈小结](https://www.cnblogs.com/grandyang/p/8887985.html)

**单调栈的两种写法**  

```
// 写法一
int trap(vector<int>& height) 
{
    if (height.empty())
        return 0;
    
    int res = 0;
    int i = 0;
    stack<int> monoStack;
    while( i < height.size())
    {
        if (monoStack.empty() || height[i] <=height[monoStack.top()])
        {
            monoStack.push(i++);
        }
        else
        {
            int tmp =  monoStack.top();
            monoStack.pop();
            if (monoStack.empty())
                continue;
        
            int h = min(height[i], height[monoStack.top()]);
            res = res + (h - height[tmp]) * (i- monoStack.top() -1);
        }   
    }
   return res;
}
// 写法二
int largestRectangleArea(vector<int> height)
{
    stack<int> monoStack;
    int res = 0; 
    height.push_back(0);
    for (int i = 0; i < height.size(); i++)
    {
        
        while(!monoStack.empty() && height[i] <= height[monoStack.top()])  // 但栈非空时，且当前元素大于栈顶元素时，进行弹出操作，并且结算该弹出元素
        {
            int h = height[monoStack.top()]; 
            monoStack.pop();
            int left = monoStack.empty() ? -1 : monoStack.top();
            // int left = monoStack.size() > 0 ? monoStack.top() : -1;
            res = max(res, h * (i - left -1));
        }
        monoStack.push(i);
    }
    return res;
}
```


#### [42. Trapping Rain Water](https://leetcode.com/problems/trapping-rain-water/)

```
int trap(vector<int> &height)
{
    if (height.empty())
        return 0;
    int res = 0;
    int i = 0;
    stack<int> monoStack; // 因为要求一个数左边比他大和右边比他大,所以应该是一个单调递减的栈, 这个栈需要保持严格单调递减
    while (i < height.size())
    {
        // 如果满足入栈条件,则直接入栈 
        if (monoStack.empty() || height[i] < height[monoStack.top()])
        {
            monoStack.push(i++);
        }
        else// 如果不满足入栈条件,则弹出栈顶元素,这个时候可以结算当前元素,栈顶元素的下一个元素则为左边界，当前遍历到的height[i]则为右边界
        {
            int tmp = monoStack.top();
            monoStack.pop();
            if (monoStack.empty())
                continue;
            int h = min(height[i], height[monoStack.top()]);
            res = res + (h - height[tmp]) * (i - monoStack.top() - 1);
        }
    }
    return res;
}
```
####  [84. Largest Rectangle in Histogram](https://leetcode.com/problems/largest-rectangle-in-histogram/) 

```
int largestRectangleArea(vector<int> &heights)
{
    int res = 0;
    stack<int> st;
    heights.push_back(0);
    for (int i = 0; i < heights.size(); ++i)
    {
        while (!st.empty() && heights[st.top()] >= heights[i])
        {
            int cur = st.top();
            st.pop();
            res = max(res, heights[cur] * (st.empty() ? i : (i - st.top() - 1)));
        }
        st.push(i);
    }
    return res;
}
```



#### [85. Maximal Rectangle](https://leetcode.com/problems/maximal-rectangle/)
```
class Solution {
    
    int largestRectangleArea(vector<int> height)
    {
        stack<int> monoStack;
        int res = 0; 
        height.push_back(0);
        for (int i = 0; i < height.size(); i++)
        {
            while(!monoStack.empty() && height[i] <= height[monoStack.top()])  // 但栈非空时，且当前元素大于栈顶元素时，进行弹出操作，并且结算该弹出元素
            {
                int h = height[monoStack.top()]; 
                monoStack.pop();
                int left = monoStack.empty() ? -1 : monoStack.top();
                // int left = monoStack.size() > 0 ? monoStack.top() : -1;
                res = max(res, h * (i - left -1));
                
            }
            monoStack.push(i);
        
        }
        return res;
    } 
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty())
            return 0;
        
        vector<int> heights(matrix[0].size(), 0);
        int res = 0;
        int m = matrix.size();
        int n = heights.size();
        
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if (matrix[i][j] == '1')
                {
                    heights[j] += 1;
                }
                else
                {
                    heights[j] = 0;
                }
            }
            
            res = max(largestRectangleArea(heights), res);
            
        }
        return res;
    }
};
```
#### [402. Remove K Digits](https://leetcode.com/problems/remove-k-digits/)

#### [768. Max Chunks To Make Sorted II](https://leetcode.com/problems/max-chunks-to-make-sorted-ii/)

### 二分查找 

33 34 81 153 154 704 


```

// 形成自己的套路，right 初始化为nums.size(), while判断就可以用left < right了
int find(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) left = mid + 1;
        else right = mid;
    }
    return -1;
}

int find(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target) left = mid + 1;
        else right = mid;
    }
    return right;
}
```


[378. Kth Smallest Element in a Sorted Matrix](https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/)

```
//整个二维数组中 matrix[0][0]matrix[0][0] 为最小值，matrix[n - 1][n - 1]matrix[n−1][n−1] 为最大值，现在我们将其分别记作 ll 和 rr。
可以发现一个性质：任取一个数 midmid 满足 l\leq mid \leq rl≤mid≤r，那么矩阵中不大于 midmid 的数，肯定全部分布在矩阵的左上角。
初始位置在 matrix[n - 1][0]matrix[n−1][0]（即左下角；
设当前位置为 matrix[i][j]matrix[i][j]。若 matrix[i][j] \leq midmatrix[i][j]≤mid，则将当前所在列的不大于 midmid 的数的数量（即 i + 1i+1）累加到答案中，并向右移动，否则向上移动；
不断移动直到走出格子为止。


bool check(vector<vector<int>> &matrix, int mid, int k, int n)
{
    int i = n - 1;
    int j = 0;
    int num = 0;
    while (i >= 0 && j < n)
    {
        if (matrix[i][j] <= mid)
        {
            num += i + 1;
            j++;
        }
        else
        {
            i--;
        }
    }
    return num >= k;
}
int kthSmallest(vector<vector<int>> &matrix, int k)
{
    int n = matrix.size();
    int left = matrix[0][0];
    int right = matrix[n - 1][n - 1];
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (check(matrix, mid, k, n))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}
```

### 排序

#### 快速排序

[75. Sort Colors](https://leetcode.com/problems/sort-colors/) 快排partion 

```
void sortColors(vector<int>& nums)
{
    if (nums.empty())
        return;
    
    int n = nums.size();
    int left = 0;  // 小于区域的下一个位置
    int index = 0;
    int right = n - 1;  // 大于区域的上一个位置
    
    while(index <= right)
    {
        if (nums[index] < 1)
        {
            swap(nums[index], nums[left]);
            index++;
            left++;
        }
        else if (nums[index] > 1)
        {
            swap(nums[index], nums[right]); 
            right--;
        }
        else
        {
            index++;
        }     
    }
}
```

[324. Wiggle Sort II](https://leetcode.com/problems/wiggle-sort-ii/)   
核心思想， 如果当前数小于num,当前数和小于区域的下一个数交换, 如果当前数大于num,当前数和大于区域的前一个数交换

```
// 利用快速排序原理
void wiggleSort(vector<int> &nums)
{
    auto midptr = nums.begin() + nums.size() / 2;
    nth_element(nums.begin(), midptr, nums.end());
    int mid = *midptr;

    int i = 0, j = 0, k = nums.size() - 1;
    while (j < k)
    {
        if (nums[j] > mid)
        {
            swap(nums[j], nums[k]);
            k--;
        }
        else if (nums[j] < mid)
        {
            swap(nums[j], nums[i]);
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }

    if (nums.size() % 2)
        ++midptr;

    vector<int> tmp1(nums.begin(), midptr);
    vector<int> tmp2(midptr, nums.end());

    for (int i = 0; i < tmp1.size(); i++)
    {
        nums[2 * i] = tmp1[tmp1.size() - 1 - i];
    }
    for (int i = 0; i < tmp2.size(); i++)
    {
        nums[2 * i + 1] = tmp2[tmp2.size() - 1 - i];
    }
}
```

#### 链表排序  对归并排序还不是很清晰
[148. Sort List](https://leetcode.com/problems/sort-list/)  对链表使用归并的方式排序

```
ListNode *merge(ListNode *l1, ListNode *l2)
{
    ListNode *fakeHead = new ListNode(-1);
    ListNode *p = fakeHead;

    while (l1 != nullptr && l2 != nullptr)
    {
        if (l1->val < l2->val)
        {
            p->next = l1;
            l1 = l1->next;
        }
        else
        {
            p->next = l2;
            l2 = l2->next;
        }
        p = p->next;
    }
    if (l1 != nullptr)
    {
        p->next = l1;
    }
    if (l2 != nullptr)
    {
        p->next = l2;
    }

    return fakeHead->next;
}

//O(nlogn)对链表排序 归并和递归的方式
ListNode *sortList(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    ListNode *fast = head->next, *slow = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    fast = slow->next;
    slow->next = nullptr;
    return merge(sortList(head), sortList(fast));
}
```


### 动态规划 

#### 坐标型动态规划  120不会

***状态: f(x)表示从起点走到坐标x, f[x][y]表示我从起点走到坐标x,y; 方程: 研究走到x, y这个点之前的一步; 初始化: 起点; 答案: 终点***

#### 单序列动态规划

***状态: f[i]表示前i个位置/数字/字符, 第i个; 方程: f[i] = f(f[j]), j是i之前的一个位置; 初始化: f[0]; 答案: f[n-1]; 小技巧: 一般有N个数字/字符, 就开N+1个位置的数组, 第0个位置单独留出来作初始化.(跟坐标相关的动态规划除外)***


#### 双序列动态规划
***状态: f[i][j]表示第一个sequence的前i个数字/字符, 配上第二个sequence的前j个; 方程: f[i][j] = 研究第i个和第j个的匹配关系; 初始化: f[i][0]和f[0][i]; 答案: f[n][m], 其中n = s1.length(); m = s2.length();***  

[10. Regular Expression Matching](https://leetcode.com/problems/regular-expression-matching/)

```
bool isMatch(string s, string p) 
{
    int m = s.length();
    int n = p.length();
    
    // dp[i][j] 表示 s[0...i-1]和p[0...j-1] 匹配
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    
    dp[0][0] = true;
    for (int i = 1; i <= m; i++)
        dp[i][0] = false;
    
    for(int j = 1; j <= n; j++)
    {
        dp[0][j] = j > 1 && '*' == p[j - 1] && dp[0][j - 2];
    }
    
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if (p[j-1] != '*') // 如果p[j-1]的位置不是*的情况下， 如果s[i-1] == p[j-1] || p[j-1] == '.'， 则dp[i][j] 匹配
                dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '.');
            else
            {
                dp[i][j] = dp[i][j-2] || (s[i-1] == p[j-2] || '.' == p[j-2]) && dp[i-1][j];
            }            
        }
    }
    return dp[m][n];
}
```


[44. Wildcard Matching](https://leetcode.com/problems/wildcard-matching/)

```
bool isMatch(string s, string p) 
{
    int m = s.size();
    int n = p.size();
    
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    
    dp[0][0] = true;
    
    for(int i = 1; i <= m; i++)
    {
        dp[i][0] = false;
    }
    
    for(int j = 1; j <= n; j++)
    {
        if (p[j-1] == '*')
            dp[0][j] = true;
        else
            break;
    }
     
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if (p[j-1] != '*')
            {
                dp[i][j] = dp[i-1][j-1] && (s[i-1] == p[j-1] || p[j-1] == '?');
            }
            else
            {
                dp[i][j] = dp[i][j-1] || dp[i-1][j];
            }
        }
    }
    return dp[m][n];
}
```

[72. Edit Distance](https://leetcode.com/problems/edit-distance/)  

```
int minDistance(string word1, string word2)
{
    int m = word1.size();
    int n = word2.size();
    // dp[i][j] 表示word1[0...i-1] 变换到word2[0...j-1]所需要的最小步骤
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0)); // 二维dp数组初始化大小为[m+1][n+1] 是为了初始化第0行和第0列

    for (int i = 0; i <= m; i++)
        dp[i][0] = i;
    for (int j = 0; j <= n; j++)
        dp[0][j] = j;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (word1[i - 1] == word2[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = min(dp[i - 1][j] + 1, min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 1));
            }
        }
    }
    return dp[m][n];
}
```

[97. Interleaving String](https://leetcode.com/problems/interleaving-string/)  

```
//LeetCode 没过很奇怪
bool isInterleave(string s1, string s2, string s3)
{
    int m = s1.size();
    int n = s2.size();
    int k = s3.size();

    if (m + n != k)
        return false;

    // dp[i][j] 表示s1[0...i-1] 和s2[0...j-1]能否交替表示成s3[i+j-1]
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    dp[0][0] = true;
    for (int i = 0; i <= m; i++)
    {
        if (s1[i - 1] != s3[i - 1])
        {
            break;
        }
        dp[i][0] = true;
    }

    for (int j = 0; j <= n; j++)
    {
        if (s2[j - 1] != s3[j - 1])
        {
            break;
        }
            
        dp[0][j] = true;
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if ((s1[i - 1] == s3[i + j - 1] && dp[i - 1][j]) || (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]))
                dp[i][j] = true;
        }
    }
    return dp[m][n];
}
```


[115. Distinct Subsequences](https://leetcode.com/problems/distinct-subsequences/)  

```
// 这一题的转移方程还没有理解
int numDistinct(string s, string t)
{
    int m = t.size();
    int n = s.size();
   
    // dp[i][j]表示S[0...j-1]中的子序列等于T[0..i-1]
    vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
    
    for(int j = 0; j < n; j++)
    {
        dp[0][j] = 1;
    }
    
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
           if (t[i-1] != s[j-1])
               dp[i][j] = dp[i][j-1];
           else
               dp[i][j] = dp[i-1][j-1] + dp[i][j-1];   
        }
    }  
    return dp[m][n];
}
```

[712. Minimum ASCII Delete Sum for Two Strings](https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/)

```
    int minimumDeleteSum(string s1, string s2) 
    {   
        int m = s1.size();
        int n = s2.size();
        
        //dp[i][j]表示s1[0...i-1]和s2[0...j-1]需要的最小cost
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for(int i = 1; i <= m; i++)
        {
            dp[i][0] = dp[i-1][0] + s1[i-1];
        }
        
        for(int j = 1; j <= n; j++)
        {
            dp[0][j] = dp[0][j-1] + s2[j-1];
        }
        
        for(int i = 1; i <= m; i++)
        {
            for(int j = 1; j <= n; j++)
            {
                if (s1[i-1] == s2[j-1]) // 表示不需要删除
                    dp[i][j] = dp[i-1][j-1];
                else
                {
                    dp[i][j] = min(dp[i-1][j] + s1[i-1], dp[i][j-1] + s2[j-1]);
                }
            }
        }
        return dp[m][n];
    }
```


[1143. Longest Common Subsequence](https://leetcode.com/problems/longest-common-subsequence/)

```
int longestCommonSubsequence(string word1, string word2)
{
    int m = word1.size();
    int n = word2.size();

    if (m == 0 && n == 0)
        return 0;

    // dp[i][j] 表示word1[0...i-1]和word2[0...j-1]上的最长公共子序列长度
    // 这里dp数组初始化长度为m+1,n+1,为了初始化方便考虑第0行和第0列
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int j = 0; j <= n; j++)
    {
        dp[0][j] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[i][0] = 0;
    }

    for (int i = 1; i <= m; i++) // 循环就得下标1开始
    {
        for (int j = 1; j <= n; j++)
        {
            if (word1[i - 1] == word2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[m][n];
}
```

