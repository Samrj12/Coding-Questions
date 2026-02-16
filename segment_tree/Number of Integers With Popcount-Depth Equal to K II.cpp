class Solution {
public:
    struct SegmentTree {
        vector<int> st;
        int n;
        SegmentTree(int n) : n(n), st(4 * n, 0) {}
        void build(int p, int l, int r, vector<int>& arr) {
            if (l == r) {
                st[p] = arr[l];
                return;
            }
            int m = (l + r) >> 1;
            build(p << 1, l, m, arr);
            build(p << 1 | 1, m + 1, r, arr);
            st[p] = st[p << 1] + st[p << 1 | 1];
        }
        void update(int p, int l, int r, int idx, int val) {
            if (l == r) {
                st[p] = val;
                return;
            }
            int m = (l + r) >> 1;
            if (idx <= m)
                update(p << 1, l, m, idx, val);
            else
                update(p << 1 | 1, m + 1, r, idx, val);
            st[p] = st[p << 1] + st[p << 1 | 1];
        }
        int query(int p, int l, int r, int i, int j) {
            if (r < i || j < l)
                return 0;
            if (i <= l && r <= j)
                return st[p];
            int m = (l + r) >> 1;
            return query(p << 1, l, m, i, j) +
                   query(p << 1 | 1, m + 1, r, i, j);
        }
    };
    vector<int> popcountDepth(vector<long long>& nums,
                              vector<vector<long long>>& queries) {
        int n = nums.size();
        vector<SegmentTree> st(6, SegmentTree(n));
        vector<vector<int>> depthNums(6, vector<int>(n));
        for (int i = 0; i < n; i++) {
            int depth = findDepthNum(nums[i]);
            depthNums[depth][i] = 1;
        }
        for (int d = 0; d < 6; d++) {
            st[d].build(1, 0, n - 1, depthNums[d]);
        }
        vector<int> res;
        for (auto& query : queries) {
            if (query[0] == 1) {
                int l = query[1], r = query[2], k = query[3];
                res.push_back(st[k].query(1, 0, n - 1, l, r));
            } else {
                int idx = query[1]; long long val = query[2];
                int oldDepth = findDepthNum(nums[idx]);
                st[oldDepth].update(1, 0, n - 1, idx, 0);
                nums[idx] = val;
                int newDepth = findDepthNum(val);
                st[newDepth].update(1, 0, n - 1, idx, 1);
            }
        }
        return res;
    }
    int findDepthNum(long long n) {
        int depth = 0;
        while (n > 1) {
            n = __builtin_popcountll(n);
            depth++;
        }
        return depth;
    }
};
