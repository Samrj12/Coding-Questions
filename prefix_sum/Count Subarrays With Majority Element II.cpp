class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int pre = n + 1;
        vector<int> cnt(2*n + 2), acc(2*n + 2);
        cnt[pre] = acc[pre] = 1;
        long long res = 0;
        for(int i=0;i<n;i++){
            pre += nums[i] == target ? 1 : -1;
            acc[pre] = ++cnt[pre] + acc[pre - 1];
            res += acc[pre - 1];
        }
        return res;
    }
};
