class Solution {
public:

    int countPrimes(int n) {
       if (n <= 2) return 0;
        static vector<bool> isPrime;
        if (isPrime.empty()) {
            int MAXN = 5000000;
            isPrime.resize(MAXN, true);
            isPrime[0] = isPrime[1] = false;
            for (int i = 2; i <= MAXN / i; i++) {
                if (isPrime[i]) {
                    for (int j = i * i; j < MAXN; j += i) {
                        isPrime[j] = false;
                    }
                }
            }
        }
        int count = 0;
        for (int i = 2; i < n; i++) {
            if (isPrime[i]) {
                count++;
            }
        }

        return count;
    }
};