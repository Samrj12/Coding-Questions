class EventManager {
public:
    struct CustomCompare {
        bool operator()(const pair<int, int>& a, const pair<int, int>& b) {
            if (a.first != b.first) {
                return a.first < b.first;
            }
            return a.second > b.second;
        }
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, CustomCompare> pq;
    unordered_map<int, int> idToPrio; 
    EventManager(vector<vector<int>>& events) {
        for(auto e: events)
        pq.push({e[1], e[0]}), idToPrio[e[0]] = e[1];
    }

    void updatePriority(int eventId, int p) {
        if(idToPrio.count(eventId) > 0){
            pq.push({p, eventId});
            idToPrio[eventId] = p;
        }
    }

    int pollHighest() {
        while(!pq.empty()){
            auto p = pq.top();
            pq.pop();
            if(p.first == idToPrio[p.second]){
                idToPrio.erase(p.second);
                return p.second;
            }
        }
        return -1;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */
