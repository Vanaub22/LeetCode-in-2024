class Solution {
private:
    int solve(int i, int s, auto& nums, int target) {
        if(i==nums.size()) return s==target;
        return solve(i+1,s+nums[i],nums,target)+solve(i+1,s-nums[i],nums,target);
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int ways=0;
        return solve(0,0,nums,target);
    }
};