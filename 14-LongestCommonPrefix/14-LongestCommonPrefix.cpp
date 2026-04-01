// Last updated: 01/04/2026, 19:29:11
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      
        int mini = strs[0].size();
        for(auto ch : strs){
            mini = min(mini,(int)ch.size());
        }

        for(int i = 0;i<mini;i++){

            for(int k = 0;k<strs.size()-1;k++){
                if(strs[k][i] != strs[k+1][i]){
                    return strs[0].substr(0,i);
                }
            }
        }
        return strs[0].substr(0,mini);
    }
};