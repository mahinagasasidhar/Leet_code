// Last updated: 01/04/2026, 19:28:46
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    for(int i=0;i<n;i++){
        for(int j=i;j<m;j++){
        swap(matrix[i][j],matrix[j][i]);
    }
    }
    for(int i=0;i<(n/2);i++){
        for(int j=0;j<m;j++){
          swap(matrix[j][i],matrix[j][n-i-1]);
        }
    }
    }
};