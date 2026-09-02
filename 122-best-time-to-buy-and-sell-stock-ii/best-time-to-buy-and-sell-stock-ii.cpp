class Solution {
public:

    int solve(int i, vector<int> &a, int buy, vector<vector<int>> &dp){
        int n=a.size();

        if(i==n+1) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];

        int profit;
        if(buy){
            profit=max(-a[i-1]+solve(i+1, a, 0, dp), solve(i+1, a, 1, dp));
        }
        else{
            profit=max(a[i-1]+solve(i+1, a, 1, dp), solve(i+1, a, 0, dp));
        }
        return dp[i][buy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int buy = 1;
        vector<vector<int>> dp(prices.size()+1, vector<int> (2, -1));
        return solve(1, prices, buy, dp);
    }
};