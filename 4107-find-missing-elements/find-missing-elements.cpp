class Solution {
public:
    vector<int> findMissingElements(vector<int>& a) {
        sort(a.begin(),a.end());
        int n=a.size();
        int x=a[0];
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(a[i]!=x){
                ans.push_back(x);
                i--;
            }
            x++;
        }
        return ans;
    }
};