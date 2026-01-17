class Solution {
public:
    long long min_cost_to_match(long long val, long long mask) {
        if ((val & mask) == mask) return 0;
        
        long long x = 0;
        for (int i = 30; i >= 0; --i) {
            if((mask >> i) & 1){
                if((val >> i) & 1){
                    x |= (1 << i);
                }else{
                    x |= (1 << i);
                    for(int j = i - 1;j >=0;j--){
                        if((mask >> j) & 1){
                            x |= (1 << j);
                        }
                    }
                    return x - val;
                }
            }else if((val >> i) & 1){
                x |= (1 << i);
            }
        }
        return x - val;
    }

    int maximumAND(vector<int>& nums, int k, int m) {
        long long current_mask = 0;
        
        for (int b = 30; b >= 0; --b) {
            long long target_mask = current_mask | (1LL << b);
            vector<long long> costs;
            
            for (int num : nums) {
                costs.push_back(min_cost_to_match((long long)num, target_mask));
            }
            
            sort(costs.begin(), costs.end());
            
            long long total = 0;
            for(int i=0;i<m;i++){
                total += costs[i];
                if(total > k)
                break;
            }
            if (total <= k) {
                current_mask = target_mask;
            }
        }
        
        return (int)current_mask;
    }
};
