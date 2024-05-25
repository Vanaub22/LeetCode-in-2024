class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> res;
        int n=s.length();
        for(auto& word:wordDict) {
            int m=word.length();
            if(s.substr(0,m)==word) {
                if(m==n) res.push_back(word);
                else {
                    vector<string> others=wordBreak(s.substr(m),wordDict);
                    for(auto& other:others) res.push_back(word+" "+other);
                }
            }
        }
        return res;
    }
};