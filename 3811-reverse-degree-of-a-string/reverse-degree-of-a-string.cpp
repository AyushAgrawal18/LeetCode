class Solution {
public:
    int reverseDegree(string s) {
        long long ans=0;
        for(int i=0;i<s.length();i++){
            int x = ('z'-s[i])+1;
            ans+=(x*(i+1));
        }
        return ans;
    }
};