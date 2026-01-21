class Solution {
public:
    vector<vector<int>> dist;
    int maxPartitionFactor(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2)
            return 0;
        dist.resize(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                dist[i][j] = dist[j][i] = abs(points[i][0] - points[j][0]) +
                             abs(points[i][1] - points[j][1]);
            }
        }
        int low = 0, high = INT_MAX, ans = 0;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            if (isValid(points, mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
    bool isValid(vector<vector<int>>& points, int D) {
        int n = points.size();
        vector<int> color(n, -1);

        for (int i = 0; i < n; i++) {
           if(color[i] == -1){
            if(!dfs(i,0,n, color, D))return false;
           }
        }
        return true;

    }

    bool dfs(int u, int c, int n, vector<int>& color, int D){
        color[u] =c;
        for(int v =0; v<n;v++){
            if(v == u)continue;
            if(dist[v][u] < D){
                if(color[v] == -1){
                    if(!dfs(v, 1 - c,n, color, D))return false;
                }else if(color[v] == color[u])return false;
            }
        }
        return true;
    }
};
