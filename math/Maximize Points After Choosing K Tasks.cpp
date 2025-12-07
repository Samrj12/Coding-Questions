class Solution {
public:
    long long maxPoints(vector<int>& t1, vector<int>& t2, int k) {
        vector<vector<int>> arr;
        for(int i=0;i<t1.size();i++){
            arr.push_back({t1[i] - t2[i], t1[i], t2[i]});
        }
        sort(arr.begin(), arr.end(), [&](const auto& a, const auto& b){
            return a > b;
        });
        long long res = 0;
        for(int i=0;i<k;i++){
            res += arr[i][1];
        }
        for(int i=k;i<arr.size();i++){
            res += max(arr[i][1], arr[i][2]);
        }
        return res;
    }
};
