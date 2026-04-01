// Last updated: 01/04/2026, 19:26:21
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
    int n = bits.size();
    int i=0;
    while(i<n){
        if(bits[i]==1){
        if(i+2>=n){
        return false;
        }
        else{
            i=i+2;
        }
        }
        else{
            i++;
        }
    }
    return true;
    }
};