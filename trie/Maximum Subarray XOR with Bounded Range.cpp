class Solution {
public:
    int maxXor(vector<int>& nums, int k) {
         struct Trie
        {
            int B = 14;
            struct Node
            {
                vector<Node*> ch;
                int cnt;
                Node()
                {
                    ch.resize(2);
                    cnt = 0;
                }
            };
            Node* root;
            Trie() { root = new Node(); }
            void add(int x, int delta)
            {
                Node* curr = root;
                curr->cnt += delta;
                for (int b = B; b >= 0; --b)
                {
                    int bit = (x >> b) & 1;
                    if (!curr->ch[bit])
                    {
                       curr->ch[bit] = new Node();
                    }
                    curr =  curr->ch[bit];
                    curr->cnt += delta;
                }
            }
            void insert(int x) { add(x, +1); }
            void erase(int x) { add(x, -1); }
            int maxXor(int x)
            {
                int res = 0;
                
                Node* curr = root;
                for (int b = B; b >= 0; --b)
                {
                    int bit = (x >> b) & 1;
                    int want = bit ^ 1;
                    Node* next = curr->ch[want];
                    if (next && next->cnt > 0)
                    {
                        res |= (1 << b);
                        curr = next;
                    }
                    else
                    {
                        curr =  curr->ch[bit];
                    }
                }
                return res;
            }
        };

        int n = nums.size();
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] ^ nums[i];

        deque<int> mx, mn;
        Trie tr;
        int L = 0, ans = 0;
        tr.insert(pref[0]);

        for (int r = 0; r < n; r++)
        {
            while (!mx.empty() && nums[mx.back()] <= nums[r])
                mx.pop_back();
            mx.push_back(r);
            while (!mn.empty() && nums[mn.back()] >= nums[r])
                mn.pop_back();
            mn.push_back(r);

            while (nums[mx.front()] - nums[mn.front()] > k)
            {
                if (mx.front() == L)
                    mx.pop_front();
                if (mn.front() == L)
                    mn.pop_front();
                tr.erase(pref[L]);
                L++;
            }

            ans = max(ans, tr.maxXor(pref[r + 1]));
            tr.insert(pref[r + 1]);
        }
        return ans;
    }
};©leetcode
