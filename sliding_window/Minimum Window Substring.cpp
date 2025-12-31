class Solution {
public:
    string minWindow(string st, string t) {
        if (t.size() > st.size())
            return "";
        vector<int> mp(128);
        int k = t.size();
        for (char c : t)
            mp[c]++;
        int s = 0;
        int res = INT_MAX;
        int x = -1;
        for (int e = 0; e < st.size(); e++) {
            if (mp[st[e]]-- > 0) {
                k--;
            }
            while (k == 0) {
                if (e - s + 1 < res) {
                    res = e - s + 1;
                    x = s;
                }
                if (mp[st[s]]++ >= 0) {
                    k++;
                }
                s++;
            }
        }
        return x == -1 ? "" : st.substr(x, res);
    }
};
