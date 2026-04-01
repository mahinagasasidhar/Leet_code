// Last updated: 01/04/2026, 19:26:51
class Solution {
    public:
    int n;
    unordered_map<int,int> mp;
    int dp[2001][2001];
    int rec(int index,int k,vector<int>& stones){
        if(index == n-1) return 1;
        if(dp[index][k] != -1) return dp[index][k];
        int ans = 0;
        for(int jump=k-1;jump<=k+1;jump++){
            if(jump > 0 && mp.count(stones[index] + jump)) ans |= rec(mp[stones[index] + jump],jump,stones); 
        }
        return dp[index][k] = ans;
    }
public:
    bool canCross(vector<int>& stones) {
     n = stones.size();
     if(stones[1] != 1) return 0;
     for(int i = 0; i < n;i++) mp[stones[i]] = i;
     memset(dp,-1,sizeof(dp));
     return rec(1,1,stones);
    }
};