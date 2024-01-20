class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        string ans;
        unordered_map<string,int> freq;
        set<string> bSet(banned.begin(),banned.end());
        paragraph+=" ";
        int n=paragraph.length(),mFreq=0;
        string word="";
        for(int i=0;i<n;i++) {
            if(isalpha(paragraph[i])) word+=tolower(paragraph[i]);
            else {
                if(word!="" && bSet.find(word)==bSet.end()) freq[word]++;
                word="";
            }
        }
        for(auto& it:freq) if(it.second>mFreq) {
            mFreq=it.second;
            ans=it.first;
        }
        return ans;
    }
};