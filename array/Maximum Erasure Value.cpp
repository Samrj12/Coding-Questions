class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int l = 0, r = 0;
        int currSum = 0;
        int mx = 0;
        while(r < n){
            mp[nums[r]]++;
            currSum += nums[r];
            while(mp[nums[r]] > 1){
                currSum -= nums[l];
                mp[nums[l]]--;
                l++;
            }
            mx = max(mx, currSum);
            r++;
        }
        return mx;
    }
};
