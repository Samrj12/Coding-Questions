class Solution {
public:
    string removeSubstring(string s, int k) {
        vector<pair<char, int>> st;
        for(char c : s){
            if(!st.empty() && st.back().first == c)
            st.back().second++;
            else
            st.push_back({c, 1});
            int n = st.size();
            while(n > 1 && st[n - 2].first == '(' && st[n - 2].second >= k && st[n - 1].first == ')' && st[n - 1].second == k){
                st.pop_back();
                n--;
                st.back().second -= k;
                if(st.back().second == 0)
                {
                    st.pop_back();
                    n--;
                }
            }
        }
        string res = "";
        for(auto& [c, ct] : st){
            res += string(ct, c);
        }
        return res;
    }

};
