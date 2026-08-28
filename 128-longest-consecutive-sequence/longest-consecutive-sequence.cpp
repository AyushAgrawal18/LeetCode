class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        if (a.size() == 0)
            return 0;
        // int ans=1;
        // sort(a.begin(),a.end());
        // int count=1;
        // for(int i=1;i<a.size();i++){
        //     if(a[i]==a[i-1]+1) count++;
        //     else{
        //         ans=max(count,ans);
        //         count=1;
        //     }
        // }
        // ans=max(ans, count);
        // return ans;
        set<int> s;

        for (int i = 0; i < a.size(); i++) {
            s.insert(a[i]);
        }

        int count = 1;
        int ans = 1;

        auto it = s.begin();
        auto prev = it;
        it++;

        while (it != s.end()) {
            if (*it == *prev + 1) {
                count++;
            } else {
                ans = max(ans, count);
                count = 1;
            }

            prev = it;
            it++;
        }

        ans = max(ans, count);

        return ans;
    }
};