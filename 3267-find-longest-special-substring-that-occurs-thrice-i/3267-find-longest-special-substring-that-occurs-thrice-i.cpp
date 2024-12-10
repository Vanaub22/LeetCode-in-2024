class Solution {
public:
    int maximumLength(string s) {
        unordered_map<string,int> sstr_freq;
        for(int i=0;i<s.length();i++) {
            char sc=s[i];
            int slen=0;
            for(int j=i;j<s.length();j++) {
                if(s[j]==sc) slen++;
                else break;
            }
            for(int i=1;i<=slen;i++) sstr_freq[string(i,sc)]++;
        }
        int ans=0;
        for(auto& [str,f]:sstr_freq) if(f>=3 && ans<str.length()) ans=str.length();
        return ans?ans:-1;
    }
};