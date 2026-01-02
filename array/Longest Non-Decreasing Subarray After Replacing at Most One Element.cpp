class Solution {
public:
    int longestSubarray(vector<int>& A) {
        int n = A.size();
        int mx = 1;
        int prev = 0, len = 0, j = 0;
        for(int i=1;i<=n;i++){
            if(i == n || A[i - 1] > A[i]){
                int len = i - j;
                mx = max(mx, len + 1);
                if(j > 1 && A[j - 2] <= A[j]){
                    mx = max(mx, prev + len );
                }
                if(j > 0 && j + 1 < n && A[j - 1] <= A[j + 1])
                mx = max(mx, prev + len);
                j = i;
                prev = len;
            }
        }
        return min(mx, n);
    }
};
