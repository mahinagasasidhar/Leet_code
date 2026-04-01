// Last updated: 01/04/2026, 19:26:35
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums2.size();
        stack<int> st;
        unordered_map<int,int> mp;

        for(int i=m-1;i>=0;i--){
            if(st.empty()){
                mp[nums2[i]] = -1;
                st.push(nums2[i]);
            }
            else if(!st.empty() && st.top() > nums2[i]){
                mp[nums2[i]] = st.top();
                st.push(nums2[i]);
            }
            else{
                while(!st.empty() && st.top() < nums2[i]){
                    st.pop();
                }
                if(!st.empty()) mp[nums2[i]] = st.top();
                else mp[nums2[i]] = -1;
                st.push(nums2[i]);
            }
        }
        vector<int> ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(mp[nums1[i]]);
        }
        return ans;
    }
};