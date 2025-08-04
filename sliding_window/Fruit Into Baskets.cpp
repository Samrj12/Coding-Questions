class Solution {
public:
    int totalFruit(vector<int>& a) {
        int maxLen = 0;
        int l = 0, r= 0;
        int n = a.size();
        unordered_map<int, int> mp;
        while(r < n){
            mp[a[r]]++;
            while(mp.size() > 2){
                mp[a[l]]--;
                if (mp[a[l]] == 0) {
                    mp.erase(a[l]);
                }
                l++;
            }
            maxLen = max(r - l + 1, maxLen);
            r++;
        }
        return maxLen;
    }
};
