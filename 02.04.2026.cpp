class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, INT_MIN)));
        for (int k = 0; k < 3; k++) {
            dp[m-1][n-1][k] = (k > 0 ? max(0, coins[m-1][n-1]) : coins[m-1][n-1]);
        }
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i == m - 1 && j == n - 1) continue;
                for (int k = 0; k < 3; k++) {
                    int best = INT_MIN;
                    if (i + 1 < m) best = max(best, dp[i+1][j][k]);
                    if (j + 1 < n) best = max(best, dp[i][j+1][k]);
                    if (best != INT_MIN)
                        dp[i][j][k] = coins[i][j] + best;
                    if (coins[i][j] < 0 && k > 0) {
                        int skip = INT_MIN;
                        if (i + 1 < m) skip = max(skip, dp[i+1][j][k-1]);
                        if (j + 1 < n) skip = max(skip, dp[i][j+1][k-1]);
                        dp[i][j][k] = max(dp[i][j][k], skip);
                    }
                }
            }
        }
        return dp[0][0][2];
    }
};
