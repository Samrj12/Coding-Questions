class Solution {
public:
    long long minNumberOfSeconds(int h, vector<int>& workerTimes) {
        int mn = INT_MAX;
        for(int i : workerTimes){
            mn = min(mn, i);
        }
        long long l = 0, r = (mn * (1LL*h * (h + 1))/2);
        long long ans = 0;
        while(l <= r){
            long long mid = l + ((r  - l) >> 1);
            if(canDig(mid, h,workerTimes)){
                ans = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
        return ans;
    }
    
    bool canDig(long long t, int height,  vector<int>& workerTimes){
        long long tot = 0;
        for(int i : workerTimes){
            double limit = 8 * (t / i);
            long long currDig = (-1 + sqrt(1 + limit)) / 2;
            if(tot + currDig >= height)return true;
            tot += currDig;
        }
        return false;
    }
};
