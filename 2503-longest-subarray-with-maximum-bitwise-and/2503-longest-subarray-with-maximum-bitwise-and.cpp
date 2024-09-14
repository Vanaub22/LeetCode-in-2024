// Bitwise-AND of two numbers will always be lesser than the greater number
// Required subarray will be the one which contains only the maximum element in the array
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int m=*max_element(nums.begin(),nums.end()),n=nums.size(),ans=1,sl=0;
        for(int i=0;i<n;i++) {
            if(nums[i]==m) sl++;
            else {
                ans=max(ans,sl);
                sl=0;
            }
        }
        return max(ans,sl);
    }
};