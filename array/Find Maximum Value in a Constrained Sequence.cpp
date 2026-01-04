class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions,
                   vector<int>& diff) {
        vector<long long> vals(n, LLONG_MAX);
        vals[0] = 0;

        for (auto& r : restrictions) {
            vals[r[0]] = (long long)r[1];
        }

        for (int i = 1; i < n; i++) {
            vals[i] = min(vals[i], vals[i - 1] + diff[i - 1]);
        }

        for (int i = n - 2; i >= 0; i--) {
            vals[i] = min(vals[i], vals[i + 1] + diff[i]);
        }

        return *max_element(vals.begin(), vals.end());
    }
};
