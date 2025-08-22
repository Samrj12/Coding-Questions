class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int mnx = INT_MAX, mny = INT_MAX, mxx = -1,  mxy= -1;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == 1){
                    mnx = min(j, mnx);
                    mny = min(i, mny);
                    mxx = max(j, mxx);
                    mxy = max(i, mxy);
                }
            }
        }
        return (mxx - mnx + 1) * (mxy - mny + 1);
    }
};
