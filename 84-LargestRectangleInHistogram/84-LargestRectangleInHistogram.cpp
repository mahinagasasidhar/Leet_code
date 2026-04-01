// Last updated: 01/04/2026, 19:28:22
class Solution {
public:
    vector<int> pse(vector<int>& heights){
        int n = heights.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            else{
                ans[i] = -1;
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> nse(vector<int>& heights){
        int n = heights.size();
        stack<int> st;
        vector<int> ans(n);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if(!st.empty()){
                ans[i] = st.top();
            }
            else{
                ans[i] = n;
            }
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> psee = pse(heights);
        vector<int> nsee = nse(heights);
        int rect = 0;
        int maxrect = 0;
        for(int i=0;i<n;i++){   
            rect = heights[i]*((nsee[i] - i - 1)+(i - psee[i]));
            maxrect = max(rect,maxrect);
        } 
        return maxrect;   
    }
};