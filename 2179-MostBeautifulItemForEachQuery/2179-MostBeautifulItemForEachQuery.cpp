// Last updated: 01/04/2026, 19:24:56
class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        int n = items.size();
        int m = queries.size();
        vector<int> preMap(n);
        vector<int> ans1(m,0);
        preMap[0] = items[0][1];
        for(int i = 1;i < n; i++){
            preMap[i] = max(preMap[i - 1],items[i][1]);
        }
        vector<int> ans(m);
        for(int i = 0;i < m; i++){
            int idx = upper_bound(items.begin(),items.end(),vector<int>{queries[i],INT_MAX}) - items.begin() - 1;
            if(idx != -1) ans1[i] = preMap[idx];
        }
        return ans1;
    }
};