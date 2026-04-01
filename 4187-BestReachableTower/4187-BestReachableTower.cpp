// Last updated: 01/04/2026, 19:23:50
class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius){
        int n = towers.size();
        int d  = 0;
        int q = -1;
        vector<int> ans(2,-1);
        for(int i = 0;i < n;i++){
            d = abs(towers[i][0] - center[0]) + abs(towers[i][1] - center[1]);
            if(d <= radius){
                if(towers[i][2] > q){
                    ans[0] = towers[i][0];
                    ans[1] = towers[i][1];
                    q = towers[i][2];
                }
                else if(towers[i][2] == q && (towers[i][0] < ans[0] || (towers[i][0] == ans[0] && towers[i][1] < ans[1]))){
                    ans[0] = towers[i][0];
                    ans[1] = towers[i][1];
                    q = towers[i][2];
                }
            }
        }
        return ans;
    }
};