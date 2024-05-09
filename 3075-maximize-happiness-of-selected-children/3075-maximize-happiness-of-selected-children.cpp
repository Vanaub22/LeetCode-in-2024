class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        sort(h.rbegin(),h.rend());
        long long ans=0;
        for(int i=0;i<k;i++) if(h[i]-i>=0) ans+=h[i]-i;
        return ans;
    }
};