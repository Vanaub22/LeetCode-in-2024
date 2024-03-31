class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int n=nums.size(),left=0,min_in_sub=-1,max_in_sub=-1;
        for(int right=0;right<n;right++) {
            if(nums[right]<minK || nums[right]>maxK) {
                left=right+1; // Changing the starting point
                continue;
            }
            if(nums[right]==maxK) max_in_sub=right;
            if(nums[right]==minK) min_in_sub=right;
            ans+=max((min(max_in_sub,min_in_sub)-left+1),0); // Adding valid subarrays ending at index 'right'
        }
        return ans;
    }
};