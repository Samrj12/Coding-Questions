class Solution {
public:

    long long minimumCost(vector<int>& nums, int k, int d) {
        int n = nums.size();
        long long ans = nums[0];
        multiset<int> s, t;

        // Initialize the multisets and sum for the initial subarray
        for(int i=1 ; i<k;i++)
        {
            ans += nums[i];
            s.insert(nums[i]);
        }        
        for (int i = k; i <= d + 1; i++) {
            auto it = prev(s.end());
            int val = *it;
            if(nums[i] < val){
                ans -= val;
                ans += nums[i];
                s.erase(it);
                s.insert(nums[i]);
                t.insert(val);
            }else{
                t.insert(nums[i]);
            }
        }
        long long res = ans;
        for (int i = d+2; i < n; i++) {
            int front = i - d - 1;
            if(s.find(nums[front]) != s.end())
            {
                ans -= nums[front];
                s.erase(s.find(nums[front]));
                if(t.size() > 0 && *t.begin() < nums[i])
                {
                    int el = *t.begin();
                    ans += el;
                    s.insert(el);
                    t.erase(t.find(el));
                    t.insert(nums[i]);
                }else{
                    s.insert(nums[i]);
                    ans+=nums[i];
                }
            }else{
                t.erase(t.find(nums[front]));
                if(nums[i] < *s.rbegin())
                {
                    ans += nums[i];
                    ans -= *s.rbegin();
                    s.insert(nums[i]);
                    t.insert(*s.rbegin());
                    s.erase(prev(s.end()));
                }else{
                    t.insert(nums[i]);
                }
            }
            res = min(res, ans);
        }
        return res;
    }
};
