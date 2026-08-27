class Solution {
public:

    int solve(int i, int target, vector<int> &a, vector<vector<int>> &dp){
        if(target==0) return 1;
        if(i==0){
            if(target%a[i]==0) return 1;
            return 0;
        } 

        if(dp[i][target]!=-1) return dp[i][target];
        int not_take= solve(i-1, target, a, dp);
        int take=0;
        if(a[i]<=target) take=solve(i, target-a[i], a, dp);

        return dp[i][target]=(not_take+take);
    }

    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> dp(n, vector<int> (amount+1, -1));
        return solve(n-1, amount, coins, dp);
    }
};