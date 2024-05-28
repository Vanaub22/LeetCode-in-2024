class Solution {
public:
    int equalSubstring(string s, string t, int budget) {
        int n=s.length(),left=0,right=0,ans=0;
        while(right<n) {
            budget-=abs(s[right]-t[right]);
            while(budget<0) {
                budget+=abs(s[left]-t[left]);
                left++;
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};