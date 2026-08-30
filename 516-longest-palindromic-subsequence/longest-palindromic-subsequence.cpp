class Solution {
public:

    int solve(int i, int j, string &a, string &b, vector<vector<int>> &dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int take=0;
        if(a[i]==b[j]){
            take=1+solve(i-1, j-1, a, b, dp);
        }
        int not_take = max(solve(i-1, j, a, b, dp),solve(i, j-1, a, b, dp));

        return dp[i][j]=max(take,not_take);
    }



    int longestPalindromeSubseq(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        int n=s.size();
        vector<vector<int>> dp(n+1, vector<int> (n+1 , -1));
        return solve(n-1, n-1, s, t, dp);
    }
};