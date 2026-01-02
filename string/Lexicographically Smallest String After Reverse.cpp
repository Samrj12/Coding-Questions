class Solution {
public:
    string lexSmallest(string s)
{
    vector<string> all;
    int n = s.size();
    for(int k = 1; k<=n;k++){

        string s1 = s.substr(0, k), s2 = s.substr(n - k);
        string rs1 = s1, rs2 = s2;
        reverse(rs1.begin(), rs1.end());
        reverse(rs2.begin(), rs2.end());

        all.push_back(rs1 + s.substr(k));
        all.push_back(s.substr(0,n -k) + rs2);
    }
    sort(all.begin(), all.end());
    return all[0];
}
};
