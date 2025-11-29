class Solution {
public:
    int comps = 0;
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<int> adjList[n];
        for (auto edge : edges) {
            int node1 = edge[0];
            int node2 = edge[1];
            adjList[node1].push_back(node2);
            adjList[node2].push_back(node1);
        }
        dfs(adjList, values, 0, -1, k);
        return comps;
    }
    int dfs(vector<int> adjList[], vector<int>& nodeVals, int node, int p, int k){
        int sum = 0;
        for(int nei : adjList[node]){
            if(nei != p)
            sum += dfs(adjList, nodeVals, nei, node, k);
        }
        sum += nodeVals[node];
        sum %= k;
        if(sum == 0)
        {
            comps++;
        }
        return sum;
    }
};
