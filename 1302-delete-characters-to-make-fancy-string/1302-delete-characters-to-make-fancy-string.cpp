class Solution {
public:
    string makeFancyString(string s) {
        int grp_ch=s[0],grp_cnt=0;
        for(char& c:s) {
            if(grp_ch==c) {
                grp_cnt++;
                if(grp_cnt>2) c='_';
            }
            else grp_cnt=1,grp_ch=c;
        }
        string ans="";
        for(char c:s) if(c!='_') ans+=c;
        return ans;
    }
};