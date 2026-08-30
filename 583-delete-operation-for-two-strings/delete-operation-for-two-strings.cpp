class Solution {
public:
    int minDistance(string s, string t) {
        // string t=s;
        // reverse(t.begin(),t.end());
        int n=s.size();
        int m=t.size();
        // vector<vector<int>> dp(n+1, vector<int> (n+1 , 0));
        vector<int> prev(m+1, 0);
        // return solve(n-1, n-1, s, t, dp);
        for(int i=1;i<=n;i++){
            vector<int> curr(m+1, 0);
            for(int j=1;j<=m;j++){
               int take=0;
                if(s[i-1]==t[j-1]){
                    take=1+prev[j-1];
                }
                int not_take = max(prev[j],curr[j-1]);
                curr[j]=max(take,not_take);
            }
            prev=curr;
        }
        // return n-prev[n];
        return (n+m)-(2*prev[m]);
    }
};