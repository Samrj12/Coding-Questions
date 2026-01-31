class Solution {
    vector<long long> prefixSum;

    long long get_value(long long sumArr) {
        return sumArr * (sumArr + 1) / 2;
    }

    void compute(int L, int R, int optL, int optR, 
                 vector<long long>& prev_dp, vector<long long>& curr_dp) {
        if (L > R) return;

        int mid = L + (R - L) / 2;
        int best_p = -1;

        for (int p = optL; p <= min(mid - 1, optR); p++) {
            if (prev_dp[p] == LLONG_MAX) continue;
            
            long long current_sub_sum = prefixSum[mid] - prefixSum[p];
            long long score = prev_dp[p] + get_value(current_sub_sum);
            
            if (score < curr_dp[mid]) {
                curr_dp[mid] = score;
                best_p = p;
            }
        }

        compute(L, mid - 1, optL, best_p, prev_dp, curr_dp);
        compute(mid + 1, R, best_p, optR, prev_dp, curr_dp);
    }

public:
    long long minPartitionScore(vector<int>& nums, int k) {
        int n = nums.size();
        prefixSum.assign(n + 1, 0);
        for (int i = 0; i < n; i++) prefixSum[i + 1] = prefixSum[i] + nums[i];

        vector<long long> prev_dp(n + 1);
        for (int j = 1; j <= n; j++) prev_dp[j] = get_value(prefixSum[j]);

        for (int i = 2; i <= k; i++) {
            vector<long long> curr_dp(n + 1, LLONG_MAX);
            // Use D&C to fill curr_dp based on prev_dp
            compute(i, n, i - 1, n - 1, prev_dp, curr_dp);
            prev_dp = curr_dp;
        }

        return prev_dp[n];
    }
};
