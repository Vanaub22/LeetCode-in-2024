class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n=nums.size(),len=1,i=0;
        while(i<n-1) {
            int j=i+1;
            while(j<n) {
                if(nums[j]>nums[j-1]) j++;
                else break;
            }
            len=max(len,j-i);
            i=j;
        }
        return len;
        
    }
};