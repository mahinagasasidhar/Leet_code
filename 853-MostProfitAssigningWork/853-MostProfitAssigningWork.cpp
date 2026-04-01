// Last updated: 01/04/2026, 19:26:11
class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        int n = difficulty.size();
        int m = worker.size();
        vector<vector<int>> ans;
        ans.reserve(n);
        for(int i = 0; i < n; i++){
            ans.push_back({difficulty[i],profit[i]});
        }
        sort(ans.begin(),ans.end());
        vector<int> preMap(n);
        preMap[0] = ans[0][1];
        for(int i = 1; i < n; i++){
            preMap[i] = max(preMap[i - 1],ans[i][1]);
        }
        int sum = 0;
        for(int i = 0; i < m; i++){
            int idx = upper_bound(ans.begin(),ans.end(),vector<int> {worker[i],INT_MAX}) - ans.begin() - 1;
            if(idx >= 0) sum += preMap[idx];
        }
        return sum;
    }
};