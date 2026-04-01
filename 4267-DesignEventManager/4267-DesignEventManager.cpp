// Last updated: 01/04/2026, 19:23:22
class EventManager {
public:
    set<pair<int,int>> st;
    unordered_map<int,int> mp;
    EventManager(vector<vector<int>>& events) {
        for(auto& it : events){
            mp[it[0]] = it[1];
            st.insert({-it[1],it[0]});
        }
    }
    void updatePriority(int eventId, int newPriority) {
        int old = mp[eventId];
        st.erase({-old,eventId});
        mp[eventId] = newPriority;
        st.insert({-newPriority,eventId});
    }
    
    int pollHighest() {
        if(st.empty()) return -1;
        auto it = st.begin();
        int eventId = it -> second;
        st.erase(it);
        mp.erase(eventId);
        return eventId;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */