class Solution {
public:
    struct Edge {
        int u, v, w, m;
    };
    class DSU {
    public:
        vector<int> par;
        DSU(vector<int>& p) : par(p) {}
        int find(int u) {
            if (u != par[u]) {
                par[u] = find(par[u]);
            }
            return par[u];
        }
        void unite(int u, int v) {
            int pu = find(u);
            int pv = find(v);
            if (pu != pv) {
                par[pu] = pv;
            }
        
        }
    };
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        int m = edges.size();
        if (m < n - 1)
            return -1;
        vector<int> par(n);
        int up = 1e9;
        for (int i = 0; i < n; i++)
            par[i] = i;
        DSU init(par);
        vector<Edge> must, optional;
        for (const auto& edge : edges) {
            if (edge[3] == 1) {
                must.push_back({edge[0], edge[1], edge[2], edge[3]});
                
            } else {
                optional.push_back({edge[0], edge[1], edge[2], edge[3]});
            }
        }
        if (must.size() > n - 1)
            return -1;
        int selectedInit = 0;
        for (const auto& e : must) {
            if (init.find(e.u) == init.find(e.v))
                return -1;
            selectedInit++;
            init.unite(e.u, e.v);
            up = min(up, e.w);
        }
        sort(optional.begin(), optional.end(), [](const auto& a, const auto& b){
            return b.w < a.w;
        });
        int l = 0;
        int r = up;
        int ans = -1;
        while (l < r) {
            int mid = l + ((r - l + 1) >> 1);

            DSU dsu(init.par);

            int selected = selectedInit;
            int doubledCount = 0;

            for (const auto& edge : optional) {
                if (dsu.find(edge.u) == dsu.find(edge.v)) {
                    continue;
                }

                if (edge.w >= mid) {
                    dsu.unite(edge.u, edge.v);
                    selected++;
                } else if (doubledCount < k && edge.w * 2 >= mid) {
                    doubledCount++;
                    dsu.unite(edge.u, edge.v);
                    selected++;
                } else {
                    break;
                }

                if (selected == n - 1) {
                    break;
                }
            }

            if (selected != n - 1) {
                r = mid - 1;
            } else {
                ans = mid;
                l = mid;
            }
        }

        return ans;
    }
};
