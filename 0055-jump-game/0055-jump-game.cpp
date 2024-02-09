class Solution {
public:
    // One-pass greedy approach in linear time complexity
    bool canJump(vector<int>& nums) {
        int n=nums.size(),dest_idx=n-1;
        for(int i=n-2;i>=0;i--) if(dest_idx-i<=nums[i]) dest_idx=i;
        return !dest_idx;
    }
};