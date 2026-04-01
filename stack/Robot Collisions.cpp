class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions,
                                      vector<int>& healths, string directions) {
        vector<int> idx;
        int n = positions.size();
        for (int i = 0; i < n; i++) {
            idx.push_back(i);
        }
        sort(idx.begin(), idx.end(),
             [&](int i, int j) { return positions[i] < positions[j]; });
        stack<int> st;
        for (int i : idx) {
            if (directions[i] == 'R') {
                st.push(i);
            } else {
                while (!st.empty() && healths[i] > 0) {
                    int topIdx = st.top();

                    if (healths[topIdx] < healths[i]) {
                        healths[topIdx] = 0;
                        healths[i] -= 1;
                        st.pop();
                    } else if (healths[topIdx] > healths[i]) {
                        healths[topIdx] -= 1;
                        healths[i] = 0;
                    } else {
                        healths[topIdx] = 0;
                        healths[i] = 0;
                        st.pop();
                    }
                }
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (healths[i] > 0) {
                ans.push_back(healths[i]);
            }
        }
        return ans;
    }
};
