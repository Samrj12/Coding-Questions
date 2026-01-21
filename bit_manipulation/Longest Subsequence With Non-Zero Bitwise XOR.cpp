class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int tot = 0;
        bool nonZero = false;

        for(int x : nums){
            tot ^= x;
            if(x != 0) nonZero = true;
        }

        if(tot != 0) 
            return nums.size();
        if(nonZero) 
            return nums.size() - 1;
        else 
            return 0;
    }
};
