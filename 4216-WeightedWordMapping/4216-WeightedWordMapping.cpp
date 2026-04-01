// Last updated: 01/04/2026, 19:23:38
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string res = "";
        for (auto& word : words) {
            long long total = 0;
            for (char c : word) {
                total += weights[c - 'a'];
            }
            int rem = total % 26;
            char mappedChar = 'z' - rem;
            res += mappedChar;
        }
        
        return res;
    }
};