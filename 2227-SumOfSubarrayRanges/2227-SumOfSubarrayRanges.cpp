// Last updated: 01/04/2026, 19:24:52
class Solution {
public:
    vector<int> pse(vector<int>& nums){
        stack<int> st;
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()] > nums[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> nse(vector<int>& nums){
        stack<int> st;
        vector<int> ans(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] >= nums[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = nums.size();
            }
            else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> pge(vector<int>& nums){
        stack<int> st;
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            while(!st.empty() && nums[st.top()] < nums[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = -1;
            }
            else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> nge(vector<int>& nums){
        stack<int> st;
        vector<int> ans(nums.size());
        for(int i=nums.size()-1;i>=0;i--){
            while(!st.empty() && nums[st.top()] <= nums[i]){
                st.pop();
            }
            if(st.empty()){
                ans[i] = nums.size();
            }
            else{
                ans[i] = st.top();
            }
            st.push(i);
        }
        return ans;
    }
    long long misum(vector<int>& nums){
        vector<int> left = pse(nums);
        vector<int> right = nse(nums);
        long long cont = 0;
        for(int i=0;i<nums.size();i++){
            cont += 1LL*nums[i]*(i-left[i])*(right[i]-i);
        }
        return cont;
    }
    long long masum(vector<int>& nums){
        vector<int> left = pge(nums);
        vector<int> right = nge(nums);
        long long cont = 0;
        for(int i=0;i<nums.size();i++){
            cont += 1LL*nums[i]*(i-left[i])*(right[i]-i);
        }
        return cont;
    }
    long long subArrayRanges(vector<int>& nums) {
        return masum(nums)-misum(nums);
    }
};