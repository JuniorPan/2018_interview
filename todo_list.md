

## Todolist 2023

#### [581. 最短无序连续子数组](https://leetcode.cn/problems/shortest-unsorted-continuous-subarray/)

#### [402. 移掉 K 位数字](https://leetcode-cn.com/problems/remove-k-digits/)

#### [321. 拼接最大数](https://leetcode.cn/problems/create-maximum-number/)

#### [768. 最多能完成排序的块 II](https://leetcode-cn.com/problems/max-chunks-to-make-sorted-ii/)

[316. 去除重复字母](https://leetcode.cn/problems/remove-duplicate-letters/)  单调栈



[378. 有序矩阵中第K小的元素](https://leetcode-cn.com/problems/kth-smallest-element-in-a-sorted-matrix/)

[540.有序数组中的单一元素](https://leetcode.cn/problems/single-element-in-a-sorted-array/description/) #todo

[315. 计算右侧小于当前元素的个数](https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/)  todo

[31. 下一个排列](https://leetcode-cn.com/problems/next-permutation/)  #todo

[556. 下一个更大元素 III](https://leetcode.cn/problems/next-greater-element-iii/)

[93. 复原IP地址](https://leetcode-cn.com/problems/restore-ip-addresses/)

[139. 单词拆分](https://leetcode-cn.com/problems/word-break/)

[140. 单词拆分 II](https://leetcode.cn/problems/word-break-ii/)

[159. 最多有两个不同字符的最长子串](https://www.cnblogs.com/grandyang/p/5185561.html)

[340. 最多有K个不同字符的最长子串](https://www.cnblogs.com/grandyang/p/5351347.html)

[239. 滑动窗口最大值](https://leetcode-cn.com/problems/sliding-window-maximum/)

[473. 火柴拼正方形](https://leetcode.cn/problems/matchsticks-to-square/)

[491. 递增子序列](https://leetcode.cn/problems/non-decreasing-subsequences/description/)

[443. 压缩字符串](https://leetcode.cn/problems/string-compression/)

[524. 通过删除字母匹配到字典里最长单词](https://leetcode-cn.com/problems/longest-word-in-dictionary-through-deleting/)  #todo

[581. 最短无序连续子数组](https://leetcode-cn.com/problems/shortest-unsorted-continuous-subarray/) #todo 20210419 双指针

[977. 有序数组的平方](https://leetcode.cn/problems/squares-of-a-sorted-array/)

[516. 最长回文子序列](https://leetcode-cn.com/problems/longest-palindromic-subsequence/)  后面两题 逆向遍历 为什么？？？ 重点是画图 空间优化

[647. 回文子串](https://leetcode-cn.com/problems/palindromic-substrings/) todo: 空间优化

[474. 一和零](https://leetcode.cn/problems/ones-and-zeroes/)

[36. 有效的数独](https://leetcode.cn/problems/valid-sudoku/)

[37. 解数独](https://leetcode.cn/problems/sudoku-solver/)

[51. N 皇后](https://leetcode.cn/problems/n-queens/)

[52. N皇后 II](https://leetcode-cn.com/problems/n-queens-ii/)

[212. 单词搜索 II](https://leetcode.cn/problems/word-search-ii/)

[399. 除法求值](https://leetcode.cn/problems/evaluate-division/)

[827. 最大人工岛](https://leetcode.cn/problems/making-a-large-island/)

**[785.判断二分图](https://leetcode.cn/problems/is-graph-bipartite/)** 一定要看

[856. 括号的分数](https://leetcode-cn.com/problems/score-of-parentheses/)

#### [3. 无重复字符的最长子串](https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/) #todo

#### [238. 除自身以外数组的乘积](https://leetcode-cn.com/problems/product-of-array-except-self/) #todo

下面 三题 套路差不多

[41. 缺失的第一个正数](https://leetcode-cn.com/problems/first-missing-positive/)#todo

[442. 数组中重复的数据](https://leetcode.cn/problems/find-all-duplicates-in-an-array/)

[448. 找到所有数组中消失的数字](https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/)

[160. 相交链表](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/) # todo 双指针 虚假的easy



[235. 二叉搜索树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-search-tree/) todo

[236. 二叉树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/) todo

[124. 二叉树中的最大路径和](https://leetcode-cn.com/problems/binary-tree-maximum-path-sum/)todo: 还不是很懂

[543. 二叉树的直径](https://leetcode-cn.com/problems/diameter-of-binary-tree/) # todo其实和124套路一样 

[1339. 分裂二叉树的最大乘积](https://leetcode.cn/problems/maximum-product-of-splitted-binary-tree/)

[剑指 Offer 33. 二叉搜索树的后序遍历序列](https://leetcode-cn.com/problems/er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/)

[99. 恢复二叉搜索树](https://leetcode.cn/problems/recover-binary-search-tree/) todo

## [左神的课](https://www.bilibili.com/video/BV13g41157hK?p=5&vd_source=f740ff72b448a270a8990e020d263b59)

### p1

#### code 位运算   0:0:0~1:14:20

#### code 插入排序  1:14:20~1:32:27

```c++
// https://leetcode.cn/problems/sort-an-array/
// 这里做的是为了 0~i 上有序
for (int i = 1; i < nums.size(); i++)
{
  for (int j = i - 1; j >= 0; j--)
  {
    if (nums[j + 1] < nums[j])
        swap(nums[j + 1], nums[j]);
  }
}
```

#### code 二分的详解与扩展  1:32:27~

```c++
// 1）在一个有序数组中，找某个数是否存在
// 2）在一个有序数组中，找大于等于某个数最左侧的位置 low_bound
int lower_bound(vector<int>& nums, int target)
{
  int left = 0;
  int right = nums.size();
  while(left < right)
  {
      int mid = left + (right - left) / 2;
      if (nums[mid] < target)
          left = mid + 1;
      else
          right = mid;
  }
  return left;
}
// 3）局部最小值问题
```

### p2

#### code 归并排序  0:34:57~0:59:42 [912. 排序数组](https://leetcode.cn/problems/sort-an-array/)

```c++
 void merge(vector<int> &nums, int left, int mid, int right)
    {
        vector<int> temp; // 注意这个地方 如果这样写 就不用指定数组的大小了

        int i = left, j = mid + 1;
        int index = 0;
        while(i <= mid && j <= right)
        {
            // if (nums[i] <= nums[j])
            // {
            //     temp.push_back(nums[i]);
            //     i++;
            // }
            // else 
            // {
            //     temp.push_back(nums[j]);
            //     j++;
            // }  
            // temp[index++] = nums[i] < nums[j] ? nums[i++] :nums[j++]; 
            temp.push_back(nums[i] < nums[j] ? nums[i++] :nums[j++]);
        }

        while(i <= mid)
        {
            // temp[index++] = nums[i++]; 
            temp.push_back(nums[i++]);
        }
            

        while(j <= right)
        {
           temp.push_back(nums[j++]);
        }
            

        for(int i = 0; i < temp.size(); i++)
        {
            nums[i+left] = temp[i];
        }
    }

    void merge_sort(vector<int> &nums, int left, int right)
    {
        if (left == right)
        {
            return;
        }
        int mid = left + (right - left) / 2;
        merge_sort(nums, left, mid);
        merge_sort(nums, mid+1, right);
        merge(nums, left, mid, right);
    }
```

#### code 小和问题和逆序对问题 1:01:32~1:31:11

```
```



#### code 快排 荷兰国旗问题 1:44:00~2:25:00  [215. 数组中的第K个最大元素](https://leetcode.cn/problems/kth-largest-element-in-an-array/)

```c++
// 1）给定一个数组arr和指定的num,请把小于等于num的数放在数组的左边，大于num的数放在右边，要求额外空间复杂度O(1),时间复杂度O(N)
215. 数组中的第K个最大元素
// 2）给定一个数组arr和指定的num,请把小于num的数放在数组的左边，等于num的放中间，大于num的数放在右边，要求额外空间复杂度O(1),时间复杂度O(N)
void sortColors(vector<int>& nums) 
{
    if (nums.empty())
        return;

    int small = 0; // 小于区域的最后一个元素位置
    int large = nums.size() - 1; // 大于区域的第一个位置
    int index = 0;
    while(index <= large)
    {
        if (nums[index] < 1)
        {
            swap(nums[index++], nums[small++]);
        }
        else if (nums[index] == 1)
        {   
            index++;
        }
        else 
        {
            swap(nums[index], nums[large--]);
        }
    }
}

```



### p3

#### code 堆结构 0:08:00~0:51:00

```
```

#### code 堆排序 0:51:00~1:18:00

```
```

#### code 堆排序扩展题 1:19:30~1:36:53

```c++
// 己知一个几乎有序的数组，几乎有序是指，如果把数组排好顺序的话，每个元素移动的距离可以不超过k，
// 并且k相对于数组来说比较小。请选择一个合适的排序算法针对这个数据进行排序。
```



#### code 桶排序 1:51:22~2:24:12

```c++
1)计数排序
2)基数排序
```

### [p6_4][https://www.bilibili.com/video/BV13g41157hK?p=6]

code  链表 1:10:24 

```c++
// 翻转单向和双向链表
```



### [p7_5二叉树](https://www.bilibili.com/video/BV13g41157hK?p=7&vd_source=f740ff72b448a270a8990e020d263b59)

code 二叉树遍历 递归 0:52:19~1:09:25

```c++
// 递归序
void pre_order(TreeNode *root)
{
    if (root == nullptr)
        return;
    // 第一次来到当前节点
    cout << root->val << ", ";
    pre_order(root->left);
    // 第二次来到当前节点
    cout << root->val << ", ";
    pre_order(root->right);
    // 第三次来到当前节点
    cout << root->val << ", ";
}
```

code 二叉树遍历非递归 1:09:25~1:38:42

```c++ 
先序非递归
// 1）根节点先入栈 
// 2）从栈中弹出一个节点 记为cur
// 3）打印（处理）cur节点
// 4）先右后左 （cur的左右节点 如果有的话）
// 5) 重复以上步骤
// 二叉树前序遍历非递归
vector<int> preorderTraversal(TreeNode* root) 
{
  vector<int> res;
  if (root == nullptr)
      return res;

  stack<TreeNode *> s;
  s.push(root);

  while(!s.empty())
  {
      root = s.top();
      s.pop();
      res.push_back(root->val);

      if (root->right)
          s.push(root->right);
      if (root->left)
          s.push(root->left);  
  }
  return res;
}
```

```c++
后序非递归 
）先搞一个栈 头右左  // 这个地方相当于 先序的镜像 
）再搞一个栈 收集起来 在弹出 就能得到 左右头 即后序遍历

// 1）根节点先入栈 
// 2）从栈中弹出一个节点 记为cur 放在收集栈
// 3）打印（处理）cur节点
// 4）先左后右 （cur的左右节点 如果有的话） 
// 5) 重复以上步骤 
vector<int> postorderTraversal(TreeNode* root) 
{
    vector<int> res;
    if (root == nullptr)
        return res;

    stack<TreeNode *> s1;
    stack<TreeNode *> s2;
    s1.push(root);
    while(!s1.empty())
    {
        root = s1.top();
        s1.pop();
        s2.push(root);
        if (root->left)
            s1.push(root->left);
        if (root->right)
            s1.push(root->right);
    }
    while(!s2.empty())
    {
        res.push_back(s2.top()->val);
        s2.pop();
    }
    return res;
}
```

```c++
// 中序 非递归
// 逮到一棵树，不管三七二十一，先把左边界全部压栈， 依次弹出每一个节点的时候，让他的右节点也进行同样的操作
vector<int> inorderTraversal(TreeNode* root)
{
    vector<int> res;
    if (root == nullptr)
    {
        return {};
    }
    stack<TreeNode *> s;
    while(!s.empty() || root)
    {
        if (root != nullptr)
        {
            s.push(root);
            root = root->left;
        } else {
           root = s.top();
          res.push_back(root->val);
          s.pop();
          root = root->right;
        }
    }
    return res;
}
```

code 二叉树 宽度遍历 层次遍历 1:45:22 ~

#### [662. 二叉树最大宽度](https://leetcode.cn/problems/maximum-width-of-binary-tree/)



### [p8_6 图（其实还是二叉树）](https://www.bilibili.com/video/BV13g41157hK/?p=8&vd_source=f740ff72b448a270a8990e020d263b59)

code 二叉树的相关概念及其实现判断 0:0:0~1:19:15

```c++
// 如何判断一颗二叉树是否是搜索二叉树？

// 如何判断一颗二叉树是完全二叉树？
   1) 任意节点 如果有右孩子但是没有左孩子，直接返回false
   2) 在（1）不违规的情况下，遇到的第一个左右孩子不双全的情况下，那么接下的遇到的所有节点都必须是叶节点

// 如何判断一颗二叉树是否是满二叉树？

// 如何判断一颗二叉树是否是平衡二叉树？《二叉树题目套路)  树形dp
```



code 最近公共祖先  1:22:15 ~1:48:03

[236. 二叉树的最近公共祖先](https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/)

```
// 两个节点可能的几种情况
1） o1是o2的最近公共祖先 或o2是o1的最近公共祖先
2)  o1 和 o2彼此 不互为公共祖先

```

code 二叉树中一个节点的后继节点 1:48:03~2:02:08

```
todo: 
```

code 二叉树序列化和反序列化 2:02:08



### [p9 7.详解前缀树和贪心算法(实际是图算法)](https://www.bilibili.com/video/BV13g41157hK?p=9&vd_source=f740ff72b448a270a8990e020d263b59)



### [p10_8. 暴力递归 (实际是前缀树和贪心) 0~1:50:03](https://www.bilibili.com/video/BV13g41157hK?p=10)



### [p11_9. 补充视频（暴力递归 35:00:00~）](https://www.bilibili.com/video/BV13g41157hK?p=11)

#### 题目二 汉诺塔问题 0:44:42~0:57:45

```c++

```

#### 题目三 打印一个字符串的全部子序列 0:57:45~1:06:30

```
// 子集问题
```

#### 题目四 打印一个字符串的全部排列 （重复和不重复） 1:06:30~ 1:20:24

![image-20221007210526609](/Users/panqiang/Library/Application Support/typora-user-images/image-20221007210526609.png)

```
```



#### 题目八 拿纸牌问题 1:20:24~1:31:16

#### [486. 预测赢家](https://leetcode.cn/problems/predict-the-winner/)

```
```



#### 题目五 逆序栈 只能用递归 1:31:16~2:04:28

```
```

#### 题目九 N皇后 2:04:28

### [p_17 15.基础提升  大数据题目等](https://www.bilibili.com/video/BV13g41157hK?p=17)

#### 题目一 机器人走动  0:0:0~0:59:54

https://blog.csdn.net/weixin_43364551/article/details/115533919

![image-20221020223126528](/Users/panqiang/Library/Application Support/typora-user-images/image-20221020223126528.png)

#### 题目二  零钱兑换  0:59:54~2:05:00

#### [322. 零钱兑换](https://leetcode-cn.com/problems/coin-change/)

![image-20221020231336254](/Users/panqiang/Library/Application Support/typora-user-images/image-20221020231336254.png)

```
零钱兑换
```



### [p_18 16.基础提升  暴力递归（上）等](https://www.bilibili.com/video/BV13g41157hK?p=18&vd_source=f740ff72b448a270a8990e020d263b59)

#### 题目一 拿纸牌问题 0:0:~0:0:0





## todo_list_2021_1227 小镇刷题家他又来了

http://erdengk.top/archives/zuo-lao-shi-suan-fa-ke-xue-xi-jian-yi

https://blog.csdn.net/qq_41852212/article/details/120628784

左神课程 68小时版本对应第四期

新课: https://www.bilibili.com/video/BV1db4y1m7Xc?spm_id_from=333.999.0.0

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

```c++
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

## 快速排序

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



[https://www.bilibili.com/video/BV13g41157hK?p=6]: 

[https://www.bilibili.com/video/BV13g41157hK?p=6]: 
