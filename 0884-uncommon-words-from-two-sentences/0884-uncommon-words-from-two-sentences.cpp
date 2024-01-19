class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        vector<string> uncommon;
        s1+=" ";
        s2+=" ";
        unordered_map<string,int> freq;
        string word="";
        for(char c:s1) {
            if(c!=' ') word+=c;
            else {
                freq[word]++;
                word="";
            }
        }
        for(char c:s2) {
            if(c!=' ') word+=c;
            else {
                freq[word]++;
                word="";
            }
        }
        for(auto it:freq) if(it.second==1) uncommon.push_back(it.first);
        return uncommon;
    }
};