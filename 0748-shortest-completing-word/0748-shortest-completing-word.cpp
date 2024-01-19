class Solution {
public:
    string shortestCompletingWord(string lp, vector<string>& words) {
        int lp_f[26]={0};
        for(char c:lp) if(isalpha(c)) lp_f[tolower(c)-'a']++;
        int shortest=INT_MAX;
        string res;
        for(auto word:words) {
            int f[26]={0};
            for(char c:word) f[tolower(c)-'a']++;
            if(completing(lp_f,f) && word.size()<shortest) {
                shortest=word.size();
                res=word;
            }
        }
        return res;
    }
    bool completing(int lp_f[], int f[]) {
        for(int i=0;i<26;i++) if(lp_f[i] && lp_f[i]>f[i]) return false;
        return true;
    }
};