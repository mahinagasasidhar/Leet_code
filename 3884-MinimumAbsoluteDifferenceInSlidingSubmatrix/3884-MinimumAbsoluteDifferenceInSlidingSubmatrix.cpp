// Last updated: 01/04/2026, 19:24:23
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int n= grid.size();
        int m = grid[0].size();
        vector<vector<int>> ans(n-k+1,vector<int>(m-k+1,0));
        if(k==1) return ans;
        for(int r = 0 ;r < n-k+1;r++){
            for(int c = 0;c < m-k+1;c++){
                set<int> st;
                for(int i = r;i < r+k;i++){
                    for(int j=c;j<c+k;j++){
                        st.insert(grid[i][j]);
                    }
                }
                int y = INT_MAX;
                for(auto it = st.begin();next(it) != st.end();it++) y = min(y,abs(*it-*next(it)));
                ans[r][c] = (y == INT_MAX) ? 0 : y;
            }
        }
        return ans;
    }
};