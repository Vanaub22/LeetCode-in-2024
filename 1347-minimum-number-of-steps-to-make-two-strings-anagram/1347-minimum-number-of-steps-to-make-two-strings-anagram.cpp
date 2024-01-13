class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> freq_s,freq_t;
        for(char c:s) freq_s[c]++;
        for(char c:t) freq_t[c]++;
        int ops=0;
        for(auto it:freq_s) if(freq_t[it.first]<it.second) ops+=it.second-freq_t[it.first];
        return ops;
    }
};