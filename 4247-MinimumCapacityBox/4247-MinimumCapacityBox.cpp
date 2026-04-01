// Last updated: 01/04/2026, 19:23:31
class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int ans = INT_MAX;
        int index = -1;
        for(int i = 0; i < capacity.size();i++){
            if(capacity[i] >= itemSize){
                if(capacity[i] < ans) ans = capacity[i],index = i;
            }
        }
        return (ans == INT_MAX) ? -1 : index;
    }
};