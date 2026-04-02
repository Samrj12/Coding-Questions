class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>> (n, vector<int> (3, INT_MIN)));
        return dfs(0,0,2, coins,dp);
    }
    int dfs(int i, int j, int k, vector<vector<int>>& coins, vector<vector<vector<int>>>& dp){
        if(i == coins.size() - 1 &&  j == coins[0].size() - 1){
            return coins[i][j] < 0 && k > 0 ? 0 : coins[i][j];
        }
        if(i >= coins.size() || j >= coins[0].size() ){
            return INT_MIN/100;
        }
        if(dp[i][j][k] != INT_MIN)return dp[i][j][k];

        int& ans = dp[i][j][k];
        int right = dfs(i, j + 1, k, coins, dp);
        int down = dfs(i + 1, j, k, coins, dp);
        if(coins[i][j] >= 0){
            ans = coins[i][j] + max(right, down);
        }else{
            if(k > 0){
                ans = max(dfs(i, j + 1, k - 1,coins, dp),  dfs(i + 1, j, k - 1, coins, dp));
            }
            ans = max(ans, coins[i][j] + max(right, down));
        }
        return ans;
    }
};
