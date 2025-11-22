class Solution {
public:
    using ll = long long;
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        ll sum = 1LL * (n)*(n + 1)/2;
        ll curr = 0;
        if(sum < target || -sum > target)return {};
        vector<int> res;
        for(int i=n;i >= 1; i--){
            curr += i;
            if(sum - curr >= target + i ){
                target += i;
                res.push_back(-i);
            }else{
                target -= i;
                res.push_back(i);
            }
        }
        if(target != 0)return {};
        sort(res.begin(), res.end());
        return res;
    }
};
