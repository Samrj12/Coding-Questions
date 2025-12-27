class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        sort(meetings.begin(), meetings.end());
        for(int i=0;i<n;i++)
        freeRooms.push(i);
        int mx = 0;
        int resIdx = -1;
        vector<int> cnt(n);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> busyRooms;
        for(auto m : meetings){
            int s = m[0], e = m[1];
            while(!busyRooms.empty() && busyRooms.top().first <= s){
                freeRooms.push(busyRooms.top().second);
                busyRooms.pop();
            }
            if(!freeRooms.empty()){
                int i = freeRooms.top();
                freeRooms.pop();
                busyRooms.push({e, i});
                cnt[i]++;
                if(mx < cnt[i] || (mx == cnt[i] && i < resIdx))
                {
                    mx = cnt[i];
                    resIdx = i;
                }
            }else{
                auto [t, i] = busyRooms.top();
                int duration = e - s;
                busyRooms.pop();
                cnt[i]++;
                busyRooms.push({t + duration, i});
                if(mx < cnt[i]|| (mx == cnt[i] && i < resIdx))
                {
                    mx = cnt[i];
                    resIdx = i;
                }
            }
        }
        return resIdx;
    }
};
