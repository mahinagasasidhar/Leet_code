// Last updated: 01/04/2026, 19:26:34
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        vector<int> ans(n,-1);
        for(int i=(2*n)-1;i>=0;i--){
            int ind = i%n;
                while(!st.empty() && st.top() <= nums[ind]){
                    st.pop();
                }
                if(i<n && !st.empty()) ans[i] = st.top();
                st.push(nums[ind]);
        }
        return ans;
    }
};