class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long min_contribution=1e9,ans=0,xor_increase=0;
        for(int i:nums) {
            if((i^k)>i) {
                ans+=(i^k);
                min_contribution=min(min_contribution,(long long)((i^k)-i));
                xor_increase++;
            }
            else {
                ans+=i;
                min_contribution=min(min_contribution,(long long)(i-(i^k)));
            }
        }
        return xor_increase%2?ans-min_contribution:ans;
    }
};