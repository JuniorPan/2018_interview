/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 */

// @lc code=start
class Solution {

    class Bucket
    {
        public:
            bool used = false;
            int minval = numeric_limits<int>::max();        // same as INT_MAX
            int maxval = numeric_limits<int>::min();        // same as INT_MIN
    };

public:
    int maximumGap(vector<int>& nums)
    {
        if (nums.empty() || nums.size() < 2)
            return 0;

        // 分别找出桶中的最大值与最小值用来确定桶的容量和大小
        int mini = *min_element(nums.begin(), nums.end()),
        maxi = *max_element(nums.begin(), nums.end());

        if (mini == maxi)
			return 0;

        //todo: 主要是注意一下桶的大小和桶的数量
        int buckerNum = nums.size() + 1; // N个数准备N+1个桶 
        vector<Bucket> buckets(buckerNum);

        // for (auto&& num : nums) {
        for(int i = 0; i < nums.size(); i++)
        {
            int bucketIdx = (int) ((nums[i] - mini) * nums.size() / (maxi - mini));                         // locating correct bucket
            buckets[bucketIdx].used = true;
            buckets[bucketIdx].minval = min(nums[i], buckets[bucketIdx].minval);
            buckets[bucketIdx].maxval = max(nums[i], buckets[bucketIdx].maxval);
        }

        int prevBucketMax = mini, maxGap = 0;
        for (int i = 0; i < buckets.size(); i++) {
            if (!buckets[i].used)
                continue;

            maxGap = max(maxGap, buckets[i].minval - prevBucketMax);
            prevBucketMax = buckets[i].maxval;
        }

        return maxGap;
    }
};
// @lc code=end

