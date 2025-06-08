class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>res;
        for(int i=1;i<=9;i++){
            dfs(i, n,res);
        }
        return res;
    }
    void dfs(int start, int limit, vector<int>& res){
        if(start > limit)return;

        res.push_back(start);
        for(int i=0;i<=9;i++){
            int curr = start * 10 + i;
            if(curr <= limit)
            dfs(curr, limit,res);
            else
            break;
        }
    }
};
