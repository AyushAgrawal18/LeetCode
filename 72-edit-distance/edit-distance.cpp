class Solution {
public:

    int solve(int i, int j, string &a, string &b, vector<vector<int>> &dp){
        if(i<0) return j+1;
        if(j<0) return i+1;

        if(dp[i][j]!=-1) return dp[i][j];

        if(a[i]==b[j]){
            return dp[i][j]=solve(i-1, j-1, a, b, dp);
        }
        int insert = solve(i, j-1, a, b, dp);
        int del = solve(i-1, j, a, b, dp);
        int replace = solve(i-1, j-1, a, b, dp);
        return dp[i][j]=1 + min({insert, del, replace});
    }

    int minDistance(string a, string b) {
        int n=a.size();
        int m=b.size();
        // vector<vector<int>> dp(n, vector<int> (m, -1));
        // return solve(n-1, m-1, a, b, dp);

        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));

        for(int i=0;i<=n;i++) dp[i][0]=i;
        for(int i=0;i<=m;i++) dp[0][i]=i;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

                if(a[i-1]==b[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    int insert = dp[i][j-1];
                    int del = dp[i-1][j];
                    int replace = dp[i-1][j-1];
                    dp[i][j] = 1+min({insert, del, replace});
                }
            }
        }
        return dp[n][m];
    }
};