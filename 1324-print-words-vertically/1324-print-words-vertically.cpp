class Solution {
public:
    vector<string> printVertically(string s) {
        s+=" "; // Adding a space so that the last word gets considered
        // Finding out dimensions
        int L=0,word_cnt=1,n=s.length(),word_len=0;
        for(int i=0;i<n;i++) {
            if(s[i]==' ') {
                if(word_len<L) word_len=L;
                word_cnt++;
                L=0;
            }
            else L++;
        }
        cout<<word_len<<" "<<word_cnt;
        // Constructing the vertical result
        vector<string> res(word_len,string(word_cnt,' '));
        int r=0,c=0,i=0;
        while(i<n) {
            if(s[i]==' ') {
                c++;
                r=0;
            }
            else {
                res[r][c]=s[i];
                r++;
            }
            i++;
        }
        // Removing Trailing spaces
        for(auto& word:res) while(word.back()==' ') word.pop_back();
        return res;
    }
};