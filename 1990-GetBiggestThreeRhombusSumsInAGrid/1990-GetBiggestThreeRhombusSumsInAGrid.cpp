// Last updated: 01/04/2026, 19:25:04
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        set<int>st;
        for(int i = 0;i < m;i++){
            for(int j = 0;j < n;j++){
                //single
                st.insert(grid[i][j]);
                //for k sizes
                for(int k = 1; ;k++){
                    int sum = 0;
                    if(i+2*k > m-1 || j + k > n-1 || j-k <0) break;
                    for(int t = 1;t <= k;t++)sum += grid[i+t][j+t];
                    for(int t = 1;t <= k;t++)sum += grid[i+k+t][j+k-t];
                    for(int t = 1;t <= k;t++)sum += grid[i+2*k-t][j-t];
                    for(int t = 1;t <= k;t++)  sum += grid[i+k-t][j-k+t];
                    st.insert(sum);
                }
            }
        }
        vector<int> ans;
        for(auto it = st.rbegin();it != st.rend() && ans.size() < 3;it++) ans.push_back(*it);
        return ans;
    }
};