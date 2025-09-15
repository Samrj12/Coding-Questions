class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int count = 0;
        int i=0, n = text.size();
        while (i < n) {
            bool canType = true;
            while (i < n && text[i] != ' ') {
                if (brokenLetters.find(text[i]) != string::npos) {
                    canType = false;
                }
                i++;
            }
            if (canType) count++;
            i++;
        }
        return count;
    }
};
