class Solution {
public:
    long long perfectPairs(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0)
                nums[i] *= -1;
        }
        sort(nums.begin(), nums.end());
        long long res = 0;
        int l = 0;
        for (int i = 0; i < n; i++) {
            int b = nums[i];
            int minA = (b + 1) / 2;
            while(nums[l] < minA)l++;
            res += i - l;
        }
        return res;
    }
};
