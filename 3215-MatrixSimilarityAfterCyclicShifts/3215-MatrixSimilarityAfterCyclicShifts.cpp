// Last updated: 01/04/2026, 19:24:35
class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        
        if (k % m == 0) return true;
        
        k %= m;
        
        vector<vector<int>> modified = mat;
        
        for (int i = 0; i < n; ++i) {
            if (i % 2 == 0) {
                for (int j = 0; j < m; ++j) {
                    modified[i][j] = mat[i][(j + k) % m];
                }
            } else {
                for (int j = 0; j < m; ++j) {
                    modified[i][j] = mat[i][(j - k % m + m) % m];
                }
            }
        }
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] != modified[i][j]) {
                    return false;
                }
            }
        }
        
        return true;
    }
};
