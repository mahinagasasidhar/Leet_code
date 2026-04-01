// Last updated: 01/04/2026, 19:25:57
class Solution {
private:
    const int MOD = 7+(int)1e9;
public:
    vector<int> pse(vector<int> nums){
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
    vector<int> nse(vector<int> nums){
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
        int sumSubarrayMins(vector<int>& arr) {
        vector<int> nsee = nse(arr);
        vector<int> psee = pse(arr);
        int cont = 0;
        for(int i=0;i<arr.size();i++){
            cont = (cont + arr[i]*1L*(nsee[i]-i)*(i-psee[i]))%MOD;
        }
        return cont;
    }
};