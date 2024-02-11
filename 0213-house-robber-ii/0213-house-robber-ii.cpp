// Modifying House Robber-1 solution for choosing either the first house or the last house
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        int dp1[n],dp2[n];
        memset(dp1,-1,sizeof(dp1));
        memset(dp2,-1,sizeof(dp2));
        return max(solve(n-1,nums,dp1,true),solve(n-2,nums,dp2,false));
    }
private:
    int solve(int i, auto& nums, int memo[], bool leaveFirst) {
        if(leaveFirst) {
            // Leaving the first house (indexing starts from 1)
            if(i==1) return nums[i];
            if(i<=0) return 0;
        }
        else  {
            if(i==0) return nums[i];
            if(i<0) return 0;
        }
        if(memo[i]!=-1) return memo[i];
        int take=nums[i]+solve(i-2,nums,memo,leaveFirst),not_take=solve(i-1,nums,memo,leaveFirst);
        return memo[i]=max(take,not_take);
    }
};