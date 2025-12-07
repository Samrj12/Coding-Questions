class Solution {
public:
    int countOdds(int low, int high) {
        return numOdds(high) - numOdds(low - 1);
    }
    int numOdds(int n){
        if(n <= 0)return 0;
        return n/2 + (n % 2);
    }
};
