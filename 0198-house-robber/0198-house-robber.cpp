// Recursive approach involving take/not-take optimized using 1-D top-down DP on subsequences (memoization)
class Solution {
private:
    int solve(int i, vector<int>& nums, int memo[]) {
        if(i==0) return nums[0];
        if(i<0) return 0;
        if(memo[i]!=-1) return memo[i];
        int take=nums[i]+solve(i-2,nums,memo),not_take=solve(i-1,nums,memo);
        return memo[i]=max(take,not_take);
    }
public:
    int rob(vector<int>& nums) {
        int memo[nums.size()];
        memset(memo,-1,sizeof(memo));
        return solve(nums.size()-1,nums,memo);
    }
};