class Solution {
public:
    bool halvesAreAlike(string s) {
        int m=0,n=0,L=s.length();
        for(int i=0;i<L;i++) if(isVowel(s[i])) {
            if(i<L/2) m++;
            else n++;
        }
        return m==n;
    }
    bool isVowel(char c) {
        return c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U';
    }
};