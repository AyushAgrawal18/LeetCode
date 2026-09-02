class Solution {
public:

    int solve(int i, vector<int> &a, int buy, int chance, vector<vector<vector<int>>> &dp){
        int n=a.size();

        if(i==n+1) return 0;
        if(chance==0) return 0;
        if(dp[i][buy][chance]!=-1) return dp[i][buy][chance];

        int profit;
        if(buy){
            profit=max(-a[i-1]+solve(i+1, a, 0, chance, dp), solve(i+1, a, 1, chance, dp));
        }
        else{
            profit=max(a[i-1]+solve(i+1, a, 1, chance-1, dp), solve(i+1, a, 0, chance, dp));
        }
        return dp[i][buy][chance]=profit;
    }


    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buy=1;
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (3,-1)));
        return solve(1, prices, buy, 2, dp);
    }
};