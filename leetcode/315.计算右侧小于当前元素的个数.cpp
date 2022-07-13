/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 *
 * https://leetcode-cn.com/problems/count-of-smaller-numbers-after-self/description/
 *
 * algorithms
 * Hard (41.73%)
 * Likes:    848
 * Dislikes: 0
 * Total Accepted:    66K
 * Total Submissions: 155.1K
 * Testcase Example:  '[5,2,6,1]'
 *
 * 给你一个整数数组 nums ，按要求返回一个新数组 counts 。数组 counts 有该性质： counts[i] 的值是  nums[i]
 * 右侧小于 nums[i] 的元素的数量。
 *
 *
 *
 * 示例 1：
 *
 *
 * 输入：nums = [5,2,6,1]
 * 输出：[2,1,1,0]
 * 解释：
 * 5 的右侧有 2 个更小的元素 (2 和 1)
 * 2 的右侧仅有 1 个更小的元素 (1)
 * 6 的右侧有 1 个更小的元素 (1)
 * 1 的右侧有 0 个更小的元素
 *
 *
 * 示例 2：
 *
 *
 * 输入：nums = [-1]
 * 输出：[0]
 *
 *
 * 示例 3：
 *
 *
 * 输入：nums = [-1,-1]
 * 输出：[0,0]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 10^5
 * -10^4 <= nums[i] <= 10^4
 *
 *
 */

// @lc code=start
class Solution
{
public:
    vector<int> index; //用于解决排序后原数组元素顺序变更问题

    void merge(vector<int> &nums, int left, int mid, int right, vector<int> &res)
    {
        int n = right - left + 1;
        int *tmp = new int[n], *tempIndex = new int[n];

        vector<int> temp;
        vector<int> tempIndex;
        int tmpPos = 0;
        int i = left, j = mid + 1;
        while (i <= mid && j <= right)
        {
            if (nums[i] > nums[j]) //数组降序排列
            {
                res[index[i]] += right - j + 1; //用下标直接计算排序好的右半部分小于nums[i]元素的数目
                tempIndex.push_back(index[i]);  //记录元素位置的改变，与排序思想相同
                temp.push_back(nums[i++]);
            }
            else // nums[i]<=nums[j]，等号放在这里是为了更方便上面计算right-j+1这个数目
            {
                tempIndex.push_back(index[j]); //记录元素位置的改变，与排序思想相同
                temp.push_back(nums[j++]);
            }
        }
        while (i <= mid)
        {
            tempIndex.push_back(index[i]); //记录元素位置的改变，与排序思想相同
            temp.push_back(nums[i++]);
        }

        while (j <= right)
        {
            tempIndex.push_back(index[j]); //记录元素位置的改变，与排序思想相同
            temp.push_back(nums[j++]);
        }

        for (int i = 0; i < n; ++i)
        {
            nums[left + i] = tmp[i];
            index[left + i] = tempIndex[i];
        }
    }
    void mergesort(vector<int> &nums, int left, int right, vector<int> &res)
    {
        if (left == right)
            return;
        int mid = (right - left) / 2 + left;
        mergesort(nums, left, mid, res);
        mergesort(nums, mid + 1, right, res);
        merge(nums, left, mid, right, res);
    }
    vector<int> countSmaller(vector<int> &nums)
    {
        vector<int> res(nums.size(), 0);
        index.resize(nums.size());
        for (int i = 0; i < nums.size(); ++i)
            index[i] = i;
        mergesort(nums, 0, nums.size() - 1, res);
        return res;
    }
};

// @lc code=end
