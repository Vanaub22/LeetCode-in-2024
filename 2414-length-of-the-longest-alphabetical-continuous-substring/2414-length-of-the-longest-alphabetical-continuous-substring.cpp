class Solution {
public:
    // Sliding Window (Maximizing length of window)
    int longestContinuousSubstring(string s) {
        int n=s.length(),L=1;
        for(int left=0;left<n;left++) {
            int right=left+1;
            while(right<n) {
                if(s[right]==s[right-1]+1) {
                    right++;
                    L=max(L,right-left);
                }
                else break;
            }
            left=right-1;
        }
        return L;
    }
};