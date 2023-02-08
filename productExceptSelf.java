class Solution {
    public int[] productExceptSelf(int[] nums) {
        int l = nums.length;
        int[] res = new int[l];
        int curr = 1;
        for(int i=0;i<l;i++)
        {
            res[i] = curr;
            curr *= nums[i];
        }
        curr =1;
        for(int j=l-1;j>=0;j--)
        {
            res[j] *= curr;
            curr *= nums[j];
        }
        return res;
    }
}
