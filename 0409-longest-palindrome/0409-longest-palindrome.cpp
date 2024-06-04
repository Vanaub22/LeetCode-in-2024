class Solution {
public:
    int longestPalindrome(string s) {
        int f[123]={0},ans=0;
        bool hasOdd=false;
        for(char c:s) f[c]++;
        for(int i=0;i<123;i++) {
            if(f[i]%2==0) ans+=f[i];
            else {
                if(!hasOdd) ans+=f[i];
                else ans+=f[i]-1;
                hasOdd=true;
            }
        }
        return ans;
    }
};