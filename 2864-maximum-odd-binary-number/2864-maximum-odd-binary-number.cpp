class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int ones=-1;
        for(char& c:s) if(c=='1') {
            ones++;
            c='0';
        }
        s[s.length()-1]='1';
        for(char& c:s) if(ones>0) {
            c='1';
            ones--;
        }
        else break;
        return s;
    }
};