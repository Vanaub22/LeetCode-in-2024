class Solution {
public:
    int countKeyChanges(string s) {
        int c=0;
        s[0]=tolower(s[0]);
        for(int i=1;i<s.size();i++) {
            s[i]=tolower(s[i]);
            if(s[i-1]!=s[i]) c++;
        }
        return c;
    }
};