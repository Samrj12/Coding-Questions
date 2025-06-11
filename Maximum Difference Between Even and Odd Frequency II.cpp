class Solution {
public:
    int maxDifference(string s, int k) {
        int ans = INT_MIN;
        for(char a = '0'; a<= '4';a++){
            for(char b = '0'; b  <= '4'; b++)
            {
                if(a == b)continue;
                vector<int> bestPrev(4, INT_MAX);
                int currA = 0, currB = 0, prevA = 0, prevB = 0;
                int r = 0, l  = -1;
                for(r = 0; r < s.size(); r++){
                    currA += (s[r] == a) ? 1 : 0;
                    currB += (s[r] == b) ? 1 : 0;

                    while(r-l >= k && currB - prevB >= 2){
                        int prevState = getCode(prevA, prevB);
                        bestPrev[prevState] = min(bestPrev[prevState], prevA - prevB);
                        
                        l++;
                        prevA += (s[l] == a) ? 1 : 0;
                        prevB += (s[l] == b) ? 1 : 0;
                    }
                int reqStatus = getCode(currA, currB) ^ (0b10);
                if(bestPrev[reqStatus] != INT_MAX)
                ans = max(ans, (currA - currB) - bestPrev[reqStatus]);
                }

            }
        }
        return ans;
    }
    int getCode(int cntA, int cntB){
        return ((cntA & 1) << 1) | (cntB & 1);
    }
};
