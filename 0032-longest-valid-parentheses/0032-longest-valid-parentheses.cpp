// 2-Pass Solution with O(N) T.C. and O(1) S.C.
class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.length(),opened=0,closed=0,ans=0;
        for(char c:s) {
            if(c=='(') opened++;
            else closed++;
            if(opened==closed) ans=max(ans,opened*2);
            else if(closed>opened) opened=closed=0;
        }
        opened=closed=0;
        for(int i=n-1;i>=0;i--) {
            if(s[i]=='(') opened++;
            else closed++;
            if(opened==closed) ans=max(ans,opened*2);
            else if(opened>closed) opened=closed=0;
        }
        return ans;
    }
};