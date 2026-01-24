class Solution {
public:
    int minOperations(string s) {
        int ans = 0;
        for (auto x : s) {
            ans = max(ans, ('a' + 26 - x) % 26);
        }
        return ans;
    }
};
