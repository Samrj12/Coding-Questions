class Solution {
public:
    int maxXorSubsequences(vector<int>& nums) {
        int mx = 0;
        vector<int> basis(31, 0);
        for(int x : nums){
            for(int i= 30; i>=0 ; i--){
                if(!((x >> i) & 1))continue;
                if(!basis[i]){
                    basis[i] = x;
                    break;
                }
                x ^= basis[i];
            }
        }
        for(int i = 30; i>= 0;i--)
        mx = max(mx, mx ^ basis[i]);
        return mx;
    }
};
