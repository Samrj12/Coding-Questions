class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(n, vector<vector<long long>> (k + 1, vector<long long> (3, -1)));
        return dfs(prices,k,0,0,dp);
    }
    long long dfs(vector<int> & prices, int k, int idx, int prevAct, vector<vector<vector<long long>>>& dp){
        if(idx == prices.size())
        return prevAct == 0 ? 0 : LLONG_MIN /100;
        if(dp[idx][k][prevAct] != -1)return dp[idx][k][prevAct];
        if(prevAct == 0 && k > 0) // buy or short sell
        {
            dp[idx][k][prevAct] = dfs(prices, k - 1,idx + 1, 1, dp) - prices[idx];//bought
            dp[idx][k][prevAct] = max( dp[idx][k][prevAct], dfs(prices, k - 1,idx + 1, 2, dp) + prices[idx]);//short sell
        }else if(prevAct == 1){
            dp[idx][k][prevAct] = dfs(prices, k,idx + 1, 0, dp) + prices[idx];//sell
        }else{
             dp[idx][k][prevAct] = dfs(prices,k,idx + 1, 0, dp) - prices[idx]; //buying as we short sold before
        }
        return dp[idx][k][prevAct] = max( dp[idx][k][prevAct], dfs(prices,k,idx + 1, prevAct, dp));
    }
};
