class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int extra = nums2[n];
        long long tot = 0; int extraCost = INT_MAX;

        for(int i=0;i<n;i++){
            int cost = 0;
            if ((nums1[i] <= extra && extra <= nums2[i]) ||
                (nums1[i] >= extra && extra >= nums2[i]))
                cost = 0;
            else
            cost = min(abs(nums1[i] - extra), abs(nums2[i] - extra));
            tot += abs(nums1[i] - nums2[i]);
            extraCost = min(extraCost, cost);
        }
        return tot + extraCost + 1;
    }
};
