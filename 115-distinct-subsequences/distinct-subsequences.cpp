class Solution {
public:


    int solve(int i, int j, string &a, string &b, vector<vector<int>> &dp){
        if(j<0) return 1;
        if(i<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(a[i]==b[j]){
            return dp[i][j]=solve(i-1, j-1, a, b, dp) + solve(i-1, j, a, b, dp);
        }
        return dp[i][j]=solve(i-1, j ,a, b, dp);
    }


    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        // vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        // return solve(n-1, m-1, s, t, dp);

        // vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        // for(int i=0;i<=n;i++) dp[i][0]=1;
        vector<long long> prev (m+1, 0);
        prev[0]=1;
        for(int i=1;i<=n;i++){
            vector<long long> curr(m+1, 0);
            curr[0]=1;
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]){
                    long long val = (long long)prev[j - 1] + prev[j];
                    curr[j] = min(val, (long long)INT_MAX);
                }
                else{
                    curr[j]=prev[j];
                }
            }
            prev=curr;
        }
        return prev[m];
    }
};