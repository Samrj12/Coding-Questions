class Solution {
public:
    bool solveHorizontal(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        long long bottomSum = 0, topSum = 0;
        unordered_map<int, int> bottomFreq, topFreq;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                bottomSum += grid[i][j];
                bottomFreq[grid[i][j]]++;
            }
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < m; j++) {
                bottomSum -= grid[i][j];
                bottomFreq[grid[i][j]]--;
                topSum += grid[i][j];
                topFreq[grid[i][j]]++;
            }

            if (topSum == bottomSum)
                return true;

            long long diffTop = topSum - bottomSum;
            if (diffTop > 0 && diffTop <= 100000) {
                int h = i + 1, w = m;
                if (h > 1 && w > 1) {
                    if (topFreq[diffTop] > 0)
                        return true;
                } else if (h > 1 && w == 1) {
                    if (grid[0][0] == diffTop || grid[i][0] == diffTop)
                        return true;
                } else if (h == 1 && w > 1) {
                    if (grid[0][0] == diffTop || grid[0][w - 1] == diffTop)
                        return true;
                }
            }

            long long diffBottom = bottomSum - topSum;
            if (diffBottom > 0 && diffBottom <= 100000) {
                int h = n - i - 1, w = m;
                if (h > 1 && w > 1) {
                    if (bottomFreq[diffBottom] > 0)
                        return true;
                } else if (h > 1 && w == 1) {
                    if (grid[i + 1][0] == diffBottom ||
                        grid[n - 1][0] == diffBottom)
                        return true;
                } else if (h == 1 && w > 1) {
                    if (grid[n - 1][0] == diffBottom ||
                        grid[n - 1][w - 1] == diffBottom)
                        return true;
                }
            }
        }

        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        if (solveHorizontal(grid))
            return true;

        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> transposed(m, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                transposed[j][i] = grid[i][j];
            }
        }

        return solveHorizontal(transposed);
    }
}
;
