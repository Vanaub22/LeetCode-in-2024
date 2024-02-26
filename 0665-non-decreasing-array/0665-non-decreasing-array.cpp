class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size(),peaks=0;
        for(int i=0;i<n-1;i++) {
            if(nums[i]>nums[i+1]) {
                if(i==0 || i==n-2)  peaks++; // Removal at the beginning or at the end
                else {
                    // Removal somewhere in the middle (Either nums[i] or nums[i+1])
                    if(nums[i-1]<=nums[i+1] || nums[i]<=nums[i+2]) peaks++;
                    else return false; // The removal won't make the array non-decreasing
                }
            }
        }
        return n==1 || peaks<=1;
    }
};