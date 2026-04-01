// Last updated: 01/04/2026, 19:23:49
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        unordered_set<int> st;
        for(int i =0;i < n;i++){
            if(nums[i] != target[i]){
                if(st.find(nums[i]) == st.end()) st.insert(nums[i]); 
            }
        }
        return st.size();
    }
};