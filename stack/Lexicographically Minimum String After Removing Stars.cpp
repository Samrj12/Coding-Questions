class Solution {
public:
    string clearStars(string s) {
        vector<stack<int>> stk(26);

        for(int i=0;i<s.size();i++){
            if(s[i] != '*')
            stk[s[i] - 'a'].push(i);
            else{
                for(int j=0;j<26;j++)
                {
                    if(!stk[j].empty()){
                        s[stk[j].top()] = '*';
                        stk[j].pop();
                        break;
                    }
                }
            }
        }
        string res = "";
        for(int i=0;i<s.size();i++){
            if(s[i] != '*')
            res += s[i];
        }
        return res;
    }
};
