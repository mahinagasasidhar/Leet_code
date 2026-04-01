// Last updated: 01/04/2026, 19:25:09
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        if(n != m) return 0;
        vector<int> v1(26,0);
        vector<int> v2(26,0);
        for(int i=0;i<n;i++) v1[word1[i]-'a']++;
        for(int i=0;i<n;i++) v2[word2[i]-'a']++;
        for(int i=0;i<26;i++){
            if(v1[i]!=0 && v2[i]==0) return 0;
            else if(v2[i]!=0 && v2[i] == 0) return 0;
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
        if(v1!=v2) return 0;
        return 1;
    }
};