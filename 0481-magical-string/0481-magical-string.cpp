class Solution {
public:
    int magicalString(int n) {
        int ptr=2,cnt=1;
        string s="122";
        bool flg=true;
        while(s.length()<n) {
            int f=s[ptr++]-'0';
            if(flg) {
                s+=string(f,'1');
                cnt+=f;
                if(s.length()>n) cnt-=s.length()-n;
            }
            else s+=string(f,'2');
            flg=!flg;
        }
        return cnt;
    }
};