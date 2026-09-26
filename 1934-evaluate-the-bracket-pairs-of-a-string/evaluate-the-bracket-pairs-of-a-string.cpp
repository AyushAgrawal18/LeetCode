class Solution {
public:
    string evaluate(string s, vector<vector<string>>& k) {
        map<string, string> mp;
        for (auto &x : k)
            mp[x[0]] = x[1];
        string ans;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]!='(') ans.push_back(s[i]);
            else{
                int r=i+1;
                string temp;
                while(s[r]!=')'){
                    temp.push_back(s[r]);
                    r++;
                }
               if (mp.count(temp))
                ans += mp[temp];
            else
                ans += '?';
                i=r;
            }
        }
        return ans;
    }
};