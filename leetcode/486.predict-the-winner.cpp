/*
 * @lc app=leetcode id=486 lang=cpp
 *
 * [486] Predict the Winner
 *
 * https://leetcode.com/problems/predict-the-winner/description/
 *
 * algorithms
 * Medium (47.68%)
 * Likes:    1629
 * Dislikes: 94
 * Total Accepted:    75.6K
 * Total Submissions: 156.5K
 * Testcase Example:  '[1,5,2]'
 *
 * Given an array of scores that are non-negative integers. Player 1 picks one
 * of the numbers from either end of the array followed by the player 2 and
 * then player 1 and so on. Each time a player picks a number, that number will
 * not be available for the next player. This continues until all the scores
 * have been chosen. The player with the maximum score wins.
 * 
 * Given an array of scores, predict whether player 1 is the winner. You can
 * assume each player plays to maximize his score.
 * 
 * Example 1:
 * 
 * 
 * Input: [1, 5, 2]
 * Output: False
 * Explanation: Initially, player 1 can choose between 1 and 2. 
 * If he chooses 2 (or 1), then player 2 can choose from 1 (or 2) and 5. If
 * player 2 chooses 5, then player 1 will be left with 1 (or 2). 
 * So, final score of player 1 is 1 + 2 = 3, and player 2 is 5. 
 * Hence, player 1 will never be the winner and you need to return False.
 * 
 * 
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [1, 5, 233, 7]
 * Output: True
 * Explanation: Player 1 first chooses 1. Then player 2 have to choose between
 * 5 and 7. No matter which number player 2 choose, player 1 can choose 233.
 * Finally, player 1 has more score (234) than player 2 (12), so you need to
 * return True representing player1 can win.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= length of the array <= 20.
 * Any scores in the given array are non-negative integers and will not exceed
 * 10,000,000.
 * If the scores of both players are equal, then player 1 is still the winner.
 * 
 * 
 */

// @lc code=start
class Solution
{
    // 作为先发者 在i...j范围上先发获得的收益
    int f(vector<int> &nums, int i, int j)
    {
        if (i == j) // 如果只有一个数并且又是先发者，则直接拿走该数
            return nums[i];

        else
            return max(s(nums, i + 1, j) + nums[i], s(nums, i, j - 1) + nums[j]);
    }
    // / 作为后发者 在i...j范围上后发获得的收益
    int s(vector<int> &nums, int i, int j)
    {
        if (i == j)
        {
            return 0;
        }
        else // 对方也是绝顶聪明,作为后发者,此时只能选先发者拿完之后 剩下最小的
            return min(f(nums, i + 1, j), f(nums, i, j - 1));
    }
public:
    bool PredictTheWinner(vector<int> &nums)
    {

        if (nums.empty())
            return false;
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];

        int res = f(nums, 0, nums.size() - 1);
        return sum - res > res ? false : true;
    }
};

// @lc code=end
