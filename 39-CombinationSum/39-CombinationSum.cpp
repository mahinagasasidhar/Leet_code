// Last updated: 01/04/2026, 19:28:53
class Solution {
public:
        void findcom(vector<vector<int>>& fans,vector<int>& ans,vector<int>& candidates,int target,int index){
        if(index == candidates.size()){
            if(target == 0){
                fans.push_back(ans);
            }
            return;
        }
        if(candidates[index]<=target){
            ans.push_back(candidates[index]);
            findcom(fans,ans,candidates,target-candidates[index],index);
            ans.pop_back();
        }
        findcom(fans,ans,candidates,target,index+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> fans;
        vector<int> ans;
        findcom(fans,ans,candidates,target,0);
        return fans;
    }
};