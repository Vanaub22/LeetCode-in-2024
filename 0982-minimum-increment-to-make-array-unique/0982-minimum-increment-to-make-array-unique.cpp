class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int inc=0;
        sort(nums.begin(),nums.end());
        for(int i=1;i<nums.size();i++) {
            if(nums[i]<=nums[i-1]) {
                inc+=nums[i-1]-nums[i]+1;
                nums[i]=nums[i-1]+1;
            }
        }
        return inc;
    }
};