class Solution {
public:

    // int solve(int i, int j, vector<vector<int>> &a, vector<vector<int>> &dp){
    //     int n=a.size();
    //     if(i==n-1) return a[i][j];
    //     if(dp[i][j]!=-1) return dp[i][j];

    //     int down = a[i][j]+solve(i+1, j, a, dp);
    //     int dig = a[i][j]+solve(i+1, j+1, a, dp);
    //     return dp[i][j]=min(down,dig);
    // }


    int minimumTotal(vector<vector<int>>& a) {
        int n=a.size();
        if(n==0) return 0;
        vector<vector<int>> dp(n, vector<int> (n, 0));
        // return solve(0, 0, triangle,dp);
        dp[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                int down = a[i][j]+dp[i+1][j];
                int dig = a[i][j]+dp[i+1][j+1];
                dp[i][j] =min(down,dig);
            }
        }
        return dp[0][0];
    }
};