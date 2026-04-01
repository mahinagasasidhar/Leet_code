// Last updated: 01/04/2026, 19:26:50
class Solution {
public:
    bool possible(vector<int>& arr, int maxSum, int k) {
    int n = arr.size();
    int sum = 0, subarray = 1;

    for (int i = 0; i < n; i++) {
        if (arr[i] > maxSum) return false;
            if (sum + arr[i] <= maxSum) {
                sum += arr[i];
            } else {
                subarray++;
                sum = arr[i];
            }
        }
        return subarray <= k;
    }

    int splitArray(vector<int>& nums, int k) {
    int low = *max_element(nums.begin(), nums.end());
    int high = accumulate(nums.begin(), nums.end(), 0);
     int ans = 0;

    while (low <= high) {
    int mid = (low + high) / 2;

    if (possible(nums, mid, k)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
