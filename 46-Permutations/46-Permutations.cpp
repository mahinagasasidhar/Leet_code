// Last updated: 01/04/2026, 19:28:47
class Solution {
public:
    void permu(vector<vector<int>>& fans,vector<int>& nums,int index){
        if(index == nums.size()){
            fans.push_back(nums);
            return;
        }
        for(int i = index;i<nums.size();i++){
            swap(nums[i],nums[index]);
            permu(fans,nums,index+1);
            swap(nums[i],nums[index]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> fans;
    vector<int> ans;
    permu(fans,nums,0);
    return fans;
    }
};