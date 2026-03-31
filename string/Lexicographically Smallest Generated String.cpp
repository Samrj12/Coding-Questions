class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        string a = string(n + m - 1, '0');
        vector<bool> locked(n + m - 1);
        for(int i=0;i<n;i++){
            if(str1[i] == 'T'){
                for(int j = 0;j<m;j++){
                    if(a[i + j] != '0' && a[i + j] != str2[j]){
                        return "";
                    }
                    a[i + j] = str2[j];
                    locked[i + j] = true;
                }
            }
        }
        for(int i=0;i<n + m - 1;i++){
            if(a[i] == '0')a[i] = 'a';
        }
        for(int i=0;i<n;i++){
            if(str1[i] == 'F'){
                string wrd = a.substr(i, m);
                if(wrd == str2){
                    bool fixed = false;
                    for(int j = m - 1; j>=0;j--){
                        if(!locked[i + j]){
                            a[i + j] = 'b';
                            fixed = true;
                            break;
                        }
                    }
                    if(!fixed)return "";
                }
            }
        }
        return a;
    }
};
