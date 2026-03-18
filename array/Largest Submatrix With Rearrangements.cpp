class Solution {
public:
    // int largestRect(vector<int>& heights) {
    //     int n = heights.size();
    //     stack<int> stk;
    //     int mx = 0;
    //     for (int i = 0; i <= heights.size(); i++) {
    //         while (stk.size() > 0 &&
    //                (i == n || heights[stk.top()] > heights[i])) {
    //             int idx = stk.top();
    //             stk.pop();
    //             int width = stk.empty() ? i : i - stk.top() - 1;
    //             mx = max(mx, heights[idx] * width);
    //         }
    //         stk.push(i);
    //     }
    //     return mx;
    // }
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> h(n);

        int mx = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j]) {
                    h[j]++;
                } else
                    h[j] = 0;
            }
            auto tmp = h;
            sort(tmp.begin(), tmp.end(), greater<int>());
            for(int i=0;i<n;i++){
                mx = max(mx, (i + 1) * tmp[i]);
            }
        }
        return mx;
    }
};
