class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int ans=0;
        for(auto& word:words) {
            bool consistent=true;
            for(char c:word) if(allowed.find(c)==string::npos) {
                consistent=false;
                break;
            }
            if(consistent) ans++;
        }
        return ans;
    }
};