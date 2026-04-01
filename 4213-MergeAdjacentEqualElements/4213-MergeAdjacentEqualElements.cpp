// Last updated: 01/04/2026, 19:23:40
class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        reverse(nums.begin(),nums.end());
        int n = nums.size();
        stack<long long> st;
        st.push(nums.back());
        nums.pop_back();
        for(int i = n - 2;i >= 0;i--){
            if(nums[i] == st.top()){
                long long temp = st.top();
                st.pop();
                st.push(2*temp);
                while(!st.empty() && st.size() != 1){
                    long long temp = st.top();
                    st.pop();
                    if(st.top() == temp){
                        st.pop();
                        st.push(2*temp);
                    }
                    else{
                        st.push(temp);
                        break;
                    }
                }
            }
            else st.push(nums[i]);
            nums.pop_back();
        }
        vector<long long> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};