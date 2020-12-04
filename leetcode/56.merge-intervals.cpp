/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)
        {
            return {};
        }
        // 首先将列表中的区间按左端点排序, 然后将第一个区间加入到merged数组中
        // 1: 如果当前区间的左端点在merged数组中最后一个区间的右端点之后,那么他们不会重合,则直接将该区间加入数组merged中
        // 2: 如果当前区间的左端点在merged数组中最后一个区间的右端点之前, 需要更新当前区间的右端点更新数组中merged中最后一个区间的右端点，取二者的最大值
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for(int i = 0; i < intervals.size(); i++)
        {
            int left = intervals[i][0];
            int right = intervals[i][1];

            if(!merged.size() || merged.back()[1] < left) // 条件1，不会重合
                merged.push_back({left, right});
            else // 条件2 重合,已有区间的右端点和当前右端点取最大值
                merged.back()[1] = max(merged.back()[1], right);
        }
        return merged;
    }
};
// @lc code=end

