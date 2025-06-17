const int MOD = 1e9 + 7;
const int MX = 1e5;

long long fact[MX];
long long inv_fact[MX];

class Solution {
    long long qpow(long long base, int exp) {
        long long res = 1;
        while (exp) {
            if(exp & 1){
                res = (res * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return res;
    }

    long long comb(int n, int m) {
        return fact[n] * inv_fact[m] % MOD * inv_fact[n - m] % MOD;
    }
    void init() {
        if (fact[0]) {
            return;
        }
        fact[0] = 1;
        for(int i=1;i<MX;i++)
        fact[i] = (i * fact[i - 1]) % MOD;

        inv_fact[MX - 1] = qpow(fact[MX - 1], MOD - 2);
        for(int i = MX - 1; i>=1;i--)
        inv_fact[i - 1] = (i * inv_fact[i]) % MOD;
    }

public:
    int countGoodArrays(int n, int m, int k) {
        init();
        return comb(n - 1, k) * m % MOD * qpow(m - 1, n - k - 1) % MOD;
    }
};
