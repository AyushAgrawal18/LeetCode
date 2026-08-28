class Solution {
public:

    int solve(int i, int j, string &a, string &b, vector<vector<int>> &dp){

        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int take=0;
        if(a[i]==b[j]){
            take = 1 + solve(i-1, j-1, a, b, dp);
        }
        int not_take = max(solve(i-1, j, a, b, dp), solve(i, j-1, a, b, dp));


        return dp[i][j]=max(take, not_take);
    }


    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        // vector<vector<int>> dp(n+1, vector<int> (m+1,0));
        vector<int> prev(m+1,0);
        // return solve(n-1,m-1,text1, text2, dp);
        for(int i=0;i<n;i++){
            vector<int> curr(m+1, 0);
            for(int j=0; j<m;j++){
                int take=0;
                if(text1[i]==text2[j]){
                 take = 1 + prev[j];
                }
                int not_take = max(prev[j+1],curr[j]);
                curr[j+1] = max(take, not_take); 
            }
            prev = curr;
        }
        return prev[m];
    }
};