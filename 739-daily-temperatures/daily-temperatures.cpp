class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& a) {
        int n= a.size();
        vector<int> ans(n,0);
        // for(int i=0;i<n;i++){
        //     int temp=1;
        //     bool flag=false;
        //     for(int j=i+1;j<n;j++){
        //         if(a[j]>a[i]) {
        //             flag=true;
        //             break;
        //         }
        //         temp++;
        //     }
        //     if(flag){
        //         ans.push_back(temp);
        //     }
        //     else{
        //         ans.push_back(0);
        //     }
        // }



        stack<int> s;
        
        for(int i=0;i<n;i++){
            while(!s.empty()&&a[i]>a[s.top()]){
                int idx=i-s.top();
                ans[s.top()]=idx;
                s.pop();
            }
            s.push(i);
        }


        return ans;
    }
};