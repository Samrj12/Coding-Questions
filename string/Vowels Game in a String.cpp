class Solution {
public:
    bool doesAliceWin(string s) {
        bool hasVowel = false;
        for(char c : s){
            if(c =='a' || c =='i' ||c =='e' ||c =='o' ||c =='u')
            return true;
        }
        return false;
    }
};
