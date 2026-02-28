class Solution {
public:
const int MOD = 1e9 + 7;
    int concatenatedBinary(int n) {
        long long ans = 0;
        int mod = 1e9 + 7, len = 0;
        for (int i = 1; i <=n; i++) {
            if((i & (i - 1)) == 0)len++;
            ans = ((ans << len) | i) % MOD;
        }   
        return ans;
    }
};
