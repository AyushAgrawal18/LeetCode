class Solution {
public:
    int solve(int i, vector<int>& nums, int target, vector<map<int, int>>& dp) {

        if (i == 0) {
            if (target == nums[0] && target == -nums[0])
                return 2;
            if (target == nums[0] || target == -nums[0])
                return 1;

            return 0;
        }
        if (dp[i].count(target))
            return dp[i][target];

        int add = solve(i - 1, nums, target + nums[i], dp);
        int sub = solve(i - 1, nums, target - nums[i], dp);

        return dp[i][target] = add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<map<int, int>> dp(n);
        return solve(n - 1, nums, target, dp);
    }
};