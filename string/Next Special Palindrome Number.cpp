class Solution {
public:
    vector<long long> precomputed;
    string nextPermutation(const string& s) {
        string dup = s;
        if(s.size() == 0)return dup;
        int n = s.size(), l = s.size() - 1;
        while (l > 0 && s[l - 1] >= s[l])
            l--;
        if (l == 0)
            return dup;
        int p = bs(l, n - 1, s, s[l - 1]);
        swap(dup[p], dup[l - 1]);
        reverse(dup.begin() + l, dup.end());
        return dup;
    }
    int bs(int l, int r, const string& s, char c) {
        int ans = 0;
        while (l <= r) {
            int m = (l + r) / 2;
            if (s[m] > c)
                ans = m, l = m + 1;
            else
                r = m - 1;
        }
        return ans;
    }
    array<int, 3> check(int n) {
        int cnt = 0, oddCnt = 0, oddNum = -1;
        for (int i = 0; i < 9; i++) {
            if (n & (1 << i)) {
                cnt += i + 1;
                if ((i + 1) % 2) {
                    oddCnt++;
                    oddNum = i + 1;
                }
            }
        }
        return {cnt, oddCnt, oddNum};
    }
    string getHalf(int n) {
        string ans = "";
        for (int i = 0; i < 9; i++) {
            if (n & (1 << i)) {
                for(int j = 0; j < (i + 1)/2;j++)
                ans += ((i + 1)) + '0';
            }
        }
        return ans;
    }
    void precompute() {
        for (int i = 1; i < (1 << 9); i++) {
            auto [cnt, oddCnt, oddNum] = check(i);
            if (oddCnt > 1 || cnt > 16)
                continue;
            string half = getHalf(i);
            string curr =half;
            do {
                string rev = curr;
                reverse(rev.begin(), rev.end());
                string res = curr + (oddCnt ? to_string(oddNum) : "") + rev;
                precomputed.push_back(stoll(res));
            } while (next_permutation(curr.begin(), curr.end()));
        }
        sort(precomputed.begin(), precomputed.end());
    }
    long long specialPalindrome(long long n) {
        if(precomputed.empty())precompute();
        auto it = upper_bound(precomputed.begin(), precomputed.end(), n);
        return *it;
    }
};
