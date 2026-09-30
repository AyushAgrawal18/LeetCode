class Solution {
public:
    vector<int> maxDepthAfterSplit(string s) {
        vector<int> ans;
        int depth=0;
        for (int i=0;i<s.size();i++) {
            if (s[i]=='(') {
                ans.push_back(depth%2);
                depth++;
            }
            else{
                depth--;
                ans.push_back(depth%2);
            }
        }
        return ans;
    }
};