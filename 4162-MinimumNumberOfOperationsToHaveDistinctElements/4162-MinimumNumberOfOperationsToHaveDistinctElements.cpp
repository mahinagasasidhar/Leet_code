// Last updated: 01/04/2026, 19:24:02
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        double index = -1;
       unordered_set<int> st;
        for(int i=n-1;i>=0;i--){
            if(st.find(nums[i]) != st.end()){
                index = i;
                break;
            }
            st.insert(nums[i]);
        }
        int ans = ceil((index+1)/3);
        return ans;
    }
};