class Solution {
public:
    long long lastInteger(long long n) {
        long long s = 1, e = n, d = 1;
        int op = 0;
        while(s < e){
                long long tot = (e - s)/d + 1;
            if(!op){
                if(tot % 2 == 0){
                    e -= d;
                }
            }else{
                if(tot % 2 == 0){
                    s += d;
                }
            }
            d*= 2;
            op ^= 1;
        }
        return s;
    }
};
