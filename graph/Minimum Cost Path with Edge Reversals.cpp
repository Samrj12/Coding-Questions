class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back({v, e[2]});
            adj[v].push_back({u, e[2] * 2});
        }
        priority_queue<pair<int, int>> q;
        vector<bool> vis(n);
        q.push({0, 0});

        while (!q.empty()) {
            auto [cost, u] = q.top();
            q.pop();
            if (vis[u])
                continue;
            vis[u] = true;
            if (u == n - 1)
                return -cost;
            for (auto& [v, w] : adj[u]) {
                if (vis[v])
                    continue;
                q.push({cost - w, v});
            }
        }
        return -1;
    }
};
