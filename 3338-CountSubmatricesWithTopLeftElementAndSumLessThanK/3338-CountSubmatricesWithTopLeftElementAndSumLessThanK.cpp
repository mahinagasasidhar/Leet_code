// Last updated: 01/04/2026, 19:24:34
class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                grid[j][i] += grid[j - 1][i];
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 1; j < m; ++j) {
                grid[i][j] += grid[i][j - 1];
            }
        }

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] <= k) {
                    count++;
                }
            }
        }

        return count;
    }
};
