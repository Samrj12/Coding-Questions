class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int d, int k) {
        vector<int> dst(n, INT_MAX);
        dst[src] = 0;
        for(int i=0;i<=k;i++)
        {
            vector<int> tmp = dst;
            for(auto& fl : flights)
            {
                int u = fl[0], v = fl[1], cst = fl[2];
                if(dst[u] != INT_MAX && tmp[v] > dst[u] + cst)
                {
                    tmp[v] =  dst[u] + cst;
                }
            }
            dst = tmp;
        }
        return dst[d] == INT_MAX ? -1 : dst[d];
    }
};
