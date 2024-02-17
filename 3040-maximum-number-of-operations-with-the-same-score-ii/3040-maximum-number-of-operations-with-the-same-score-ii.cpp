class Solution {
private:
    int solve(int left, int right, int sum, vector<int>& nums, vector<vector<int>>& dp) {
        if(left>=right) return 0;
        if(dp[left][right]!=-1) return dp[left][right];
        int p1=0,p2=0,p3=0;
        if(left+1<=right && nums[left]+nums[left+1]==sum) p1=1+solve(left+2,right,sum,nums,dp);
        if(right-1>=left && nums[right]+nums[right-1]==sum) p2=1+solve(left,right-2,sum,nums,dp);
        if(nums[left]+nums[right]==sum) p3=1+solve(left+1,right-1,sum,nums,dp);
        return dp[left][right]=max({p1,p2,p3});
    }
public:
    int maxOperations(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp1(n,vector<int>(n,-1)),dp2(n,vector<int>(n,-1)),dp3(n,vector<int>(n,-1));
        int p1=solve(2,n-1,nums[0]+nums[1],nums,dp1),p2=solve(0,n-3,nums[n-1]+nums[n-2],nums,dp2),p3=solve(1,n-2,nums[0]+nums[n-1],nums,dp3);
        return 1+max({p1,p2,p3});
    }
};
