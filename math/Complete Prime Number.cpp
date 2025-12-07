class Solution {
public:

    bool completePrime(int num) {
        int a = num, b = 0, pow = 1;
        while(a){
            b += (a % 10)*pow;
            if(a == 1 || !isPrimeChk(a))return false;
            if(b == 1 || !isPrimeChk(b))return false;
            a /= 10;
            pow *= 10;
        }
        return true;
    }

    bool isPrimeChk(int n){
        for(int i=2; i<= sqrt(n);i++){
            if(n % i == 0)return false;
        }
        return true;
    }
};
