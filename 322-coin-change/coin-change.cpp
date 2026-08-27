class Solution {
public:

    int solve(int i, vector<int> &a, int target, vector<vector<int>> &dp){
        if(target==0) return 0;
        if(i==0){
            if(target%a[i]==0) return target/a[i];
            return 1e9;
        }

        if(dp[i][target]!=-1) return dp[i][target];
        int not_take= solve(i-1, a, target, dp);
        int take=1e9;
        if(a[i]<=target){
            take=1+solve(i, a, target-a[i], dp);
        }
        return dp[i][target]=min(take, not_take);
    }


    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1,-1));
        int ans= solve(n-1, coins, amount, dp);
        if(ans>=1e9) return -1;
        return ans;
    }
};