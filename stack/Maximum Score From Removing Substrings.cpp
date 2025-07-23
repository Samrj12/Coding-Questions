class Solution {
public:
    int maximumGain(string s, int x, int y) {
        string high = x > y ? "ab" : "ba";
        string low = x > y ? "ba" : "ab";

        string firstPart = removeSubstrings(s, high);
        int cntFirstPassRemoval = (s.size() - firstPart.size())/2;
        string secondPart = removeSubstrings(firstPart, low);
        int cntSecondPassRemoval = (firstPart.size() - secondPart.size())/2;
        return x > y ? cntFirstPassRemoval * x + cntSecondPassRemoval * y : cntFirstPassRemoval * y + cntSecondPassRemoval * x;
    }
    string removeSubstrings(string& s, string& chk){
        stack<char> stk;
        for(char& c : s){
            if(c == chk[1] && !stk.empty() && stk.top() == chk[0])
            stk.pop();
            else
            stk.push(c);
        }
        string res = "";
        while(!stk.empty()){
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
