class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size() , m = grid[0].size();
        long long total = 0;
        vector <long long> row(n) , col(m); 
        for(int i = 0 ; i < n ; i++)
            for(int j = 0 ; j < m ; j++)
                row[i] += grid[i][j] , col[j] += grid[i][j] , total += grid[i][j];

        if(total % 2)return false;
        total /= 2;
        for(int i = 0; i < n ; i++){
            row[i] += (i > 0 ? row[i - 1] : 0);
            if(row[i]  == total) 
                return true; 
        }
        for(int i = 0 ; i < m ; i++){
            col[i] += (i > 0 ? col[i - 1] : 0);
            if(col[i] == total)
                return true; 
        }
        return false;
    }
};
