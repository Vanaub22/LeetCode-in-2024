class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size(),maxOr=0;
        for(int i:nums) maxOr|=i;
        function<int(int,int)> solve=[&](int i, int curr)->int {
            return i==n?curr==maxOr:solve(i+1,curr)+solve(i+1,curr|nums[i]);
        };
        return solve(0,0);
    }
};