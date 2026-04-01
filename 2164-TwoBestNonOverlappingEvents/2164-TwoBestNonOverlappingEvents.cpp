// Last updated: 01/04/2026, 19:24:57
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int n = events.size();
        sort(events.begin(),events.end());
        vector<int> preMax(n);
        preMax[n - 1] = events[n - 1][2];
        for(int i = n - 2; i >= 0; i--){
            preMax[i] = max(preMax[i + 1],events[i][2]); 
        }
        int maxsum = 0;
        int idx = 0;
        for(int i = 0;i < n; i++){
            idx =  upper_bound(events.begin(),events.end(),vector<int>{events[i][1],INT_MAX,INT_MAX}) - events.begin();
           if(idx < n) maxsum = max(maxsum,events[i][2] + preMax[idx]);
           else if(idx == n) maxsum = max(maxsum,events[i][2]);
        }
        return maxsum;
    }
};