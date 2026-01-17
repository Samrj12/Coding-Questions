class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            unordered_set<int> st;
            int sum = 0;
            for(int j = i; j<n;j++){
                st.insert(nums[j]);
                sum += nums[j];
                if(st.count(sum))
                res++;
            }
        }
        return res;

    }
};
