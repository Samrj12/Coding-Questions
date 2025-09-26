class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int cnt = 0;
        sort(nums.begin(), nums.end());
        int n= nums.size();
        int k = 2;
        for(int i=0;i<n - 2;i++){
            k = i + 2;
            for(int j=i + 1; j < n - 1;j++){
                while(k < n && nums[i] + nums[j] > nums[k])
                k++;
                if(k > j)
                cnt += k - j - 1;
            }
        }
        return cnt;
    }
};
