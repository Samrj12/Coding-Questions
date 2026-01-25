class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();
        int z0 = 0;
        for (char c : s)
            if (c == '0')
                z0++;
        if (z0 == 0)
            return 0;

        vector<int> dist(n + 1, -1);
        queue<int> q;

        set<int> unvisited[2];
        for (int i = 0; i <= n; i++) {
            unvisited[i % 2].insert(i);
        }

        q.push(z0);
        dist[z0] = 0;
        unvisited[z0 % 2].erase(z0);

        while (!q.empty()) {
            int z = q.front();
            int o = n - z;
            q.pop();
            int maxZflip = min(z, k);
            int minZflip = o >= k ? 0 : k - o;
            int nextZ_min = z - maxZflip + (k - maxZflip);
            int nextZ_max = z - minZflip + (k - minZflip);
            int p = nextZ_min % 2;
            auto it = unvisited[p].lower_bound(nextZ_min);

            while (it != unvisited[p].end() && *it <= nextZ_max) {
                int nz = *it;
                if (nz == 0)
                    return dist[z] + 1;
                dist[nz] = dist[z] + 1;
                q.push(nz);
                it = unvisited[p].erase(it);
            }
        }

        return -1;
    }
};
