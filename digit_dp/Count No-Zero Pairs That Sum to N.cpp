class Solution {
public:
string s;
    long long dp[16][2][2][2];
    long long countNoZeroPairs(long long n) {
        s = to_string(n);
        reverse(s.begin(), s.end());
        memset(dp, -1, sizeof(dp));
        return dfs(0, 0, 0, 0);
    }

    long long dfs(int idx, int carry, int za, int zb){
        if(idx == s.size()){
            return carry == 0;
        }
        if(dp[idx][carry][za][zb] != -1)return dp[idx][carry][za][zb] ;
        int ea = (za ? 0 : 9);
        int eb = (zb ? 0 : 9);
        int sa = ((idx == 0) ? 1 : 0);
        int sb = ((idx == 0) ? 1 : 0);
        long long& res = dp[idx][carry][za][zb] ;
        res = 0;
        for(int i=sa; i<= ea;i++){
            for(int j = sb; j <= eb; j++){
                int x = i + j + carry;
                if((x % 10) == (s[idx] - '0')){
                    res += dfs(idx + 1, x / 10, za | (i == 0), zb | (j == 0));
                }
            }
        }
        return res;
    }
};
