class Solution {
public:
    string stringHash(string s, int k) {
        string res="";
        int n=s.size();
        for(int i=0;i<=n-k;i+=k) {
            int score=0;
            for(int j=0;j<k;j++) score+=s[i+j]-'a';
            res+='a'+score%26;
        }
        return res;
    }
};