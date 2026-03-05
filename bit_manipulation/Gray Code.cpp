class Solution {
public:
    vector<int> grayCode(int n) {
        int sz = (1 << n);
        vector<int> res;
        for(int i=0;i <sz;i++){
            res.push_back(i ^ (i >> 1));
        }
        return res;
    }
};
