class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        for(int i=0;i<nums.size();i++)
        nums[i] *= nums[i];
        sort(nums.begin(), nums.end());
        long long res = 0;
        int p = nums.size()/2;
        for(int i = nums.size() - 1; i>=0;i--){
            res += (i >= p ? 1 : -1) * (nums[i]);
        }
        return res;
    }
};
