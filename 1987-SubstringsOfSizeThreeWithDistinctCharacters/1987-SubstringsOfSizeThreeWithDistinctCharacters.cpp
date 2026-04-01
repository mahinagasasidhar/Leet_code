// Last updated: 01/04/2026, 19:25:06
class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n-2;i++){
             unordered_map<char,int> mp;
            int j = i;
            int cnt = 0;
            while(true){
                if(mp.find(s[j]) == mp.end()){
                   
                    mp[s[j]]++;
                    cnt++;
                    j++;
                }
                else{
                    break;
                }
                if(cnt == 3){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};