class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n=a.size();
        int ans=0;
        int buy=a[0];
        for(int i=0;i<n;i++){
            ans=max(ans,a[i]-buy);
            buy=min(buy, a[i]);
        }
        return ans;
    }
};