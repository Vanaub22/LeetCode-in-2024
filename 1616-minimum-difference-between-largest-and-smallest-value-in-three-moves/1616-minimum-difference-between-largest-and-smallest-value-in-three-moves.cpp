class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n=nums.size();
        if(n<=4) return 0; // It is possible to make all elements equal
        sort(nums.begin(),nums.end());
        // To minimize the difference we require to remove 3 elements from the extreme ends only
        return min({nums[n-1]-nums[3],nums[n-2]-nums[2],nums[n-3]-nums[1],nums[n-4]-nums[0]});
    }
};