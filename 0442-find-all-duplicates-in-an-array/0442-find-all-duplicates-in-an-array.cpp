class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> duplicates;
        for(int i:nums) {
            if(nums[abs(i)-1]<0) duplicates.push_back(abs(i)); 
            nums[abs(i)-1]*=(-1);
        }
        return duplicates;
    }
};