class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int s = 0, e = 0;
        int z = 0;
        int mx = 0, n = nums.size();
        while(e < n){
            if(nums[e] == 0)z++;
            while(z > 1){
                if(nums[s++] == 0)z--;
            }
            mx = max(mx, e - s);
            e++;
        }
        return mx;
    }
};
