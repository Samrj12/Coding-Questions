class Solution {
public:
    const int MOD = 1e9 + 7;

    int solve(int cnt0, int cnt1, int prev, int streak, int zero, int one,
              int limit, vector<vector<vector<vector<int>>>>& dp) {

        if (cnt0 > zero || cnt1 > one)
            return 0;

        if (cnt0 == zero && cnt1 == one)
            return 1;

        if (prev != -1 && dp[cnt0][cnt1][prev][streak] != -1)
            return dp[cnt0][cnt1][prev][streak];

        long long ans = 0;

        int newStreak = (prev == 0 ? streak + 1 : 1);
        if (newStreak <= limit)
            ans = (ans +
                   solve(cnt0 + 1, cnt1, 0, newStreak, zero, one, limit, dp)) %
                  MOD;

        newStreak = (prev == 1 ? streak + 1 : 1);
        if (newStreak <= limit)
            ans = (ans +
                   solve(cnt0, cnt1 + 1, 1, newStreak, zero, one, limit, dp)) %
                  MOD;

        if (prev != -1)
            dp[cnt0][cnt1][prev][streak] = ans;

        return ans;
    }

    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<vector<int>>>> dp(
            zero + 1,
            vector<vector<vector<int>>>(
                one + 1, vector<vector<int>>(2, vector<int>(limit + 1, -1))));

        return solve(0, 0, -1, 0, zero, one, limit, dp);
    }
};
