// Last updated: 01/04/2026, 19:26:53
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        string st;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.back() > num[i] && k>0){
                k--;
                st.pop_back();
            }
            if(st.empty() && num[i] == '0') continue;
            st.push_back(num[i]);
            
        }
        while(!st.empty() && k>0){
            st.pop_back();
            k--;
        }
        return (st.empty() ? "0" : st);      
    }
};