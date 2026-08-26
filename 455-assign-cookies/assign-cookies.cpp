class Solution {
public:

    int solve(int i, int j, vector<int> &a, vector<int> &b, vector<vector<int>> &dp){
        if(i<0||j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take=0;
        if(a[i]<=b[j]){
            take=1+solve(i-1, j-1, a, b, dp);
        }
        int not_take= solve(i-1, j, a, b, dp);

        return dp[i][j]=max(take,not_take);
    }

    // int findContentChildren(vector<int>& g, vector<int>& s) {
    //     sort(g.begin(),g.end());
    //     sort(s.begin(),s.end());
    //     int n=g.size();
    //     int m=s.size();
    //     // vector<vector<int>> dp(n+1, vector<int> (m+1,0));

    //     // vector<int> prev(m+1,0);
    //     // vector<int> curr(m+1,0);

    //     // for(int i=1;i<=n;i++){
    //     //     for(int j=1;j<=m;j++){
    //     //         int take=0;
    //     //         if(g[i-1]<=s[j-1]){
    //     //             take=1+prev[j-1];
    //     //         }
    //     //         int not_take= max(prev[j], prev[j-1]);
    //     //         curr[j]=max(take, not_take);
    //     //     }
    //     //     prev=curr;
    //     // }
    //     // return prev[m];
        
    // }
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int i = 0; 
        int j = 0; 

        while (i < g.size() && j < s.size()) {
            if (s[j] >= g[i]) {
                i++; 
            }
            j++; 
        }

        return i;
    }
};