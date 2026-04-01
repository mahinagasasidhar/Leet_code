// Last updated: 01/04/2026, 19:23:47
class Solution {
    private:
    long long rec(long long i,long long j, long long encCost, long long flatCost,vector<long long>& pre){
        long long len = j - i +1;
        long long X = pre[j] - ((i > 0) ? pre[i-1] :0);
        if((len)%2 == 1){
            if(X > 0) return  (len)*(X)*encCost;
            else return flatCost;
        }
        long long mid = (i + j)/2;
        long long ans = 1e17;
        ans = min(ans,rec(i,mid,encCost,flatCost,pre)+rec(mid + 1,j,encCost,flatCost,pre));
        if(X > 0) ans = min(ans,len*X*encCost);
        else if(X == 0) ans = min(ans,flatCost);
        return ans;
    }
public:
    long long minCost(string s, int encCost, int flatCost) {
        long long n = s.size();
        int dp[100001][100001];
        vector<long long> pre(n);
        pre[0] = (s[0] == '1') ? 1 : 0;
        for(long long i= 1; i < n;i++){
            pre[i] = pre[i - 1] + ((s[i] == '1') ? 1 : 0);
        }
        return rec(0,n-1,encCost,flatCost,pre);

    }
};