class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=shifts.size();
        for(int i=n-1;i>=0;i--) {
            if(i==n-1) shifts[i]%=26; 
            else shifts[i]=(shifts[i]+shifts[i+1])%26;
        }
        for(int i=0;i<n;i++) s[i]=((s[i]+shifts[i])-'a')%26+'a';
        return s;
    }
};