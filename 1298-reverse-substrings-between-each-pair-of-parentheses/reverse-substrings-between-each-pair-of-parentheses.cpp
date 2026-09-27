class Solution {
public:
    string reverseParentheses(string s) {
        int n=s.size();
        stack<char> a;
        for(int i=0;i<n;i++){
            if(s[i]==')'){
                string temp="";
                while(a.top()!='('){
                    temp+=a.top();
                    a.pop();
                }
                a.pop();
                for(int j=0;j<temp.size();j++){
                    a.push(temp[j]);
                }
            }
            else{
                a.push(s[i]);
            }
        }
        string ans="";
        while(!a.empty()){
            ans+=a.top();
            a.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }

};