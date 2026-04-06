// Last updated: 06/04/2026, 10:57:54
1class Solution {
2public:
3    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
4        //d tells the direction
5        int n = commands.size();
6        char d = 'n';
7        int x = 0;
8        int y = 0;
9        int mx = 0;
10        set<pair<int,int>> st;
11        for (auto &o : obstacles) st.insert({o[0], o[1]});
12        for(int i=0;i<n;i++){
13            if(commands[i] == -2){
14                if(d == 'n') d = 'w';
15                else if(d == 'e') d = 'n';
16                else if(d == 'w') d = 's';
17                else d = 'e';
18                continue;
19             } else if(commands[i] == -1){
20                if(d == 'n') d = 'e';
21                else if(d == 'e') d = 's';
22                else if(d == 'w') d = 'n';
23                else d = 'w';
24                continue;
25             }
26                for(int j=0;j<commands[i];j++){
27                    int ox = x;
28                    int oy = y;
29                    if(d == 'n') y += 1;
30                    else if(d == 'e') x+=1;
31                    else if(d == 'w') x -= 1;
32                    else y-=1;
33                    if(st.count({x,y})){
34                        x = ox;
35                        y = oy;
36                        break;
37                    }
38                    mx = max(mx,(x*x + y*y));
39                }
40             }
41        return mx;
42    }
43};