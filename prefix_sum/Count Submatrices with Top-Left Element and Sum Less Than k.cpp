class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int count = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> pref(m + 1, vector<int> (n + 1));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                pref[i][j] = grid[i - 1][j - 1] + pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1];
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(pref[i][j] > k)break;
                count++;
            }
        }
        return count;
    }
};
