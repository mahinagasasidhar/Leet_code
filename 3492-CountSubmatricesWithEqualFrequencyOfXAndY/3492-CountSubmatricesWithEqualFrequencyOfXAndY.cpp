// Last updated: 01/04/2026, 19:24:30
class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<int> x(m,0);
        vector<int> y(m,0);
        int cnt = 0;
        for(int i=0;i < n;i++){
            int xs=0,ys=0;
            for(int j=0;j<m;j++){
                if(grid[i][j] == 'X') xs++;
                else if(grid[i][j] == 'Y') ys++;
                x[j] += xs;
                y[j] += ys;
                if(x[j] == y[j] && x[j] > 0) cnt++;
            }
        }
        return cnt;
    }
};