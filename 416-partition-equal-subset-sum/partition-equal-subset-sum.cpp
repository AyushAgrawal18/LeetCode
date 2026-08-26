class Solution {
public:


    bool solve(int i, int target, vector<int> &a, vector<vector<int>> &dp){
        if(target==0) return true;
        if(i==0) return (a[i]==target);
        if(i<0) return false;
        if(dp[i][target]!=-1) return dp[i][target];

        bool take = false;
        if(a[i]<=target){
            take= solve(i-1, target-a[i], a, dp);
        }
        bool not_take= solve(i-1, target, a, dp);

        return dp[i][target]=(take || not_take);
    }


    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        if(sum&1) return false;
        int target=sum/2;
        vector<vector<int>> dp(n, vector<int> (target+1, -1));
        return solve(n-1,target,nums,dp);
    }
};

// Recursive DP hmmm Acceptable...