typedef __int128 ll;
class Solution {
public:
    bool checkEqualPartitions(vector<int>& nums, long long target) {
        int n = nums.size();
        ll ans = 1;
        for (auto it : nums) {
            ans *= it;
            if (ans > (ll)target * target) return false;
        }

        if (ans != (ll)target * target) return false;

        int maxMask = (1 << n) - 1;
        for(int i=1;i <= maxMask;i++){
            ll currProd = 1;
            for(int j=0;j<n;j++){
                if((1 << j) & i){
                    currProd *= nums[j];
                    if(currProd > target) break;
                }
            }
            if(currProd == target)return true;
        }
        return false;
    }
};
