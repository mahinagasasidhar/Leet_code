// Last updated: 04/04/2026, 22:45:07
1class Solution {
2public:
3    bool rotateString(string s, string goal) {
4      if(s.size() != goal.size()) return false;
5      int n = s.size();
6      for(int i=0;i<n;i++){
7        bool flag = true;
8        for(int j=0;j<n;j++){
9            if(s[j] != goal[(j+i)%n]) flag = false;
10        }
11        if(flag == true) return true;
12      }
13      return false;
14    }
15};      