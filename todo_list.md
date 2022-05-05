左程云

P17 --- 2:03:16

![image-20220301230908662](/Users/panqiang/Library/Application Support/typora-user-images/image-20220301230908662.png)

P18--- 



## todo_list_2021_1227 小镇刷题家他又来了

http://erdengk.top/archives/zuo-lao-shi-suan-fa-ke-xue-xi-jian-yi

https://blog.csdn.net/qq_41852212/article/details/120628784

[旧课 p8-p45 基础班，基础提升，中级班，高级班](https://www.bilibili.com/video/BV1gL4y1a7Fu)

[新课 p46-p61 基础班](https://www.bilibili.com/video/BV1gL4y1a7Fu)

[新课：基础提升，训练营](https://www.bilibili.com/video/BV11v411G7xR?p=1)



新课: https://www.bilibili.com/video/BV1db4y1m7Xc?p=12 基础



##### [判断一棵二叉树是否完全二叉树](https://www.nowcoder.com/practice/f31fc6d3caf24e7f8b4deb5cd9b5fa97?tpId=191&&tqId=35928&rp=1&ru=/activity/oj&qru=/ta/job-code-high-algorithm/question-ranking) #TODO

#### [437. 路径总和 III](https://leetcode-cn.com/problems/path-sum-iii/) 

#### [124. 二叉树中的最大路径和](https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/)todo: 还不是很懂



[剑指 Offer 26. 树的子结构](https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/)

[剑指 Offer 33. 二叉搜索树的后序遍历序列](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/)

[493. 翻转对](https://leetcode-cn.com/problems/reverse-pairs/)

#### [416. 分割等和子集](https://leetcode-cn.com/problems/partition-equal-subset-sum/)

[474. 一和零](https://leetcode-cn.com/problems/ones-and-zeroes/)

[55. 跳跃游戏](https://leetcode-cn.com/problems/jump-game/) todo

[91. 解码方法](https://leetcode-cn.com/problems/decode-ways/) #todo 20210415 

[198. 打家劫舍](https://leetcode-cn.com/problems/house-robber/)  

[312. 戳气球](https://leetcode-cn.com/problems/burst-balloons/)

[114. 二叉树展开为链表](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/) 

#### [424. 替换后的最长重复字符](https://leetcode-cn.com/problems/longest-repeating-character-replacement/)

#### [543. 二叉树的直径](https://leetcode-cn.com/problems/diameter-of-binary-tree/)

#### [287. 寻找重复数](https://leetcode-cn.com/problems/find-the-duplicate-number/)

[647. 回文子串](https://leetcode-cn.com/problems/palindromic-substrings/) todo: 空间优化

#### [560. 和为 K 的子数组](https://leetcode-cn.com/problems/subarray-sum-equals-k/)

#### [347. 前 K 个高频元素](https://leetcode-cn.com/problems/top-k-frequent-elements/)

#### [90. 子集 II](https://leetcode-cn.com/problems/subsets-ii/)

#### [136. 只出现一次的数字](https://leetcode-cn.com/problems/single-number/)

#### [169. 多数元素](https://leetcode-cn.com/problems/majority-element/)

#### [221. 最大正方形](https://leetcode-cn.com/problems/maximal-square/)

## todo_list_history

#### ~~[49. 字母异位词分组](https://leetcode-cn.com/problems/group-anagrams/)~~

#### **~~[138. 复制带随机指针的链表](https://leetcode-cn.com/problems/copy-list-with-random-pointer/)~~**

#### [146. LRU 缓存机制](https://leetcode-cn.com/problems/lru-cache/)

```c++
l.splice(l.begin(), l, m[key]); // 这个函数的意思
```

#### [179. 最大数](https://leetcode-cn.com/problems/largest-number/)

```c++
// c++ lambda表达式
sort(nums.begin(), nums.end(), [](int a, int b) {
           return to_string(a) + to_string(b) > to_string(b) + to_string(a); 
        });

string largestNumber(vector<int>& nums) 
{
    //对于两个数字a和b来说，如果将其都转为字符串，如果 ab > ba，则a排在前面，比如9和34，由于 934>349，所以9排在前面，
    // 再比如说 30 和3，由于 303<330，所以3排在 30 的前面。按照这种规则对原数组进行排序后，将每个数字转化为字符串再连接起来就是最终结果
    string res;
    sort(nums.begin(), nums.end(), [](int a, int b) {
       return to_string(a) + to_string(b) > to_string(b) + to_string(a); 
    });
    for (int i = 0; i < nums.size(); ++i) {
        res += to_string(nums[i]);
    }
    return res[0] == '0' ? "0" : res;
}
```

#### ~~[189. 旋转数组](https://leetcode-cn.com/problems/rotate-array/)~~

#### [208. 实现 Trie (前缀树)](https://leetcode-cn.com/problems/implement-trie-prefix-tree/)

#### ~~[287. 寻找重复数](https://leetcode-cn.com/problems/find-the-duplicate-number/)~~

#### ~~[328. 奇偶链表](https://leetcode-cn.com/problems/odd-even-linked-list/)~~

#### ~~[334. 递增的三元子序列](https://leetcode-cn.com/problems/increasing-triplet-subsequence/)~~

#### [347. 前 K 个高频元素](https://leetcode-cn.com/problems/top-k-frequent-elements/)

#### [378. 有序矩阵中第K小的元素](https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/)

#### [384. 打乱数组](https://leetcode-cn.com/problems/shuffle-an-array/)  #Todo: 洗牌算法

```
vector<int> shuffle() 
{
	// 遍历数组每个位置，每次都随机生成一个坐标位置，然后交换当前遍历位置和随机生成的坐标位置的数字
    vector<int> res = v;
    for (int i = 0; i < res.size(); ++i) 
    {
        int t = i + rand() % (res.size() - i);
        swap(res[i], res[t]);
    }
    return res;
}
```



#### [380. 常数时间插入、删除和获取随机元素](https://leetcode-cn.com/problems/insert-delete-getrandom-o1/)

#### ~~[114. 二叉树展开为链表](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/)~~





#### [15. 三数之和](https://leetcode-cn.com/problems/3sum/)

#### [96. 不同的二叉搜索树](https://leetcode-cn.com/problems/unique-binary-search-trees/)

#### [221. 最大正方形](https://leetcode-cn.com/problems/maximal-square/) #TODO

#### [1277. 统计全为 1 的正方形子矩阵](https://leetcode-cn.com/problems/count-square-submatrices-with-all-ones/) #TODO

https://leetcode-cn.com/problems/count-square-submatrices-with-all-ones/solution/tong-ji-quan-wei-1-de-zheng-fang-xing-zi-ju-zhen-2/



#### [198. 打家劫舍](https://leetcode-cn.com/problems/house-robber/)

#### [213. 打家劫舍 II](https://leetcode-cn.com/problems/house-robber-ii/)

#### [337. 打家劫舍 III](https://leetcode-cn.com/problems/house-robber-iii/)

```c++
// 那么对于某一个节点，如果其左子节点存在，通过递归调用函数，算出不包含左子节点返回的值，
// 同理，如果右子节点存在，算出不包含右子节点返回的值，那么此节点的最大值可能有两种情况，一种是该节点值加上不包含左子节点和右子节点的返回值之和，
// 另一种是左右子节点返回值之和不包含当期节点值，取两者的较大值返回即可
int dfs(TreeNode *root, unordered_map<TreeNode*, int> &m) 
{
    if (!root) return 0;
    if (m.count(root)) return m[root];
    int val = 0;
    if (root->left) {
        val += dfs(root->left->left, m) + dfs(root->left->right, m);
    }
    if (root->right) {
        val += dfs(root->right->left, m) + dfs(root->right->right, m);
    }
    val = max(val + root->val, dfs(root->left, m) + dfs(root->right, m));
    m[root] = val;
    return val;
}

int rob(TreeNode* root) 
{
    unordered_map<TreeNode*, int> m;
    return dfs(root, m);
}
```



#### [121. 买卖股票的最佳时机](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/)

#### [122. 买卖股票的最佳时机 II](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/)

#### [123. 买卖股票的最佳时机 III](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/)

#### [188. 买卖股票的最佳时机 IV](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/)

#### [309. 最佳买卖股票时机含冷冻期](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/)





TODO: 位运算

#### [191. 位1的个数](https://leetcode-cn.com/problems/number-of-1-bits/)

#### [338. 比特位计数](https://leetcode-cn.com/problems/counting-bits/)





#### [394. 字符串解码](https://leetcode-cn.com/problems/decode-string/)

https://www.cnblogs.com/grandyang/p/5849037.html

#### [406. 根据身高重建队列](https://leetcode-cn.com/problems/queue-reconstruction-by-height/)

#### [437. 路径总和 III](https://leetcode-cn.com/problems/path-sum-iii/)



#### [8. 字符串转换整数 (atoi)](https://leetcode-cn.com/problems/string-to-integer-atoi/)

#### [124. 二叉树中的最大路径和](https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/)

#### [4. 寻找两个正序数组的中位数](https://leetcode-cn.com/problems/median-of-two-sorted-arrays/)

#### [297. 二叉树的序列化与反序列化](https://leetcode-cn.com/problems/serialize-and-deserialize-binary-tree/)

```c++
class Codec {
    TreeNode* de(istringstream& iss)
    {
        TreeNode* root = NULL;
        string word;
        if (iss >> word && word != "null") {
            root = new TreeNode(stoi(word));
            root->left = de(iss);
            root->right = de(iss);
        }
        return root;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == NULL)
        {
            return "null";
        }
        else
            return to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return de(iss);
    }
};
```



#### [72. 编辑距离](https://leetcode-cn.com/problems/edit-distance/)

#### [301. 删除无效的括号](https://leetcode-cn.com/problems/remove-invalid-parentheses/)

#### [312. 戳气球](https://leetcode-cn.com/problems/burst-balloons/)





#### **[295. 数据流的中位数](https://leetcode-cn.com/problems/find-median-from-data-stream/)** # TODO

```c++
关于addNum 逻辑还不是很懂
priority_queue 
```



https://www.nowcoder.com/practice/185a87cd29eb42049132aed873273e83?tpId=191&&tqId=36660&rp=1&ru=/ta/job-code-high-algorithm&qru=/ta/job-code-high-algorithm/question-ranking

```
 int dfs(TreeNode * root, int sum)
{
    if (root == nullptr)
        return 0;
    sum = 10 * sum + root->val;
    if (root->left == nullptr && root->right == nullptr)
        return sum;
    return dfs(root->left, sum) + dfs(root->right, sum);
}

int sumNumbers(TreeNode* root) {
    // write code here
    if(!root) return 0;
    int sum = 0;
    return dfs(root, sum);
}
```





#### [88. Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)





#### [41. First Missing Positive](https://leetcode.com/problems/first-missing-positive/) #todo

```
int firstMissingPositive(vector<int> &nums)
{
    //思路是把1放在数组第一个位置 nums[0]，2放在第二个位置 nums[1]，即需要把 nums[i] 放在 nums[nums[i] - 1]上，\
    // 遍历整个数组，如果 nums[i] != i + 1, 而 nums[i] 为整数且不大于n，另外 nums[i] 不等于 nums[nums[i] - 1] 的话，
    // 将两者位置调换，如果不满足上述条件直接跳过，最后再遍历一遍数组，如果对应位置上的数不正确则返回正确的数
    int n = nums.size();
    for (int i = 0; i < n; ++i)
    {
        while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i])
        {
            swap(nums[i], nums[nums[i] - 1]);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        if (nums[i] != i + 1)
            return i + 1;
    }
    return n + 1;
}
```





#### [128. 最长连续序列](https://leetcode-cn.com/problems/longest-consecutive-sequence/)

```c++
int longestConsecutive(vector<int>& nums) 
{
    int res = 0;
    unordered_set<int> s(nums.begin(), nums.end());
    for(int i = 0; i < nums.size(); i++)
    {
        // if (!s.count(val)) continue;
        if(s.find(nums[i]) != s.end())
            s.erase(nums[i]);
        int pre = nums[i] - 1, next = nums[i] + 1;
        while (s.count(pre)) s.erase(pre--);
        while (s.count(next)) s.erase(next++);
        res = max(res, next - pre - 1);
    }
    return res;
}
```





#### 快速排序

```c++
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
```

#### [判断一棵二叉树是否完全二叉树](https://www.nowcoder.com/practice/f31fc6d3caf24e7f8b4deb5cd9b5fa97?tpId=191&&tqId=35928&rp=1&ru=/activity/oj&qru=/ta/job-code-high-algorithm/question-ranking) #TODO

```c++
bool judgeTotal(TreeNode *root)
{
    if(root==nullptr)
        return false;
    TreeNode *p = root;
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty())
    {
        p = q.front();
        q.pop();
        if(p->left && p->right){
            q.push(p->left);
            q.push(p->right);
        }
        else if(p->left==nullptr && p->right)
            return false;
        else{
            if(p->left && p->right==nullptr)
                while(!q.empty()){
                    p = q.front();
                    q.pop();
                    if(p->left || p->right)
                        return false;
                }                
        }
    }
    return true;
}
```



#### [在两个长度相等的排序数组中找到上中位数](https://www.nowcoder.com/practice/6fbe70f3a51d44fa9395cfc49694404f?tpId=191&&tqId=36127&rp=1&ru=/activity/oj&qru=/ta/job-code-high-algorithm/question-ranking) # Todo

```c++
class Solution {
public:
    /**
     * find median in two sorted array
     * @param arr1 int整型vector the array1
     * @param arr2 int整型vector the array2
     * @return int整型
     */
    int findMedianinTwoSortedAray(vector<int>& arr1, vector<int>& arr2) {
        // write code here
        
        int start_1 = 0;
        int end_1 = arr1.size() -1;
        
        int start_2 = 0;
        int end_2 = arr2.size() -1;
        
        int mid_1 = 0;
        int mid_2 = 0;
        int offset = 0;
        
        while(start_1 < end_1)
        {
            mid_1 = start_1 + (end_1 - start_1) / 2;
            mid_2 = start_2 + (end_2 - start_2) / 2;
            offset = ((end_1 - start_1+1) & 1 ) ^1;
            if (arr1[mid_1] == arr2[mid_2])
            {
                return arr1[mid_1];
            }
            else if (arr1[mid_1] > arr2[mid_2])
            {
                start_2 = mid_2 + offset;
                end_1 = mid_1;
                
            }
            else
            {
                start_1 = mid_1 + offset;
                end_2 = mid_2;
            }
        }
        return min(arr1[start_1], arr2[start_2]);
    }
};
```



[数组中出现次数超过一半的数字](https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=191&&tqId=36300&rp=1&ru=/activity/oj&qru=/ta/job-code-high-algorithm/question-ranking)

#### [169. 多数元素](https://leetcode-cn.com/problems/majority-element/)

投票法先将第一个数字假设为过半数，然后把计数器设为1，比较下一个数和此数是否相等，若相等则计数器加一，反之减一。然后看此时计数器的值，若为零，则将下一个值设为候选过半数。

```c++
int majorityElement(vector<int>& nums) 
{
    // 投票法先将第一个数字假设为过半数，然后把计数器设为1，比较下一个数和此数是否相等，若相等则计数器加一，反之减一。然后看此时计数器的值，若为零，则将下一个值设为候选过半数。
    int n = nums.size();
    if (n <= 0)
        return 0;
    int count = 0;
    int res;

    for(int i = 0; i < nums.size(); i++)
    {
        if (count == 0)
        {
            res = nums[i];
            count ++;
        }
        else if (nums[i] == res)
        {
            count ++;
        }
        else
        {
            count--;
        }
    }
    return res;
}
```





#### [20. 有效的括号](https://leetcode-cn.com/problems/valid-parentheses/)

```c++
stack<char> st;
for (char c : s)
{
    if (c == '(' || c == '{' || c == '[')
    {
        st.push(c);
    }
    else
    {
        if (st.empty())
            return false;
        if (c == ')' && st.top() != '(')
            return false;
        if (c == '}' && st.top() != '{')
            return false;
        if (c == ']' && st.top() != '[')
            return false;
        st.pop();
    }
}
return st.empty();
```



#### [25. K 个一组翻转链表](https://leetcode-cn.com/problems/reverse-nodes-in-k-group/)

```c++
ListNode* reverseKGroup(ListNode* head, int k) 
{
    ListNode *fakeHead = new ListNode(-1);
    fakeHead->next = head;

    ListNode *pre = fakeHead;
    ListNode *cur = fakeHead;

    int num = 0;
    while(cur->next)
    {
        ++num;
        cur = cur->next;
    }   
    while(num >= k)
    {
        cur = pre->next;

        for(int i = 1; i < k; i++)
        {
            // 把cur后面的一个节点temp摘下来，然后用头插法插入到pre后面
            ListNode *temp = cur->next;
            cur->next = temp->next;
            temp->next = pre->next;
            pre->next = temp;
        }
        pre = cur;
        num -= k;
    }
    return fakeHead->next;
}
```

难度困难835



#### 中间结点的前一个

```c++
ListNode *fast = head;
ListNode *slow = head;
// 如果链表个数为奇数，那么直接找到了中间结点，如果是偶数则是中间结点的前一个
while(fast->next && fast->next->next)
{
    slow = slow->next;
    fast = fast->next->next;
}
```

#### 找到第n个节点 从0开始 如果n=3 那么会走到第4个节点上

```
   找到第n个节点 从0开始 如果n=3 那么会走到第4个节点上
   for(int i = 0; i < n; i++)
    {
        fast = fast->next;
    }
```





https://www.nowcoder.com/practice/c215ba61c8b1443b996351df929dc4d4?tpId=191&&tqId=36121&rp=1&ru=/activity/oj&qru=/ta/job-code-high-algorithm/question-ranking



#### [剑指 Offer 49. 丑数](https://leetcode-cn.com/problems/chou-shu-lcof/)

```c++
int nthUglyNumber(int index) 
{
    if(index == 0)
        return 0;
    vector<int> res(1, 1);
    int i2 = 0, i3 = 0, i5 = 0;
    // (1) 1x2,  2x2, 2x2, 3x2, 3x2, 4x2, 5x2...
    // (2) 1x3,  1x3, 2x3, 2x3, 2x3, 3x3, 3x3...
    // (3) 1x5,  1x5, 1x5, 1x5, 2x5, 2x5, 2x5...
    while (res.size() < index) 
    {
        int m2 = res[i2] * 2, m3 = res[i3] * 3, m5 = res[i5] * 5;
        int mn = min(m2, min(m3, m5)); // 用来记录是哪个数产生的下个丑数
        if (mn == m2) ++i2;
        if (mn == m3) ++i3;
        if (mn == m5) ++i5;
        res.push_back(mn);
    }
    return res.back();
}
```



KMP next数组



[43. 字符串相乘](https://leetcode-cn.com/problems/multiply-strings/) #todo

```
class Solution {
public:
    string multiply(string num1, string num2) 
    {

        if (num1 == "0" || num2 == "0")
            return "0";

        vector<int> temp(num1.size() + num2.size());
        string res;
        for(int i = num1.size()-1; i >= 0; i--)
        {
            for(int j = num2.size()-1; j >= 0; j--)
            {
                temp[i+j+1] += ((num1[i] - '0') * (num2[j] - '0'));
                temp[i+j] += temp[i+j+1]/10;
                temp[i+j+1] %= 10;
            }
        }
        for(int i = 0; i < temp.size(); i++)
        {
            if (i == 0 && temp[0] == 0)
                continue;
            else
                res += to_string(temp[i]);
        }

        return res == "" ? "0" :res;
    }
};
```





#### [最长公共子串](https://www.nowcoder.com/practice/f33f5adc55f444baa0e0ca87ad8a6aac?tpId=188&&tqId=37034&rp=1&ru=/activity/oj&qru=/ta/job-code-high-week/question-ranking)

```

string LCS(string str1, string str2) 
{
    // write code here
    if (str1.empty() || str2.empty())
        return "-1";
    int m = str1.size();
    int n = str2.size();
    vector<vector<int>> dp(m+1, vector<int>(n+1,0));
    int max_len = INT_MIN;
    int max_right = 0;
    for(int i = 1; i <= m; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if (str1[i-1] == str2[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;

            if(dp[i][j] > max_len)
            {
                max_len = dp[i][j];
                max_right = i;
            }
        }
    }

   if(max_len==0)return "-1";
   return str1.substr(max_right-max_len,max_len);
}


```

#### [14. 最长公共前缀](https://leetcode-cn.com/problems/longest-common-prefix/)





https://www.nowcoder.com/practice/c56f6c70fb3f4849bc56e33ff2a50b6b?tpId=117&&tqId=35073&&companyId=665&rp=1&ru=/company/home/code/665&qru=/ta/job-code-high/question-ranking



####  [82. 删除排序链表中的重复元素 II](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/) 

#### [83. 删除排序链表中的重复元素](https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/)

https://www.nowcoder.com/practice/046a55e6cd274cffb88fc32dba695668?tpId=117&&tqId=35041&&companyId=665&rp=1&ru=/company/home/code/665&qru=/ta/job-code-high/question-ranking



#### [78. 子集](https://leetcode-cn.com/problems/subsets/)

#### [93. 复原IP地址](https://leetcode-cn.com/problems/restore-ip-addresses/)



#### [剑指 Offer 53 - II. 0～n-1中缺失的数字](https://leetcode-cn.com/problems/que-shi-de-shu-zi-lcof/)





#### [581. 最短无序连续子数组](https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/)



#### [287. 寻找重复数](https://leetcode-cn.com/problems/find-the-duplicate-number/)



[86. 分隔链表](https://leetcode-cn.com/problems/partition-list/)](https://leetcode.com/problems/partition-list/) 





# 总结

## 链表总结

### 1） i 从零开始 最终fast会停在第n个节点上，n从零开始

```
ListNode *fast = head;
for(int i = 0; i < n; i++)
{
    fast = fast->next;
}
```

2） 找链表的中间节点

```
ListNode *fast = head;
ListNode *slow = head;
// 如果链表个数为奇数，那么直接找到了中间结点，如果是偶数则是中间结点的前一个
while(fast->next && fast->next->next)
{
    slow = slow->next;
    fast = fast->next->next;
}
```

https://www.nowcoder.com/practice/71cef9f8b5564579bf7ed93fbe0b2024?tpId=117&tqId=37729&companyId=665&rp=1&ru=%2Fcompany%2Fhome%2Fcode%2F665&qru=%2Fta%2Fjob-code-high%2Fquestion-ranking&tab=answerKey

```
ListNode* deleteDuplicates(ListNode* head)
{
        // write code here
        if (!head || !head->next)
            return head;
        ListNode *dummy = new ListNode(-1), *pre = dummy;
        dummy->next = head;
        while (pre->next)
        {
            ListNode *cur = pre->next;
            while (cur->next && cur->next->val == cur->val)
            {
                cur = cur->next;
            }
            if (cur != pre->next)
                pre->next = cur->next;
            else
                pre = pre->next;
        }
        return dummy->next;
    }
```

## 快手排序

```c++
int partition(vector<int> &nums, int left, int right)
{
    int small = left -1; // small 指向小于区域的最后一个元素
    for(int i = left; i < right; i++)
    {
        if (nums[i] < nums[right])
            swap(nums[i], nums[++small]);
    }
    swap(nums[++small], nums[right]);
    return small;
}

void quickSort(vector<int> &nums, int left, int right)
{
    if (left < right)
    {
        int index = partition(nums, left, right);
        quickSort(nums, left, index - 1);
        quickSort(nums, index + 1, right);
    }
}

vector<int> MySort(vector<int>& arr) {
    // write code here
    quickSort(arr, 0, arr.size()-1);
    return arr;
}
```

## 归并排序

```c++
vector<int> sortArray(vector<int>& nums) {
    mergeSort(nums, 0, (int)nums.size() - 1);
    return nums;
  }
  void mergeSort(vector<int>& nums, int start, int end) {
    if (start >= end) return;
    int mid = (start + end) / 2;
    mergeSort(nums, start, mid);
    mergeSort(nums, mid + 1, end);
    merge(nums, start, mid, end);
  }
  void merge(vector<int>& nums, int start, int mid, int end) {
      vector<int> tmp(end - start + 1);
      int i = start, j = mid + 1, k = 0;
      while (i <= mid && j <= end) {
        if (nums[i] < nums[j]) tmp[k++] = nums[i++];
        else tmp[k++] = nums[j++];
      }
      while (i <= mid) tmp[k++] = nums[i++];
      while (j <= end) tmp[k++] = nums[j++];
      for (int idx = 0; idx < tmp.size(); ++idx) {
        nums[idx + start] = tmp[idx];
      }
  }
```

