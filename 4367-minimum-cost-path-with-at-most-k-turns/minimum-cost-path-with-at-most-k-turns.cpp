class Solution {
public:

    int minCost(vector<vector<int>>& a, int k) {
        int n = a.size();
        int m = a[0].size();

        const long long INF = 1e18;

        // dp[i][j][turns][dir]
        // dir = 0 -> up
        // dir = 1 -> down
        // dir = 2 -> left
        // dir = 3 -> right
        vector<vector<vector<vector<long long>>>> dp(
            n,
            vector<vector<vector<long long>>>(
                m,
                vector<vector<long long>>(
                    k + 1,
                    vector<long long>(4, INF)
                )
            )
        );

        using T = tuple<long long, int, int, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;

        for (int d = 0; d < 4; d++) {
            dp[0][0][0][d] = a[0][0];
            pq.push({a[0][0], 0, 0, 0, d});
        }

        int dx[4] = {-1, 1, 0, 0};
        int dy[4] = {0, 0, -1, 1};

        long long ans = INF;

        while (!pq.empty()) {
            auto [cost, i, j, turns, dir] = pq.top();
            pq.pop();

            if (cost != dp[i][j][turns][dir])
                continue;

            if (i == n - 1 && j == m - 1) {
                ans = min(ans, cost);
            }

            for (int nd = 0; nd < 4; nd++) {

                int ni = i + dx[nd];
                int nj = j + dy[nd];

                if (ni < 0 || nj < 0 || ni >= n || nj >= m)
                    continue;

                int newTurns = turns;

                if (nd != dir)
                    newTurns++;

                if (newTurns > k)
                    continue;

                long long newCost = cost + a[ni][nj];

                if (newCost < dp[ni][nj][newTurns][nd]) {
                    dp[ni][nj][newTurns][nd] = newCost;

                    pq.push({
                        newCost,
                        ni,
                        nj,
                        newTurns,
                        nd
                    });
                }
            }
        }

        return ans == INF ? -1 : (int)ans;
    }
};