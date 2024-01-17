class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length()<k) return false;
        unordered_map<char,int> freq;
        for(char c:s) freq[c]++;
        int odd=0;
        // Number of odd frequency characters = Minimum number of palindromes that must be made
        for(auto& it:freq) if(it.second%2) odd++;
        return odd<=k;
    }
};