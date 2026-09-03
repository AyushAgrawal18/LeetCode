class Solution {
public:

    const int OFFSET = 10000;

    int solve(int i, vector<int> &a, int last, vector<vector<int>> &dp){
        if(i<0) return 0;
        
        // int lastIndex = (last == INT_MAX ? a.size() : last);

        if(dp[i][last] != -1) return dp[i][last];  

        int take=0;
        if(last == a.size() || a[i]< a[last]){
            take = 1 + solve(i-1, a, i, dp);
        }
        int not_take = solve(i-1, a, last, dp);

        return dp[i][last] = max(take, not_take);

    }


    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(n-1, nums, n, dp);
    }
};