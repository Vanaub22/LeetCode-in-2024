class Solution {
public:
    // Tabulation DP (Bottom-Up Approach)
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> lds;
        int n=nums.size(),len=1,dp[n+1],prev=-1;
        fill(dp,dp+n,1);
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++) {
            for(int j=0;j<i;j++) {
                if(nums[i]%nums[j]==0 && 1+dp[j]>dp[i]) {
                    dp[i]=1+dp[j];
                    len=max(len,dp[i]);
                }
            }
        }
        for(int i=n-1;i>=0;i--) {
            if(dp[i]==len && (prev==-1 || prev%nums[i]==0)) {
                lds.push_back(nums[i]);
                len--;
                prev=nums[i];
            }
        }
        return lds;
    }
};