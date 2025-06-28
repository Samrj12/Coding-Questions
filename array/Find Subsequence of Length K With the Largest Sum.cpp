class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> pairRes;
        int n = nums.size();
        for(int i=0;i<n;i++)
        pairRes.push_back({i, nums[i]});
        sort(pairRes.begin(), pairRes.end(), [&](auto x1, auto x2){
            return x1.second > x2.second;
        });
        sort(pairRes.begin(), pairRes.begin() + k);
        vector<int> res;
        for(int i=0;i<k;i++)
            res.push_back(pairRes[i].second);
        
        return res;
    }
};
