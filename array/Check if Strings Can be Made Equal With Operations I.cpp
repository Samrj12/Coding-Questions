class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        vector<int> mp1(26, 0), mp2(26, 0);
        for(int i=0;i<4; i+=2){
            mp1[s1[i] - 'a']++;
            mp1[s2[i] - 'a']--;
        }
        for(int i=0;i<26;i++){
            if(mp1[i] != 0)return false;
        }
        for(int i=1;i<4; i+=2){
            mp2[s1[i] - 'a']++;
            mp2[s2[i] - 'a']--;
        }
        for(int i=0;i<26;i++){
            if(mp2[i] != 0)return false;
        }
        return true;
    }
};
