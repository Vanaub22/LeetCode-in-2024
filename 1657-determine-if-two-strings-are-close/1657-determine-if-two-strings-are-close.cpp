class Solution {
public:
    bool closeStrings(string w1, string w2) {
        vector<int> f1(26,0),f2(26,0);
        for(char c:w1) f1[c-'a']++;
        for(char c:w2) f2[c-'a']++;
        // The same characters must be present in both the words
        for(int i=0;i<26;i++) if(f1[i]!=0 && f2[i]==0 || f1[i]==0 && f2[i]!=0) return false;
        sort(f1.begin(),f1.end());
        sort(f2.begin(),f2.end());
        // The frequency values must be identical in both the words
        for(int i=0;i<26;i++) if(f1[i]!=f2[i]) return false;
        return true;
        
    }
};