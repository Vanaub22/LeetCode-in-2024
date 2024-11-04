class Solution {
public:
    string compressedString(string word) {
        string ans="";
        char grp_start='~';
        int grp_size=0;
        for(char c:word) {
            if(c==grp_start) {
                grp_size++;
                if(grp_size==9) {
                    ans+=to_string(grp_size)+grp_start;
                    grp_size=0;
                }
            }
            else {
                if(grp_size) ans+=to_string(grp_size)+grp_start;
                grp_start=c;
                grp_size=1;
            }
        }
        if(grp_size) ans+=to_string(grp_size)+grp_start;
        return ans;
    }
};