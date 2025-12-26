class Solution {
public:
    int bestClosingTime(string customers) {
        int remY = 0, currN = 0;
        int mnPn = INT_MAX, mnPnIdx = -1;
        for(auto c : customers)
        if(c == 'Y')remY++;
        int n = customers.size();
        for(int i=0;i<n;i++){
            int pn = currN + remY;
            if(pn < mnPn){
                mnPn = pn;
                mnPnIdx = i;
            }
            if(customers[i] == 'Y')
            remY--;
            else
            currN++;
        }
        if(currN + remY < mnPn){
            mnPnIdx = n;
        }
        return mnPnIdx;
    }
};
