// Last updated: 01/04/2026, 19:24:26
class Solution {
public:
    long long column(int c,vector<vector<int>>& grid){
        long long sum = 0;
        for(int i=0;i<grid.size();i++) sum += grid[i][c];
        return sum;
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
      int n = grid.size();
      int m = grid[0].size();
      long long total = 0;
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            total += grid[i][j];
        }
      }
      long long rsum = 0;
      for(int i=0;i<n;i++){
        rsum += accumulate(grid[i].begin(),grid[i].end(),0LL);
        if(2*rsum == total) return true;
      }
      rsum = 0;
      for(int i=0;i<m;i++){
        rsum += column(i,grid);
        if(2*rsum == total) return true;
      }
      return false;
    }
};