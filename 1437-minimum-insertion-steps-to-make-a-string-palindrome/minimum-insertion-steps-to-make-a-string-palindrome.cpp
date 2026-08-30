class Solution {
public:
    int minInsertions(string s) {
        string t=s;
        reverse(t.begin(),t.end());
        int n=s.size();
        // vector<vector<int>> dp(n+1, vector<int> (n+1 , 0));
        vector<int> prev(n+1, 0);
        // return solve(n-1, n-1, s, t, dp);
        for(int i=1;i<=n;i++){
            vector<int> curr(n+1, 0);
            for(int j=1;j<=n;j++){
               int take=0;
                if(s[i-1]==t[j-1]){
                    take=1+prev[j-1];
                }
                int not_take = max(prev[j],curr[j-1]);
                curr[j]=max(take,not_take);
            }
            prev=curr;
        }
        return n-prev[n];
    }
};