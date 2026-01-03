class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        string s1 = s;
        sort(s1.begin(), s1.end());
        reverse(s1.begin(), s1.end());
        if (s1 <= target)
            return "";
        vector<int> cnt(26);
        for (char c : s) {
            cnt[c - 'a']++;
        }
        int p = -1;
        int i = 0;
        for (i = 0; i < target.size(); i++) {
            if(nextBig(cnt, target[i]) != -1)
            p = i;
            if (cnt[target[i] - 'a'] > 0)
                cnt[target[i] - 'a']--;
            else {
                break;
            }
        }
        int j = p;
        while(j < i)
        {
            cnt[target[j] - 'a']++;
            j++;
        }
        string res = "";
        int nxt = nextBig(cnt, target[p]);
        cnt[nxt]--;
        res = target.substr(0, p) + (char)('a' + nxt);
        string rem = "";
        for (int i = 0; i < 26; i++)
            while (cnt[i])
            {
                
                res += 'a' + i;
                cnt[i]--;
            }

        return res;
    }

    int nextBig(vector<int>& v, char c) {
        int x = c - 'a' + 1;
        while (x < 26) {
            if (v[x] > 0)
                return x;
            x++;
        }
        return -1;
    }
};
