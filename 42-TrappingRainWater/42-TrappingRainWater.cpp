// Last updated: 01/04/2026, 19:28:51
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> dpr(n,0);
        dpr[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--){
          dpr[i] = max(height[i],dpr[i+1]);
        }
        int sum = 0;
        int lsum = 0;
        for(int i=0;i<n;i++){
            lsum = max(height[i],lsum);
            sum += min(dpr[i],lsum) - height[i];
        }
        return sum;
    }
};