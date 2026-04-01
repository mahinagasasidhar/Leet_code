// Last updated: 01/04/2026, 19:25:14
class Solution {
public:
    int rec(int i,string s,unordered_set<string>& st){
        if(i == s.size()) return 0;
        int ans = 0;
        for(int j=i;j<s.size();j++){
            string sub = s.substr(i,j-i+1);
            if(st.find(sub) == st.end()){
                st.insert(sub);
                ans = max(ans,1+rec(j+1,s,st));
                st.erase(sub);
            } 
        }
        return ans;
    }
    int maxUniqueSplit(string s) {
        unordered_set<string> st;
        return rec(0,s,st);
    }
};