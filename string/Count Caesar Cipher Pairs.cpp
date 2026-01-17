class Solution {
public:
    long long countPairs(vector<string>& words) {

        unordered_map<string, int> mp;
        long long res = 0;
        for(string& s : words){
            int n = s.size();
            string tmp = "";
            
            int shift = s[0] - 'a';
            for(int i=1;i<n;i++){
                tmp += 'a' + (s[i] - 'a' - shift + 26) % 26;
            }
            if(mp.count(tmp))
            res += mp[tmp];
            mp[tmp]++;
        }
        return res;
    }
};
