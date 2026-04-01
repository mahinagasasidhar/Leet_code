// Last updated: 01/04/2026, 19:25:20
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
    int j = 0;
    int cnt = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] == 1) {
            if (cnt == 0) {
                j = i;
                cnt++;
            }
        else {
            if (i- j- 1 >= k) {
                j = i;
            }
            else {
                return false;
            }
        }
    }
    }
    return true;
        }
};