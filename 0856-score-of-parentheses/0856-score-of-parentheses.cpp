class Solution {
public:
    int scoreOfParentheses(string s) {
        int depth=0,ans=0;
        char prev=*s.begin();
        for(char c:s) {
            if(c=='(') depth++;
            else {
                depth--;
                if(prev=='(') ans+=pow(2,depth);
            }
            prev=c;
        }
        return ans;
    }
};