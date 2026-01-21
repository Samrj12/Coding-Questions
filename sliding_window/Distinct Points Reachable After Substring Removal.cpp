class Solution {
public:
    int distinctPoints(string s, int k) {
        unordered_set<long long> visited;
        int x = 0, y = 0;

        auto update = [&](char c, int dir) {
            if (c == 'L')
                x -= dir;
            else if (c == 'R')
                x += dir;
            else if (c == 'U')
                y += dir;
            else if (c == 'D')
                y -= dir;
        };

        for (int i = 0; i < k; i++)
            update(s[i], 1);

        visited.insert(((long long)x << 32) | (unsigned int)y);

        for (int i = k; i < s.size(); i++) {
            update(s[i - k], -1); 
            update(s[i], 1);      

            visited.insert(((long long)x << 32) | (unsigned int)y);
        }

        return visited.size();
    }
};
