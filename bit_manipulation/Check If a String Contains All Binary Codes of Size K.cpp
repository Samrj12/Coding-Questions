class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.size() < k)return false;
        int tot = (1 << k);
        int mask = tot - 1;
        vector<bool> found(tot);
        int n = s.size();
        int curr = 0;
        for(int i=0;i<k;i++){
            curr <<= 1;
            curr |= s[i] - '0';
        }
        curr &= mask;
        found[curr] = true;
        tot--;
        for(int i=0;i<n;i++){
            curr <<= 1;
            curr |= s[i] - '0';
            curr &= mask;
            
            if(!found[curr])
            tot--;
            found[curr] = true;
        }
        return tot == 0;
    }
};
