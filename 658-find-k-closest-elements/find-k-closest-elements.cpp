class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n= arr.size();
        priority_queue<pair<int,int>> maxHeap;
        for(int i=0;i<n;i++){
            maxHeap.push({abs(arr[i]-x),arr[i]});
            if(maxHeap.size()>k){
                maxHeap.pop();
            }
        }
        vector<int> ans;
        while(maxHeap.size()>0){
            int x = maxHeap.top().second;
            ans.push_back(x);
            maxHeap.pop();
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};