class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        int mx1 = 0, mx2 = 0, mx3 = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int l = min(min(i, m - 1 - i), min(j, n - 1 - j));
                for (int k = 0; k <= l; k++) {
                    int sum = 0;
                    for (int s = i - k; s <= i + k; s++) {
                        for (int t = j - k; t <= j + k; t++) {
                            if (abs(s - i) + abs(t - j) == k)
                                sum += grid[s][t];
                        }
                    }
                    if(sum > mx1){
                        mx3 = mx2;
                        mx2 = mx1;
                        mx1 = sum;
                    }else if(sum > mx2 && sum != mx1){
                        mx3 = mx2;
                        mx2 = sum;
                    }else if(sum > mx3 && sum != mx2 && sum != mx1){
                        mx3 = sum;
                    }
                }
            }
        }
        vector<int> ans;
        if(mx1 != 0)ans.push_back(mx1);
        if(mx2 != 0)ans.push_back(mx2);
        if(mx3 != 0)ans.push_back(mx3);
        return ans;
    }
};
