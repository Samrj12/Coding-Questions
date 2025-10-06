class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;

        pq.push({grid[0][0], 0, 0});
        vis[0][0] = true;

        int dirs[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

        while(!pq.empty()) {
            auto [maxSoFar, r, c] = pq.top();
            pq.pop();

            if(r == n-1 && c == n-1) return maxSoFar;

            for(auto& d : dirs) { 
                int nr = r + d[0], nc = c + d[1];
                if(nr < 0 || nc < 0 || nr >= n || nc >= n || vis[nr][nc]) continue;

                vis[nr][nc] = true;
                int newMax = max(maxSoFar, grid[nr][nc]);
                pq.push({newMax, nr, nc});
            }
        }
        return -1; // should not happen
    }
};
