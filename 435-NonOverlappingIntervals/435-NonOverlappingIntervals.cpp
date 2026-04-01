// Last updated: 01/04/2026, 19:26:44
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){
            if(a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        }); 
        int endtime  = INT_MIN;
        int cnt = 0;
        for(int i = 0;i < n; i++){
            if(intervals[i][0] >= endtime) {cnt++;endtime = intervals[i][1];}
        }
        return n - cnt;
    }
};