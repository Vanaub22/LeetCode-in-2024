class Solution {
public:
    long long countSubstrings(string s, char x) {
        long long cnt=0,ans=0;
        for(char c:s) if(c==x) {
            cnt++;
            ans+=cnt;
        }
        return ans;
    }
};