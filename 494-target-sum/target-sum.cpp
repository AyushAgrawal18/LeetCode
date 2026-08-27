class Solution {
public:

    int solve(int i, vector<int> &a, int target){
        if(i==0){
            if (target == a[0] && target == -a[0]) return 2;
            if(target-a[i]==0 || target+a[i]==0) return 1;
            return 0;
        }
        int add = solve(i-1, a, target+a[i]);
        int sub = solve(i-1, a, target-a[i]);

        return (add+sub);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return solve(n-1, nums, target);
    }
};

// Recursive Code toh pakka TLE dega
