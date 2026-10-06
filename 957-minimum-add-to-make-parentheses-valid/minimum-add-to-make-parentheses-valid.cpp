class Solution {
public:
    int minAddToMakeValid(string s) {
        int n=s.size();
        stack<char> st;
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push(s[i]);
                ans++;
            }
            else{
                if(!st.empty()){
                    st.pop();
                    ans--;
                }
                else ans++;
            }
        }
        return ans;
    }
};