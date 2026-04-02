class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        int dp[m][n][3];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 3; k++)
                    dp[i][j][k] = INT_MIN / 100;
            }
        }
        for (int i = 0; i < 3; i++) {
            if (i > 0 && coins[0][0] < 0)
                dp[0][0][i] = 0;
            else
                dp[0][0][i] = coins[0][0];
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0)
                    continue;
                for (int k = 0; k < 3; k++) {
                    int prev = INT_MIN / 100;
                    if (i > 0)
                        prev = max(prev, dp[i - 1][j][k]);
                    if (j > 0)
                        prev = max(prev, dp[i][j - 1][k]);
                    dp[i][j][k] = coins[i][j] + prev;
                    if (k > 0 && coins[i][j] < 0) {
                        prev = INT_MIN / 100;

                        if (i > 0)
                            prev = max(prev, dp[i - 1][j][k - 1]);
                        if (j > 0)
                            prev = max(prev, dp[i][j - 1][k - 1]);
                        dp[i][j][k] = max(dp[i][j][k], prev);
                    }
                }
            }
        }
        return *max_element(dp[m - 1][n - 1], dp[m - 1][n - 1] + 3);
    }
};
