class Solution {
public:
    int countBinaryPalindromes(long long n) {
        if (n == 0)
            return 1; 

        int B = 64 - __builtin_clzll(n); 
        int ans = 1;                     

        for (int L = 1; L < B; ++L) {
            ans += (1LL << ((L + 1) / 2 - 1));
        }

        long long halfLen = (B + 1) / 2;
        long long pfx = n >> (B / 2);

        long long minPfx = (1LL << (halfLen - 1));
        ans += (pfx - minPfx);

        // 3. Check if the palindrome formed by pfx itself is <= n
        if (createPalindrome(pfx, B) <= n) {
            ans++;
        }

        return ans;
    }

private:
    long long createPalindrome(long long pfx, int totalLen) {
        long long res = pfx;

        long long temp = (totalLen % 2 == 0) ? pfx : (pfx >> 1);
        while(temp){
            res = (res << 1) | (temp & 1);
            temp >>= 1;
        }
        return res;
    }
};
