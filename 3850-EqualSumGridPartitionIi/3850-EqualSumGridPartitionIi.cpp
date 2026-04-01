// Last updated: 01/04/2026, 19:24:25
class Solution {
public:
    typedef long long ll;

    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        int m = mat.size(); 
        int n = mat[0].size();
        vector<vector<int>> res(n, vector<int>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res[j][i] = mat[i][j];
            }
        }
        return res;
    }

    bool check(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<int> rightside(100001, 0), leftside(100001, 0);
        ll rtotal = 0, ltotal = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                rightside[grid[i][j]]++;
                rtotal += grid[i][j];
            }
        }

        for(int i = 0; i < n - 1; i++){
            for(int j = 0; j < m; j++){
                ltotal += grid[i][j];
                rtotal -= grid[i][j];
                leftside[grid[i][j]]++;
                rightside[grid[i][j]]--;
            }

            if(ltotal == rtotal) return true;

            if(ltotal > rtotal){
                ll diff = ltotal - rtotal;
                int h = i + 1, w = m;

                if(diff > 0 && diff <= 100000 && leftside[diff] > 0){
                    if(h > 1 && w > 1){
                        return true;
                    }
                    else if(h > 1 && w == 1){
                        if(grid[0][0] == diff || grid[i][0] == diff) return true;
                    }
                    else if(h == 1 && w > 1){
                        if(grid[0][0] == diff || grid[0][w-1] == diff) return true;
                    }
                }
            }
            else{
                ll diff = rtotal - ltotal;
                int h = n - i - 1, w = m;

                if(diff > 0 && diff <= 100000 && rightside[diff] > 0){
                    if(h > 1 && w > 1){
                        return true;
                    }
                    else if(h > 1 && w == 1){
                        if(grid[i+1][0] == diff || grid[n-1][0] == diff) return true;
                    }
                    else if(h == 1 && w > 1){
                        if(grid[n-1][0] == diff || grid[n-1][w-1] == diff) return true;
                    }
                }
            }
        }

        return false;
    }

    bool canPartitionGrid(vector<vector<int>>& grid) {
        if(check(grid)) return true;

        vector<vector<int>> t = transpose(grid);
        if(check(t)) return true;

        return false;
    }
};