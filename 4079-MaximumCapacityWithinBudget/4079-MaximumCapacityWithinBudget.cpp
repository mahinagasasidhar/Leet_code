// Last updated: 01/04/2026, 19:24:16
class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        vector<pair<int,int>> ans;

        for(int i = 0; i < n; i++){
            ans.emplace_back(costs[i], capacity[i]);
        }

        sort(ans.begin(), ans.end());

        vector<int> prefMax(n);
        prefMax[0] = ans[0].second;
        for(int i = 1; i < n; i++) {
            prefMax[i] = max(prefMax[i-1], ans[i].second);
        }

        int maxcap = 0;
        
        for(int i = 0; i < n; i++){
            if(ans[i].first < budget){
               maxcap = max(maxcap, ans[i].second); 
            }
        }

        int l = 0;
        for (int r = n - 1; r > 0; r--) {
            while (l < n && ans[l].first + ans[r].first < budget) {
                l++;
            }
            
            int validL = min(l - 1, r - 1);
            
            if (validL >= 0 && ans[validL].first + ans[r].first < budget) {
                maxcap = max(maxcap, prefMax[validL] + ans[r].second);
            }

            if (l > 0) l--; 
        }

        return maxcap;
    }
};