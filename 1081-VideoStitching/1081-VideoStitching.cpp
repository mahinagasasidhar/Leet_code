// Last updated: 01/04/2026, 19:25:42
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(),clips.end());
        int n = clips.size();
        int st = 0;
        int end = 0;
        int i = 0;
        int cnt = 0;
        while(st < time){
            while(i < n && clips[i][0] <= st){
                end = max(end,clips[i][1]);
                i++;
            }
            if(st == end) return -1;
            st = end;
            cnt++;
        }
        return cnt;
    }
};