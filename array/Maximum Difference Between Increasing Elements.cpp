class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mn = nums[0];
        int res = -1;
        for(int i=1; i<nums.size();i++){
            if(nums[i] > mn)
            res = max(res, nums[i] - mn);
            else
            mn = nums[i];
        }
        return res;
    }
};
