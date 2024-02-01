class Solution {
public:
    string removeOuterParentheses(string s) {
        int open=0;
        string res="";
        for(char c:s) {
            if(c=='(') {
                if(open) res+=c;
                open++;
            }
            else {
                if(open>1) res+=c;
                open--;
            }
        }
        return res;
    }
};