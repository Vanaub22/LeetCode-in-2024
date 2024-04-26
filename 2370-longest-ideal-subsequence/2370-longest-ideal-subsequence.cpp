class Solution {
public:
    int longestIdealString(string s, int k) {
        int ans=0,lis[123]={0}; // To store the length of the longest ideal string for that character
        for(char c:s) {
            for(int i=c;i>=c-k && i>=97;i--) {
                if(i==c && !lis[i]) {
                    lis[c]=1;
                    ans=max(ans,lis[c]);
                    continue;
                }
                lis[c]=max(lis[c],lis[i]+1);
            }
            for(int i=c+1;i<=c+k && i<=122;i++) lis[c]=max(lis[c],lis[i]+1);
            ans=max(ans,lis[c]);
        }
        return ans;
    }
};