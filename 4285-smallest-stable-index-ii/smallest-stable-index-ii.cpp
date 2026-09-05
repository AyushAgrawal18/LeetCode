class Solution {
public:
    int firstStableIndex(vector<int>& a, int k) {
        int n = a.size();
        int curr= INT_MAX;
        vector<int> mn(n+1, a[n-1]);
        for(int i=n-1; i>=0; i--){
            mn[i]=min(mn[i+1],a[i]);
        }
        int maxi=0;
        int ans=-1;
        for(int i=0;i<=n-1;i++){
            maxi=max(maxi,a[i]);
            ans=maxi-mn[i];
            if(ans<=k) return i;
        }
        return -1;
    }
};