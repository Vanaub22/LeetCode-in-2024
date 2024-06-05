class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> res;
        int freq[26]={0};
        for(char c:words[0]) freq[c-'a']++;
        for(auto& word:words) {
            int wordf[26]={0};
            for(char c:word) wordf[c-'a']++;
            for(int i=0;i<26;i++) freq[i]=min(freq[i],wordf[i]);
        }
        for(int i=0;i<26;i++) for(int j=0;j<freq[i];j++) res.push_back(string(1,i+97));
        return res;
    }
};