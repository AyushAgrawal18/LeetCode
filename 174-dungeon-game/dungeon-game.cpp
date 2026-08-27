class Solution {
public:

    int solve(int i, int j, vector<vector<int>> &a,vector<vector<int>> &dp) {
        int n=a.size();
        int m=a[0].size();
        if (i==n-1 && j==m-1) {
            return max(1, 1-a[i][j]);
        }
        if (i>=n || j>=m) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];

        int down = solve(i + 1, j, a, dp);
        int right = solve(i, j + 1, a, dp);

        int need = min(down, right)-a[i][j];

        return dp[i][j]=max(1, need);
    }

    int calculateMinimumHP(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        vector<vector<int>> dp(n, vector<int> (m,-1));
        return solve(0, 0, a, dp);
    }
};