// Last updated: 05/04/2026, 08:09:22
1class Solution {
2public:
3    int mirrorFrequency(string s) {
4        int n = s.size();
5        vector<int> freq(26,0);
6        for(int i=0;i<n;i++) if(s[i] >= 'a' && s[i] <= 'z') freq[s[i] - 'a']++;
7        vector<int> freq2(10,0);
8        for (int i=0;i<n;i++) if(s[i] >= '0' && s[i] <= '9') freq2[s[i] - '0']++;
9        int i=0;
10        int j = 25;
11        int total = 0;
12        while(i < j){
13            total += abs(freq[i++] - freq[j--]);
14        }
15        i = 0;
16        j = 9;
17        while(i < j){
18            total += abs(freq2[i++] - freq2[j--]);
19        }
20        return total;
21    }
22};