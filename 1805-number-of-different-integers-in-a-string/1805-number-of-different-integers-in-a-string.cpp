class Solution {
private:
    // Helper fn. to remove leading zeroes from the string representation of integer
    string removeLeadingZeroes(string& s) {
        int i;
        for(i=0;i<s.size();i++) if(s[i]-'0') break;
        return s.substr(i);
    }
public:
    int numDifferentIntegers(string word) {
        bool num=isdigit(word[0]);
        string x="";
        set<string> s;
        for(int i=0;i<word.size();i++) {
            if(num) {
                if(isdigit(word[i])) x+=word[i];
                else  {
                    if(!x.empty()) s.insert(removeLeadingZeroes(x));
                    x.clear();
                    num=false;
                }
            }
            else {
                if(isdigit(word[i])) {
                    num=true;
                    x+=word[i];
                }
            }
            if(i==word.size()-1 && !x.empty()) s.insert(removeLeadingZeroes(x));
        }
        return s.size();
    }
};