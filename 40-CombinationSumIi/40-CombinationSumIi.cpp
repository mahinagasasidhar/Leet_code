// Last updated: 01/04/2026, 19:28:52
class Solution {
public:
    void findcombo(vector<vector<int>>& fans,vector<int>& ans,vector<int>& candidates,int target,int index){
        if(target == 0){
            fans.push_back(ans);
            return;
        }
    for(int i = index;i<candidates.size();i++){
        if(i>index && candidates[i]==candidates[i-1]) continue;
        if(candidates[i]>target) break;
        ans.push_back(candidates[i]);
        findcombo(fans,ans,candidates,target-candidates[i],i+1);
        ans.pop_back();
    }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> fans;
        vector<int> ans;
        findcombo(fans,ans,candidates,target,0);
        return fans;
    }
};