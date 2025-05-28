class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n1 = edges1.size() + 1, n2 = edges2.size() + 1;
        vector<vector<int>> adj1(n1), adj2(n2);
        vector<int> ct1(n1), ct2(n2);
        for(auto& e : edges1){
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        for(auto& e : edges2){
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }
        for(int i=0;i<n1;i++)
        ct1[i] = dfs(adj1, k, i, -1);
        int mx = 0;
        for(int i=0;i<n2;i++){
        ct2[i] = dfs(adj2, k - 1, i, -1);mx  = max(mx, ct2[i]);}


        for(int i=0;i<n1;i++)
        ct1[i] += mx;
        return ct1;
    }

    int dfs(vector<vector<int>>& adj, int k, int curr, int p){
        if(k < 0)return 0;
        int res = 1;
        for(int v : adj[curr]){
            if(p == v)continue;
            res += dfs(adj, k - 1, v, curr);
        }
        return res;
    }
};
