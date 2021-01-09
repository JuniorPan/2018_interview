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
```

#### ~~[189. 旋转数组](https://leetcode-cn.com/problems/rotate-array/)~~

#### [208. 实现 Trie (前缀树)](https://leetcode-cn.com/problems/implement-trie-prefix-tree/)

#### ~~[287. 寻找重复数](https://leetcode-cn.com/problems/find-the-duplicate-number/)~~

#### ~~[328. 奇偶链表](https://leetcode-cn.com/problems/odd-even-linked-list/)~~

#### ~~[334. 递增的三元子序列](https://leetcode-cn.com/problems/increasing-triplet-subsequence/)~~

#### [347. 前 K 个高频元素](https://leetcode-cn.com/problems/top-k-frequent-elements/)

#### [378. 有序矩阵中第K小的元素](https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/)

#### [384. 打乱数组](https://leetcode-cn.com/problems/shuffle-an-array/)  #Todo: 洗牌算法



#### [380. 常数时间插入、删除和获取随机元素](https://leetcode-cn.com/problems/insert-delete-getrandom-o1/)

#### ~~[114. 二叉树展开为链表](https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/)~~





#### [15. 三数之和](https://leetcode-cn.com/problems/3sum/)

#### [96. 不同的二叉搜索树](https://leetcode-cn.com/problems/unique-binary-search-trees/)

#### [221. 最大正方形](https://leetcode-cn.com/problems/maximal-square/)

#### [1277. 统计全为 1 的正方形子矩阵](https://leetcode-cn.com/problems/count-square-submatrices-with-all-ones/)

https://leetcode-cn.com/problems/count-square-submatrices-with-all-ones/solution/tong-ji-quan-wei-1-de-zheng-fang-xing-zi-ju-zhen-2/



#### [198. 打家劫舍](https://leetcode-cn.com/problems/house-robber/)

#### [337. 打家劫舍 III](https://leetcode-cn.com/problems/house-robber-iii/)

#### [213. 打家劫舍 II](https://leetcode-cn.com/problems/house-robber-ii/)



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

#### [72. 编辑距离](https://leetcode-cn.com/problems/edit-distance/)

#### [301. 删除无效的括号](https://leetcode-cn.com/problems/remove-invalid-parentheses/)

#### [312. 戳气球](https://leetcode-cn.com/problems/burst-balloons/)





#### [295. 数据流的中位数](https://leetcode-cn.com/problems/find-median-from-data-stream/)

```c++
关于addNum 逻辑还不是很懂
priority_queue 
```



https://www.nowcoder.com/practice/185a87cd29eb42049132aed873273e83?tpId=191&&tqId=36660&rp=1&ru=/ta/job-code-high-algorithm&qru=/ta/job-code-high-algorithm/question-ranking





#### [88. Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)





#### [41. First Missing Positive ](https://leetcode.com/problems/first-missing-positive/) #todo



#### [128. 最长连续序列](https://leetcode-cn.com/problems/longest-consecutive-sequence/)



```
    
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

https://www.nowcoder.com/practice/f31fc6d3caf24e7f8b4deb5cd9b5fa97?tpId=191&&tqId=35928&rp=1&ru=/activity/oj&qru=/ta/job-code-high-algorithm/question-ranking

```
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





https://www.nowcoder.com/practice/6fbe70f3a51d44fa9395cfc49694404f?tpId=191&&tqId=36127&rp=1&ru=/activity/oj&qru=/ta/job-code-high-algorithm/question-ranking

```
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
            else{
                start_1 = mid_1 + offset;
                end_2 = mid_2;
            }
        }
        return min(arr1[start_1], arr2[start_2]);
    }
};
```



https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=191&&tqId=36300&rp=1&ru=/activity/oj&qru=/ta/job-code-high-algorithm/question-ranking



#### [169. 多数元素](https://leetcode-cn.com/problems/majority-element/)

投票法先将第一个数字假设为过半数，然后把计数器设为1，比较下一个数和此数是否相等，若相等则计数器加一，反之减一。然后看此时计数器的值，若为零，则将下一个值设为候选过半数。





#### [20. 有效的括号](https://leetcode-cn.com/problems/valid-parentheses/)



#### [25. K 个一组翻转链表](https://leetcode-cn.com/problems/reverse-nodes-in-k-group/)

难度困难835