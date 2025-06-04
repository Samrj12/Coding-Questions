class Solution {
public:
    int minMoves(vector<string>& A) {
        int r = A.size(), c = A[0].size();
        vector<vector<int>> dist(r, vector<int>(c, INT_MAX));
        unordered_map<char, vector<pair<int, int>>> portals;
        vector<vector<bool>> visited(r, vector<bool>(c, false));
        vector<bool> usedTeleport(26, false);

        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                char ch = A[i][j];
                if (isupper(ch)) {
                    portals[ch].emplace_back(i, j);
                }
            }
        }

        deque<pair<int, int>> q;
        q.push_back({0, 0});
        dist[0][0] = 0;

        int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop_front();
            int d = dist[i][j];

            for (int k = 0; k < 4; ++k) {
                int ni = i + dx[k], nj = j + dy[k];
                if (ni >= 0 && nj >= 0 && ni < r && nj < c && A[ni][nj] != '#' && dist[ni][nj] > d + 1) {
                    dist[ni][nj] = d + 1;
                    q.push_back({ni, nj});
                }
            }

            char ch = A[i][j];
            if (isupper(ch) && !usedTeleport[ch - 'A']) {
                usedTeleport[ch - 'A'] = true;
                for (auto& [ti, tj] : portals[ch]) {
                    if ((ti != i || tj != j) && dist[ti][tj] > d) {
                        dist[ti][tj] = d;
                        q.push_front({ti, tj});
                    }
                }
            }
        }

        return dist[r - 1][c - 1] == INT_MAX ? -1 : dist[r - 1][c - 1];
    }
};
