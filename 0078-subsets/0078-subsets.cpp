class Solution {
private:
    void helper(int i, auto subset, auto& subsets, auto& nums) {
        if(i==nums.size()) {
            subsets.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        helper(i+1,subset,subsets,nums);
        subset.pop_back();
        helper(i+1,subset,subsets,nums);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> subsets;
        vector<int> subset;
        helper(0,subset,subsets,nums);
        return subsets;
    }
};