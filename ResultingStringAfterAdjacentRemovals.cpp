class Solution {
public:
    bool isCircularPair(char a, char b) {
        int diff = abs(a - b);
        return diff == 1 || diff == 25;
    }

    string resultingString(string s) {
        vector<char> stack;
        for (char ch : s) {
            if (!stack.empty() && isCircularPair(stack.back(), ch)) {
                stack.pop_back();  // remove the pair
            } else {
                stack.push_back(ch);
            }
        }

        return string(stack.begin(), stack.end());
    }
};
