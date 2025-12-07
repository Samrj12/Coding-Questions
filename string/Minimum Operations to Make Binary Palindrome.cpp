class Solution {
public:
    vector<int> palindromes;
    string toBinary(int x) {
        string s = "";
        while (x) {
            s += (x % 2) + '0';
            x /= 2;
        }
        return s;
    }
    bool isPalindrome(int x) {
        string bin = toBinary(x);
        string rev = bin;
        reverse(rev.begin(), rev.end());
        return bin == rev;
    }
    vector<int> minOperations(vector<int>& nums) {
        if(palindromes.empty())
        for(int i = 1;i<=5000;i++)
        if(isPalindrome(i))
        palindromes.push_back(i);

        vector<int> ans;
        for(int& i : nums){
            int closest = INT_MAX;
            auto it = upper_bound(palindromes.begin(), palindromes.end(), i);
            if(it != palindromes.end())
             closest = *it - i;
            if(it != palindromes.begin())closest = min(closest, i - *prev(it));
            ans.push_back(closest);
        }
        return ans;
    }
};
