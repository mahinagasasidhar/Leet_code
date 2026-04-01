// Last updated: 01/04/2026, 19:24:13
class RideSharingSystem {
public:
        queue<int> p;
        queue<int> d;
        set<int> st;
    RideSharingSystem() {  }
    
    void addRider(int riderId) {
      p.push(riderId);
      st.insert(riderId);
    }
    
    void addDriver(int driverId) {
        d.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        if(p.empty() || d.empty()) return{-1,-1};
        vector<int> temp;
        temp.push_back(d.front());
        temp.push_back(p.front());
        d.pop();
        p.pop();
        return temp;
    }
    void cancelRider(int riderId) {
        if(st.find(riderId) != st.end()){
            queue<int> q;
            while(!p.empty()){
                if(p.front() != riderId) q.push(p.front());
                p.pop();
            }
            p = q;
            st.erase(riderId);
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */