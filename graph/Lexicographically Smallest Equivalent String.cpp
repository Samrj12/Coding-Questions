class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char, unordered_set<char>> mp;
        int n = s1.size();
        for(int i=0;i<n;i++){
            mp[s1[i]].insert(s2[i]);
            mp[s2[i]].insert(s1[i]);
        }
        string res = "";
        vector<char> mpToSmallest;
        for(char ch = 'a'; ch <= 'z'; ch++){
            vector<int> vis(26);
            mpToSmallest.push_back(dfs(ch, vis, mp));
        }
        for(char ch : baseStr)
        res += mpToSmallest[ch - 'a'];
        return res;
    }
    char dfs(char curr, vector<int>& vis, unordered_map<char, unordered_set<char>>& mp){
        vis[curr - 'a'] = 1;
        char minCh = curr;
        for(char ch : mp[curr]){
            if(vis[ch - 'a'] == 0){
                minCh = min(minCh, dfs(ch, vis, mp));
            }
        }
        return minCh;
    }
};
