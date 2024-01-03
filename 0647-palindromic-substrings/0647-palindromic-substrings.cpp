class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length(),cnt=n; // All single-character substrings are palindromes
        for(int i=0;i<n;i++) {
            string str(1,s[i]);
            for(int j=i+1;j<n;j++) {
                str+=s[j];
                // Palindrome Checking
                int L=str.length();
                bool pal=true;
                for(int k=0;k<=L/2;k++) if(str[k]!=str[L-k-1]) {
                    pal=false;
                    break;
                }
                if(pal) cnt++;
            }
        }
        return cnt;
    }
};