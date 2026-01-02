class Solution {
public:
const int MOD = 1e9 + 7;
    int countCoprime(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> dp(n, vector<int> (151, -1));
        return dfs(0, mat,0,dp);
    }
    int dfs(int r, vector<vector<int>>& mat, int g, vector<vector<int>>& dp){
        if(r == mat.size()){
            return g == 1;
        }
        int j = mat[0].size();
        if(dp[r][g] != -1)return dp[r][g];
        int res = 0;
        for(int i=0;i<j;i++){
            res += dfs(r + 1, mat, g ? gcd(g,mat[r][i]): mat[r][i], dp);
            res %= MOD;
        }
        return dp[r][g] = res;
    }
    int gcd(int a, int b){
        if(b == 0)return a;
        return gcd(b, a % b);
    }
};
