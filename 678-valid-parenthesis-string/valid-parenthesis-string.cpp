class Solution {
public:
    bool checkValidString(string s) {
        int n=s.size();
        int a=0,b=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                a++,b++;
            }
            else if(s[i]==')'){
                a--,b--;
            }
            else{
                a--,b++;
            }
            if(b<0) return false;
            a=max(a,0);
        }
        return a==0; 
    }
};