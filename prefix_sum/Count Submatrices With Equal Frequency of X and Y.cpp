class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int sum = 0, m = grid.size(), n = grid[0].size();
        vector<vector<array<int, 2>>> pref(m + 1, vector<array<int, 2>>(n + 1, {0, 0}));
        
        int res = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                pref[i][j][0] = pref[i-1][j][0] + pref[i][j-1][0] - pref[i-1][j-1][0];
                pref[i][j][1] = pref[i-1][j][1] + pref[i][j-1][1] - pref[i-1][j-1][1];
                
                char c = grid[i-1][j-1];
                if (c == 'X') {
                    pref[i][j][0]++; 
                    pref[i][j][1]++; 
                } else if (c == 'Y') {
                    pref[i][j][0]--;
                }
                
                if (pref[i][j][0] == 0 && pref[i][j][1] > 0) {
                    res++;
                }
            }
        }
        return res;
    }
};
