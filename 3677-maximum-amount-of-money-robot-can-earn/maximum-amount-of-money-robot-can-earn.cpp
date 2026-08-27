class Solution {
public:

    int solve(int i, int j, vector<vector<int>>&a, int limit, vector<vector<vector<int>>> &dp){

        if(i==0 & j==0){
            if(a[i][j]<0 && limit>0) return 0;
            return a[i][j];
        }
        if(i<0 || j<0) return -1e9;

        if(dp[i][j][limit]!=-1) return dp[i][j][limit];
        // int up =0;
        int use = -1e9;
        if(a[i][j]<0 && limit>0){
            use = solve(i-1, j, a, limit-1, dp);
        }
        int not_use = a[i][j]+solve(i-1, j, a, limit, dp);
        int up=max(use, not_use);

        // int left=0;
        use = -1e9;
        if(a[i][j]<0 && limit>0){
            use = solve(i, j-1, a, limit-1, dp);
        }
        not_use = a[i][j]+solve(i, j-1, a, limit, dp);
        int left=max(use, not_use);

        return dp[i][j][limit]=max(left,up);

    }

    int maximumAmount(vector<vector<int>>& coins) {
        int n=coins.size();
        int m=coins[0].size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (m+1, vector<int> (3,-1)));
        return solve(n-1,m-1,coins, 2, dp);
    }
};