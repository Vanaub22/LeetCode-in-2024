class Solution {
public:
    string sortString(string s) {
        string res="";
        bool c;
        int freq[26]={0};
        for(char c:s) freq[c-'a']++;
        do {
            for(int i=0;i<26;i++) {
                if(freq[i]) {
                    freq[i]--;
                    res+='a'+i;
                }
            }
            c=false;
            for(int i=25;i>=0;i--) {
                if(freq[i]) {
                    freq[i]--;
                    res+='a'+i;
                }
                if(freq[i]) c=true;
            }

        } while(c);
        return res;
    }
};