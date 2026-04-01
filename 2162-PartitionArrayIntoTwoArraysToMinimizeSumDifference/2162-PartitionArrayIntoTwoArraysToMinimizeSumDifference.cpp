// Last updated: 01/04/2026, 19:24:59
class Solution {
public:
    int minimumDifference(vector<int>& nums) {
      int n = nums.size()/2;
      vector<int> left(nums.begin(),nums.begin()+n);
      vector<int> right(nums.begin()+n,nums.end());
      vector<vector<int>> l(n+1),r(n+1);
      //left 
      for(int mask = 0; mask < (1<<n);mask++){
        int size = __builtin_popcount(mask);
        int sum = 0; 
        for(int i =0;i < n;i++){
            if(mask & (1<<i)) sum += left[i]; 
        }
        l[size].push_back(sum);
      }
      //right
      for(int mask = 0; mask < (1<<n);mask++){
        int size = __builtin_popcount(mask);
        int sum = 0; 
        for(int i =0;i < n;i++){
            if(mask & (1<<i)) sum += right[i];
        }
        r[size].push_back(sum);
      } 
      int total = accumulate(nums.begin(),nums.end(),0); 
      int ans = INT_MAX;
      for(int i = 0;i <=n;i++) sort(r[i].begin(),r[i].end());
      for(int k = 0;k <= n;k++){
        for(auto x : l[k]){
            int target = total/2 - x;
            auto &vec = r[n-k];
            auto it = lower_bound(vec.begin(),vec.end(),target);
            if(it!=vec.end()){
                int y = *it;
                int sum = x+y;
                ans = min(ans,abs(total-2*sum));
            }
            if(it!=vec.begin()){
                --it;
                int y = *it;
                int sum = x+y;
                ans = min(ans,abs(total-2*sum));
            }
        }
      }
      return ans;
    }
};