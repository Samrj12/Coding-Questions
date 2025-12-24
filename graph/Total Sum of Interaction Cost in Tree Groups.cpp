class Solution {
public:
    long long ans = 0;

    unordered_map<int, pair<long long, long long>>
    dfs(int u, int p, vector<vector<int>>& adj, vector<int>& group) {

        unordered_map<int, pair<long long, long long>> cur;
        cur[group[u]] = {1, 0}; // count, sumDist

        for (int v : adj[u]) {
            if (v == p) continue;

            auto child = dfs(v, u, adj, group);

            for(auto& [g, pr] : child){
                pr.second += pr.first;
            }
            for(auto& [g, pr] : child){
                if(cur.count(g)){
                    ans += cur[g].first * pr.second + pr.first * cur[g].second;
                }
            }
            for(auto& [g, pr] : child){
                cur[g].second += pr.second;
                cur[g].first += pr.first;

            }
        }

        return cur;
    }

    long long interactionCosts(int n, vector<vector<int>>& edges, vector<int>& group) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        dfs(0, -1, adj, group);
        return ans;
    }
};
