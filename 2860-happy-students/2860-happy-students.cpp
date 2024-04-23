class Solution {
public:
    int countWays(vector<int>& nums) {
        int n=nums.size(),ways=0;
        sort(nums.begin(),nums.end());
        if(nums[0]>0) ways++; // None of the students are selected but all are happy
        if(n-1>=nums.back()) ways++; // All the students are selected and all are happy
        for(int i=0;i<n-1;i++) if(i>=nums[i] && i+1<nums[i+1]) ways++; // Valid arrangement
        return ways;
    }
};