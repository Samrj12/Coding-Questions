class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int m = grid.size();
        if (m == 0) return 0;

        int ans = (1 << 21) - 1;
        int mn = INT_MIN;
        const int num_bits = 32;  
        for (int b = 20; b >= 0; --b) {
            int cand = ans & (~(1 << b));
            bool ok = true;
            for(int i=0;i<m;i++){
                bool rowHas = false;
                for(int v : grid[i]){
                    if((v & cand) == v){
                        rowHas = true;
                        break;
                    }
                }
                if(!rowHas){
                    ok = false;
                    break;
                }
            }
            if(ok){
                ans = cand;
            }

        }
        return ans;
    }
};
