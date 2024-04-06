// O(N) T.C. 
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string vps="";
        int cnt=0,n=s.length();
        for(char& c:s) {
            if(c=='(') cnt++;
            else if(c==')') {
                if(cnt) cnt--;
                else c='~';
            }
        }
        cnt=0;
        for(int i=n-1;i>=0;i--) {
            if(s[i]==')') cnt++;
            else if(s[i]=='(') {
                if(cnt) cnt--;
                else s[i]='~';
            }
        }
        for(char c:s) if(c!='~') vps+=c;
        return vps;
    }
};