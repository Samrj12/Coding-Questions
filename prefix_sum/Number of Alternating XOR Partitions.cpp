class Solution {
public:
    const int MOD = 1e9 + 7;
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        unordered_map<int, int> mp_odd, mp_even;
        long long curr1 = 0, curr2 = 0;
        int pr = 0;

        for (int i : nums) {
            pr ^= i;
            curr1 = (mp_even[pr ^ target1] + (pr == target1 ? 1 : 0)) % MOD;
            curr2 = (mp_odd[pr ^ target2]) % MOD;

            // 3. Log these results so FUTURE indices can look back at them
            mp_odd[pr] = (mp_odd[pr] + curr1) % MOD;
            mp_even[pr] = (mp_even[pr] + curr2) % MOD;
        }
        return (curr1 + curr2) % MOD;
    }
};
