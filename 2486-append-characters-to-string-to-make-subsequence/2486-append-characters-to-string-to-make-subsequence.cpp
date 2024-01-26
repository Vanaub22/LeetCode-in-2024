class Solution {
public:
    int appendCharacters(string s, string t) {
        int i=0,ptr=0;
        while(i<s.size()) if(s[i++]==t[ptr]) ptr++;
        return t.size()-ptr;
    }
};