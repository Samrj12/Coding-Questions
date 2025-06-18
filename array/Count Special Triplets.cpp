class Solution {
public:
    const int MOD = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, int> mp; // cnt for i
        unordered_map<int, int> prodJ; //cnt for j
        int res = 0;
        int n = nums.size();
        for(int i=0;i<n ;i++){
            
            if(nums[i] % 2 == 0)
            res += prodJ[nums[i] / 2];
            res %= MOD;
            int tot = mp[nums[i] * 2];
            prodJ[nums[i]] += tot;
            prodJ[nums[i]] %= MOD;
            mp[nums[i]]++;
        }
        return res;
    }
};
