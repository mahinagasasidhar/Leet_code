// Last updated: 01/04/2026, 19:25:22
class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
      int n = cardPoints.size();
      int i = n - k;
      int j = n - k;
      int sum = 0;
      int maxsum = 0;
      for(int steps = 0;steps<k;steps++){
        sum += cardPoints[(j++) % n];
      }
        maxsum = max(sum,maxsum);
      for(int steps=0;steps<k;steps++){
        sum -= cardPoints[(i++) % n];
        sum += cardPoints[(j++) % n];
        maxsum = max(sum,maxsum);
      }
      return maxsum;
    }
};