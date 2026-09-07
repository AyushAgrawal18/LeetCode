class Solution {
public:
    const int MOD = 1e9 + 7;
    int solve(int i, string &s, vector<int> &last, vector<long long> &dp) {
        if (i < 0) return 1;
        if (dp[i] != -1) return dp[i];
        
        long long ans = 2 * solve(i - 1, s, last, dp);
        int prev = last[s[i]-'a'];
        if (prev != -1) {
            ans -= solve(prev-1, s, last, dp);
        }
        last[s[i]-'a']=i;

        return dp[i]=(ans + MOD) % MOD;
    }

    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> last(26, -1);
        vector<long long> dp(n, -1);
        return (solve(n - 1, s, last, dp) - 1 + MOD) % MOD;
    }
};