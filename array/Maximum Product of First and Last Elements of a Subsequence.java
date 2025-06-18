class Solution {
    public long maximumProduct(int[] nums, int m) {
        long res = Long.MIN_VALUE;
        int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
        for(int i=m - 1; i<nums.length;i++){
            min = Math.min(min, nums[i - m + 1]);
            max = Math.max(max, nums[i - m + 1]);
            int other = nums[i];
            if(m != 1)
            {
                if(nums[i] < 0)
                other = min;
                else
                other = max;
            }
            res = Math.max(res,1L*other*nums[i]);
        }
        return res;
    }
}
