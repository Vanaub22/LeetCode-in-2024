class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i,ii=i=0;
        for(;i<nums.size();i++) if(i<2 || nums[ii-2]!=nums[i]) nums[ii++]=nums[i];
        return ii;
    }
};