class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int cost=0,m=nums.size(),i=0;
        long long int upper=0;
        while(upper<n) {
            if(i<m && nums[i]<=upper+1) {
                upper+=nums[i];
                i++;
            }
            else {
                cost++;
                upper+=upper+1;
            }
        }
        return cost;
    }
};