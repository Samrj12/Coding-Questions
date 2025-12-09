class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int i=0,n = words.size();
        while(i < n){
            string s = "";
            int l = words[i].size();
            int j = i + 1;
            while(j < n && l + 1 + words[j].size() <= maxWidth){
                l += 1 + words[j].size();
                j++;
            }

                int noWords = j - i;
            if(j == n || noWords == 1){
                for(int k=i; k < j; k++){
                    s += words[k];
                    if(k < j - 1){
                    s += " ";}
                }
                while(s.size() < maxWidth){
                    s += " ";
                }
            }else{
                int chars = 0;
                for(int k = i; k < j;k++) chars += words[k].size();
                int spaces = maxWidth - chars;
                int spacesPerGap = spaces / (noWords - 1);
                int extra = spaces % (noWords - 1);
                
                for(int k = i; k < j;k++) {
                    s += words[k];
                    if(k != j - 1){
                        int space = spacesPerGap;
                        while(space-- > 0){
                            s += " ";
                        }
                        if(extra > 0){
                            s += " ";
                            extra--;
                        }
                    }
                }
            }
            res.push_back(s);
            i = j;
        }
        return res;
    }
};
