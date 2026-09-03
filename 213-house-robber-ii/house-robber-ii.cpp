class Solution {
public:
    int solve(int i, vector<int>& a, int include, vector<vector<int>> &dp){
        int n=a.size();
        if(i>=n) return 0;
        if(i==n-1){
            if(include!=1) return a[i];
            return 0;
        }
        if(dp[i][include]!=-1) return dp[i][include];
        int take=0;
        if(i==0){
            take=a[i]+solve(i+2, a, 1, dp);
        }
        else{
            take=a[i]+solve(i+2,a, include, dp);
        }
        int not_take=solve(i+1,a, include, dp);
        return dp[i][include]=max(take,not_take);
    }


    int rob(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+1, vector<int> (2, -1));
        return solve(0, nums, 0, dp);
    }
};