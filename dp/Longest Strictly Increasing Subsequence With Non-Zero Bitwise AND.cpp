class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(32, vector<int>(n));
        vector<int> idx(32);
        int mx = 0;
        for (int i = 0; i < 32; i++) {
            for (int val : nums) {
                if ((val >> i) & 1) {
                    int p = binaryS(dp[i], 0, idx[i], val);
                    if (idx[i] == p) {
                        dp[i][idx[i]] = val;
                        idx[i]++;
                        mx = max(mx, idx[i]);
                    } else {
                        dp[i][p] = val;
                    }
                }
            }
        }
        return mx;
    }
    int binaryS(vector<int>& nums, int l, int r, int target) {
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
