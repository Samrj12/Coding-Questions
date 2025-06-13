class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int n  = nums.size();
        int l = 0, h = nums[n - 1] - nums[0] + 1;
        while(l < h)
        {
            int m = l + (h - l)/2;
            int total = 0;
            int k = 1;
            while(k < n)
            {
                if(nums[k] - nums[k - 1] <= m)
                {
                    total++;k++;
                }
                k++;
            }
            if(total >= p)
            {
                h = m;
            }else{
                l = m + 1;
            }
        }
        return l;
    }
};
