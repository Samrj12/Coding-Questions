class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        int m = INT_MAX;
        unordered_map<int, int> freq;
        for(int i : b1)
        {
            freq[i]++;
            m = min(m, i);
        }
        for(int i : b2)
        {
            freq[i]--;
            m = min(m, i);
        }

        vector<int> merge;
        for(auto [k, c] : freq){
            if(abs(c) % 2 != 0)
            return -1;

            for(int i=0;i<abs(c)/2;i++){
                merge.push_back(k);
            }
        }
        nth_element(merge.begin(), merge.begin() + merge.size()/2, merge.end());
        return accumulate(merge.begin(), merge.begin() + merge.size() / 2, 0ll,
                          [&](long long res, int x) -> long long {
                              return res + min(2 * m, x);
                          });
    }
};
