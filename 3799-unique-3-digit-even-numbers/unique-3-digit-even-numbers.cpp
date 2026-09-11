class Solution {
public:
    int totalNumbers(vector<int>& a) {
        unordered_set<int> seen;
        int n = a.size();

        for(int h = 0; h < n; h++){
            if (a[h] == 0) continue;
            for(int t = 0; t < n; t++){
                if (t == h) continue;
                for(int u = 0; u < n; u++){
                    if(u == h || u == t) continue;
                    if(a[u] % 2 != 0) continue;

                    int num = a[h]*100+a[t]*10+a[u];
                    seen.insert(num);
                }
            }
        }

        return seen.size();
    }
};