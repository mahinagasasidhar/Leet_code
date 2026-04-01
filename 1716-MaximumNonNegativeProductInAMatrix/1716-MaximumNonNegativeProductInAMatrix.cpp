// Last updated: 01/04/2026, 19:25:13
class Solution {
public:
    int MOD = 1e9 + 7;
    int maxProductPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<long long> mx(m);
        vector<long long> mn(m);
        mx[0] = mn[0] = grid[0][0]; 
        for(int i=1;i<m;i++){
            mx[i] = grid[0][i]*mx[i-1];
            mn[i] = grid[0][i]*mn[i-1];
        }
        for(int i=1;i<n;i++){
            for(int j = 0;j<m;j++){
                if(j == 0){ 
                    mx[0] = grid[i][0]*mx[0];
                    mn[0] = grid[i][0]*mn[0];
                }else{
                    long long val = grid[i][j];
                    long long maxi = max({mn[j]*val,mx[j]*val,mx[j-1]*val,mn[j-1]*val});
                    long long mini = min({mn[j]*val,mx[j]*val,mx[j-1]*val,mn[j-1]*val});
                    mx[j] = maxi;
                    mn[j] = mini;
                }
            }
        }
        if(mx[m-1] < 0 ) return -1;
        return mx[m-1]%(MOD);
    }
};