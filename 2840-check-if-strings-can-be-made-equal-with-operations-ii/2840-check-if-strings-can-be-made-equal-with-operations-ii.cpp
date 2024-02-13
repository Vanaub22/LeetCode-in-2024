class Solution {
public:
    bool checkStrings(string s1, string s2) {
        if(s1.length()!=s2.length()) return false;
        int o_cnt[26]={0},e_cnt[26]={0};
        for(int i=0;i<s1.length();i++) {
            if(i%2) {
                o_cnt[s1[i]-'a']++;
                o_cnt[s2[i]-'a']--;
            }
            else {
                e_cnt[s1[i]-'a']++;
                e_cnt[s2[i]-'a']--;
            }
        }
        for(int i=0;i<26;i++) if(o_cnt[i] || e_cnt[i]) return false;
        return true;
    }
};